#include<iostream>
using namespace std;

int main(){

    int numberofdays, k;
    cin >> numberofdays >> k;

    int* temperatures = new int[numberofdays];
    for(int i = 0; i < numberofdays; i++){
        cin >> temperatures[i];
    }

    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += temperatures[i];
    }

    int max = sum;

    for(int i = k; i < numberofdays; i++){
        sum = sum + temperatures[i] - temperatures[i-k];
        if(sum > max){
            max = sum;
        }
    }

    cout << max << "\n";


    return 0;
}