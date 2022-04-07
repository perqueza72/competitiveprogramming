#include <bits/stdc++.h>


using namespace std;

string board, win;


bool is_win(string s){
  bool filas = false, columns = false;
  for(int i=0; i<3; i++){
    if(s[0+i*3] != '.' && s[0+i*3] == s[1+i*3] && s[1+i*3] == s[2+i*3]) filas = true;
    if(s[0+i] != '.' && s[0+i] == s[3+i] && s[3+i] == s[6+i]) columns = true;
  }

  bool diagonal = ((s[0] != '.' && s[4] == s[0] && s[4] == s[8]) || (s[2] != '.' && s[2] == s[4] && s[4] == s[6]));

  return filas || diagonal || columns;
}

void BFS(queue<pair<string, bool> > q){
  string sActual;
  bool turno;
  while(q.size()){
    sActual = q.front().first;
    turno = q.front().second;
    q.pop();
    if(sActual == board){
      win = "yes\n";
      return;
    }
    if(is_win(sActual)){

      continue;
    }

    for(int i=0; i<9; i++){
      if(sActual[i] == '.'){
        sActual[i] = turno ? 'X' : 'O';
        if(board[i] == sActual[i]) q.push(make_pair(sActual, turno ^ 1));
        sActual[i] = '.';
      }
    }
    //cout << "holi" << endl;
  }
}

int main(){

  int t;
  cin >> t;
  string sAux;
  queue<pair<string, bool>> q;
  
  
  for(int cases=0; cases<t; cases++){
    board = "";
    win ="no\n";
    for(int i=0; i<3; i++){
      cin >> sAux;
      board+= sAux;
    }

    //X = 1; O = 0;
    q.push(make_pair(".........",1));
    BFS(q);
    cout << win;
    
    q.pop();
  }

  return 0;
}
