#include <bits/stdc++.h>

using namespace std;

const int INF = -1000;
const int MAX_CANDIES = 12;
int n, max_k;

int c[1010][MAX_CANDIES];
int dp[1010][12012];

int f(int i, int j, int k){
    if(k >= max_k) return 0;
    if(i >= n) return 0;
    if(j >= MAX_CANDIES) return f(i+1, 0, k);

    if (dp[i][k] != INF) return dp[i][k];

    dp[i][k] = max(c[i][j] + f(i, j+1, k+1), f(i+1, 0, k));
    return dp[i][k];
}

int main(){
    cin >> n >> max_k;
    for(int i=0; i<n; i++){
        for(int k=0; k<max_k; k++) dp[i][k] = INF;

        for(int j=0; j<MAX_CANDIES; j++)  cin >> c[i][j];
    }
    
    cout << f(0, 0, 0) << endl;
    
    return 0;
}