#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    string name;
    cin >> name;

    int alphabetcount[26] = {0,};

    for(char c : name){
        int alphabetindex = c - 'A';
        alphabetcount[alphabetindex] += 1;
    }

    string frontpart = "";
    string middleletter = "";
    bool canmake = true;

    for(int i = 0; i < 26; i++){
        char alphabet = 'A' + i;
        int count = alphabetcount[i];
        if(count % 2 == 1){
            if(middleletter.length() == 0){
                middleletter.push_back(alphabet);
            }
            else{
                canmake = false;
                break;
            }
        }
        for(int j = 0; j < count/2; j++){
            frontpart.push_back(alphabet);
        }
    }

    if(canmake){
        cout << frontpart << middleletter;
        reverse(frontpart.begin(), frontpart.end());
        cout << frontpart << "\n";
        
    }
    else{
        cout << "I'm Sorry Hansoo" << "\n";
    }

    return 0;
}