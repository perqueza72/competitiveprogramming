#include <bits/stdc++.h>

using namespace std;


int arr[10] = {0};

void descompose(int number){

  if(number == 0 || number == 1) return;
  if(number != 9 && number != 7 && number != 5 && number != 3 && number != 6){
    arr[2]+= log2(number);
  }
  else if(number == 9){
    arr[3]+=2;
  }
  else if(number == 6){
    arr[2]++;
    arr[3]++;
  }
  else  arr[number]++;

  descompose(number-1);
  return;
}

int main(){

  int n;
  char number;
  int iter;
  cin >> n;
  getchar();
  for(int i=0; i<n; i++){
    number = getchar();
    descompose(number-'0');
  }

  for(char i=7; i>=3; i-=2){
      iter = arr[i];
    for(int j=0; j<iter; j++){
      printf("%d", i);
    }
    if(i == 7){
      arr[7]=0;
      arr[5]-=iter;
      arr[3]-=2*iter;
      arr[2]-=4*iter;
    }
    else if(i == 5){
      arr[5]=0;
      arr[3]-=iter;
      arr[2]-=3*iter;
    }
    else if(i == 3){
      arr[3]=0;
      arr[2]-=iter;
    }
  }

  for(char i=0; i<arr[2]; i++){
    printf("%d", 2);
  }

  printf("\n");

  return 0;
}