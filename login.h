#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "menu.h"

using namespace std;
bool IsLoggedIn()
{
  string username, password, un, pw;
  cout << "   LOGIN " << endl;
  cout << "   " << endl;
  cout << "   Username : "; cin >> username;
  cout << "   Password : "; cin >> password;

  ifstream read("D:\\" + username + ".txt");
  getline(read, un);
  getline(read, pw);
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
  if (un == username && pw == encrypHexa)
  {
    return true;
  } else {
    return false;
  }
}
