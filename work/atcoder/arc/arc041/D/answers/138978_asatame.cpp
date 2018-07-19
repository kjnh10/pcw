#include <iostream>
using namespace std;

int m[510][510] = {};
int res[510][510] = {};

int main(void){
    // Here your code !
    int h,w;
    cin >> h >> w;
    
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++){
            char a;
            cin >> a;
            m[i][j] = a-'0';
            //cout << m[i][j] << " ";
        }
    
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++){
            if(m[i][j]){
                //cout << i << " " << j << endl;
                res[i+1][j] = m[i][j];
                
                m[i+2][j] -= m[i][j];
                m[i+1][j+1] -= m[i][j];
                m[i+1][j-1] -= m[i][j];
                m[i][j] -= m[i][j];
            }
        }
    
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++)
            cout << res[i][j];
        cout << endl;
    }
    
    return 0;
}
