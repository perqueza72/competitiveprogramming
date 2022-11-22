#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, d;
    vector<pair<long long, long long> > points;
    pair<long long,long long> p;

    cin >> n >> d;
    vector<long long> sum(n, 0);
    while(n--){
        cin >> p.first >> p.second;
        points.push_back(p);
    }

    sort(points.begin(), points.end());

    long long start = 0;
    long long min_money = points[start].first;

    sum[0] = points[start].second;

    for(int i=1; i<points.size(); i++){

        sum[i] = sum[i-1];
        while( (points[i].first - min_money) >= d && start <= i){
            sum[i]-=points[start].second;
            start++;
            min_money = points[start].first;
        }

        sum[i]+=points[i].second;
    }
    // cout << sum.size() << endl;

    cout << *max_element(sum.begin(), sum.end()) << endl;


    return 0;
}