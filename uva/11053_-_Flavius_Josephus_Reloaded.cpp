#include <bits/stdc++.h>

using namespace std;

long long a, b;
int n;
long long f(long long x){
    return (a*(x*x%n)%n+b)%n;
}

int main(){

    long long x;
    long long tort, hare;
    while(cin >> n, n){
        cin >> a >> b;
        tort = hare = 0;
        
        do{
            hare = f(f(hare));
            tort = f(tort);
        }while(hare != tort);
        
        hare = f(tort);
        int j = 1;
        while(hare != tort){
            hare = f(hare);
            j++;
        }

        cout << (n-j) << "\n";
    }   

    return 0;
}