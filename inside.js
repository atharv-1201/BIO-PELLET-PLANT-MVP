class Name {
    static getName(Name) {
        return Name;
    }
}

class Quantity {
    static getQuantity(Quantity) {
        return Quantity;
    }
}

class CropName {
    static getCropName(CropName) {
        return CropName;
    }
}

class Price {
    static getPrice(Price, Quantity) {
        return 3.5 * Quantity;
    }
}

class ChennaiPlant {
    constructor(name, latitude, longitude) {
        this.name = name;
        this.latitude = latitude;
        this.longitude = longitude;
    }
}

function calculateDistance(lat1, lon1, lat2, lon2) {
    const earthRadius = 6371.0;

    const dLat = (lat2 - lat1) * Math.PI / 180.0;
    const dLon = (lon2 - lon1) * Math.PI / 180.0;

    const a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
        Math.cos(lat1 * Math.PI / 180.0) * Math.cos(lat2 * Math.PI / 180.0) *
        Math.sin(dLon / 2) * Math.sin(dLon / 2);

    const c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));

    const distance = earthRadius * c;

    return distance;
}

function findNearestPlant(plants, latitude, longitude) {
    let nearestPlant;
    let minDistance = Number.MAX_VALUE;

    for (const plant of plants) {
        const distance = calculateDistance(latitude, longitude, plant.latitude, plant.longitude);

        if (distance < minDistance) {
            minDistance = distance;
            nearestPlant = plant;
        }
    }

    return nearestPlant;
}

const pincodeinMap = {
    636108: [11.59435, 78.61286],
    603201: [12.80158, 80.02379],
    // ... other pincode entries ...
};

const plants = [
    new ChennaiPlant("Sree Amman Bio Fuels ( Wood Chips Suppliers in TamilNadu , 4.6)", 11.59435, 78.61286),
    // ... other ChennaiPlant entries ...
];

const Pincode = parseInt(prompt("Enter your pincode:"));
const Name = prompt("Enter your name:");
const Cropname = prompt("Enter crop name:");
const Quantity = parseInt(prompt("Enter crop quantity:"));
const Price = Quantity * 3.5;

console.log("Name: " + Name);
console.log("Crop Name: " + Cropname);
console.log("Quantity: " + Quantity);

let found = false;
for (let i = Pincode - 20; i <= Pincode + 20; ++i) {
    if (pincodeinMap[i]) {
        const userCoordinates = pincodeinMap[i];
        const nearestPlant = findNearestPlant(plants, userCoordinates[0], userCoordinates[1]);

        console.log("Nearest Bio-Pellet Plant for pincode " + i + ": " + nearestPlant.name);

        found = true;
        break;
    }
}

if (!found) {
    console.log("No bio-pellet plants found within the range " + Pincode);
}

console.log("Total Price: " + Price);

const choice = prompt("Do you want to receive payment? (Y/N):");
if (choice.toUpperCase() === 'Y') {
    console.log("Your payment is being processed......");
    console.log("You received: " + Price);
}
