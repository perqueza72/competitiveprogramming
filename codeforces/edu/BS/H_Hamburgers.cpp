#include <bits/stdc++.h>


using namespace std;

long long b, nS, c;
long long pB, pS, pC;
long long tB = 0, tS = 0, tC = 0;
long long r;

bool isTooMuch(const long long &x){
    long long needB = x*tB;
    long long needS = x*tS;
    long long needC = x*tC;

    if(x == 2){
        // cout << tS << " " << needS << "-" << nS << endl;
        // cout << (max(0ll, (needB-b))*pB) << " ";
        // cout << (max(0ll, (needS-s))*pS) << " ";
        // cout << (max(0ll, (needC-c))*pC) << endl;

    }

    // cout << x << ": " << (max(0ll, (needB-b))*pB + max(0ll, (needS-nS))*pS + max(0ll, (needC-c))*pC) << endl;
    return (max(0ll, (needB-b))*pB + max(0ll, (needS-nS))*pS + max(0ll, (needC-c))*pC) > r;
}

long long bs(){
    long long l = 0, r = (long long)1e14+10;
    long long mid;

    while(l <= r){
        mid = (r-l)/2 + l;
        // cout << mid << endl;

        if(isTooMuch(mid)) r = mid-1;
        else l = mid + 1;
    }

    return r;
}

int main(){

    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'B') tB++;
        if(s[i] == 'S') tS++;
        if(s[i] == 'C') tC++;
    }

    // cout << tB << tS << tC << endl;

    cin >> b >> nS >> c;
    cin >> pB >> pS >> pC;
    cin >> r;

    cout << bs() << endl;




    return 0;
}