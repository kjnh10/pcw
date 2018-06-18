#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int lastdata[] = {31,-1,31,30,31,30,31,31,30,31,30,31};
int feb[] = {28,29};

bool fl(int n){
  if(n%400 == 0){
    return true;
  }else if(n%100 == 0){
    return false;
  }else if(n%4 == 0){
    return true;
  }
  return false;
}

struct date{
  int y;
  int m;
  int d;
};

date next(date d1){
  date r;

  int ld = lastdata[d1.m-1];
  if(ld == -1){
    if(fl(d1.y)){
      ld = feb[1];
    }else{
      ld = feb[0];
    }
  }

  if(d1.d == ld){
    r.d = 1;
    if(d1.m == 12){
      r.m = 1;
      r.y = d1.y+1;
    }else{
      r.m = d1.m+1;
      r.y = d1.y;
    }
    return r;
  }

  r.y = d1.y;
  r.m = d1.m;
  r.d = d1.d+1;
  return r;
}

bool diva(date d){
  int dd = d.m*d.d;
  if(d.y%dd == 0)return true;
  return false;
}


int main(){
  string s;
  cin >> s;

  int a,b,c;
  a = stoi(s.substr(0,4));
  b = stoi(s.substr(5,2));
  c = stoi(s.substr(8,2));

  date d;
  d.y=a;d.m=b;d.d=c;
  while(true){
    if(diva(d)){
      break;
    }
    d = next(d);
  }

  cout << d.y << "/"
       << setfill('0') << setw(2) << d.m << "/"
       << setfill('0') << setw(2) << d.d << endl;

  return 0;
}