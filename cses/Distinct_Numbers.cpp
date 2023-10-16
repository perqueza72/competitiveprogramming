#include <bits/stdc++.h>

using namespace std;

int main(){
    set<int> s;
    int n, aux;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> aux;
        s.insert(aux);
    }
    cout << s.size() << endl;

    return 0;
}