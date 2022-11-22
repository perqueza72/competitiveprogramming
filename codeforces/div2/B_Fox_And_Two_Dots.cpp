#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

vector<vector<int> > seen;
vector<string> grafo;
bool DFS(int i, int j, const int pi, const int pj){
    if(seen[i][j] != -1) return false;
    if(grafo[i][j] != grafo[pi][pj]) return false;

    int actual = seen[i][j] = grafo[i][j] - 'A';

    bool r = false;
    for(int k = 0; k<4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
            if(0 > x || x >= n || 0 > y || y >= m) continue;
            int vecino = seen[x][y];
            if( ((pi != x) || (pj != y)) &&  vecino == actual){
                return true;
            }
            if(seen[x][y] == -1){
                r|= DFS(x, y, i, j);
            }
    }

    return r;
}

int main(){
 
    cin >> n >> m;
    grafo.resize(n);
    seen.assign(n, vector<int>(m, -1));
    for(int i=0; i<n; i++){
        cin >> grafo[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(seen[i][j] == -1 && DFS(i, j, i, j)){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";

    return 0;
}