#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <iomanip>
#include <queue>
#include <deque>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <map>
#include <utility>
using namespace std;

#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",&n)
#define MOD 1000000007
#define ll long long int
#define vi vector<int>
#define vii vector< vector<int> >
#define PI 3.1415926535897932384626433832795

int main() {
	ll k;
	cin >> k;
	cout << "50\n";
	if(k%50 != 0) {
		vector<ll> nums (50,k/50+50);
		for(int i = 0; i < 50-k%50; i++) {
			int maxat = 0;
			for(int j = 0; j < 50; j++) {
				if(nums[j] > nums[maxat]) {
					maxat = j;
				}
			}
			for(int j = 0; j < 50; j++) {
				if(j == maxat) {
					nums[j]-= 50;
				} else {
					nums[j]++;
				}
			}
		}
		for(int j = 0; j < 50; j++) {
			cout << nums[j] << " ";
		}
	} else {
		vector<ll> nums (50,k/50+49);
		for(int j = 0; j < 50; j++) {
			cout << nums[j] << " ";
		}
	}
	return 0;
}

