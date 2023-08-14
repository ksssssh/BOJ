#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int main(){

    string answer = "";

    int t;
    cin >> t;
    while(t--){

        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<bool>> isplanted(m, vector<bool>(n, false));
        while(k--){
            int x, y;
            cin >> x >> y;
            isplanted[x][y] = true;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> isvisited(m, vector<bool>(n, false));
        int count = 0;

        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                if(!isplanted[x][y]){
                    continue;
                }
                if(isvisited[x][y]){
                    continue;
                }

                count++;

                q.push(make_pair(x,y));
                isvisited[x][y] = true;
                while(!q.empty()){
                    pair<int, int> pos = q.front();
                    q.pop();
                    int delta[2][4] = {{1,-1,0,0},{0,0,1,-1}};
                    for(int i = 0; i < 4; i++){
                        pair<int, int> newpos = make_pair(pos.first+delta[0][i], pos.second+delta[1][i]);
                        if(newpos.first < 0 || newpos.first >= m){
                            continue;
                        }
                        if(newpos.second < 0 || newpos.second >= n){
                            continue;
                        }
                        if(!isplanted[newpos.first][newpos.second]){
                            continue;
                        }
                        if(isvisited[newpos.first][newpos.second]){
                            continue;
                        }
                        q.push(newpos);
                        isvisited[newpos.first][newpos.second] = true;
                    }
                }
            }
        }

        answer.append(to_string(count)).append("\n");
    }

    cout << answer;

    return 0;
}