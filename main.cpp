#include <iostream>
#include <string>

struct Item {
    int id;
    std::string name;
    int price;
    int quantity;
    Item* next;
};

class SuperMarket {
private:
    Item* head;
    std::string userType;

public:
    SuperMarket() {
        head = NULL;
        userType = "";
    }

    void setUserType(std::string type) {
        userType = type;
    }

    void addItem(int id, std::string name, int price, int quantity) {
        if (userType == "admin") {
            Item* newItem = new Item();
            newItem->id = id;
            newItem->name = name;
            newItem->price = price;
            newItem->quantity = quantity;
            newItem->next = NULL;

            if (head == NULL) {
                head = newItem;
            } else {
                Item* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newItem;
            }
            std::cout << "Item added successfully." << std::endl;
        } else {
            std::cout << "You don't have permission to add items." << std::endl;
        }
    }

    void deleteItem(std::string name) {
        if (userType == "admin") {
            Item* temp = head;
            Item* prev = NULL;

            if (temp != NULL && temp->name == name) {
                head = temp->next;
                delete temp;
                std::cout << "Item deleted successfully." << std::endl;
                return;
            }

            while (temp != NULL && temp->name != name) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) {
                std::cout << "Item not found." << std::endl;
            } else {
                prev->next = temp->next;
                delete temp;
                std::cout << "Item deleted successfully." << std::endl;
            }
        } else {
            std::cout << "You don't have permission to delete items." << std::endl;
        }
    }

    void modifyItem(std::string name, int quantity) {
        if (userType == "admin") {
            Item* temp = head;

            while (temp != NULL && temp->name != name) {
                temp = temp->next;
            }

            if (temp == NULL) {
                std::cout << "Item not found." << std::endl;
            } else {
                temp->quantity = quantity;
                std::cout << "Item modified successfully." << std::endl;
            }
        } else {
            std::cout << "You don't have permission to modify items." << std::endl;
        }
    }

    void displayItems() {
        Item* temp = head;
        while (temp != NULL) {
            std::cout << "Product ID: " << temp->id << std::endl;
            std::cout << "Name: " << temp->name << std::endl;
            std::cout << "Price: " << temp->price << std::endl;
            std::cout << "Quantity: " << temp->quantity << std::endl;
            temp = temp->next;
        }
    }
};

int main() {
    SuperMarket sm;
    std::string type, name;
    int id, quantity;
    float price;
    std::cout << "Enter user type (admin/cashier): ";
    std::cin >> type;
    sm.setUserType(type);
    std::cout << "Enter Product ID: ";
    std::cin >> id;
    std::cout << "Enter Product Name: ";
    std::cin >> name;
    std::cout << "Enter Product Price: ";
    std::cin >> price;
    std::cout << "Enter Product Quantity: ";
    std::cin >> quantity;
    sm.addItem(id, name, price, quantity);
    sm.displayItems();
    return 0;
}