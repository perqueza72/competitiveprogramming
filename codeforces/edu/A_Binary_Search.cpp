#include <bits/stdc++.h>

using namespace std;

int n;
int arr[(int)1e5+10];
bool bs(int value){

    int r = n;
    int l = 0;
    while(l <= r){
        int mid = (r+l)/2;
        int midV = arr[mid];

        if (midV == value) return true;
        if(midV < value) l = mid+1;
        else if(midV > value) r = mid-1;
    }

    return false;
}


int main(){
    int k, query;
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<k; i++){
        cin >> query;
        if(bs(query)) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}