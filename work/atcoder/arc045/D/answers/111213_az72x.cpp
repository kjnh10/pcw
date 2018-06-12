#include <bits/stdc++.h>

using namespace std;

const int maxRooms = 300000;
const int maxStudents = 100000;
int N, M;
int s[maxStudents], t[maxStudents];
int start[maxRooms], stop[maxRooms];
bool canLeave[maxRooms];
vector< pair<int, int> > canLeaveSection;

void init() {
  cin >> N >> M;

  for(int i = 0; i < M; i++) {
    cin >> s[i] >> t[i];
    s[i] -= 1;
    t[i] -= 1;
    start[s[i]] += 1;
    stop[t[i]] += 1;
  }
}

void solve() {

  int current = 0;

  for(int i = 0; i < N; i++) {
    if(i == 0)
      current += start[i];
    else
      current += start[i] - stop[i - 1];

    if(current >= 2) 
      canLeave[i] = true;
  }

  int sectionStart = -1, sectionEnd = -1;
  
  for(int i = 0; i < N; i++) {
    if(canLeave[i] && sectionStart == -1) {
      sectionStart = i;
    }
    if(canLeave[i] == false && sectionStart != -1) {
      sectionEnd = i - 1;
      pair<int, int> newSection;
      newSection.first = sectionStart;
      newSection.second = sectionEnd;
      canLeaveSection.push_back(newSection);
      sectionStart = sectionEnd = -1;
    }
  }

  if(sectionStart != -1) {
    pair<int, int> newSection;
    newSection.first = sectionStart;
    newSection.second = N - 1;
    canLeaveSection.push_back(newSection);
  }

  int sectionRightmost[maxRooms];

  for(int i = 0; i < maxRooms; i++) {
    sectionRightmost[i] = -1;
  }
  
  for(auto i: canLeaveSection) {
    for(int k = i.first; k <= i.second; k++) {
      sectionRightmost[k] = i.second;
    }
  }

  vector<int> ans;
  
  for(int i = 0; i < M; i++) {
    if(sectionRightmost[s[i]] != -1 && sectionRightmost[s[i]] >= t[i]) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;

  for(int i: ans) {
    cout << i + 1 << endl;
  }
}


  

int main() {
  init();
  solve();

}
