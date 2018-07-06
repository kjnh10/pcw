#include <bits/stdc++.h>
using namespace std;
int N;
long long D;
//i回目からdで割り切る事ができる確率
double dp[100][60][38][26];
bool dpb[100][60][38][26];
double rec(int i,int d2,int d3,int d5){
	if(d2+d3+d5==0) return 1.0;
	if(i==N) return 0.0;
	if(dpb[i][d2][d3][d5]) return dp[i][d2][d3][d5];
	double res=0.0;
	//サイコロが1の時
	res += rec(i+1,d2,d3,d5);
	//サイコロが5の時
	if(d5>0){
		res += rec(i+1,d2,d3,d5-1);
	}else{
		res += rec(i+1,d2,d3,d5);
	}
	//サイコロが6の時2の時3の時
	if(d2>0 || d3>0){
		if(d3>0 && d2>0){
			res += rec(i+1,d2-1,d3-1,d5);//6
			res += rec(i+1,d2-1,d3,d5);//2
			res += rec(i+1,d2,d3-1,d5);//3
		}else if(d2==0){
			res += 2*rec(i+1,d2,d3-1,d5);//6,3
			res += rec(i+1,d2,d3,d5);//2
		}else if(d3==0){
			res += 2*rec(i+1,d2-1,d3,d5);//6,2
			res += rec(i+1,d2,d3,d5);//3
		}
	}else{
		res += 3*rec(i+1,d2,d3,d5);//6,2,3
	}
	//サイコロが4の時
	if(d2>0){
		if(d2>1){
			res += rec(i+1,d2-2,d3,d5);
		}else{
			res += rec(i+1,d2-1,d3,d5);
		}
	}else{
		res += rec(i+1,d2,d3,d5);
	}
	//cout <<" i:"<< i  << " d2:" << d2 << " d3:" << d3 << " d5:"<< d5 <<" res:"<< res << endl;
	dp[i][d2][d3][d5] = res/6;
	dpb[i][d2][d3][d5] =true;
	return res/6;
}
int main(){

	cin >> N >> D ;
	int d2=0,d3=0,d5=0;
	while(D%5==0){
		D/=5; d5++;
	}
	while(D%3==0){
		D/=3; d3++;
	}
	while(D%2==0){
		D/=2; d2++;
	}
	if(D!=1){
		cout << "0.0\n" << endl;
		return 0;
	}
	cout<<fixed<<setprecision(6)<<rec(0,d2,d3,d5)<<endl;
	int a;
	cin >> a;
	return 0;
}