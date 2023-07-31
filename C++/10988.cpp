#include<iostream>
#include<string>
using namespace std;

int main(){

    string s;
    cin >> s;
    bool ispalindrome = true;
    int length = s.length();
    int lastindex = length - 1;
    for(int i = 0; i < length/2; i++){
        char leftside = s[i];
        char rightside = s[lastindex - i];
        if(leftside != rightside){
            ispalindrome = false;
            break;
        }
    }
    if(ispalindrome){
        cout << 1 << "\n";
    }
    else{
        cout << 0 << "\n";
    }

    return 0;
}