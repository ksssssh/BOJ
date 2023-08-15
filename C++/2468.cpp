#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int countsafetyzone(int n, const vector<vector<int>> &height, int rainheight){

    int count = 0;

    queue<pair<int,int>> q;
    vector<vector<bool>> isvisited(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isvisited[i][j]){
                continue;
            }
            if(height[i][j] <= rainheight){
                continue;
            }
            count++;
            q.push(make_pair(i,j));
            isvisited[i][j] = true;
            while(!q.empty()){
                pair<int, int> pos = q.front();
                q.pop();
                int delta[2][4] = {{1,-1,0,0},{0,0,1,-1}};
                for(int k = 0; k < 4; k++){
                    pair<int, int> newpos = make_pair(pos.first + delta[0][k], pos.second + delta[1][k]);
                    if(newpos.first < 0 || newpos.first >= n){
                        continue;
                    }
                    if(newpos.second < 0 || newpos.second >= n){
                        continue;
                    }
                    if(isvisited[newpos.first][newpos.second]){
                        continue;
                    }
                    if(height[newpos.first][newpos.second] <= rainheight){
                        continue;
                    }
                    q.push(newpos);
                    isvisited[newpos.first][newpos.second] = true;
                }
            }
        }
    }

    return count;
}

int main(){

    int n;
    cin >> n;

    vector<vector<int>> height(n, vector<int>(n));
    int maxheight = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> height[i][j];
            maxheight = height[i][j] > maxheight ? height[i][j] : maxheight; 
        }
    }

    int answer = 1;
    for(int rainheight = 1; rainheight < maxheight; rainheight++){
        int count = countsafetyzone(n, height, rainheight);
        if(count > answer){
            answer = count;
        }
    }

    cout << answer << "\n";


    return 0;
}