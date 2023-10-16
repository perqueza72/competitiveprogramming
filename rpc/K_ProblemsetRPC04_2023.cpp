#include <bits/stdc++.h>

using namespace std;

int a, b, c;
string w, s;
vector<vector<int> > v(26, vector<int>(0));

int valueIterations(const int &val){

    int num_w = v[val].size();
    int r = 2*c + b*num_w;
    if (num_w == 0) return 0;
    if (num_w == 1) return r;

    int wi = v[val][0];
    for(int i=1; i<v[val].size(); i++){
        r+=min(a*(v[val][i]-wi-1), 2*c);
        wi = v[val][i];
    }

    return r;
}

int main(){

    cin >> a >> b >> c;
    cin >> w;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        v[s[i]-'a'].push_back(i);
    }

    for(int i=0; i<w.size(); i++) cout << valueIterations(w[i]-'a') << "\n";

    return 0;
}