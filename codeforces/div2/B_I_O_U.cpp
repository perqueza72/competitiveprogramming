#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, a ,b ,d;
    cin >> m >> n;
    vector<int> friends(m, 0);
    for(int i=0; i<n; i++){
        cin >> a >> b >> d;
        friends[a-1]-=d;
        friends[b-1]+=d;
    }

    int sum = 0;
    for(auto &frien : friends){
        if(frien < 0)
            sum+= frien;
    }

    cout << abs(sum) << endl;

    return 0;
}