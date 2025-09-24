#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vegetable {
public:
    vector<string> names;
    int n;

    Vegetable() {
        cout << "-------- Welcome to the HITESH Fresh Market -----------\n";
        n = 0;
    }

    void input() {
        cout << "How many vegetables do you want to add initially? ";
        cin >> n;
        names.resize(n);

        for (int i = 0; i < n; i++) {
            cout << "Enter vegetable " << i + 1 << " name: ";
            cin >> names[i];
        }
    }
};

class Available : public Vegetable {
public:
    vector<int> qty;
    vector<int> cost;

    void getInfo() {
        qty.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "Enter quantity for " << names[i] << ": ";
            cin >> qty[i];
        }
    }

    void setCost() {
        cost.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "Enter cost for " << names[i] << ": ";
            cin >> cost[i];
        }
    }
};

class Display : public Available {
public:
    void showStock() {
        cout << "\n--------- Available Stock -------------\n";
        int grandTotal = 0;

        for (int i = 0; i < n; i++) {
            int total = qty[i] * cost[i];
            cout << names[i] << " | Quantity: " << qty[i]
                 << " | Cost: " << cost[i]
                 << " | Total: " << total << endl;
            grandTotal += total;
        }

        cout << "----------------------------------------\n";
        cout << "Grand Total Stock Value = " << grandTotal << endl;
    }

    void updateQuantity(string vegName, int newQty) {
        for (int i = 0; i < n; i++) {
            if (names[i] == vegName) {
                qty[i] = newQty;
                cout << vegName << " quantity updated!\n";
                return;
            }
        }
        cout << "Vegetable not found!\n";
    }

    void updateCost(string vegName, int newCost) {
        for (int i = 0; i < n; i++) {
            if (names[i] == vegName) {
                cost[i] = newCost;
                cout << vegName << " cost updated!\n";
                return;
            }
        }
        cout << "Vegetable not found!\n";
    }

   
    void addVegetable(string newName, int newQty, int newCost) {
        names.push_back(newName);
        qty.push_back(newQty);
        cost.push_back(newCost);
        n++;
        cout << newName << " added successfully!\n";
    }
};

int main() {
    Display shop;
    shop.input();
    shop.getInfo();
    shop.setCost();

    int choice;
    do {
        cout << "\n===== Vegetable Shop Menu =====\n";
        cout << "1. Display stock\n";
        cout << "2. Update quantity\n";
        cout << "3. Update cost\n";
        cout << "4. Add new vegetable\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            shop.showStock();
        } 
        else if (choice == 2) {
            string name; int newQty;
            cout << "Enter vegetable name to update quantity: ";
            cin >> name;
            cout << "Enter new quantity: ";
            cin >> newQty;
            shop.updateQuantity(name, newQty);
        } 
        else if (choice == 3) {
            string name; int newCost;
            cout << "Enter vegetable name to update cost: ";
            cin >> name;
            cout << "Enter new cost: ";
            cin >> newCost;
            shop.updateCost(name, newCost);
        }
        else if (choice == 4) {
            string name; int q, c;
            cout << "Enter new vegetable name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> q;
            cout << "Enter cost: ";
            cin >> c;
            shop.addVegetable(name, q, c);
        }
        else if (choice == 5) {
            cout << "Exiting... Thank you!\n";
        } 
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
