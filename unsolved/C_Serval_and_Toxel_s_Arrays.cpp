#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, n, m, v, pos, remove_value, diff, sum;
    vector<int> counting = vector<int>(0);
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        sum = diff = 0;

        counting.assign(n+m+1, 0);
        vector<int> a = vector<int>(0);

        for(int i=0; i<n; i++){
            cin >> v;
            counting[v]+=2;
            a.push_back(v);
        }

        for(auto d : counting){
            if(d >= 1) diff++;
        }



        for(int i=0; i<m; i++){
            cin >> pos >> v;

            remove_value = a[pos-1];
            counting[remove_value]--;
            counting[v]++;
            if(remove_value == v) continue;
            if(counting[v] >= 1 || counting[remove_value] >= 1) 
                diff++; 

            sum+= diff;
        }

        cout << sum << "\n";
    }
    

    return 0;
}