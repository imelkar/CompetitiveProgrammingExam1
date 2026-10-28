#include <bits/stdc++.h>
using namespace std;

#define llint long long int

int main(){
    int k, n;
    cin >> k;
    vector<int> res;
    for(int i=0; i<k; ++i){
        cin >> n;
        bool found = false;
        llint min_alice, min_me = -1, min_alice_backup = -1, temp;
        priority_queue<llint> not_found;
        cin >> min_alice;
        not_found.push(min_alice);
        for(int j=1; j<n; ++j){
            cin >> temp;
            if(found){continue;}
            if(temp < min_me || (temp < min_alice && min_me == -1)){
                if(min_alice_backup != -1){
                    min_alice = min_alice_backup;
                    min_alice_backup = -1;
                }
                if(min_me < min_alice && min_me != -1){
                    min_alice = min_me;
                }
                if(min_me == -1){
                    min_me = temp;
                    llint top = not_found.top();
                    while(top > min_me){
                        min_alice = top;
                        not_found.pop();
                        if(!not_found.empty()){
                            top = not_found.top();
                        }
                        else{
                            break;
                        }
                    }
                }
                min_me = temp;
            }
            else if((temp < min_alice && temp > min_me)&&(temp < min_alice_backup || min_alice_backup == -1)){
                min_alice_backup = temp;
            }
            else if(temp > min_alice && min_me != -1){
                found = true;
            }
            else if(min_me == -1){
                not_found.push(temp);
                if(temp > min_alice){
                    min_alice = temp;
                }
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