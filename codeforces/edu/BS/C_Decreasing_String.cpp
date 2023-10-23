#include <bits/stdc++.h>

using namespace std;

long long n, val;


long long comb(const long long &x){
    return x*(x+1ll)/2ll;
}

long long comb_n;

bool able(const long long &x){
    return comb_n - comb(x) < val;
}

int bs(long long l, long long r){

    int mid;
    while(l <= r){
        mid = (r-l)/2 + l;

        if(able(mid)) r = mid-1;
        else l = mid+1;
    }

    return r;
}


string s;
string prune(int v){
    vector<int> q(1, s[0]);

    string z = "";
    int pos = 1;
    char first = q.back(), w;
    while(v > 0 && pos < s.size()){
        w = s[pos];

        while(v > 0 && q.size()){

            first = q.back();
            if(first > w) q.pop_back();
            else break;

            v--;
            if(v == 0) break;

            if(q.size()) first = q.back();
            else break;
        }
            
        q.push_back(w);
        pos++;
    }

    for(int i=0; i<q.size(); i++)   z+= q[i];
    for(int i=pos; i<s.size(); i++) z+= s[i];

    return z;
}

int main(){
    int t;

    cin >> t;
    while(t--){

        cin >> s;
        n = s.size();
        
        comb_n = comb(n);

        cin >> val;

        int x = bs(0, n);
        int r = comb_n - comb(x);
        int l = comb_n - comb(x+1);

        int sise = r - l;

        cout << prune(n-sise)[val-l-1];

    }
}