#include <stdio.h>

int main()
{
    int n, k, i;
    char a[1000] = {0}, t, ch;
    scanf("%d", &n);
    if (getchar() == '\n')
        ;
    if (n > 0 && n <= 1000)
    {
        for (i = 0; i <= n - 1; i++)
        {
            a[i] = getchar();
        }
        scanf("%d", &k);
        if (k >= 0 && k <= n)
        {
            for (i = k - 1; i >= 0; i--)
            {
                printf("%c", a[i]);
            }
            for (i = n - 1; i >= k; i--)
            {
                printf("%c", a[i]);
            }
        }
    }
    return 0;
}