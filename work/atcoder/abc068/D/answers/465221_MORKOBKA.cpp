#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <ctime>
#include <random>
#include <queue>
  
using namespace std;
 
const int MAXN = 1e5 + 10;

long long k, a[50], n;

int main(){
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifndef _DEBUG
    /*freopen("trap.in", "r", stdin);
    freopen("trap.out", "w", stdout);*/
#endif
    cin >> k;
    n = 50;
    for (int i = 0; i < n; i++){
        a[i] = n + k / n - i;
    }
    int l = 0;
    for (int j = 0; j < n - (k % n); j++){
        a[0] -= n;
        for (int i = 1; i < n; i++){
            a[i]++;
            swap(a[i], a[i - 1]);
        }
    }
    cout << n << "\n";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    /*while (a[0] > n - 1){
        a[0] -= n;
        for (int i = 1; i < n; i++){
            a[i]++;
            swap(a[i], a[i - 1]);
        }
        l++;
    }
    cout << l;*/
    return 0;
}