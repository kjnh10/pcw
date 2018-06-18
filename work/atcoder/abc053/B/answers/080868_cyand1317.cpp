#include <cstdio>

int occ_a = -1, occ_z = -1;

int main()
{
    char ch;
    for (int i = 0; (ch = getchar()) >= 'A' && ch <= 'Z'; ++i) {
        if (ch == 'A' && occ_a == -1) occ_a = i;
        else if (ch == 'Z') occ_z = i;
    }
    printf("%d\n", occ_z - occ_a + 1);
    return 0;
}
