#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int *r, *l;
    vector<pair<int, int> > ans;
    for(int i=0; i<k; i++){
        l = min_element(arr, arr+n);
        r = max_element(arr, arr+n);


        if(*l == *r) break;
        (*r)--;
        (*l)++;

        ans.push_back({r-arr+1, l-arr+1});
    }

    cout << (*max_element(arr, arr+n)- *min_element(arr, arr+n)) << " "  << ans.size() << "\n";
    for(auto &v : ans) cout << v.first << " " <<v.second << "\n";



    return 0;
}
