#include<iostream>
#include<string>
using namespace std;

int main(){

    string answer = "";

    int n;
    cin >> n;
    string pattern;
    cin >> pattern;

    int patternlength = pattern.length();
    int starindex = pattern.find("*");
    int frontlength = starindex;
    int backlength = patternlength - frontlength - 1;

    while(n--){

        string filename;
        cin >> filename;

        int filenamelength = filename.length();
        bool ismatched = filenamelength >= frontlength + backlength;

        if(ismatched){
            for(int i = 0; i < frontlength; i++){
                char patternletter, filenameletter;
                patternletter = pattern.at(i);
                filenameletter = filename.at(i);
                if(patternletter != filenameletter){
                    ismatched = false;
                    break;
                }
            }
        }

        if(ismatched){
            for(int i = 0; i < backlength; i++){
                char patternletter, filenameletter;
                patternletter = pattern.at(patternlength-1 - i);
                filenameletter = filename.at(filenamelength-1 - i);
                if(patternletter != filenameletter){
                    ismatched = false;
                    break;
                }
            }
        }

        if(ismatched){
            answer.append("DA\n");
        }
        else{
            answer.append("NE\n");
        }

    }

    cout << answer;

    return 0;
}