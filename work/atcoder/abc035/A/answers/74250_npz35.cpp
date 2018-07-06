#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <random>
#include <algorithm>

typedef long long int ll;
#define rep(i,n) for(int i=0;i<(n);i++)
 
using namespace std;

int main(){
    double w, h;
    cin >> w >> h;

    if(w*w + h*h == (h*5/3)*(h*5/3))    cout << "4:3" << endl;
    else                                cout << "16:9" << endl;

    return 0;
}
