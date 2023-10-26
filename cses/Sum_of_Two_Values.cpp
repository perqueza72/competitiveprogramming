#include <bits/stdc++.h>

using namespace std;


int arr[2*(int)1e5+10];
int n;


void get(int x, int y){

    int draw = 0;
    for(int i=0; i<n && draw < 2; i++){
        if(arr[i] == x || arr[i] == y){
            cout << (i+1) << " ";
            draw++;
        }
    }


}

int main(){

    int x, aux;
    map<int, int> s;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> aux;
        if(s.count(aux)) s[aux]++;
        else s.insert({aux, 1});

        arr[i] = aux;
    }

    for(auto v : s){

        if(v.first == (x-v.first)){
            if(v.second > 1){
                get(v.first, v.first);
                return 0;
            }
        }else if(s.find(x-v.first) != s.end()){
            get(v.first, x-v.first);
            // cout << v.first << " " << (x-v.first) << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}