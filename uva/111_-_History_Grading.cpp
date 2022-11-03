#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#include <vector>
using namespace std;

#define MAXN 22

int Orginal[MAXN], Store[MAXN];
int N, X[MAXN];
vector<int> Rank;

void ReadOrginal()
{
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &Orginal[i]);
}

void LIS()
{
    int maxi;
    Rank.resize(0);
    Rank.push_back(Store[1]);

    for (int i = 2; i <= N; i++)
    {
        if(Rank.back() < Store[i]){
            Rank.push_back(Store[i]);
            continue;
        }
        auto site = lower_bound(Rank.begin(), Rank.end(), Store[i]);
        *site = Store[i];
    }

    cout << Rank.size() << "\n";
}

int main()
{
    int temp, i;
    ReadOrginal();
    while (scanf("%d", &temp) == 1)
    {
        Store[temp] = Orginal[0];
        for (i = 1; i < N; i++)
        {
            scanf("%d", &temp);
            Store[temp] = Orginal[i];
        }
        LIS();
    }
    return 0;
}