#include <bits/stdc++.h>

using namespace std;


int n, k;
int arr[(int)1e5+10];
int bs(int val){

    int l = 0;
    int r = n-1;
    int mid, arrVal;
    while(l <= r){
        mid = (l+r)/2;
        arrVal = arr[mid];

        if(arrVal < val) l = mid+1;
        else if(arrVal >= val) r = mid-1;
    }

    
    // if(arr[r] == val) return r;
    return l;
}

int main(){

    int query;
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<k; i++){
        cin >> query;
        cout << (bs(query)+1) << "\n";
    }
}