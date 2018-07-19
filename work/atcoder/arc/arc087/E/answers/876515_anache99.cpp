#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>
#include <cstring>

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
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 100000;

char s[1 + MAXN];

struct Trie {
    Trie *son[2];

    Trie() {
        son[0] = son[1] = NULL;
    }
};

Trie *root;

void Insert() {
    int n = strlen(s + 1);
    Trie *node = root;
    for (int i = 1; i <= n; i++) {
        if (!node->son[s[i] - '0'])
            node->son[s[i] - '0'] = new Trie();
        node = node->son[s[i] - '0'];
    }
}

long long l, xorSum = 0;

long long SG(long long x) {
    return x & -x;
}

void Solve(Trie *node, int depth) {
    for (int i = 0; i < 2; i++)
        if (!node->son[i])
            xorSum ^= SG(l - depth);
        else
            Solve(node->son[i], depth + 1);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    root = new Trie();
    int n;
    scanf("%d%lld\n", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%s\n", s + 1);
        Insert();
    }
    Solve(root, 0);
    if (xorSum)
        printf("Alice\n");
    else
        printf("Bob\n");
    return 0;
}
