const inputs = document.querySelectorAll(".input");

function addcl() {
    let parent = this.parentNode.parentNode;
    parent.classList.add("focus");
}

function remcl() {
    let parent = this.parentNode.parentNode;
    if (this.value === "") {
        parent.classList.remove("focus");
    }
}

inputs.forEach(input => {
    input.addEventListener("focus", addcl);
    input.addEventListener("blur", remcl);
});

function findNearestPlant() {
    const name = document.getElementById("name").value;
    const cropname = document.getElementById("cropname").value;
    const quantity = document.getElementById("quantity").value;
    const pincode = document.getElementById("pincode").value;

    // You can use these values to perform further actions or API requests
    console.log("Name:", name);
    console.log("Crop Name:", cropname);
    console.log("Quantity:", quantity);
    console.log("Pincode:", pincode);

    // For now, just display a message
    const resultDiv = document.getElementById("result");
    resultDiv.innerHTML = "Searching for nearest plant";
}
