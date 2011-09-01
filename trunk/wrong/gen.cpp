// generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define input "input.txt"

long a, b, c, n, k, p, m, s[10];
FILE *f;


void write_numbers()
{
    scanf("%ld %ld", &n, &m);
	f = fopen(input, "w");
    fprintf(f, "%ld %ld\n", n, m);
    fclose(f);
}

void write_vector()
{
	long i, x, y, p10;

	scanf("%ld", &n);

	f = fopen(input, "w");

	fprintf(f, "%ld\n", n);

	for (i = n; i; i--)
    {
		x = -100 + rand() % 200L;
		do
		{
		y = -100 + rand() % 200L;
		} while (y < x);
		fprintf(f, "%ld %ld\n", x, y);
    }

    fclose(f);
}

void write_matrix()
{
	long i, j;

    f = fopen(input, "w");

    scanf("%ld %ld", &n, &m);
    fprintf(f, "%ld %ld\n", n, m);

    for (i = 0; i < n; i++, fprintf(f, "\n"))
		for (j = 0; j < m; j++)
        {
			a = rand() % 100L;
            fprintf(f, "%ld ", a);
        }

	fclose(f);
}

int main()
{
	time_t t;
    srand((unsigned) time(&t)); // randomize

    // write_numbers();
    //write_vector();
    // write_matrix();
    
    freopen("output.txt", "w", stdout);
    printf("99999\n");
    printf("0 0 10 100\n");
    for(int i =0 ; i < 99998; ++i) {
        printf("%d %d %d %d\n", (i+1)*10,0,(i+2)*10 , 100);
    }

    return 0;
}
