#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <windows.h>

struct Product {
    int id;
    std::string name;
    double price;
    int quantity;
    Product *next;
};

struct Cashier {
    std::string cashierName;
    std::string cashierPassword;
    Cashier *nextCashier;
};

class Supermarket {
private:
    Product *head;
    Cashier *headCashier;

public:
    Supermarket() {
        head = NULL;
        headCashier = NULL;
    }

    // Add a product to the linked list
    void addProduct(int id, std::string name, double price, int quantity) {
        Product *newProduct = new Product;
        newProduct->id = id;
        newProduct->name = name;
        newProduct->price = price;
        newProduct->quantity = quantity;
        newProduct->next = NULL;

        if (head == NULL) {
            head = newProduct;
            return;
        }

        Product *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProduct;
    }

    // Delete a product from the linked list
    void deleteProduct(int id) {
        Product *temp = head, *prev;
        if (temp != NULL && temp->id == id) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;

        prev->next = temp->next;
        delete temp;
    }

    // Modify a product in the linked list
    void modifyProduct(int id, std::string name, double price, int quantity) {
        Product *temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                temp->name = name;
                temp->price = price;
                temp->quantity = quantity;
                break;
            }
            temp = temp->next;
        }
    }

    // Display all products in the linked list
    void displayProducts() {
        Product *temp = head;
        while (temp != NULL) {
            std::cout << "\n\tID: " << temp->id << std::endl;
            std::cout << "\tName: " << temp->name << std::endl;
            std::cout << "\tPrice: $" << temp->price << std::endl;
            std::cout << "\tQuantity: " << temp->quantity << std::endl;
            temp = temp->next;
            std::cout << std::endl;
        }
    }

    // Function to find the product price from linked list using product ID
    double getProductPrice(int id) {
        Product *temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                return temp->price;
            }
            temp = temp->next;
        }
        return 0; // If product ID not found
    }

    // Function to find the product name from linked list using product ID
    std::string getProductName(int id) {
        Product *temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                return temp->name;
            }
            temp = temp->next;
        }
        return "NA"; // If product Name not found
    }

    // Function to find the product quantity from linked list using product ID
    double getQuantity(int id) {
        Product *temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                return temp->quantity;
            }
            temp = temp->next;
        }
        return 0; // If product ID not found
    }

    void setQuantity(int productId, int newQuantity) {
        Product *temp = head;
        while (temp != NULL) {
            if (temp->id == productId) {
                temp->quantity = newQuantity;
                return;
            }
            temp = temp->next;
        }
        // If productId is not found in the list, you could choose to throw an exception or print an error message here
    }

    // Function to calculate each varity total
    double calculateEachTotal(int id, int quantity) {
        double price = getProductPrice(id);
        if (price == 0) {
            std::cout << "Product not found" << std::endl;
        } else {
            double total = price * quantity;
            return total;
        }
    }


    // Add a cashier to the linked list
    void addCashier(std::string cashierName, std::string cashierPassword) {
        Cashier *newCashier = new Cashier;
        newCashier->cashierName = cashierName;
        newCashier->cashierPassword = cashierPassword;
        newCashier->nextCashier = NULL;

        if (headCashier == NULL) {
            headCashier = newCashier;
            return;
        }

        Cashier *temp = headCashier;
        while (temp->nextCashier != NULL) {
            temp = temp->nextCashier;
        }
        temp->nextCashier = newCashier;
    }

    //******************************************
    // Delete a cashier from the linked list
    void deleteCashier(std::string cashierName) {
        Cashier *temp = headCashier, *prevCashier;
        if (temp != NULL && temp->cashierName == cashierName) {
            headCashier = temp->nextCashier;
            delete temp;
            return;
        }

        while (temp != NULL && temp->cashierName != cashierName) {
            prevCashier = temp;
            temp = temp->nextCashier;
        }

        if (temp == NULL) return;

        prevCashier->nextCashier = temp->nextCashier;
        delete temp;
    }
    //******************************************


    // Display all cashiers in the linked list
    void displayCashiers() {
        Cashier *temp = headCashier;
        while (temp != NULL) {
            std::cout << "\n\tUser Name: " << temp->cashierName << std::endl;
            std::cout << "\tPassword: " << temp->cashierPassword << std::endl;
            temp = temp->nextCashier;
            std::cout << std::endl;
        }
    }

    // Function to find the cashier name from linked list using cashier name
    bool getCashierName(std::string cashierName) {
        Cashier *temp = headCashier;
        while (temp != NULL) {
            if (temp->cashierName == cashierName) {
                return true;
            }
            temp = temp->nextCashier;
        }
        return false; // If product Name not found
    }
};




