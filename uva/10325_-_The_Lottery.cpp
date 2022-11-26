#include <bits/stdc++.h>

using namespace std;

vector<long long> number(15);
long long n;
int m;

long long inc_exe(int idx = 0, long long d = 1){
    if(idx == m){
        if(d == 1) return 0;
        return n/d;
    }   

    return inc_exe(idx+1, d) - inc_exe(idx+1, d*number[idx]/__gcd(d, number[idx]));
}

long long f(int i, int size, long long num){
    if(num > n) return 0;
    if(size == 0) return n/num;

    long long ans = 0;
    for(int j = i + 1; j < m; j++){
        ans += f(j, size - 1, (num*number[j])/__gcd(num, number[j]));
    }

    return ans;
}

long long g(){
    long long ans = 0;

    for(int i = 1; i <= m; i++){
        if(i & 1) ans += f(-1, i, 1);
        else ans -= f(-1, i, 1);
    }

    return ans;
}

int main(){

    vector<long long> aux(15);
    int mAux;
    bool puede;
    while(cin >> n >> m){
        for(int i=0; i<m; i++){
            cin >> aux[i];
        }
        sort(aux.begin(), aux.begin()+m);

        mAux = 1;
        number[0] = aux[0];
        for(int i=1; i<m; i++){
            puede = true;
            for(int j=0; j<mAux; j++){
                if((aux[i]%number[j]) == 0){
                    puede = false;
                    break;
                }
            }

            if(puede) number[mAux] = aux[i];
            mAux+= puede;
        }


        swap(mAux, m);
        cout << (n+inc_exe()) << "\n";
    }
    
    return 0;
}