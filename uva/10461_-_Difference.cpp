#include <bits/stdc++.h>

using namespace std;

int it = 0;
vector<int> times;

int DFS(const int i,const vector<vector<int> > &grafo, vector<int> &seen){
    if(seen[i] == it) return 0;
    seen[i] = it;

    int sum = times[i];
    for(int j=0; j<grafo[i].size(); j++){
        if(seen[grafo[i][j]] != it) sum+= DFS(grafo[i][j], grafo, seen);
    }
    return sum;
}

int main(){

    int n, m, t = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<int> seen(510, -1), seen_lost(510, -1);
    vector<vector<int> > grafo(510), needMe(510);

    vector<int> min_time, lost_time;
    while(cin >> n >> m, n+m){
        // if(t++) cout << "\n";
        t++;

        int max_time = 0;
        times.resize(n+1);
        min_time.assign(n+1, -1);
        lost_time.assign(n+1, -1);
        
        for(int i=1; i<=n; i++){
            cin >> times[i];
            grafo[i] = needMe[i] = vector<int>();
            max_time+= times[i];
        }

        int a,b;
        for(int i=0; i<m; i++){
            cin >> a >> b;
            grafo[b].push_back(a);
            needMe[a].push_back(b);
        }

        int q, node;
        cin >> q;
        cout << "Case #" << t << ":\n";
        for(int i=0; i<q; i++){
            cin >> node;
            if(min_time[node] == -1) min_time[node] = DFS(node, grafo, seen);
            if(lost_time[node] == -1) lost_time[node] = DFS(node, needMe, seen_lost);
            it++;

            // cout << min_time[node] << " " << lost_time[node] << endl;

            cout << (max_time - lost_time[node] -min_time[node] + times[node] ) << "\n";
            // cout << max_time << " " << min_time[node] <<  " "<< lost_time[node] << " " << times[node] << endl;
        }
        cout << "\n";

    }

    return 0;
}