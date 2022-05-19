#include <bits/stdc++.h>
//UNSOLVED


using namespace std;


int OO = -1;
int day[110] = {0};
int calculed[110][4];
int n;

int f(int selected, int i){

  if(i == n) return 0;
  int dia = day[i];
  int &ans = calculed[i][selected];
  if(ans != OO) return ans;

  switch (dia){
    case 0:
      ans = 1 + f(0, i+1);
      break;

    case 1:
      if(selected != 1) ans = min(f(1,i+1), 1 + f(0, i+1));
      else ans = 1 + f(0, i+1);
      break;

    case 2:
      if(selected != 2) ans = min(f(2,i+1), 1 + f(0, i+1));
      else ans = 1 + f(0, i+1);
      break;

    case 3:
      if(selected == 1) ans = min(f(2, i+1), 1+ f(0, i+1));
      else if(selected == 2) ans = min(f(1, i+1), 1 + f(0, i+1));
      else ans = min(f(2, i+1), min(f(1, i+1),1 + f(0, i+1)));
      break;
  }

  return ans;
}


int main(){
  cin >> n;
  memset(calculed, OO, sizeof(calculed));

  for(int i=0; i<n; i++){
    cin >> day[i];
  }

  printf("%d\n", f(0,0));

  return 0;
}