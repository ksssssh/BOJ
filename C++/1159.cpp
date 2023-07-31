#include<iostream>
#include<string>
using namespace std;

int main(){

    int n;

    cin >> n;

    int* firstlettercount = new int[26];

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        char firstletter = name[0];
        int index = firstletter - 'a';
        firstlettercount[index] += 1;
    }

    bool canplay = false;

    for(int i = 0; i < 26; i++){
        if(firstlettercount[i] >= 5){
            canplay = true;
            char firstletter = 'a' + i;
            cout << firstletter;
        }
    }

    if(!canplay){
        cout << "PREDAJA";
    }

    delete[] firstlettercount;

    return 0;
}