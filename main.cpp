#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "login.h"
using namespace std;

int main()
{
  int hello;
  cout << " " << endl;
  cout << " " << endl;
  cout << " Lakukan Login Sebelum Memakai  " << endl;
  cout << " Lakukan Sign In, Jika Belum Mempunyai Akun  " << endl;
  cout << " " << endl;
  cout << " " << endl;
  cout << " 1. LOGIN" << endl;   
  cout << " 2. SIGN UP" << endl;
  cout << " " << endl;
  cout << " " << endl;
  cout << " >> "; cin >> hello;
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;
  if (hello == 2)
  {
    string username, password, email;

    cout << "   SIGN UP " << endl;
    cout << "           " << endl;
    cout << "   Username : "; cin >> username;
    cout << "   Password : "; cin >> password;
    cout << "   Email    : "; cin >> email;
    MessageBox(0,"Registration Succes!","Sign Up",0);
    string encrypHexa = "";
        int keyItr = 0;
        string key = "5";
        stringstream res;
        for (int i = 0; i < password.length(); i++){
            int temp = password[i] ^ key[keyItr];

            res << hex << setfill('0') << std::setw(2) << (int)temp;
            keyItr++;
            if (keyItr >= key.length()){
                keyItr = 0;
            }
        }

        res >> encrypHexa;

    ofstream file;
    file.open("D:\\" + username + ".txt");
    file << username << endl << encrypHexa << endl << email;
    file.close();
    system("cls");
    main();
  }
  else if (hello == 1)
  {
    bool status = IsLoggedIn();

    if (!status)
    {
      MessageBox(0,"Login Failed!","LOGIN",0);
      cout << "   "; system("PAUSE");
      return 0;
    }
    else
    {
      MessageBox(0,"Login Success!","LOGIN",0);
      system("cls");
      menu();
      return 1;
    }
  }
  else
  {
    cout << "   Your Choice is Wrong!" << endl;
    cout << "   "; system("PAUSE");
  }
  cin.get();
  return 0;
}
