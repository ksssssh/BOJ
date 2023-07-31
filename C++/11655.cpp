#include<iostream>
#include<string>
using namespace std;

bool isalphabet(char letter){
    if(letter >= 'A' && letter <= 'Z') return true;
    if(letter >= 'a' && letter <= 'z') return true;
    return false;
}

char push13(char alphabet){
    bool isupper = alphabet <= 'Z';
    int alphabetindex = isupper ? alphabet - 'A' : alphabet - 'a';
    int newalphabetindex = alphabetindex + 13;
    if(newalphabetindex >= 26){
        newalphabetindex -= 26;
    }
    char newalphabet = isupper ? 'A' + newalphabetindex : 'a' + newalphabetindex;

    return newalphabet;
}

string rot13(string plaintext){

    int textlength = plaintext.length();

    char* ciphertext = new char[textlength+1];

    for(int i = 0; i < textlength; i++){
        char letter = plaintext[i];
        if(isalphabet(letter)){
            letter = push13(letter);
        }
        ciphertext[i] = letter;
    }
    ciphertext[textlength] = '\0';

    return ciphertext;
}

int main(){

    string s;
    getline(cin, s);
    cout << rot13(s) << "\n";

    return 0;
}