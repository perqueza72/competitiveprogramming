#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long judge[(int)1e3*2+10], remember[(int)1e3*2+10];
    deque<long long> ans;

    int n, k;
    cin >> k >> n;
    for(int i=0; i<k; i++){
        cin >> judge[i];
    }

    for(int i=0; i<n; i++){
        cin >> remember[i];
    }
    sort(remember, remember+n);
    // n  = unique(remember, remember+n) - remember;

    long long val;
    map<long long, int> s;
    for(int i=0; i<n; ++i){

        val = remember[i];
        for(int j=0; j<k; ++j){

            val -= judge[j];
            
            auto it = s.find(val);
            if(it == s.end()) s.insert({val, i});
            else if(it->second == i) continue;
            else it->second = i;

            ans.push_back(val);
        }
    }

    sort(ans.begin(), ans.end());
    int count = 1, r = 0;
    long long ant = 1e18;
    for(int i=0; i<ans.size(); i++){
        if(ant == ans[i]) count++;
        else{
            if(count == n) ++r; 
            ant = ans[i];
            count = 1;
        }
    }

    // for(auto it=ans.begin(); it != ans.end(); it++){
    //     if(it->second == n) r++; 
    // }

    cout << r << "\n";

    return 0;
}