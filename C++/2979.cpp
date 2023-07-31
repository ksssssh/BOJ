#include<iostream>
using namespace std;

int main(){

    int a, b, c;

    cin >> a >> b >> c;

    int* howmanytrucks = new int[100];

    for(int i = 0; i < 3; i++){
        int truckin, truckout;
        cin >> truckin >> truckout;
        for(int j = truckin; j < truckout; j++){
            howmanytrucks[j] += 1;
        }
    }

    int totalcost = 0;

    for(int i = 0; i < 100; i++){
        switch(howmanytrucks[i]){
            case 1:
                totalcost += a;
                break;
            case 2:
                totalcost += b*2;
                break;
            case 3:
                totalcost += c*3;
                break;
            default:
                break;
        }
    }

    cout << totalcost << "\n";

    delete[] howmanytrucks;

    return 0;
}