//class Cashier {
//	private:
//	    Cashier *head;
//
//	public:
//	    Transations() {
//	        head = NULL;
//	    }
//
//};

int main() {


    std::cout << "\n==============Supermarket System===============" << std::endl;
//    std::string userType;
//    std::cout << "\nEnter user type (admin or cashier): ";
//    std::cin >> userType;
    std::string userName = "admin";
    std::string password = "admin123";
    std::cout << "\nEnter User Name: ";
    std::cin >> userName;
    std::cout << "Enter Password: ";
    std::cin >> password;
    std::string cashierName_array[10];
    std::string cashierPassword_array[10];
    int cashierSize = sizeof(cashierName_array) / sizeof(cashierName_array[0]);

    Supermarket sm;

    while (true) {
        system("cls"); // Use "cls" on Windows systems
        std::cout << "\n==============Supermarket System===============" << std::endl;
        std::cout << "\n\tSelect an option:" << std::endl;
        std::cout << "\t\t1. Change User Type" << std::endl;
        std::cout << "\t\t2. Add Product" << std::endl;
        std::cout << "\t\t3. Delete Product" << std::endl;
        std::cout << "\t\t4. Modify Product" << std::endl;
        std::cout << "\t\t5. Display Products" << std::endl;
        std::cout << "\t\t6. Create Transactions" << std::endl;
        std::cout << "\t\t7. Add Cashiers" << std::endl;
        std::cout << "\t\t8. Delete Cashiers" << std::endl;
        std::cout << "\t\t9. Display Cashiers" << std::endl;
        std::cout << "\t\t10. Exit" << std::endl;

        int choice;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        int id;
        std::string name;
        double price;
        int quantity;
        switch (choice) {
            case 1:
                std::cout << "\nEnter User Name: ";
                std::cin >> userName;
                std::cout << "Enter Password: ";
                std::cin >> password;
                break;
            case 2:
                if (userName == "admin" && password == "admin123") {
                    std::cout << "\nAdd your Item: ";
                    std::cout << "\n\tEnter product ID: ";
                    std::cin >> id;
                    std::cout << "\tEnter product name: ";
                    std::cin >> name;
                    std::cout << "\tEnter product price: $";
                    std::cin >> price;
                    std::cout << "\tEnter product quantity: ";
                    std::cin >> quantity;
                    sm.addProduct(id, name, price, quantity);
                    std::cout << "\nItem added successfully!\n";
                } else {
                    std::cout << "Access denied. Only admin can add products." << std::endl;
                }
                break;
            case 3:
                if (userName == "admin" && password == "admin123") {
                    std::cout << "\n\tEnter product ID to delete: ";
                    std::cin >> id;
                    sm.deleteProduct(id);
                    std::cout << "\nItem deleted successfully!\n";
                } else {
                    std::cout << "Access denied. Only admin can delete products." << std::endl;
                }
                break;
            case 4:
                if (userName == "admin" && password == "admin123") {
                    std::cout << "\n\tEnter product ID to modify: ";
                    std::cin >> id;
                    std::cout << "\tEnter product name: ";
                    std::cin >> name;
                    std::cout << "\tEnter product price: $";
                    std::cin >> price;
                    std::cout << "\tEnter product quantity: ";
                    std::cin >> quantity;
                    sm.modifyProduct(id, name, price, quantity);
                    std::cout << "\nItem modified successfully!\n";
                } else {
                    std::cout << "Access denied. Only admin can modify products." << std::endl;
                }
                break;
            case 5:
                sm.displayProducts();
                break;
            case 6:
            {
                int p = 0;
                while ((userName == "admin" && password == "admin123") || (userName == cashierName_array[p] && password == cashierPassword_array[p])) {
                    int variety = 0;
                    std::cout << "\n\tHow many variety of products do you have to bill: ";
                    std::cin >> variety;
                    int id_array[variety];
                    int quantity_array[variety];
                    std::string name_array[variety];
                    double price_array[variety];
                    double eachTotal_array[variety];

                    for (int i=0; i<variety; i++) {
                        std::cout << "\n\tEnter product ID to bill: ";
                        std::cin >> id;
                        std::cout << "\tEnter product quantity: ";
                        std::cin >> quantity;

                        int newQuantity = sm.getQuantity(id) - quantity;
                        sm.setQuantity(id, newQuantity);
                        id_array[i] = id;
                        quantity_array[i] = quantity;
                        name_array[i] = sm.getProductName(id);
                        price_array[i] = sm.getProductPrice(id);
                        eachTotal_array[i] = sm.calculateEachTotal(id, quantity);

                    }

                    //calculate the grand total of the invoice
                    double grandTotal = 0;
                    for (int k=0; k<variety; k++) {
                        grandTotal += eachTotal_array[k];
                    }

                    std::cout << "\n==============TRANSACTION INVOICE===============" << std::endl;

                    std::cout << "\nID\tNAME\tPRICE\tQUANTITY\tTOTAL\n" << std::endl;
                    for (int j=0; j<variety; j++) {
                        std::cout << id_array[j] << "\t" << name_array[j] << "\t" << price_array[j] << "\t" << quantity_array[j] << "\t\t=   " << eachTotal_array[j] << std::endl;
                        Sleep(20);
                    }
                    std::cout << "\n\t\t\tGrand Total  =  " << grandTotal << std::endl;
                    std::string paymentType;
                    do {
                        std::cout << "\nPay with card/cash: ";
                        std::cin >> paymentType;
                        if (paymentType == "card" || paymentType == "CARD") {
                            int cardNumber;
                            std::cout << "\tEnter card number: ";
                            std::cin >> cardNumber;
                            std::cout << "Total amount has been paid!\n";
                            break;
                        } else if (paymentType == "cash" || paymentType == "CASH") {
                            double cashAmount;
                            std::cout << "\tEnter cash provided: ";
                            std::cin >> cashAmount;
                            double balanceAmount = 0.0;
                            balanceAmount = cashAmount - grandTotal;
                            std::cout << "Total amount has been paid! \nBalance is " << balanceAmount << std::endl;
                            break;
                        } else {
                            std::cout << "Invalid Input";
                        }
                    } while (paymentType != "card" || paymentType != "CARD" || paymentType != "CASH" || paymentType != "cash");
                    std::cout << "Total " << grandTotal*0.1 << " are added to the membership card!\n";
                    p++;
                    break;
                }
                if ((userName != "admin" && password != "admin123") || (userName != cashierName_array[p] && password != cashierPassword_array[p])) {
                    //std::cout << "Access denied. Only admins and cashiers can create transactions." << std::endl;
                }
                break;
            }
            case 7:
                if (userName == "admin" && password == "admin123") {
                    std::string cashierName, cashierPassword;
                    std::cout << "\nAdd new cashier: ";
                    std::cout << "\n\tEnter User Name: ";
                    std::cin >> cashierName;
                    std::cout << "\tEnter Password: ";
                    std::cin >> cashierPassword;
                    sm.addCashier(cashierName, cashierPassword);
                    cashierName_array[0] = cashierName;
                    cashierPassword_array[0] = cashierPassword;
                    std::cout << "\nCashier added successfully!\n";
                } else {
                    std::cout << "Access denied. Only admin can add cashiers." << std::endl;
                }
                break;
            case 8:
                if (userName == "admin" && password == "admin123") {
                    std::string cashierName;
                    std::cout << "\nDelete cashier: ";
                    std::cout << "\n\tEnter User Name: ";
                    std::cin >> cashierName;
                    if (sm.getCashierName(cashierName)) {
                        sm.deleteCashier(cashierName);
                        std::cout << "\nCashier deleted successfully!\n";
                    } else {
                        std::cout << "\nCashier NOT Found!\n";
                    }
                } else {
                    std::cout << "Access denied. Only admin can delete cashiers." << std::endl;
                }
                break;
            case 9:
                if (userName == "admin" && password == "admin123") {
                    sm.displayCashiers();
                } else {
                    std::cout << "Access denied. Only admin can display cashiers." << std::endl;
                }
                break;
            case 10:
                exit(0);
                break;
            default:
                std::cout << "Invalid option. Try again." << std::endl;
        }

        std::cout << std::endl;
        for(int i=0; i<48; i++)
        {
            std::cout << "=";
            Sleep(10);
        }
        std::cout << "\n\nPress ENTER to continue...";
        std::cin.ignore();
        std::cin.get();
    }
    return 0;
}

