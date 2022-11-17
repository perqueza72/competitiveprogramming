#include <bits/stdc++.h>

using namespace std;



int n, m;
vector<vector<bool> > grafo, b, c;
bool possible(int i, int j){
    for(int i =0; i<n; i++){
        if(!grafo[i][j]){
            return false;
        }
    }
    for(int j=0; j<m; j++){
        if(!grafo[i][j]){
            return false;
        }
    }

    return true;
}

void draw(int i, int j){
    for(int i =0; i<n; i++){
        b[i][j] = 1;
    }
    for(int j=0; j<m; j++){
        b[i][j] = 1;
    }
}

int main(){

    cin >> n >> m;
    int aux;

    grafo.assign(n, vector<bool>(m));
    b.assign(n, vector<bool>(m));
    c.assign(n, vector<bool>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> aux;
            grafo[i][j] = aux;
        }
    }

    bool puede = false;
    // bool zero = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grafo[i][j]){
                if(possible(i, j)){
                    puede = true;
                    c[i][j] = 1;
                }
                // zero = false;
            }
        }
    }
    // puede |= zero;

    // if(!puede){
    //     cout << "NO" << endl;
    //     return 0;
    // }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(c[i][j]) draw(i,j);
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grafo[i][j] != b[i][j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    

    cout << "YES" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}