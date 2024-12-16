#include <iostream>
#include <iomanip>
using namespace std;

 int main() {
 int nim, ipk;
 string password;

 cout<<  setw (50) << setfill ('=')<<"s"<< endl;
 cout << "LOGIN SPADA" << endl;

 cout<<  setw (50) << setfill ('=')<< endl;
 
 cout<< setw (20)<< setfill (' ') <<left <<"masukan NIM= ";
 cin>> nim;
 cout<< setw (20)<< setfill (' ')<<left<<"masukan pasword= ";
 cin>> password;
 cout<< setw (20)<< setfill (' ')<<left<<"masukan ipk= ";
 cin>> ipk ;
 if (password == "bebas"){
    cout << "ANDA LOGIN"<< endl;
 } else if (password != "bebas") { 
    cout  << "GAGAL LOGIN"<< endl;
 } 
 cout << "masukan ipk= ";
 cin >> ipk ;
 if (ipk >3){
    cout<< "sigma coumlode"<< endl;
} else if (ipk<3){
    cout << "segma aja"<< endl;
}

 }