#include <bits/stdc++.h>

using namespace std;

bool is_course(const string &s){
  if(toupper(s[0]) == s[0]) return true;
  return false;
}

bool f(const pair<string,int> &a, pair<string, int> &b){
  if(a.second == b.second) return a.first <= b.first;
  if(a.second >= b.second) return true;
  return false;
}

void sorting(map<string, int> m){
  vector<pair<string, int> >  v;
  for(auto u : m){
    v.push_back(u);
  }

  sort(v.begin(), v.end(), f);
  for(auto u: v) cout << u.first << " " << u.second << "\n";
}

int main(){

  string s, sCourse, actual;
  map<string, int> course;
  map<string, string> student;

  while(getline(cin, s), s != "0"){
    if(s[0] == '1'){
      sorting(course);
      course = map<string, int>();
      student = map<string, string>();
      continue;
    }
    if(is_course(s)){
      course.insert({s,0});
      actual = s;
      continue;
    }

    if(student.count(s)){
      sCourse = student[s];
      if(sCourse != actual && sCourse != "1"){
        course[sCourse]--;
        student[s] = "1";
      }
    }else{
      student.insert({s, actual});
      course[actual]++;
    }


  }

  return 0;
}