#include <bits/stdc++.h>

using namespace std;

void print(vector<long long> &v){
    for(auto u : v){
        cout << u << " ";
    }
    cout << "\n";
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<long long> hub(n), sumH(n + 1), cream(m);

    for (int i = 0; i < n; i++)
        cin >> hub[i];
    sumH[0] = 0;
    for (int i = 0; i < n; i++)
        sumH[i + 1] = hub[i] + sumH[i];
    for (int i = 0; i < m; i++)
        cin >> cream[i];

    sort(cream.begin(), cream.end());

    long long dist, l, r, possible_max, maxi = 0, max_pos = sumH.size();
    for (int i = 0; i < m - 1; i++)
    {
        dist = (cream[i + 1] - cream[i]) / 2;
        l = (cream[i] + 99) / 100; // Previous position.
        if(l == cream[i]/100) l=min(l+1ll, max_pos-1);
        possible_max = 0;
        while (0 <= l < max_pos && 100 * l <= cream[i + 1])
        {
            r = (l+1); // Current position.
            r += dist / 100ll; // Add to current position all hubs in range.

            if (r >= max_pos) r = max_pos-1; //If exceed limit.
            if ((r-1ll)*100ll >= cream[i+1]) //r-1 to determinate hub position due to r is in sumH terms.
                break;
            
            possible_max = sumH[r] - sumH[l];
            maxi = max(maxi, possible_max);
            if(r == max_pos-1) break;

            l++;
        }
    }
    
    l = max(0ll, min((cream[0]+99)/100, max_pos-1ll));
    if(l == cream[0]/100) l=max(0ll,l-1ll);
    maxi = max(maxi, sumH[l]- sumH[0]);

    r = min((cream[m-1]+99)/100, max_pos-1ll);
    if(r == cream[m-1]/100) r=min(max_pos-1ll, r+1ll);
    maxi = max(maxi, sumH[max_pos - 1ll] - sumH[r]);

    cout << maxi << endl;

    return 0;
}