#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    int min = 1, max = 1000;
    while(true){
        n = (min+max)/2;
        cout << n << endl;
        // fflush(stdout);
        cin >> s;
        if(s.compare("lower") == 0){
            max = n-1;
        }
        else if(s.compare("higher") == 0){
            min = n+1;
        }
        else{
            break;
        }
    }
}