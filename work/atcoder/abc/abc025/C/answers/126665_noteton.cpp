#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int b[2][3];
int c[3][2];
int board[3][3];

int point_check(){
  int ans=0;
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      if(board[i][j]==board[i+1][j])ans+=b[i][j];
    }  
  }

   for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      if(board[i][j]==board[i][j+1])ans+=c[i][j];
    }  
   }
   return ans;
}

int t=0;
int play(int x){
 
  //printf("x=%d\n",x);
  //print_board();
  int score;
  if(x==9){
    return point_check();
  }
  else if(x%2==0){
    score=0;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	if(board[i][j]==0){
	  board[i][j]=1;
	  int temp=play(x+1);
	  score=max(score,temp);
	  board[i][j]=0;
	}
      }
    }
    return score;
  }
  
  else {
    score=100000000;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	if(board[i][j]==0){
	  board[i][j]=2;
	  int temp=play(x+1);
	  score=min(score,temp);
	  board[i][j]=0;
	}
      }
    }
    return score;
  }
  //return score;
}

int main(){
  int ans=0;
  int sum=0;
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&b[i][j]);
      sum+=b[i][j];
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      scanf("%d",&c[i][j]);
      sum+=c[i][j];
    }
  }
  ans=play(0);
  printf("%d\n",ans);
  printf("%d\n",sum-play(0));
  return 0;
}
