#include <bits/stdc++.h>


using namespace std;

int main(){

    int t;
    string s, w;
    int n, m;
    bool could = false;

    cin >> t;
    while(t--){
        could = false;
        int cont = 0, it = 0;

        cin >> n >> m;
        cin >> s >> w;

        if(s.find(w) != string::npos){
                cout << cont << "\n";
                continue;
            }

        while(s.size() <= (4*w.size()) || it++ < 2){
            cont++;
            s+=s;
            if(s.find(w) != string::npos){
                cout << cont << "\n";
                could = true;
                break;
            }
        }
        if(!could) cout << -1 << "\n";
    }

    return 0;
}