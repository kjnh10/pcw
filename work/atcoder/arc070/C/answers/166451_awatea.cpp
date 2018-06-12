#include <cstdio>

using namespace std;

int main() {
    int x, sum = 0, i;
    
    scanf("%d", &x);
    
    for (i = 1; ; i++) {
        sum += i;
        
        if (sum >= x) break;
    }
    
    printf("%d\n", i);
    
    return 0;
}
