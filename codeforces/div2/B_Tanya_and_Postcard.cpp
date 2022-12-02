#include <bits/stdc++.h>

using namespace std;

int main(){

    string a, b;
    int aux, yay = 0, woops = 0;

    int s[256] = {0}, t[256] = {0};
    cin >> a >> b;
    for(auto &c : a) s[c]++;
    for(auto &c : b) t[c]++;
    for(int i=0; i<256; i++){
        aux = min(s[i], t[i]);
        yay+= aux;

        t[i]-=aux;
        s[i]-=aux;
    }

    int diff = 'a'-'A';
    for(int i='A'; i<='Z'; i++){
        aux = min(s[i], t[i+diff]);
        woops+= aux;
        aux = min(s[i+diff], t[i]);
        woops+= aux;

        t[i]-=aux;
    }

    cout << yay << " " <<woops << endl;
    

    return 0;
}