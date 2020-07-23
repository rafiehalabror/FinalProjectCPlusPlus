#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void cipher()
 {
    Label:
    cout << "" << endl;
    cout << "     CIPHER                            " << endl;
    cout << "                                       " << endl;
    cout << "     MENU :                            " << endl;
    cout << "     1. Encryption                     " << endl;
    cout << "     2. Decrypton                      " << endl;
    cout << "                                       " << endl;
    cout << "                                       " << endl;
    cout << "   Enter Your Choice : ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        cout << endl << "   ---Encryption---" << endl;
        char data[100], cipher[100], hasilen;
        int key;
        cout<<"   Message : ";
        gets(data);
        cout<<"   Key [1-25]: ";
        cin>>key;
        cout << " Encryption Results : ";
        for(int i=0;data[i]!='\0';i++)
                data[i] = toupper(data[i]); 
        for(int x=0;data[x]!='\0';x++)
        {
                if(data[x]==' ')
                              cipher[x] = data[x];
                else
                              cipher[x] = ((int(data[x]+key)%65)%26) + 65; 
                              cipher[x+1] = '\0'; 
        }
        for(int y=0;cipher[y]!='\0';y++)
            cout<< "   " << cipher[y];
        cout << "\n";

        char lagi;
        cout << "" << endl;
        cout << "   Repeat (Y/N) ? "; cin >> lagi;
        if (lagi == 'Y' || lagi == 'y')
        {
            goto Label;
        } else {
            goto Finish;
        }
    } else if (choice == 2){
        cout << endl << "   ---Decryption---" << endl;
        string encpMsg;
             cout<<"   Message (No Spaces): ";
            getline(cin, encpMsg);

            int dcyptKey;
            cout << "   Key [0-25]: ";
            cin >> dcyptKey;
            cin.ignore();

            string decryptedText = encpMsg;

            for (int i = 0; i < encpMsg.size(); i++){
                if(encpMsg[i]==32){
                    continue; 
                } else {
                    if((encpMsg[i] - dcyptKey) < 97 && (encpMsg[i] - dcyptKey) > 90){
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedText[i] = temp;
                    } else if((encpMsg[i] - dcyptKey) < 65){
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedText[i] = temp;
                    } else {
                        decryptedText[i] = encpMsg[i] - dcyptKey;
                    }
                }
            }

            cout << "   Decrypted Message : " << decryptedText << endl;
        cout << "\n";
        char lagi;
        cout << "" << endl;
        cout << "   Repeat (Y/N) ? "; cin >> lagi;
        if (lagi == 'Y' || lagi == 'y')
        {
            goto Label;
        } else {
            goto Finish;
        }
    } else {
        cout << endl << "   Wrong Choice! Enter Correctly! !" << endl;
    }
    Finish :
    exit;
 }