#include <bits/stdc++.h>
using namespace std;


int main(){
    long long int n, m, p, c;
    cin >> n >> m;
    long long int min = INFINITY;
    vector<long long int> ms;
    cin >> p >> c;
    for(long long int i=0; ;++i){
        long long int res = p*i-c;
        ms.push_back(res);
        if(res >= m){
            min = i;
            break;
        }
    }
    // printf("min = %lld\n", min);
    for(long long int i=1; i<n; ++i){
        cin >> p >> c;
        for(long long int j=0; j<min; ++j){
            if(ms[j] < ms[j] + p*j-c){
                ms[j] = ms[j] + p*j-c;
                if(ms[j] >= m){
                    min = j;
                    break;
                }
            }
        }
        // printf("!min = %lld\n", min);
    }
    cout << min << '\n';
}