#include <bits/stdc++.h>

using namespace std;


long long n, k;
long long arr[(int)1e5+10];

bool fulfill(const long long x){

    bool puede = true;
    long long sum = 0;
    int slices = 1;
    for(int i=0; i<n; i++){
        if(sum+arr[i] > x){
            slices++;
            sum = 0;
        }

        sum+=arr[i];
    }

    return slices <= k;
}


long long bs(){
    long long l = (*max_element(arr, arr+n)), r = (long long)1e15+10, mid;

    while(l <= r){
        mid = (r+l)/2;

        if(fulfill(mid)) r = mid-1;
        else l = mid +1;
    }

    return l;

}

int main(){

    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << bs() << endl;

    return 0;
}