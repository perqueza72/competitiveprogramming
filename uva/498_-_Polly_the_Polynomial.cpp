#include <bits/stdc++.h>

using namespace std;

vector<int> get_numbers(const string &s){
    vector<int> numbers;
    string numb = "";
    for(auto c : s){
        if(c == ' ' || c == '\n'){
            if(numb == "") continue;

            numbers.push_back(stoi(numb));
            numb = "";
            continue;
        }

        numb.push_back(c);
    }
    if(numb != "") numbers.push_back(stoi(numb));

    // for(auto n : numbers) cout << n << " ";
    // cout << endl;

    return numbers;
}

int main(){

    string s, w;
    while(getline(cin, s)){
        getline(cin, w);
        auto coeficient = get_numbers(s);
        auto polly = get_numbers(w);

        for(int i=0; i<polly.size(); i++){
            auto x = polly[i];

            int r = coeficient[0];
            for(int j=1; j<coeficient.size(); j++){
                r = coeficient[j] + x*(r);
            }
            
            if(i) cout << " ";
            cout << r;
        }
        cout << "\n";

    }

    return 0;
}