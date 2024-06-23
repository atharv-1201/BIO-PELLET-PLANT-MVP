//TEAM NAME - DEBUG THUGS
//To address this problem, we aim to develop a web application that serves as a platform for farmers to sell their crop residue directly to bio-pellet plant operators. Bio-pellets, a sustainable alternative to traditional fuels, can be produced from crop residue and used in various applications, including heating and electricity generation.

#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include <vector>
#include <map>
using namespace std;

class name {

public:
    
    static string getname(string Name) {
       
        return Name;
    }
};

class quantity {

public:
    
    static int getquantity(int Quantity) {
      
        return Quantity;
    }
};

class cropname {
public:
   
    static string getcropname(string Cropname) {
       
        return Cropname;
    }
};

class price {
public:
    
    static double getprice(double Price , int Quantity )
    {
       
        return 3.5*Quantity;
    }
};
struct ChennaiPlant {
 
    string name;
    
    double latitude;
   
    double longitude;
    
    double rating;
};

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double earthRadius = 6371.0;

    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) *
               sin(dLon / 2) * sin(dLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = earthRadius * c;
    
    return distance;
}

ChennaiPlant findNearestPlant(const vector<ChennaiPlant>& plants, double latitude, double longitude) {
    ChennaiPlant nearestPlant;
    
    double minDistance = numeric_limits<double>::max();

    for (const auto& plant : plants) 
    {
        double distance = calculateDistance(latitude, longitude, plant.latitude, plant.longitude);
        
        if (distance < minDistance)
        {
            minDistance = distance;
            nearestPlant = plant;
        }
    }

    return nearestPlant;
}

int main() {
    map<int, pair<double, double>> pincodeinMap = {
        {636108, {11.59435, 78.61286}},
        
        {603201, {12.80158, 80.02379}},
        
        {637301, {11.6332, 78.12752}},
        
        {636108, {11.08991, 77.37712}},
        
        {628217, {8.54165, 78.07609}},
        
        {604407, {12.71248, 79.53142}},
        
        {600087, {13.04216, 80.18555}},
        
        {600086, {13.045784, 80.186071}},
        
        {638107, {11.31369, 77.68807}},
        
        {600117, {12.9405, 80.17555}},
        
        {642113, {10.56512, 77.34845}},
        
        {620015, {10.76131, 78.83783}},
        
        {631502, {9.925199, 78.15794}},
        
        {600066, {13.15482, 80.2044}},
        
        {621201, {11.62291, 78.14697}},
        
        {600024, {13.04724, 80.22552}},
        
        {630606, {11.237417, 76.968849}},
        
        {641653, {11.23295, 77.1049}},
        
        {623706, {12.83314, 79.30027}},
    };

    vector<ChennaiPlant> plants;
    
    plants.push_back({"Sree Amman Bio Fuels ( Wood Chips Suppliers in TamilNadu , 4.6)", 11.59435, 78.61286 });
   
    plants.push_back({"Sakthy Muruga Bio Materials - Biomass Briquettes, Wood Chips, Biomass Pellets supplier in Tamil Nadu, India , 4.5)", 11.6332, 78.12752 });
  
  plants.push_back({"M.G.R Biopellet processing unit , 4.5", 12.80158, 80.02379 });


    plants.push_back({"Sree Bannari Amman Bio Fuels , 4.6)", 11.08991, 77.37712 } );
    
    plants.push_back({"Thugalagam Biofuels (Briquettes) , 4.2", 8.54165, 78.07609 } );
    
    plants.push_back({"Kaviya bio fuel , 5 ", 12.71248, 79.53142 });
    
    plants.push_back({"Nav indus food machines , 4.7", 13.04216, 80.18555 } );
    
    plants.push_back({"Sara bio resources(India) ltd. , 5", 13.045784, 80.186071 } );
    
    plants.push_back({"Canopus Biofuels , 4.3", 11.31369, 77.68807 });
    
    plants.push_back({"Sakthi Veera Green Energy Pvt ltd , 4.4", 12.9405, 80.17555 });
     
    plants.push_back({"Saravana Agro Fuels , 4", 10.56512, 77.34845 });
    
    plants.push_back({"Jeyamaruthi bio energy system , 3.9", 10.76131, 78.83783 });
    
    plants.push_back({"Eco Sudar Bio Pellets , 4.9", 9.925199, 78.15794 });
    
    plants.push_back({"Kothari Bio Fuels , 4.2", 13.15482, 80.2044 } );
    
    plants.push_back({"Sri Meena Agro Products , 5", 11.62291, 78.14697 } );
    
    plants.push_back({"M.A.V. Bio-Fuels , 2", 13.04724, 80.22552 });
    
    plants.push_back({"JLS AGRO ENERGY , 4.3", 11.237417, 76.968849 } );
    
    plants.push_back({"Sun Company , 4.6", 11.23295, 77.1049 });
    
    plants.push_back({"NISHE AGRO FUELS , 4.2", 12.83314, 79.30027 } );

    int Pincode;
    
    string Name;
    
    int Quantity;
    
    string Cropname;
    
    int Price;
    
    cout << "Enter your name: ";
    
    cin >> Name;
    
    cout << "Enter crop name: ";
    
    cin >> Cropname;
    
    cout << "Enter crop quantity: ";
    
    cin >> Quantity;
    
    cout << "Enter your pincode: ";
    
    cin >> Pincode;

    
    string a = name::getname(Name);
    
    string c = cropname::getcropname(Cropname);
    
    int b = quantity::getquantity(Quantity);
    
    double d = price::getprice(Price , Quantity);
    
    cout << "Name: " << a << endl;
    
    cout << "Crop Name: " << c << endl;
   
    cout << "Quantity: " << b << endl;
 

    bool found = false;
    for (int i = Pincode - 20; i <= Pincode + 20; ++i) 
    {
        if (pincodeinMap.find(i) != pincodeinMap.end()) 
        {
            pair<double, double> userCoordinates = pincodeinMap[i];
            
            ChennaiPlant nearestPlant = findNearestPlant(plants, userCoordinates.first, userCoordinates.second);

            cout << "Nearest Bio-Pellet Plant for pincode " << i << ": " << nearestPlant.name << endl;

            found = true;
            break;
        }
    }

    if (!found) 
    {
        
        cout << "No bio-pellet plants found within the range " << Pincode << endl;
    }

    cout << "Total Price: " << d << endl;
    
    cout << "Do you want to receive payment? (Y/N): ";
    
    char choice;

    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
       
        cout << "Your payment is being processed......"<< endl;
        
        cout << "You received: " << d <<endl;
    }
    return 0;
}
