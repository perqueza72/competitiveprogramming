#include <iostream>

using namespace std;

int main(){

  // freopen("circlecross.in", "r", stdin);
  // freopen("circlecross.out", "w", stdout);

  string s;
  int cont=0;
  char first[256]{}, second[256]{};
  cin >> s;
  for(int i=0; i<s.length(); i++){
    if(first[s[i]] == 0) first[s[i]] = i+1;
    else second[s[i]] = i+1;
  }

  for(char i='A'; i<='Z'; i++){
    // printf("%c\n", i);
    for(char j=first[i]; j<second[i]-1; j++){
      if(first[i] < first[s[j]] && first[s[j]] < second[i] && second[i] < second[s[j]]){
      // printf("%c: (%d, %d), %c: (%d, %d)\n", i, first[i], second[i], s[j], first[s[j]], second[s[j]]);
        cont++;
      }
    }
  }

  cout << cont << endl;

  return 0;
}