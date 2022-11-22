#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, a;
    cin >> n;
    deque<int> start(n+1), finish(n+1);
    vector<bool> used(n+1, false);
    for(int i=0; i<n; i++){
        cin >> start[i];
    }
    for(int i=0; i<n; i++) cin >> finish[i];

    int changes = 0;
    for(int i=0, j = 0; i<n && j<n;){
        if(used[start[i]]){
            i++;
            continue;
        }

        if(start[i] != finish[j]){
            changes++;
            used[finish[j]] = true;
            j++;
        }else{
            i++, j++;
        }
    }

    cout << changes << endl;


    return 0;
}