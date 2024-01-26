const inventorySystem = {
    inventory: [],

    addItem: function () {
        const newItem = {};
        newItem.itemName = prompt("Enter item name:");
        newItem.quantity = parseInt(prompt("Enter quantity:"));
        newItem.price = parseFloat(prompt("Enter price:"));

        this.inventory.push(newItem);
        alert("Item added successfully!");
    },

    displayInventory: function () {
        const output = document.getElementById("output");
        output.innerHTML = "";

        if (this.inventory.length === 0) {
            output.innerHTML = "Inventory is empty.";
            return;
        }

        const table = document.createElement("table");
        table.innerHTML = "<tr><th>Item Name</th><th>Quantity</th><th>Price</th></tr>";

        this.inventory.forEach(item => {
            const row = table.insertRow();
            row.innerHTML = `<td>${item.itemName}</td><td>${item.quantity}</td><td>$${item.price.toFixed(2)}</td>`;
        });

        output.appendChild(table);
    },

    updateQuantity: function () {
        const itemName = prompt("Enter the item name to update quantity:");
        const item = this.inventory.find(item => item.itemName === itemName);

        if (item) {
            const newQuantity = parseInt(prompt("Enter the new quantity:"));
            item.quantity = newQuantity;
            alert("Quantity updated successfully!");
        } else {
            alert("Item not found in the inventory.");
        }
    }
};

function addItem() {
    inventorySystem.addItem();
}

function displayInventory() {
    inventorySystem.displayInventory();
}

function updateQuantity() {
    inventorySystem.updateQuantity();
}

function exitProgram() {
    alert("Exiting the program. Goodbye!");
    // Additional logic for exiting the program if needed
}
