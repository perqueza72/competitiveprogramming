#include <bits/stdc++.h>

using namespace std;

int n;
int arr[(int)1e5+10];

int bsL(int val){

    int l = 0, r = n-1;
    int mid, arrVal;
    while(l <= r){
        mid = (l+r)/2;
        arrVal = arr[mid];

        if (arrVal <= val) l = mid+1;
        else if (arrVal > val) r = mid-1;
    }

    return r;
}

int bsR(int val){

    int l = 0, r = n-1;
    int mid, arrVal;
    while(l <= r){
        mid = (l+r)/2;
        arrVal = arr[mid];

        if (arrVal < val) l = mid+1;
        else if (arrVal >= val) r = mid-1;
    }

    return l;
}

int main(){
    int k, l, r;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    cin >> k;
    for(int i=0; i<k; i++){
        cin >> l >> r;
        // int val = bs(r)-bs(l);

        // cout << bsL(l) << " " << bsR(r) << endl;
        cout << (1 + bsL(r)-bsR(l)) << " ";
        // else cout << (val+1);

        // cout << " ";
    }


}