#include <bits/stdc++.h>

using namespace std;

void getInput(string &club1, int &score1, int &score2, string &club2){
  string scoreAux = "";
  club1 = club2 = "";
  char c;
  
  while(c = getchar(), c!= '#') club1+=c;
  while(c = getchar(), c!= '@') scoreAux+=c;
  
  score1 = stoi(scoreAux);
  scoreAux = "";
  while(c = getchar(), c!= '#') scoreAux+=c;
  score2 = stoi(scoreAux);
  while(c = getchar(), c!= '\n' && c!= EOF) club2+=c;

  
}

const int WIN = 3, TIE = 1, LOSE = 0;

struct Team{
  string name;
  int points;
  int wins;
  int goalsDiff;
  int maxGoals;
  int gamePlayed;
  int ties;
  int looses;
  int goalSocore;
  int goalAgain;

  void setGoalDiff(const int &p1, const int &p2){
    this->goalsDiff += p1-p2;
  };

  void setWinAndPoints(const int &p1, const int &p2){
    int &points = this->points, &wins = this->wins;
    if(p1 > p2){
      wins++;
      points+= WIN;
    }
    else if(p1 == p2){
      ties++;
      points+= TIE;
    }
    else{
      looses++;
      points+= LOSE;
    }
  };

  void setMostGoalScore(const int &p1){
    this->maxGoals = max(this->maxGoals, p1);
  };

  void setGamePlayed(){
    this->gamePlayed++;
  };

  void setGoalScored(const int &p1, const int &p2){
    this->goalSocore+= p1;
    this->goalAgain+= p2;
  }

  void setAll(const int &p1, const int &p2){
    setWinAndPoints(p1, p2);
    setGoalDiff(p1, p2);
    setMostGoalScore(p1);
    setGoalScored(p1, p2);
    setGamePlayed();
  };

  void printTeam(int index){
    printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", index+1, (this->name).c_str(), this->points, this->gamePlayed, this->wins, this->ties, this->looses, this->goalsDiff, this->goalSocore, this->goalAgain);
  }

};


bool lex_order(const string &a, const string &b){
  string cA = a, cB = b;
  for(int i=0; i<cA.length(); i++) cA[i] = toupper(cA[i]);
  for(int i=0; i<cB.length(); i++) cB[i] = toupper(cB[i]);

// cout << cA << " " << cB << endl;
  if(cA.compare(cB) > 0) return false;
  else return true;
}

bool operator<(const Team &a, const Team &b){
  
  if(a.points < b.points) return false;
  if(a.points != b.points) return true;

  if(a.wins < b.wins) return false;
  if(a.wins != b.wins) return true;

  if(a.goalsDiff < b.goalsDiff) return false;
  if(a.goalsDiff != b.goalsDiff) return true;

  if(a.goalSocore < b.goalSocore) return false;
  if(a.goalSocore != b.goalSocore) return true;

  if(a.gamePlayed > b.gamePlayed) return false;
  if(a.gamePlayed != b.gamePlayed) return true;

  return lex_order(a.name, b.name);
}

vector<Team> teams;
map<string, int> teamName;

int main(){

  int t, n, m;
  string nameCup, tName;
  string club1, club2;
  int score1, score2;

  cin >> t;
  getchar();
  while(t--){
    teamName.clear();
    teams.clear();

    getline(cin, nameCup);
    cin >> n;
    getchar();
    for(int i=0; i<n; i++){
      getline(cin, tName);
      teamName.insert({tName, i});
      teams.push_back({tName, 0,0,0,0,0,0,0,0,0});
    }

    
    cin >> m;
    getchar();
    for(int i=0; i<m; i++){
      getInput(club1, score1, score2, club2);

      teams[teamName[club1]].setAll(score1, score2);
      teams[teamName[club2]].setAll(score2, score1);
      
    }

    sort(teams.begin(), teams.end());

    cout << nameCup << "\n";
    for(int i=0; i<n; i++){
      teams[i].printTeam(i);
    }
    if(t) cout << "\n";

  }

  return 0;
}