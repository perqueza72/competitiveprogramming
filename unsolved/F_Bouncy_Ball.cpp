#include <bits/stdc++.h>

using namespace std;


int i, j, n, m;


struct Ball{
    int i;
    int j;
    pair<int, int> dir;

    Ball(int i, int j, pair<int,int> dir){
        this->i = i;
        this->j = j;
        this->dir = dir;
    }

    void print(){
        cout << this->i <<  " " << this->j << "\n\tdirection: ";
        cout << this->dir.first << "," << this->dir.second << endl;
    }
};

bool operator<(const Ball &a, const Ball &b){
    if(a.i > b.i) return true;
    if(a.j > b.j) return true;
    if(a.dir.first > b.dir.second) return true;
    if(a.dir.second > b.dir.second) return true;
    return false;
}

set<Ball> path;

Ball rebote(const Ball &ball){

    Ball new_ball = Ball(ball.i, ball.j, ball.dir);
    auto dir = ball.dir;


    int cn, cm;
    if(dir.first == 1) cn = n;
    else cn = 0;

    if(dir.second == 1) cm = m;
    else cm = 0;

    int d = min(abs(cn-ball.i), abs(cm-ball.j));
    new_ball.i +=d;
    new_ball.j +=d;

    new_ball.print();

    path.insert(new_ball);

    if(i == cn){
        new_ball.dir.first*=-1;
    }
    if(j == cm){
        new_ball.dir.second*=-1;
    }

    return new_ball;

}

bool is_possible(const Ball &ball, const pair<int,int> &dest){
    pair<int,int> pos = {ball.i, ball.j};
    int a = dest.first - pos.first;
    int b = dest.second - pos.second;
    if (a*ball.dir.first == b*ball.dir.second) return true;
    return false;

}

pair<int, int> convert_pos(const string &s){
    pair<int, int> r = {1,1};
    if(s[0] == 'D') r.first*-1;
    if(s[1] == 'L') r.second*-1;

    return r;
}

int main(){

    int t, cont = 0;
    pair<int, int> dest, orientation;
    int i, j;
    string d;
    cin >> t;
    while(t--){
        cin >> n >> m >> i >> j >> dest.first >> dest.second >> d;

        orientation = convert_pos(d);
        path = set<Ball>();
        cont = 0;

        Ball ball = Ball(i, j, orientation);
        ball.print();

        while(!path.count(ball) && cont < 10){
            if(is_possible(ball, dest)){
                cout << cont << "\n";
                break;
            }
            cont++;
            ball = rebote(ball);
        }
            cout << "test " << t << endl;
    }

    return 0;
}