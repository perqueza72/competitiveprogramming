#include <bits/stdc++.h>

using namespace std;

bool operator==(const deque<char> &u, const deque<char> &v){
    if(u.size() != v.size()) return false;
    for(int i=0; i<u.size(); i++){
        if(u[i] != v[i]) return false;
    }

    return true;
}

void next(deque<char> &v){

    for(int i=v.size()-1; i>=0; i--){
        if(v[i] == '4'){
            v[i] = '7';
            return;
        }
        if(v[i] == '7'){
            v[i] = '4';
        }
    }

    v.push_front('4');
}

int main(){

    string s;
    deque<char> v, u;
    v.push_back('4');
    cin >> s;
    for(auto &c : s) u.push_back(c);

    int cont = 1;
    while(v != u){
        cont++;
        next(v);
    }

    cout << cont << endl;


    return 0;
}