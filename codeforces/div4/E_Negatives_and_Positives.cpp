#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t, sum, mini, neg;
    vector<long long> a;
    cin >> t;
    while(t--){
        cin >> n;
        neg = 0;
        sum = 0;
        mini = 0;
        a.resize(n);
        for(int i=0;  i<n; i++){
            cin >> a[i];
            if(a[i] < 0) neg++;
            a[i] = abs(a[i]);
        }


        for(int i=0; i<n; i++) sum+= a[i];
        if(neg&1){
            mini = *min_element(a.begin(), a.end());
            sum-=2*mini;
        }
        cout << sum << "\n";
    }


    return 0;
}