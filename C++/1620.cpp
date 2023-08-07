#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main(){

    string answer = "";

    int n, m;
    cin >> n >> m;

    vector<string> pokevec;
    pokevec.push_back("no data in index 0");
    map<string, int> pokemap; 
    for(int i = 1; i <= n; i++){
        string data;
        cin >> data;
        pokevec.push_back(data);
        pokemap.insert({data, i});
    }

    for(int i = 0; i < m; i++){
        string quiz;
        cin >> quiz;
        try{
            answer.append(pokevec[stoi(quiz)]).append("\n");
        }
        catch(exception e) {
            answer.append(to_string(pokemap[quiz])).append("\n");
        }
    }

    cout << answer;

    return 0;
}