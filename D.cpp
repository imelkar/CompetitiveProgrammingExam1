#include <bits/stdc++.h>
using namespace std;

int main(){
    int digits[10] = {0};
    char c;
    cin >> c;
    // printf("%d", c);
    while(!cin.eof()){
        ++digits[c-48];
        cin >> c;
    }
    // cout << "here" << endl;
    // for(int i=0; i<10; ++i){
    //     printf("%d ", digits[i]);
    // }
    int min_i = 1;
    int min_v = digits[1];
    for(int i=2; i<10; ++i){
        if(min_v > digits[i]){
            min_v = digits[i];
            min_i = i;
        }
    }
    // cout << "here2" << endl;
    if(min_v == 0){
        cout << min_i;
        // cout << "here3" << endl;
        return 0;
    }
    // cout << "here4" << endl;
    if(digits[0] < min_v){
        cout << min_i;
        for(int i=0; i<digits[0]+1; ++i){
            cout << 0;
        }
        // cout << "here5" << endl;
        return 0;
    }
    // cout << "here6" << endl;
    for(int i=0; i<min_v+1; ++i){
        cout << min_i;
    }
    // cout << "here7" << endl;
    return 0;
}