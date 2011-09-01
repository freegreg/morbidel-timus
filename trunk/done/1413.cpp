/*
 *  ACM Timus Online
 *  Mars Jumper - Problem 1413
 */

#include <stdio.h>

double X, Y;
#define rad2    0.70710678118654752440084436210485

int main()
{
    char ch;

    X = Y = 0;

    while (scanf("%c", &ch) == 1 && ch != '0')
    {
        switch (ch)
        {
            case '1': X -= rad2; Y -= rad2; break;
            case '2': Y--; break;
            case '3': X += rad2; Y -= rad2; break;
            case '4': X--; break;
            case '6': X++; break;
            case '7': X -= rad2; Y += rad2; break;
            case '8': Y++; break;
            case '9': X += rad2; Y += rad2; break;
        }
    }
    printf("%.10lf %.10lf\n", X, Y);

    return 0;
}
