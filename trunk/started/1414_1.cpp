/*
 *  ACM Timus Online
 *  Astronomical database - Problem 1414
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define input "file.in"

struct node
{
    char val[32];
    int height;
    struct node *l, *r;
} *R;

struct node *NIL;

#undef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#define getheight(n) (n->height = max(n->l->height, n->r->height)+1)
int nCount;

node *rotleft(node *k1)
{
    node *k2 = k1->l;
    k1->l = k2->r;
    k2->r = k1;
    getheight(k1);
    getheight(k2);
    return k2;
}

node *rotright(node *k2)
{
    node *k1 = k2->r;
    k2->r = k1->l;
    k1->l = k2;
    getheight(k2);
    getheight(k1);
    return k1;
}

node *rotate(node *n)
{
    if (n == NIL) return n;
    if (n->l->height > n->r->height+1)
    {
        if (n->l->r->height > n->l->l->height) n->l = rotright(n->l);
        n = rotleft(n);
    } else
    if (n->r->height > n->l->height+1)
    {
        if (n->r->l->height > n->r->r->height) n->r = rotleft(n->r);
        n = rotright(n);
    }
    return n;
}

node *insert(node *n, char val[])
{
    if (n == NIL)
    {
        n = (node *) malloc(sizeof(node));
		strcpy(n->val, val);
        n->height = 1;
        n->l = n->r = NIL;
        return n;
    }
	int x = strcmp(val, n->val);
    if (x < 0)
        n->l = insert(n->l, val);
    else
	if (x > 0)
        n->r = insert(n->r, val);
	else
		return n; // do not insert duplicates

    getheight(n);
    return rotate(n);
}

void init()
{
    NIL = (struct node *) malloc(sizeof(struct node));
    NIL->height = 0;
    R = NIL;
}

int strcmp2(char str[], char prefix[]) // strcmp but returns 0 also when s1 is a prefix of s2
{
	if (strlen(str) < strlen(prefix))
		return strcmp(str, prefix);

	int i;
	for (i = 0; i < strlen(prefix); i++)
		if (str[i] != prefix[i])
			return strcmp(str, prefix);

	return 0;
}

void print(struct node *n, char word[])
{
    if (n == NIL || nCount >= 20) return;

	print(n->l, word);
	if (!strcmp2(n->val, word))
	{
		nCount++;
		printf("  %s\n", n -> val);
	}
    print(n->r, word);
}

node *search(node *n, char val[])
{
	if (n == NIL) 
		return n;

	int x = strcmp2(n->val, val);

	if (x < 0)
		return search(n->r, val);
	else
	if (x > 0)
		return search(n->l, val);
	else
		return n;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	init();
	R = insert(R, "sun");

	char line[32];
	char word[32];
	while (scanf("%s", &line) == 1)
	{
		strcpy(word, line + 1);
		if (line[0] == '+')
			R = insert(R, word);
		else
		{
			printf("%s\n", word);
			nCount = 0;
			print(search(R, word), word);
		}
	}

	return 0;
}
