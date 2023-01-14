#include <bits/stdc++.h>
using namespace std;

long long m;
int powSum(long long b, long long e){

    long long r = 1;
    for(int i=0; i < 32; i++){
        if(e & (1<<i)) r=(r*b)%m;
        b=(b*b)%m;
    }

    return (r%m);
}

int main()
{
    int n;
    cin >> n >> m;

    int r = powSum(3, n)-1;
    if(r < 0) r+=m;
    cout << r;
    return 0;
}