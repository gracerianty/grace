#include <iostream>
using namespace std;

int main ()
{ 
string name;
int Student_ID, age, month_work, final_salary, base_salary;

    cout<< "enter your name: ";
    cin>> name;

    cout<< "enter your Student_ID: ";
    cin >> Student_ID;

    cout<< "enter your age: ";
    cin >> age;

    cout<< "enter your base_salary: ";
    cin >> base_salary;

    cout<< "enter the month: ";
    cin >> month_work;
    
    final_salary  =  base_salary * month_work;

    cout << "Your name is " << name << endl;
    cout << "Your Student_ID is " << Student_ID << endl;
    cout << "Your age is " << age << endl;
    cout << "Your salary is" << final_salary << endl;


}


