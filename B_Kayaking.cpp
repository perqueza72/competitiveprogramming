#include <bits/stdc++.h>

using namespace std;


int n;

int main(){

    cin >> n;
    n*=2;
    int arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n, greater<int>());


    int mini = 1e8, sum = 0;
    bool sumar = true;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum = 0, sumar = true;

            for(int k=0; k<n; k++){
                if(k != i && k != j){
                    if(sumar) sum += arr[k];
                    else sum -= arr[k];

                    sumar = !sumar;
                }
            }
            mini = min(sum, mini);
        }
    }
    cout << mini;

    return 0;
}