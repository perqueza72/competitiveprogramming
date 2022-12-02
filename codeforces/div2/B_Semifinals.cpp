#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n], b[n];
    bool r1[n] = {0}, r2[n] = {0};
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    int k = 0, i=0, j=0;
    while(k < n){
        k++;
        if(i == n){
            r2[j++] = 1;
            continue;
        }
        if(j == n){
            r1[i++] = 1;
            continue;
        }

        if(a[i] < b[j]) r1[i++] = 1;
        else r2[j++] = 1;
    }

    for(int i=0; i<n/2; i++){
        r1[i] = r2[i] = 1;
    }

    for(int i=0; i<n; i++){
        cout << r1[i];
    }
    cout << endl;
    
    for(int i=0; i<n; i++){
        cout << r2[i];
    }
    cout << endl;
    

    return 0;
}