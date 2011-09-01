/*
 *  ACM Timus Online
 *  Bookmakers - Problem 1582
 */

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

double K1, K2, K3;
double X1, X2, X3;
double Sum = 1000.0;
double Sol;


int main()
{
    scanf("%lf %lf %lf", &K1, &K2, &K3);

    X2 = 1000 / (1 + K2 / K1 + K2 / K3);
    X1 = K2 / K1 * X2;
    X3 = K2 / K3 * X2;

    Sol = MAX(K1 * X1, MAX(K2 * X2, K3 * X3));

    printf("%.0lf\n", Sol);


    return 0;
}
