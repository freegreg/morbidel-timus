/*
 *  ACM Timus Online Contest 27 March 2004
 *  E - Parallelipiped
 *
 *  back-ul ala de 6^N... (merge!)
 */

#include <stdio.h>

struct point
{
	float x, y, z;
};
struct cube
{
	point v1, v2;
} S[1000];
int N;
float vmax = 0, X, Y, Z;
point P[1001];



int inside(cube c, point p)
{
	return (p.x >= c.v1.x && p.y >= c.v1.y && p.z >= c.v1.z && p.x <= c.v2.x && p.y <= c.v2.y && p.z <= c.v2.z);
}

float volume(cube c)
{
	return (c.v2.x - c.v1.x) * (c.v2.y - c.v1.y) * (c.v2.z - c.v1.z);
}

void readdata()
{
	int i;

	scanf("%f %f %f %d", &X, &Y, &Z, &N);
	for (i = 0; i < N; i++)
		scanf("%f %f %f", &P[i].x, &P[i].y, &P[i].z);
}

void solve()
{	
	int i, j, l1, l2, ol;

	S[0].v1.x = S[0].v1.y = S[0].v1.z = 0;
	S[0].v2.x = X; S[0].v2.y = Y; S[0].v2.z = Z;

	for (i = 0; i < N; i++)
		if (!inside(S[0], P[i]))
			P[i].x = P[i].y = P[i].z = 0; /*  il facem inutil...  */

	for (l2 = l1 = i = 0; i < N; i++, l1 = ol + 1)
		for (ol = j = l2; j >= l1; j--)
			if (inside(S[j], P[i])) /*  il sparg pe S[j] in cele 6 paralelipipede rezultante  */
			{
				/*  X  */
				S[++l2].v1 = S[j].v1; S[l2].v2 = S[j].v2; S[l2].v2.x = P[i].x;
				S[++l2].v1 = S[j].v1; S[l2].v1.x = P[i].x; S[l2].v2 = S[j].v2;
				/*  Y  */
				S[++l2].v1 = S[j].v1; S[l2].v2 = S[j].v2; S[l2].v2.y = P[i].y;
				S[++l2].v1 = S[j].v1; S[l2].v1.y = P[i].y; S[l2].v2 = S[j].v2;
				/*  Z  */
				S[++l2].v1 = S[j].v1; S[l2].v2 = S[j].v2; S[l2].v2.z = P[i].z;
				S[++l2].v1 = S[j].v1; S[l2].v1.z = P[i].z; S[l2].v2 = S[j].v2;
			}
	for (i = l1; i <= l2; i++)
		if (volume(S[i]) > vmax)
			vmax = volume(S[i]);

	printf("%.2f\n", vmax);
}

int main()
{
	readdata();
	solve();
	return 0;
}
