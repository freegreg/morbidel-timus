/*
 *  ACM Timus Online
 *  Rectangles travel - Problem 1202
 *
 *  Solution: 	for each square, compute the solution until now (until upper right corner of current square)
 *  		thus we compute also the road from the previous corner to the current one, being aware when y ups and downs. 
 *  		We keep an indicator of the minimum y and maximum y we can enter on current square.
 *  		for the x axis, we simply add last x2 - 2 because we traverse all x except the two margins.
 *  		on y we climb towards the corner from the last x not from the start x.
 */

#include <stdio.h>

#define ABS(n)		((n) > 0 ? (n) : -(n))
#define MIN(a, b)	((a) > (b) ? (b) : (a))

int N, Sol;
struct square
{
	int x1, y1, x2, y2;
};

int main()
{
	int i, y;
	square o, n;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	scanf("%d", &N);

	Sol = 0;
	y = 1;	/* y at which we enter in square i */
	for (i = 1; i <= N; i++, o = n)
	{
		scanf("%d %d %d %d", &n.x1, &n.y1, &n.x2, &n.y2);
		n.y1 ++;
		n.y2 --;

		if (i == 1)
			continue;

		if (n.y1 > o.y2 || n.y2 < o.y1)	/* no road */
		{
			printf("-1\n");
			return 0;
		}

		if (y >= n.y1 && y <= n.y2)
		{
			/* do nothing, we keep our y */
			continue;
		}
		else if (y < n.y1)
		{
			Sol += n.y1 - y;
			y = n.y1;
		}
		else if (y > n.y2)
		{
			Sol += y - n.y2;
			y = n.y2;
		}
	}

	/* we are in last square, go towards the corner */
	Sol += ABS(n.y2 - y);

	/* on X we advance with last X and -2 */
	Sol += n.x2 - 2;
	printf("%d\n", Sol);

	return 0;
}

