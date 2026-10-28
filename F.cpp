#include <bits/stdc++.h>
using namespace std;

#define llint long long int

int main(){
    int k, n;
    cin >> k;
    vector<llint> res;
    for(int i=0; i<k; ++i){
        cin >> n;
        llint p[n];
        for(llint j=0; j<n; ++j){
            cin >> p[j];
        }
        queue<int> to_try;
        to_try.push(n-1);
        bool found = false;
        while(!to_try.empty()){
            int a = to_try.front();
            to_try.pop();

            llint bob = p[a];
            llint min = -1;
            for(int j=a-1; j>=0; --j){
                if(min != -1){
                    if(p[j] < bob && p[j] > min){
                        found = true;
                        break;
                    }
                }
                if(p[j] < bob){
                    if(min == -1 || min > p[j]){
                        min = p[j];
                    }
                }
                else if(p[j] > bob){
                    to_try.push(j);
                }
            }
            if(found){
                break;
            }
        }
        if(found){
            res.push_back(i+1);
        }
    }

    cout << res.size() << '\n';
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << '\n';
    }
}