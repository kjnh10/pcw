#include <bits/stdc++.h>
#define mod 1000000007;
#define pi 3.14159265358979323846264
using namespace std;
char s[100005];
int main() {
    scanf("%s", s);
    int n = strlen(s), k = n-1;
    while (k>0) {
        if (s[k]=='m'&&s[k-1]=='a'&&s[k-2]=='e'&&s[k-3]=='r'&&s[k-4]=='d') k-=5;
        else if (s[k]=='r'&&s[k-1]=='e'&&s[k-2]=='m'&&s[k-3]=='a'&&s[k-4]=='e'&&s[k-5]=='r'&&s[k-6]=='d') k-=7;
        else if (s[k]=='e'&&s[k-1]=='s'&&s[k-2]=='a'&&s[k-3]=='r'&&s[k-4]=='e') k-=5;
        else if (s[k]=='r'&&s[k-1]=='e'&&s[k-2]=='s'&&s[k-3]=='a'&&s[k-4]=='r'&&s[k-5]=='e') k-=6;
        else break;
    }
    if (k==-1) printf("YES\n");
    else printf("NO\n");
    return 0;
}