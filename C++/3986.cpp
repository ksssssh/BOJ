#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){

    int answer = 0;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;

        stack<char> s;
        s.push('z');
        for(char c : word){
            char top = s.top();
            if(top == c){
                s.pop();
            }
            else{
                s.push(c);
            }
        }

        if(s.top() == 'z'){
            answer++;
        }

    }

    cout << answer << "\n";

    return 0;
}