#include <bits/stdc++.h>

using namespace std;



int main(){

  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  int day, production, cont = 0; 
  int arr[101][3];
  memset(arr, 0, sizeof(arr));

  vector<bool> winner(3,1), newWinner(3);
  bool pene;
  string name;
  map<string, int> names;
  names.insert({"Mildred", 0});
  names.insert({"Elsie",1});
  names.insert({"Bessie", 2});
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> day >> name >> production;
    arr[day][names[name]] += production;
  }

  for(int i=1; i<101; i++){
    for(int j=0; j<3; j++) arr[i][j]+=arr[i-1][j];
    if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) newWinner = {1,1,1};
    else if(arr[i][0] == arr[i][1] && arr[i][0] > arr[i][2]) newWinner = {1,1,0};
    else if(arr[i][0] == arr[i][2] && arr[i][0] > arr[i][1]) newWinner = {1,0,1};
    else if(arr[i][1] == arr[i][2] && arr[i][1] > arr[i][0]) newWinner = {0,1,1};
    else if(arr[i][0] > arr[i][1] && arr[i][0] > arr[i][2]) newWinner = {1,0,0};
    else if(arr[i][1] > arr[i][0] && arr[i][1] > arr[i][2]) newWinner = {0,1,0};
    else if(arr[i][2] > arr[i][1] && arr[i][2] > arr[i][0]) newWinner = {0,0,1};

    pene = false;
    for(int i=0; i<3; i++) if(newWinner[i] != winner[i]) pene = true;
    cont+= pene;
    winner = newWinner;
  }

  cout << cont << endl;




  return 0;
}