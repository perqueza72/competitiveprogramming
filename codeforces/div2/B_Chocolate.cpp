#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    bool first = false, aux;
    vector<long long> nut;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> aux;
        if(first){

            if(aux)
                nut.push_back(1);
            else (nut.back())++;
        }
        else{
            if(aux){
                first = true;
                nut.push_back(1);
            }
        }
    }

    if(nut.empty()){
        cout << 0 << endl;
        return 0;
    } 
    nut.pop_back();

    long long mult = 1;
    for(auto &v : nut){
        mult*= v;
    }

    cout << mult << endl;

    return 0;
}