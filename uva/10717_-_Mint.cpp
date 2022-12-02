#include <bits/stdc++.h>

using namespace std;

vector<int> mcm;

int __mcm(const int a,const int b){
    return (a*b)/__gcd(a,b);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, t, ant;

    vector<int> coin(50);
    while(cin >> n >> t, n+t){
        for(int i=0; i<n; i++){
            cin >> coin[i];
        }

        int firstMcm, secondMcm;

        mcm = vector<int>();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                firstMcm = __mcm(coin[i], coin[j]);
                for(int k=j+1; k<n; k++){
                    for(int l=k+1; l<n; l++){
                        secondMcm = __mcm(coin[k], coin[l]);
                        mcm.push_back(__mcm(firstMcm, secondMcm));
                    }
                }
            }
        }

        int x, l, r, mini = 1e9, maxi = 1e9;
        for(int i=0; i<t; i++){
            cin >> x;
            mini = 1e9, maxi = 1e9;

            for(auto &v : mcm){
                l = (x/v)*v;
                r = l;
                if(r < x) r+=v;

                mini = min(abs(x-l), mini);
                maxi = min(abs(x-r), maxi);
            }

            cout << (x-mini) << " " << (x+maxi) << "\n";
        }
    }

    return 0;
}