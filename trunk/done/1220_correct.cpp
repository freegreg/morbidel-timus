/*
 *  ACM Timus Online
 *  Stacks - Problem 1220
 *
 * OBS:
 *  1. store the input on 5 bytes chunks (10 bits for the stack number, 30 bits for the value)
 *
 *  2. the maximum number of operations is 100k. This means that we can have a maximum
 *  of 50K push values because it should be a mirror POP operation for each PUSH, otherwise 
 *  the PUSH op is useless and should not be stored. The sum of stack lengths is max 50K.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define input        "input.txt"
#define MAX_STACKS    1024          /* 10 bits */
#define MAX_VALUE    1000000000    /* 30 bits */
#define MAX_OPS        100000
#define NO_VALUE    ((1 << 30) - 1)    /* -1, the value of POP operation */
#define CHUNK_SIZE    5
#define MASK(nbits)    ((1 << (nbits)) - 1)    /* to get the value of first nbits bits */


unsigned char *Input;
int noperations = 0;
int Len[MAX_STACKS], Push[MAX_STACKS], FirstPos[MAX_STACKS], SP[MAX_STACKS];
int Stack[MAX_OPS / 2];


/* store the stack and value in the encoded format */
/* 0..9 -> stack, 10..39 -> val */
void Encode(int nop, int stack, int val)
{
  __int64 x = (((__int64)val & MASK(30)) << (__int64)10) + (stack & MASK(10));

  memcpy(Input + nop * CHUNK_SIZE, &x, CHUNK_SIZE);
}

void Decode(int nop, int &stack, int &val)
{
  int i;
  __int64 x = 0;

  for (i = CHUNK_SIZE - 1; i >= 0; i--)
    {
      x += *(Input + nop * CHUNK_SIZE + i);

      if (i)
        {
          x <<= 8;
        }
    }

  stack = x & MASK(10);
  val = (x >> 10) & MASK(30);
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen(input, "r", stdin);
    #endif

    char line[64];
    int i, st;
    int val;


    Input = (unsigned char *) malloc(MAX_OPS * CHUNK_SIZE);

    memset(Input, 0, MAX_OPS * CHUNK_SIZE);
    memset(Len, 0, sizeof(Len));
    memset(Push, 0, sizeof(Push));

    scanf("%d", &noperations);

    for (i = 0; i < noperations; i++)
    {
        scanf("%s %d", &line, &st);

        if (!strcmp(line, "PUSH"))
        {
            scanf("%d", &val);
            
            /* PUSH st, val */
            Encode(i, st, val);

            Len[st] ++;

	    if (Len[st] > Push[st])
	      {
		Push[st] = Len[st];
		if (Push[st] > MAX_OPS / 2)
		  {
		    Push[st] = MAX_OPS / 2;
		  }
	      }
        } else
        {
            /* POP st */
            Encode(i, st, NO_VALUE);

            Len[st] --;
        }
    }

    FirstPos[0] = 0;
    for (i = 1; i < MAX_STACKS; i++)
      {
        Len[i] = Push[i];

        FirstPos[i] = FirstPos[i - 1] + Len[i - 1];
        SP[i] = FirstPos[i];
      }

    for (i = 0; i < noperations; i++)
    {
        Decode(i, st, val);

        if (val == NO_VALUE)
        {
            /* decrease stack pointer */
            if (SP[st] == FirstPos[st])
            {
                SP[st] = FirstPos[st] + Len[st] - 1;
            }
            else
            {
                SP[st] --;
            }

            /* POP st */
            printf("%d\n", Stack[SP[st]]);
            Stack[SP[st]] = NO_VALUE;
        }
        else
        {
            /* PUSH st, val */
            Stack[SP[st]] = val;

            /* increase stack pointer */
            if (SP[st] == FirstPos[st] + Len[st] - 1)
            {
                SP[st] = FirstPos[st];
            }
            else
            {
                SP[st] ++;
            }
        }
    }

    return 0;
}
