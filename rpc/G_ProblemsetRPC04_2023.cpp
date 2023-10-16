#include <bits/stdc++.h>

using namespace std;


int n, k;
int arr[100], grave[8] = {0};

int prune(){
    for(int i=1; i<k; i++){

        if(i == k-i){
            grave[i] %= 2;
            continue;
        }

        while(grave[i] > 0 && grave[k-i] > 0){
            grave[i]--;
            grave[k-i]--;
        } 
    }
}

int main(){

    
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];

    int r = 0;
    for(auto &v : arr){
        r+= v/k;
        v%=k;
        grave[v]++;
    }
    
    prune();

    for(int i=k-1; i>=1; --i){
        
        int comp = k-i, changes = 1;
        
        while(grave[i] != 0 && changes > 0){
            changes = 0;
            for(int j=comp; j<=i; j++){
                
                if(j == i){
                    if(grave[j] > 1){
                        changes++;
                        r++;
                        
                        grave[i]-=2;
                        grave[i-comp]++;
                    
                        prune();
                        break;
                    }   
                }
                else if (grave[j] != 0){
                    
                    changes++;
                    r++;

                    grave[i]--;
                    grave[j]--;
                    grave[j-comp]++;
                    
                    prune();
                    break;
                }
            }
        }
    }

    cout << r <<endl;

    return 0;
}