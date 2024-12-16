#include <iostream>
using namespace std;

int main() {
    string username, password, usernameInput, passwordInput, bookTitle;
    int stockQuantity;
    username = "Grace";
    password = "1234";
    int tries = 2, choice;
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
             << "Enter choice: ";
        cin >> choice;
  
switch (choice) {
        
        case 1: {
            string bookTitle;
            int stockQuantity;

            cout << "Enter book title: ";
            getline(cin, bookTitle);
            
            cout << "Enter stock quantity: ";  
            cin >> stockQuantity;
            cout << "Book Title: " << bookTitle << endl;
            cout << "Stock Quantity: " << stockQuantity << endl;

            break; 
            }
            case 2:
                getline(cin, bookTitle);
                break;
                case 3: {
                string bookTitle;
                cout << "Enter book title to search: ";
                getline(cin, bookTitle);
                
                break;
            }

            case 4:
                done = true; // Exit the loop
                cout << "Exiting the application." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (!done);

    return 0;
}