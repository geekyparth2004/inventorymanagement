#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct InventoryItem {
    string itemName;
    int quantity;
    double price;
};

class InventoryManagementSystem {
private:
    vector<InventoryItem> inventory;

public:
    // Function to add an item to the inventory
    void addItem() {
        InventoryItem newItem;
        cout << "Enter item name: ";
        getline(cin, newItem.itemName);
        cout << "Enter quantity: ";
        cin >> newItem.quantity;
        cout << "Enter price: $";
        cin >> newItem.price;

        inventory.push_back(newItem);

        cout << "Item added successfully!" << endl;
    }

    // Function to display the current inventory
    void displayInventory() {
        if (inventory.empty()) {
            cout << "Inventory is empty." << endl;
            return;
        }

        cout << setw(20) << "Item Name" << setw(15) << "Quantity" << setw(10) << "Price" << endl;
        cout << setfill('-') << setw(45) << "" << setfill(' ') << endl;

        for (const auto& item : inventory) {
            cout << setw(20) << item.itemName << setw(15) << item.quantity << setw(10) << "$" << fixed << setprecision(2) << item.price << endl;
        }
    }

    // Function to update the quantity of an item in the inventory
    void updateQuantity() {
        if (inventory.empty()) {
            cout << "Inventory is empty. Unable to update quantity." << endl;
            return;
        }

        string itemName;
        cout << "Enter the item name to update quantity: ";
        getline(cin, itemName);

        for (auto& item : inventory) {
            if (item.itemName == itemName) {
                int newQuantity;
                cout << "Enter the new quantity: ";
                cin >> newQuantity;
                item.quantity = newQuantity;
                cout << "Quantity updated successfully!" << endl;
                return;
            }
        }

        cout << "Item not found in the inventory." << endl;
    }
};

int main() {
    InventoryManagementSystem inventorySystem;
    int choice;

    do {
        cout << "\n=== Inventory Management System ===" << endl;
        cout << "1. Add Item\n2. Display Inventory\n3. Update Quantity\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Consume newline character

        switch (choice) {
            case 1:
                inventorySystem.addItem();
                break;
            case 2:
                inventorySystem.displayInventory();
                break;
            case 3:
                inventorySystem.updateQuantity();
                break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
