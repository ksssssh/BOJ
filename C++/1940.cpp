#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> ownnumber(n);
    for(int i = 0; i < n; i++){
        cin >> ownnumber[i];
    }

    sort(ownnumber.begin(), ownnumber.end());

    int leftpoint = 0, rightpoint = n-1;
    int answer = 0;

    while(leftpoint < rightpoint){
        int sum = ownnumber[leftpoint] + ownnumber[rightpoint];
        if(sum == m){
            answer += 1;
            leftpoint++;
            rightpoint--;
            continue;
        }
        if(sum < m){
            leftpoint++;
            continue;
        }
        else {
            rightpoint--;
        }
    }

    cout << answer << "\n";
    
    return 0;
}