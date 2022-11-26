#include <bits/stdc++.h>

using namespace std;

int main(){

    int a, b, diff = 0;
    cin >> a >> b;
    if(a == b){
        cout << diff << endl;
        return 0;
    }

    for(int i=2; i<=5; i++){
        while(a%i == 0){
            a/=i;
            if(b%i != 0) diff++;
            else b/=i;
        }

        while(b%i == 0){
            b/=i;
            if(a%i != 0) diff++;
            else a/=i;
        }
    }

    if(a != b) diff = -1;

    cout << diff << endl;

    return 0;
}