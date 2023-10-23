#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, n;
    string s;
    cin >> t;
    while(t--){

        int arr[256] = {0};
        cin >> n;
        cin >> s;
        for(int i=0; i<n; i+=2){
            if(!arr[s[i]]) arr[s[i]] = 1;
        }

        bool puede = true;
        for(int i=1; i<n; i+=2){
            if(!arr[s[i]]) arr[s[i]] = 2;
            else if(arr[s[i]] == 1) puede = false;
        }

        cout << (puede ? "YES" : "NO") << "\n";
    }

    return 0;
}