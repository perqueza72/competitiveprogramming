#include <bits/stdc++.h>

using namespace std;

const int NEXT = 2, END = 0, CONT = 1, N_PROBLEMS = 10;

struct Compe{

  int id;
  vector<int> solved;
  vector<int> times;
  int solved_p;
  int penalty;

  void reset(void){
    this->id = 0;
    (this->solved).assign(N_PROBLEMS, 0);
    (this->times).assign(N_PROBLEMS, 0);
    this->solved_p = 0;
    this->penalty = 0;
  }

  void updatePoints(){
    int total = 0;
    for(int i=0; i<N_PROBLEMS; i++){
      if(solved[i]) total+=times[i]; 
    }
    this->penalty+= total;
  }

  void setTimes(int idProblem, int score, char v){
    if(solved[idProblem]) return;
    if(v == 'I'){
      this->times[idProblem]+=20;
    }
    else if(v == 'C'){
      this->times[idProblem]+=score;
      this->solved[idProblem] = true;
      this->solved_p++;

    }    
  }

  void print(void){
    printf("%d %d %d\n", this->id, this->solved_p, this->penalty);
  }
};

bool operator<(const Compe &a, const Compe &b){
  if(a.solved_p > b.solved_p) return true;
  else if(a.solved_p < b.solved_p) return false;

  if(a.penalty < b.penalty) return true;
  else if(a.penalty > b.penalty) return false;

  if(a.id < b.id) return true;
  return false;
}


int problem, tiempo, teamID;
char response;

char getInput(){
  char c;
  string prob, t, team;
  prob = t = team = "";
  while(c = getchar(), c != ' '){
    if(c == EOF) return END;
    if(c == '\n') return NEXT;
    team+= c;
  }
  while(c = getchar(), c != ' ') prob+= c;
  while(c = getchar(), c != ' ') t+= c;
  while(c = getchar(), c != '\n') response= c;  

  teamID = stoi(team);
  problem = stoi(prob);
  tiempo = stoi(t);


  return CONT;
}

vector<Compe> competidores(105, Compe{});
inline void print(void){
  for(int i=0; i<competidores.size(); i++){
    if(competidores[i].id) competidores[i].print();
  }
}

void reset(){
  for(int i=0; i<105; i++){
    competidores[i].reset();
  }
}

void eval(){
  for(int i=0; i<competidores.size(); i++) competidores[i].updatePoints();

  sort(competidores.begin(), competidores.end());
  print();
}

int main(){

  reset();
  int t;
  char in;
  cin >> t;
  getchar();
  getchar();

  while(in = getInput(), in != END){
    if(in == NEXT){

      eval();
      printf("\n");
      reset();
      continue;
    }

    competidores[teamID].id = teamID;
    (competidores[teamID]).setTimes(problem, tiempo, response);
  }

  eval();


  return 0;
}