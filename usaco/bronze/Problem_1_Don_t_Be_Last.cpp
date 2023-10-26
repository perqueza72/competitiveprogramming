#include <bits/stdc++.h>

using namespace std;


map<string, int> m;

void fill(){
    string arr[] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    for(int i=0; i<7; i++){
        m.insert({arr[i], 0});
    }
}

int main(){

    ifstream cin("notlast.in");
    ofstream cout("notlast.out");

    int n;
    string s;
    int val;
    cin >> n;

    fill();
    for(int i=0; i<n; i++){
        cin >> s >> val;
        if(n == 1){
            cout << s << endl;
            return 0;
        }

        m[s]+=val;
    }

    int mini = 1e5;
    string name = "";
    for(auto aux = m.begin(); aux != m.end(); aux++){
        if(aux->second == 0 ) continue;
        if(mini > aux->second){
            mini = aux->second;

        }
    }

    int secondMini = 1e5;
    for(auto it2=m.begin(); it2 != m.end(); it2++){
        if(mini < it2->second && secondMini > it2->second){
            secondMini = it2->second;
            name = it2->first;
        }
    }

    // cout << secondMini << mini << endl;

    if(name != ""){
        cout << name << endl;
        return 0;
    }


    cout << "Tie\n";
    // auto it2 = ++(m.begin());

    // cout << it->first << " " << it2->first << endl;
    // if(it->second == it2->second){
    //     cout << "Tie\n";
    // }
    // else cout << it2->first << "\n";



    return 0;
}