#include<iostream>
#include<string>
using namespace std;

int main(){

    string s;
    int* count = new int[26];

    cin >> s;

    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        count[c-'a']++;
    }

    for(int i = 0; i < 26; i++){
        cout << count[i] << " ";
    }

    return 0;
}