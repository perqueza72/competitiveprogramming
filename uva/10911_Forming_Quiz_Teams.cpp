#include <bits/stdc++.h>
const int INF = 1e9;
const int EPSILON = 1e-9;

using namespace std;

double dp[(1 << 16)];

int n;
vector<pair<int, int> > v;

double d(pair<int, int> i, pair<int, int> j){
    // return i.first*j.first + i.second*j.second;
    return sqrt((i.first-j.first)*(i.first-j.first) + (i.second - j.second)*(i.second - j.second));
}

double f(const int state){

    double &ans = dp[state];

    // double mini = INF;

    
    // cout << "state " << state << endl;
    if(state + 1 == (1 << (n*2))){
        return 0.0;
    }
    
    // cout << state << ": " << dp[state] << endl;
    if(ans > -0.5){
        return ans;
    }

    ans = INF;


    for(int i=0; i < (n*2 - 1); i++){
        if(state & ( 1<<i )){
            continue;
        }

        for(int j=i+1; j<n*2; j++){
            if(state & (1<<j)){
                continue;
            }

            ans = min(d(v[i], v[j]) + f(state + (1 << i) + (1 << j)), ans);
        }


    }

    return ans;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, t = 0;
    v = vector<pair<int, int> >(16);
    cout.precision(2);

    string s;
    while(cin >> n, n){
        for(int i = 0; i<(1 << 16); i++){
            dp[i] = -1;
        }
        t++;

        for(int k=0; k<n*2; k++){
            cin >> s >> i >> j;
            v[k] = {i, j};
        }

        cout << "Case " << t << ": " << fixed << f(0) << '\n';
    }

    return 0;
}