#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 10;

struct Trie{
    int nodes[MAX][26];
    int last = 1;
    vector<int> calls = vector<int>(MAX, 0);

    Trie(){
        memset(nodes, -1, sizeof(nodes));
    }

    void clear(){
        for(int i=0; i<last; i++){
            calls[i] = 0;
            for(int j=0; j<26; j++){
                nodes[i][j] = -1;
            }
        }
        last = 1;
    }

    void add(const string &s){
        int x;
        int now = 0;

        for(auto &c : s){
            x = c - 'a';
            if(nodes[now][x] == -1){
                now = nodes[now][x] = last++;
                calls[now]++;
                continue;
            }

            now = nodes[now][x];
            calls[now]++;
        }
    }

    int minimun(const string &s){
        int now = 0, r;
        for(int i=0; i<s.size(); i++){
            now = nodes[now][s[i]-'a'];
            if(calls[now] == 1){
                r = i;
                break;
            }
        }

        return r+1;
    }
};

int main(){

    int t, n, r;
    vector<string> s;
    Trie *trie = new Trie();
    vector<int> *v;
    cin >> t;
    while(t--){
        r = 0;
        cin >> n;

        s.resize(n);
        for(int i=0; i<n; i++){
            cin >> s[i];
            trie->add(s[i]);
        }

        for(int i=0; i<n; i++){
            r+= trie->minimun(s[i]);
        }

        cout << r << "\n";
        trie->clear();
    }

    return 0;
}