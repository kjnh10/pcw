//#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <set>
#include <cassert>

using namespace std;

const int SIZE = 1 << 10;
int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0, sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

const int BASE = 10;

int cost[BASE][BASE];

void RoyFloyd() {
    for (int i = 0; i < BASE; i++)
        for (int j = 0; j < BASE; j++)
            scanf("%d", &cost[i][j]);
    for (int k = 0; k < BASE; k++)
        for (int i = 0; i < BASE; i++)
            for (int j = 0; j < BASE; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    RoyFloyd();
    int answer = 0;
    for (int i = 1; i <= n * m; i++) {
        int x;
        scanf("%d", &x);
        if (x != -1)
            answer += cost[x][1];
    }
    printf("%d\n", answer);
    return 0;
}
