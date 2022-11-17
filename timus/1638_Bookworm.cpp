#include <bits/stdc++.h>

using namespace std;

int main(){

    int paper,borde,ending, begining;
    int recorrido, comerBorde, comerInterno;
    cin >> paper >> borde >> begining >> ending;

    recorrido = abs(ending-begining)+1;
    comerBorde = min(max(1, recorrido), 2)*borde;
    comerInterno = max(0, (recorrido-2))*(paper+2*borde);
    if(ending < begining)
        comerInterno+= min(max(1, recorrido), 2)*paper;

    cout << (comerBorde+comerInterno) << endl;

    return 0;
}