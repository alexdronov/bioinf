#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define d 10

void RabinKarpStringMatch(char *, char *, int);
int main()
{
	char Text[100], Pattern[100];
	int Number = 11;

	setbuf(stdout, NULL);

	printf("\nString : ");
	gets(Text);
	printf("\nPattern : ");
	gets(Pattern);

	RabinKarpStringMatch(Text,Pattern,Number);
	return 0;
}

void RabinKarpStringMatch(char *Text, char *Pattern, int Number)
{
	int M,N,h,P=0,T=0, TempT;
	int i,j;
	M = strlen(Pattern);
	N = strlen(Text);
	h = (int)pow(d,M-1) % Number;
	for(i=0;i<M;i++)  {
		P = ((d*P) + ((int)Pattern[i])) % Number;
		TempT = ((d*T) + ((int)Text[i]));
		T =  TempT % Number;
	}
	for(i=0;i<=N-M;i++)  {
		if(P==T)  {
			for(j=0;j<M;j++)
				if(Text[i+j] != Pattern[j])
					break;
			if(j == M)
				printf("\nPosition :  %d",i+1);
		}
		TempT =((d*(T - Text[i]*h)) + ((int)Text[i+M]));
		T = TempT % Number;
		if(T<0)
			T=T+Number;
	}

}