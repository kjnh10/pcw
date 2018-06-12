#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL getMaxArea(vector<int> hist, int n)
{
    // Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    stack<int> s;
 
    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar
 
    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        // If this bar is lower than top of stack, then calculate area of rectangle 
        // with stack top as the smallest (or minimum height) bar. 'i' is 
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = (1+hist[tp]) * (1+(s.empty() ? i : i - s.top() - 1));
 
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = (1+hist[tp]) * (1+(s.empty() ? i : i - s.top() - 1));
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}

int main(){
	int h, w;
	cin >> h >> w;
	string str[h];
	for(int i = 0; i < h; i++) cin >> str[i];
	int ok[h][w];
	for(int i = 0; i < h-1; i++){
		for(int j = 0; j < w-1; j++){
			int f = str[i][j] ^ str[i][j+1] ^ str[i+1][j] ^ str[i+1][j+1];
			ok[i][j] = (f == 0);
		}
	}
	LL ans = max(h,w);
	h--; w--;
	int num[h][w];
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(i == 0){
				num[i][j] = 1;
			} else {
				num[i][j] = num[i-1][j] + 1;
			}
			if(!ok[i][j]) num[i][j] = 0;
		}
		vector<int> hist;
		for(int j = 0; j < w; j++){
			hist.push_back(num[i][j]);
		}
		ans = max(ans, getMaxArea(hist, w));

	}
	cout << ans << endl;
}
