#include <bits/stdc++.h>

using namespace std;

int main()
{

    map<int, bool> mapa;

    int n, aux, cont = 0;
    cin >> n;
    int hash[(int)1e5+1][2];
    for(int i=0; i<=n; i++){
        hash[i][0] = 0;
        hash[i][1] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (mapa.count(aux))
        {
            if (mapa[aux])
            {
                if (i - hash[aux][0] == hash[aux][1])
                    hash[aux][0] = i;
                else{
                    if(hash[aux][1] != -1) cont++;
                    hash[aux][1] = -1;
                }
            }
            else
            {
                // cout << "hash: " << i << " " << hash[aux][0] << endl;
                hash[aux][1] = i - hash[aux][0];
                hash[aux][0] = i;

                mapa[aux] = true;
            }
        }
        else
        {
            hash[aux][0] = i;
            hash[aux][1] = 0;

            mapa.insert({aux, false});
        }
    }

    cout << (mapa.size()-cont) << "\n";
    for (auto &u : mapa)
    {
        if(hash[u.first][1] == -1) continue;
        cout << u.first << " " << hash[u.first][1] << "\n";
    }

    return 0;
}