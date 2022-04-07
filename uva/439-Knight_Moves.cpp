#include <bits/stdc++.h>

using namespace std;

const int INF = 100;

bool is_possible(pair<int,int> &pos, vector<vector<int> > &board){
  if(pos.first >= 0 && pos.first <8 && pos.second >=0 && pos.second < 8 && board[pos.first][pos.second] == INF) return true;
  return false;
}

void knigth_move(pair<int,int> &pos, queue<pair<int,int> > &q, vector<vector<int> > &board){
  pair<int,int> newPos;
  newPos = make_pair(pos.first+2, pos.second+1);
  if(is_possible(newPos, board)){
    q.push(newPos);
    board[newPos.first][newPos.second] = board[pos.first][pos.second]+1;
  }
  newPos = make_pair(pos.first+2, pos.second-1);
  if(is_possible(newPos, board)){
    q.push(newPos);
    board[newPos.first][newPos.second] = board[pos.first][pos.second]+1;
  }
  newPos = make_pair(pos.first-2, pos.second+1);
  if(is_possible(newPos, board)){
    q.push(newPos);
    board[newPos.first][newPos.second] = board[pos.first][pos.second]+1;
  }
  newPos = make_pair(pos.first-2, pos.second-1);
  if(is_possible(newPos, board)){
    q.push(newPos);
    board[newPos.first][newPos.second] = board[pos.first][pos.second]+1;
  }
  newPos = make_pair(pos.first+1, pos.second+2);
  if(is_possible(newPos, board)){
    q.push(newPos);
    board[newPos.first][newPos.second] = board[pos.first][pos.second]+1;
  }
  newPos = make_pair(pos.first+1, pos.second-2);
  if(is_possible(newPos, board)){
    q.push(newPos);
    board[newPos.first][newPos.second] = board[pos.first][pos.second]+1;
  }
  newPos = make_pair(pos.first-1, pos.second+2);
  if(is_possible(newPos, board)){
    q.push(newPos);
    board[newPos.first][newPos.second] = board[pos.first][pos.second]+1;
  }
  newPos = make_pair(pos.first-1, pos.second-2);
  if(is_possible(newPos, board)){
    q.push(newPos);
    board[newPos.first][newPos.second] = board[pos.first][pos.second]+1;
  }
}

int BFS(pair<int,int> &ini, pair<int,int> &fin, vector<vector<int> > board){
  queue<pair<int, int> > q;
  pair<int, int> pos;
  q.push(ini);
  board[ini.first][ini.second] = 0;
  while(q.size()){
    pos = q.front();
    q.pop();
    if(pos == fin) break;
    
    knigth_move(pos, q, board);
  }

  return board[fin.first][fin.second];

}

int main(){

  string origin, end;
  pair<int,int> ini, fin;
  vector<vector<int> > board(8);
  vector<int> aux;
  aux.assign(8, INF);

  for(int i=0; i<8; i++){
    board[i] = aux;
    // for(int j=0; j<8; j++){
      // cout << board[i][j];
    // }
    // cout << endl;
  }

  while(cin >> origin >> end){
    ini = make_pair(((int)origin[0]-97), (origin[1]-'0'-1));
    fin = make_pair(((int)end[0]-97), (end[1]-'0'-1));
    // cout << ini.first << " " << ini.second  << endl << fin.first << " " << fin.second << endl;
    cout << "To get from " << origin << " to " << end << " takes " << (BFS(ini, fin, board)) << " knight moves.\n";
  }

  return 0;
}