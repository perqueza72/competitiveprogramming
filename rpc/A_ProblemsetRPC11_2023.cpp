#include <bits/stdc++.h>

using namespace std;

bool has7(long long &v){
    string s = to_string(v);
    for(char c: s) if (c == '7') return true;
    return false;
}

bool dis7(long long &v){
    return ((v%7) == 0);
}


int main(){

    long long n;
    cin >> n;
    if (!has7(n) && !dis7(n)) printf("0");
    else if(!has7(n) && dis7(n)) printf("1");
    else if(has7(n) && !dis7(n)) printf("2");
    else if(has7(n) && dis7(n)) printf("3");


    return 0;
}