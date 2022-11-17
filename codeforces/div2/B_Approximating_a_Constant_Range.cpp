#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, ant, r=1, maxi = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int act = v[0];
    bool change = false;
    for(int i=1; i<n; i++){
        if(act == v[i]){
            r++;
            continue;
        }

            if(change){
                if(v[i] == ant){
                    r++;
                    ant = act;
                    act = v[i];
                }
                else{
                    ant = act;
                    act = v[i];
                    maxi = max(r, maxi);
                    r = 2;
                }
            }else{
                ant = act;
                act = v[i];
                change = true;
                r++;
            }

    }

    cout << (max(maxi, r)) << endl;

    return 0;
}