#include <bits/stdc++.h>
using namespace std;



int main(int argc, char **argv){
    int x, y;
    cin >> x >> y;
    for(int i = 0;i < y + 2;i++){
        cout << "#";
    }
    cout << endl;
    for(int i = 0;i < x;i++){
        cout << "#";
        for(int j = 0;j < y;j++){
            char a;
            cin >> a;
            cout << a;
        }
        cout << "#";
        cout << endl;
    }
    for(int i = 0;i < y + 2;i++){
        cout << "#";
    }
}