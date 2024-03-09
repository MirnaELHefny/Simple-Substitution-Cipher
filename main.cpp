#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

string buildKey(string Key) {       //Function To Make The Key Alphabet

    string cipherAlphabet = Key;

    auto last = unique(cipherAlphabet.begin(), cipherAlphabet.end());     //Arrange Alphabets Tp Make The unique Ones At The Beginning
    cipherAlphabet.erase(last, cipherAlphabet.end());     //To Delete The Same The Duplicated Alphabets

    for (char ch = 'a'; ch <= 'z'; ++ch) {      //Add The Rest Of Alphabets
        if (cipherAlphabet.find(ch) == string::npos) {//If The Letter Is Already In The Key Do not Add It
            cipherAlphabet += ch;
            }
        }

    return cipherAlphabet;
}

string encrypt(string Message, string Key) {    //Function To Cipher The Text

    string newMessage = "";    //To Collect The Resulted Message

    for(int i = 0 ; i < Message.size() ; i++) {   //Starting From The First char To The Last One

        if (isalpha(Message[i])) {      //For Every Alphabet In The Text
            char currentChar = tolower(Message[i]);   //Make Them Lower Case
            int keyIndex = currentChar - 'a';     //Substitute The Index To Find Its Equal In The Cipher Alphabet
            newMessage += Key[keyIndex];   //Add The Cipher Alphabet To The Cipher Text
        }

        else {
            newMessage += Message[i];    //Add Spaces
        }
    }

    return newMessage;
}
string decrypt(string Message, string Key) {    //Function To Decrypt The Text

    string newMessage = "";    //To Collect The Resulted Message

    for (int i = 0; i < Message.size(); i++) {    //Starting From The First char To The Last One

        if (isalpha(Message[i])) {    //For Every Alphabet In The Text
            char currentChar = tolower(Message[i]);    //Make Them Lower Case
            int keyIndex = Key.find(currentChar);    //Find The Index Of The Character
            Message[i] = 'a' + keyIndex;     //Add The Index To Cipher Alphabet Index To Find Its Value In The Cipher Alphabet
            newMessage += Message[i];     //Add The Cipher Alphabet To The Cipher Text
        }

        else {
            newMessage += Message[i];   //Add Spaces
        }
    }

    return newMessage;
}

int main () {    //Main Programme

    cout << "WELCOME TO SIMPLE SUBSTITUTION CIPHER PROGRAMME" << endl;    //Welcome Message

    string Key;
    cout << "Enter Your Key (5 Unique Letters) Please:";    //Ask The User For The Cipher Key
    cin >> Key;

    while (Key.size() != 5) {   //If The Cipher Key Is Not 5 Letters
        cout << "Invalid Key, PLease Enter A Valid Key:";   //Ask The User To Enter The Key Again
        cin >> Key;
    }

    Key = buildKey(Key);
    cout << "Cipher Alphabet: " << Key << endl;  //Show The User His Cipher Alphabet

    string Message;
    cout << "Enter your Message Please:";    //Ask The User For His Message
    getline(cin >> ws , Message);

    string Choice;
    cout << "Do You Want To Cipher The Message (A) Or Decipher The Message (B)?";   //Ask The User If He Wants To Cipher Or Decipher The Message
    cin >> Choice;
    Choice = toupper(Choice[0]);

    if (Choice == "A") {   //If The User Chooses To Cipher His Message
        Message = encrypt(Message, Key);
        cout << "Cipher Message Is: " << endl << Message;
    }

    else {    //If The User Chooses To Decipher His Message
        Message = decrypt(Message, Key);
        cout << "Decipher Message Is: " << endl << Message;
    }
}