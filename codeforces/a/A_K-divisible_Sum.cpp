#include <bits/stdc++.h>

using namespace std;

int main(){

	long long t, n, k, aux1, aux2, v, r;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n >> k;

		v = (n+k-1)/k;
		k*= v;
		aux1 = (n+k-1)/n;

		cout << aux1 << "\n";
	}

	return 0;
}