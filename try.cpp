#include <iostream>
#include <string>
using namespace std;

int main() {
    string username, password, usernameInput, passwordInput, bookTitle, inputTitle;
    int stockQuantity;
    username = "Grace";
    password = "1234";
    int tries = 4, choice;

    do {
        cout << "Enter username: ";
        cin >> usernameInput;
        cout << "Enter password (4 digits): ";
        cin >> passwordInput;

        system("cls");
        if (usernameInput == username && passwordInput == password) {
            break; 
        } else {
            cout << "Invalid username or password. Try again." << endl;
        }
    } while (tries--);

    if (tries < 0) {
        cout << "Too many failed attempts. Exiting the program." << endl;
        return 0;
    }

    system("cls");
    cout << "Welcome " << username << "!" << endl;

    bool done = false;
    do {
        cout << "Main Menu:" << endl
             << "1. Input Book Data" << endl
             << "2. Check All Books" << endl
             << "3. Search for a book" << endl
             << "4. Exit" << endl
             << "Enter choice: ";
        cin >> choice;

      switch (choice) {
            case 1:
                cout << "Enter Book Title: ";
                cin >> bookTitle;
                cout << "Enter Stock Quantity: ";
                cin >> stockQuantity;
                cout << "Input book data success!" << endl;
                system("pause");
                break;
            
            case 2:
                cout << "Book Title: " << bookTitle << endl;
                cout << "Stock Quantity: " << stockQuantity << endl;
                system("pause");
                break;
            
            case 3: 
                cout << "Enter book title to search: ";
                cin >> inputTitle;
                if (inputTitle == bookTitle) {
                    cout << "Stock Quantity = " << stockQuantity << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                system("pause");
                break;
            
            case 4:
                done = true; 
                cout << "Exiting the application. See you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (!done);

    return 0;
}
