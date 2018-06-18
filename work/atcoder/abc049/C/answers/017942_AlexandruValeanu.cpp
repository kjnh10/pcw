#include <bits/stdc++.h>

using namespace std;

const vector<string> strings = {"dream", "dreamer", "erase", "eraser"};

bool checkEqual(const string &text, int p, const string &pattern){
    int i = 0;
    
    while (i < pattern.size()){
        if (text[p + i] != pattern[i])
            return false;
            
        i++;
    }
    
    return true;
}

int main()
{   
    ios_base::sync_with_stdio(false);
    
    string text;
    cin >> text;
    
    const int N = text.size();
    
    text = " " + text;
    
    vector<bool> dp(N + 1, false);
    dp[0] = true;
    
    for (int i = 0; i <= N; i++)
        if (dp[i]){
            for (auto &s: strings)
                if (i + s.size() <= N)
                    dp[i + s.size()] = dp[i + s.size()] || checkEqual(text, i + 1, s);
        }
        
    if (dp[N])
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}