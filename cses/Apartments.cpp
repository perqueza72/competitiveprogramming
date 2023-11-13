#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int usr[n], apto[m];
    for(int i=0; i<n; i++) cin >> usr[i];
    for(int j=0; j<m; j++) cin >> apto[j];

    sort(usr, usr+n);
    sort(apto, apto+m);

    int i = n-1, j = m-1, taked = 0;
    while(i > -1 && j > -1){
        if(usr[i] + k < apto[j]) j--;
        else if(usr[i] - k > apto[j]) i--;
        else{
            j--, i--;
            taked++;
        }
    }

    cout << taked << endl;

    return 0;
}