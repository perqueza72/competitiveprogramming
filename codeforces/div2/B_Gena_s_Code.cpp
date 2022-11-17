#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, uno;
    long long multi = 1, a;
    string s, tail = "1";
    deque<char> r;
    char c;
    bool beaty;
    cin >> n;
    while(n--){
        cin >> s;
        if(s == "0"){
            cout << "0\n";
            return 0;
        }
        uno = -1;
        beaty = true;
        for(int i=0; i<s.size(); i++){
            c = s[i];
            if(c == '1' && uno == -1){
                uno = i;
            }
            else if(c == '0') continue;
            else{
                beaty = false;
                break;
            }
        }

        if(uno > 1 || !beaty){
            tail = s;
            continue;
        }
        for(int i=0; i<s.size()-uno-1; i++)
            r.push_back('0');
    }

    cout << tail;
    for(auto &c : r){
        cout << c;
    }
    cout << endl;

    return 0;
}