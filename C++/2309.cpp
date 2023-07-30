#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int* arr = new int[9];
    int sum = 0;

    for(int i = 0; i < 9; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+9);

    int diff = sum - 100;
    int not1 = 0, not2 = 8;
    int temp = arr[not1] + arr[not2];
    
    while(temp != diff){
        if(temp < diff){
            not1++;
        }
        else{
            not2--;
        }
        temp = arr[not1] + arr[not2];
    }

    for(int i = 0; i < 9; i++){
        if(i == not1 || i == not2){
            continue;
        }
        cout << arr[i] << "\n";
    }


    return 0;
}