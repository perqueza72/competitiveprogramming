#include <bits/stdc++.h>

using namespace std;


// struct pair<string, string>{
//     string first = "  ";
//     string second = "  ";

//     pair<string, string>(string first, string second){
//         this->first[0] = first[0];
//         this->first[1] = first[1];

//         this->second[0] = second[0];
//         this->second[1] = second[1];
//     }

// };

// bool operator<(const pair<string, string> &a, const pair<string, string> &b){
//     if (a.first < b.first) return true;
//     if (a.second < b.second) return true;
//     return false;
// }

// bool operator==(const pair<string, string> &a, const pair<string, string> &b){
//     return a.first == b.first && a.second == b.second;
// }


map<pair<string, string>, long long> leMape;
long long calc(){

    long long total = 0, sub;
    for(auto &c : leMape){
        pair<string, string> aux = pair<string, string>(c.first.second, c.first.first);


        if(c.first.second == c.first.first){
            // total += (c.second-1)*(c.second)/2;
            c.second = 0;
        }
        else if(leMape.count(aux)){

            // cout << leMape[aux] << " " << c.second << endl;
            sub = leMape[aux] * c.second; 
            total+= sub;

            leMape[aux] = 0;
            c.second = 0;

        }
    }

    return total;
}


int main(){
    ifstream cin("citystate.in");
    ofstream cout("citystate.out");

    int n;
    string s, w;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s >> w;

        pair<string, string> aux = pair<string, string>(s.substr(0,2), w);

        // cout << "first: " << aux.first << " " << aux.second << endl;
        if(leMape.count(aux)){
            leMape[aux]++;
            // cout << leMape[aux] << endl;
        }
        else{
            leMape.insert({aux, 1});
        }
    }

    // for(auto u: leMape){
    //     cout << u.second << " ";
    // }
    // cout << endl;

    cout << calc() << endl;


    return 0;
}