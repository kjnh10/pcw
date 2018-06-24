#include<cstdio>
using namespace std;

int n, i, left, size;
char a[1010];

int main()
{
    scanf("%d", &n);
    scanf("%s", &a);
    i = 0;
    while (i < n)
    {
        if (a[i] == '(') size++;
        else
        {
            if (size == 0) left++;
                    else size--;
        }
        i++;
    }
    for (i = 1; i <= left; i++)
        printf("(");
    printf("%s", a);
    for (i = 1; i <= size; i++)
        printf(")");
    return 0;
} 