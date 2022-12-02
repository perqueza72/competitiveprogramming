#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    long long numbers[n+10];
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }
    
    long long l[m+10], r[m+10], d[m], op[n+10] ={0}, veces[m+10] = {0};
    for(int i=0; i<m; i++){
        cin >> l[i] >> r[i] >> d[i];
        l[i]--;
    }

    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        veces[a-1]++;
        veces[b]--;
    }
    for(int i=1; i<=m; i++) veces[i]+= veces[i-1];

    for(int i=0;i<m; i++){
        op[l[i]]+=veces[i]*d[i];
        op[r[i]]-=veces[i]*d[i];
    }
    for(int i=1; i<n; i++) op[i]+= op[i-1];

    for(int i=0; i<n; i++){
        numbers[i]+= op[i];
        cout << numbers[i] << " ";
    }
    cout << endl;
    

    return 0;
}