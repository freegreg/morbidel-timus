/*
 *  ACM Timus Online
 *  Diamonds - Problem 1433
 */


#include <stdio.h>
#include <string.h>

char D1[16], D2[16];
int Flag[256];

int main()
{
    int i;
   
    scanf("%s%s", &D1, D2);

    for(i = 'A'; i <= 'Z'; i++)
        Flag[i] = 0;
    for (i = 0; i < 4; i++)
        Flag[D1[i]]++, Flag[D2[i]]--;
       
    for (i = 'A'; i <= 'Z'; i++)
        if (Flag[i] != 0)
        {
            printf("different\n");
           
            return 0;
        }
    // rotate D2 so the base is the same
    if (D2[1] == D1[0]) // rotate it on left face
    {
        i = D2[1]; D2[1] = D2[0]; D2[0] = i;
        i = D2[2]; D2[2] = D2[3]; D2[3] = i;
    } else
    if (D2[2] == D1[0]) // rotate it on right face
    {
        i = D2[1]; D2[1] = D2[3]; D2[3] = i;
        i = D2[2]; D2[2] = D2[0]; D2[0] = i;
    } else
    if (D2[3] == D1[0]) // rotate it on back face
    {
        i = D2[1]; D2[1] = D2[2]; D2[2] = i;
        i = D2[0]; D2[0] = D2[3]; D2[3] = i;
    }

    if (D2[0] == D2[1] || D2[0] == D2[2] || D2[0] == D2[3] || D2[1] == D2[2] || D2[1] == D2[3] || D2[2] == D2[3])
        printf("equal\n");
    else         // all 4 are different colours, check if they are flipped
    {
        i = D2[1]; D2[1] = D2[3]; D2[3] = i; // mirror it, now check for equality
        D2[4]= D2[1];
		D2[5] = D2[2];
		D2[6] = D2[3];
		D2[7] = 0;

		char *pos = strstr(D2, D1 + 1);
        if (strstr(D2, D1 + 1))
            printf("different\n");
        else
            printf("equal\n");
    }
   
    return 0;
}
