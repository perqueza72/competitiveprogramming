#include <bits/stdc++.h>

using namespace std;

int main(){

    
    int t, n, p, cont;
    cin >> t;
    while(t--){
        cin >> n >> p;
        cont = 0;
        for(int i=0; n>i; i++){
            for(int j=i+1; n>j; j++){
                cout << (i+1) << " " << (j+1) << "\n";
                cont++;
                if(cont == 2*n+p){
                    j = n, i = n;
                    break;
                }
            }
        }
    }
    return 0;
}