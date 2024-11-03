#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

void logIn() {
  // create your dictionary
  map<string, string> dict = { {"Yency", "Art123"} };

  string username, password;

  login:
  cout << "Username: ";
  cin >> username;

  cout << "Password: ";
  cin >> password;

  // Check if provided username and password matches with the one is dictionary
  if (dict.find(username) != dict.end() && dict[username] == password) {
    cout << "Login Successfully!";
    system("pause");
  }
  else {
    cout << "Invalid Credentials"<<endl;
    cout<< "Try Again!"<<endl;
    goto login;
  }
}
int interfaceLIST(){
  cout<<"\n\t\t\t\t________________";
  cout<<"\n\t\t\t\t  Depreciation";
  cout<<"\n\t\t\t\t Inventory List";
  cout<<"\n\t\t\t\t________________"<<endl;
  return 0;
}
int interfaceCALC(){  
  cout<<"\n\t\t\t\t_______________";
  cout<<"\n\t\t\t\t Depreciation";
  cout<<"\n\t\t\t\t  Calculator";
  cout<<"\n\t\t\t\t_______________"<<endl;
  return 0;
}
int calc(){
    int I, S, depreciation,N;
    char what;

    interfaceCALC(); 
    cout << "Enter the cost basis of the asset: ";
    cin >> I;
    cout << "Enter the useful life of the asset: "; 
    cin >> N;
    cout << "Enter the estimated salvage value: ";
    cin >> S;
    depreciation = ((I-S) / N); // calculating the depreciation
    
    
    interfaceCALC();
    cout << "Straight-line method" << endl;
    cout << "The results are..." << endl;
    cout << depreciation <<endl;

    cout << "Would you like to see the other listed depreciation [Y/N]? ";
    cin >> what;
    if (what == 'Y') {
        system("cls");

        interfaceLIST();
        fstream myFile;
        myFile.open("invlist.txt", ios::out); // write
        if (myFile.is_open()) {
            myFile << "Hello" << endl;
            myFile.close();
        }
        myFile.open("invlist.txt", ios::app); // append
        if (myFile.is_open()) {
            myFile << "Hello again" << endl;
            myFile.close();
        }
        myFile.open("invlist.txt", ios::in); // read
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                cout << line << endl;
            }
            myFile.close();
        }
    } else if (what == 'N') {
        exit(0);
    } else {
        system("cls");
        cout << "You have entered a wrong input!" << endl;
        cout << "ERROR" << endl;
    }
    return 0;
}
