#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){

    string answer = "";

    int t;
    cin  >> t;
    while(t--){
        int n;
        cin >> n;

        map<string, int> clothesincategory;

        for(int i = 0; i < n; i++){
            string cloth, category;
            cin >> cloth >> category;
            if(clothesincategory.find(category) == clothesincategory.end()){
                clothesincategory.insert({category, 1});
            }
            else{
                clothesincategory[category] += 1;
            }
        }

        int cases = 1;
        for(auto iter = clothesincategory.begin(); iter != clothesincategory.end(); iter++){
            cases *= (iter->second)+1;
        }

        cases -= 1;

        answer.append(to_string(cases)).append("\n");
    }

    cout << answer;

    return 0;
}