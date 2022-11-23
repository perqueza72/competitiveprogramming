#include <bits/stdc++.h>

using namespace std;


int square[51];

int main(){

    int n, t;
    vector<vector<int> > v(50);
    for(int i=0; i<51; i++) square[i] = i*i;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++) v[i] = vector<int>();

        int ball = 1;
        bool can = true;
        while(can){
            for(int i=0; i<n; i++){
                if(v[i].empty()) v[i].push_back(ball++);
                else if(binary_search(square, square+51, v[i].back()+ball)) v[i].push_back(ball++);
                else{
                    can = false;
                    continue;
                }

                can = true;
                break;
            }
        }

        cout << (ball-1) << "\n";
    }

    return 0;
}