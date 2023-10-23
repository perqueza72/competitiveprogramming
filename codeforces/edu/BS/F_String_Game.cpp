#include <bits/stdc++.h>

using namespace std;

int del[(int)2e5+10];


string p, t;
bool fit(const int &x, string p){

    for(int i=0; i<x; i++) p[del[i]] = '$';
    // cout << p << endl;
    
    int pos = 0;
    for(int i=0; i<p.size() && pos < t.size(); i++){
        if(p[i] == t[pos]) pos++;
    }

    // cout << x << ": " << (pos >= t.size()) << " " << pos << endl;

    return pos >= t.size();
}


int bs(){
    int l = 1, r = p.size();
    int mid;
    while(l <= r){
        mid = (r-l)/2 +l;
        if(!fit(mid, p)) r = mid-1;
        else l = mid+1;
    }

    return r;
}

int main(){

    cin >> p >> t;
    
    int aux;
    for(int i=0; i<p.size(); i++){
        cin >> aux;
        del[i] = aux -1;
    }

    cout << bs() << endl;

    return 0;
}