int on = 0;

void genarb(FILE *f, int root, int maxn)
{
	int i, fii;

	if (root & 1)
		fii = 1;
	else
		fii = 1;

	if (on >= maxn) return;
	for (i = 1; i <= fii; i++)
	{
		fprintf(f, "%d %d %d\n", root, ++on, 1000);
		if (on == maxn) return;
	}
	for (i = 1; i <= fii; i++)
		genarb(f, on - fii + i, maxn);
}

void gen()
{
	scanf("%d", &N);
	FILE *f = fopen(input, "w");
	fprintf(f, "%d\n", N);

	on = 1;
	genarb(f, 1, N);

	fclose(f);
}

