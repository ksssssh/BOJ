#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> board(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++){
            if(line[j] == '1'){
                board[i][j] = true;
            }
        }
    }

    queue<pair<pair<int, int>, int>> queue;
    queue.push(make_pair(make_pair(0,0),1));
    vector<vector<bool>> isvisited(n, vector<bool>(m, false));
    isvisited[0][0] = true;

    int delta[2][4] = {{1,-1,0,0}, {0,0,1,-1}};

    int answer;

    while(!queue.empty()){
        pair<pair<int, int>, int> cur = queue.front();
        queue.pop();
        pair<int, int> pos = cur.first;
        int length = cur.second;

        if(pos.first == n-1 && pos.second == m-1){
            answer = length;
            break;
        }

        for(int i = 0; i < 4; i++){
            pair<int, int> newpos = make_pair(pos.first + delta[0][i], pos.second + delta[1][i]);
            if(newpos.first < 0 || newpos.first >= n){
                continue;
            }
            if(newpos.second < 0 || newpos.second >= m){
                continue;
            }
            if(!board[newpos.first][newpos.second]){
                continue;
            }
            if(isvisited[newpos.first][newpos.second]){
                continue;
            }

            queue.push(make_pair(newpos, length+1));
            isvisited[newpos.first][newpos.second] = true;
        }
    }

    cout << answer << "\n";

    return 0;
}