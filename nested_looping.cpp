//GRACE RIANTY BUTAR BUTAR 123240036
#include <iostream> 
using namespace std;

int main() {
    int n; //Declaring the data type

    cout << "Input n: "; // Prompts the user to enter a value for n
    cin >> n; 

    //Outer loop to control the number rows
    for (int i = 0; i < n; i++) {
        //Inner loop to make spaces before the asterisks
        for (int j = 0; j < n - i - 1; j++) {
            cout << " "; 
        }
        //Inner loop to make asterisks
        for (int k = 0; k < 2 * i + 1; k++) {
            cout << "*";
        }
        cout << endl; 
    }
}
