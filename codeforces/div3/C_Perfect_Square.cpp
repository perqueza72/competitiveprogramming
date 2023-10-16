#include <bits/stdc++.h>

using namespace std;

int n;

int f(vector<string> &g, int sise, pair<int, int> values[]){
    vector<int> v;
    for(int i=0; i<sise; i++){

        v.push_back(g[values[i].first][values[i].second]);
        // cout << "(" << values[i].first << "," << values[i].second << "," << g[values[i].first][values[i].second] << ") ";
    }
    int maxi = *max_element(v.begin(), v.end());

    int sum = 0;
    for(int i=0; i<sise; i++){
        sum+= maxi-g[values[i].first][values[i].second];
        g[values[i].first][values[i].second] = maxi;
    }
    // cout << "sum: " << sum << "\n";

    return sum;
}

int calc(int i, int j, vector<string> &g){

    int io = n-i-1, jo = n-j-1;

    pair<int, int> diag[] = {{i, j}, {i,jo}, {io,j}, {io,jo}},
        central[] = {{j,io}, {io,jo}, {i, j}, {jo,i}};
    int *values;
    if(i == j || io == jo) return f(g, 4, diag);
    return f(g, 4, central);
}

int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> n;

        vector<string> g(n);
        for(int i=0; i<n; i++) cin >> g[i];

        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) sum += calc(i, j, g);
        }

        cout << sum << "\n";

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << g[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

    }

    return 0;
}