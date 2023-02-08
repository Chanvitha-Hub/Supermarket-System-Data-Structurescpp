#include <iostream>
#include <string>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>

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

    void deleteItem(int id) {
        if (userType == "admin") {
            Item* temp = head;
            Item* prev = NULL;

            if (temp != NULL && temp->id == id) {
                head = temp->next;
                delete temp;
                std::cout << "Item deleted successfully." << std::endl;
                return;
            }

            while (temp != NULL && temp->id != id) {
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

    void modifyItem(int id, std::string name, int price, int quantity) {
        if (userType == "admin") {
            Item* temp = head;

            while (temp != NULL && temp->id != id) {
                temp = temp->next;
            }

            if (temp == NULL) {
                std::cout << "Item not found." << std::endl;
            } else {
                temp->name = name;
                temp->price = price;
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

    std::string userType;
    std::cout << "Enter user type (admin or cashier): ";
    std::cin >> userType;
    sm.setUserType(userType);

    if (userType == "admin") {
        while (true) {
            std::cout << "Select an option:" << std::endl;
            std::cout << "1. Add product" << std::endl;
            std::cout << "2. Delete product" << std::endl;
            std::cout << "3. Modify product" << std::endl;
            std::cout << "4. Display products" << std::endl;
            std::cout << "5. Exit" << std::endl;

            int option;
            std::string type, name;
            int id, quantity;
            float price;

            std::cout << "Enter your choice: ";
            std::cin >> option;

            switch (option) {
                case 1:
                    // Call addItem function here
                    std::cout << "Enter Product ID: ";
                    std::cin >> id;
                    std::cout << "Enter Product Name: ";
                    std::cin >> name;
                    std::cout << "Enter Product Price: ";
                    std::cin >> price;
                    std::cout << "Enter Product Quantity: ";
                    std::cin >> quantity;
                    sm.addItem(id, name, price, quantity);
                    break;
                case 2:
                    // Call deleteItem function here
                    std::cout << "Enter Product ID: ";
                    std::cin >> id;
                    sm.deleteItem(id);
                    break;
                case 3:
                    // Call modifyItem function here
                    sm.modifyItem(id, name, price, quantity);
                    break;
                case 4:
                    // Call displayItems function here
                    sm.displayItems();
                    break;
                case 5:
                    return 0;
                default:
                    std::cout << "Invalid option. Try again." << std::endl;

                    system("cls");
            }
            system("cls");
        }
    }
    return 0;
}