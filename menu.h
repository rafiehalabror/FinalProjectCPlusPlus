#include <iostream>
#include <windows.h>
#include "cout.h"
#include "caesar-cipher.h"
#include "xor-chiper.h"

using namespace std;

void menu()
{
  int choice, kripto;
  cout1();
    cout << "   Enter Your Choice : "; cin >> choice;
  switch(choice)
  {
    case 1:
    cout2();
    cout << "   Enter Your Choice : "; cin >> kripto;
    switch(kripto)
    {
      case 1:
      system("cls");
      cipher();
      char ask1;
      cout << "   Back to Main Menu (Y/N)? "; cin >> ask1;
      cout << "   "; system("PAUSE");
      if (ask1 == 'Y' || ask1 == 'y')
      {
        system("cls");
        menu();
      } else {
        exit;
      }
      break;

      case 2:
      system("cls");
      enxor();
      char ask2;
      cout << "   Back to Main Menu  (Y/N)? "; cin >> ask2;
      cout << "   "; system("PAUSE");
      if (ask2 == 'Y' || ask2 == 'y')
      {
        system("cls");
        menu();
      } else {
        exit;
      }
      break;
    }
    break;

    case 2:
    system("cls");
    char keluar;
    cout << "  " << endl;
    cout << "   Log Out (Y/N)? "; cin >> keluar;
    if (keluar == 'Y' || keluar == 'y')
      {
        MessageBox(0,"Log Out Succes!","LOG OUT",0);
        system("cls");
        system("main");
      } else {
        menu();
      }
    break;
  }
}