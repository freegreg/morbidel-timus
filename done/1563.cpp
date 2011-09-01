/*
 *  ACM Timus Online
 *  Bayan - Problem 1563
 */

#include <stdio.h>
#include <string.h>

#define input "input.txt"

int N, Sol = 0;
char S[1024][64];


int main()
{
    #ifndef ONLINE_JUDGE
    freopen(input, "r", stdin);
    #endif

    int i, j;

    scanf("%d\n", &N);

    for (i = 0; i < N; i++)
    {
        gets(S[i]);
    }

    for (i = 1; i < N; i++)
        for (j = 0; j < i; j++)
            if (!strcmp(S[i], S[j]))
            {
                Sol++;
                break;
            }

    printf("%d\n", Sol);


    return 0;
}
