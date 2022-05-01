#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	
	int t, n, op, last;
	vector<char> s;
	cin >> t;
	while(t--){
	cin >> n;
	getchar();
	
	s.resize(n);
	for(int i=0; i<n; i++){
	    s[i] = getchar();
	}
	getchar();
	op= 0;
	last = 0;
    	for(int i=0; i<n-1; i++){
    	    if(s[i] == '(' && s[i+1] == ')' || s[i] == '(' && s[i+1] == '('){
    	        op++;
    	        i++;
    	        last=i+1;
    	    }else if(s[i] == ')'){
    	            i++;
    	            while(i<n && s[i] != ')'){
    	                i++;
    	            }
    	            if(i != n){
    	                op++;
    	                last = i+1;
    	            }
    	        }
    	}
    	cout << op << " " << (n-last) << "\n";
    }
	return 0;
}