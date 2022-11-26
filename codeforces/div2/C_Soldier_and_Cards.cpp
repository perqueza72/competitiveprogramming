#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, a, k, b;
    deque<int> u,v;

    cin >> n;
    cin >> k;
    while(k--) cin >> a, v.push_back(a);
    cin >> k;
    while(k--) cin >> a, u.push_back(a);

    int i=0;
    for(; i<(1<<(n+1)) && v.size() && u.size(); i++){
        a = v.front();
        b = u.front();
        v.pop_front();
        u.pop_front();

        if(a > b){
            v.push_back(b);
            v.push_back(a);
        }else{
            u.push_back(a);
            u.push_back(b);
        }
    }

    if(u.empty()) cout << i << " 1" << endl;
    else if(v.empty()) cout << i << " 2" << endl;
    else cout << "-1" << endl;

    return 0;
}