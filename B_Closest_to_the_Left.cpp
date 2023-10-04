#include <bits/stdc++.h>

using namespace std;

int n;
int arr[(int)1e5 + 10];
int bs(int value){

    int l = 0, r = n;
    int mid, midV;
    while(l <= r){
        mid = (l+r)/2;
        midV = arr[mid];
        if (mid == l) break;

        if(midV == value) break;
        if (midV < value) l = mid;
        else if (midV > value) r = mid-1;
    }

    if(midV > value) return 0;
    while(value >= midV && mid < n){
        mid++;
        midV = arr[mid];
    }
    return mid;
}


int main(){

    int k, query;
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int j=0; j<k; j++){
        cin >> query;
        cout << bs(query) << "\n";
    }

    return 0;
}