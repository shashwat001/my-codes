#include <stdio.h>
#include <stdlib.h>



#define BUF 4096
char ibuf[BUF];
int ipt = BUF;

int readInt()
{
	while (ipt < BUF && ibuf[ipt] < '0')
		ipt++;

	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0')
			ipt++;
	}

	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0')
		n = (n*10)+(ibuf[ipt++]-'0');

	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0')
			n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}

/********************************************************************************************/

int i,j;

int main()
{
	int t,n;
	double *p[2001],r,s,res;
	for(i = 0;i < 2001;i++)
	{
		p[i] = (double *)malloc(sizeof(float)*1001);
	}
	p[0][1] = 0.0;
	p[0][0] = 0.0;
	for(i = 1;i <= 2000; i++)
	{
		for(j = 1;j <= (i+1)/2;j++)
		{
			if(j>i/2)
			{
				r = p[i-1][i-j];
			}
			else
				r = p[i-1][j];
			if((j-1)>i/2)
			{
				s = p[i-1][i-j+1];
			}
			else
				s = p[i-1][j-1];
			p[i][j] = 1.0 - 0.5*(r + s);
			//p[i][i+1-j] = p[i][j];
		}
	}
	t = readInt();
	while(t--)
	{
		res = 0.0;
		n = readInt();
		for(i = 1;i <= (n+1)/2;i++)
		{
			j = readInt();
			//if((n&1) && (i==(n+1)/2))
				//res = 2*p[n][i]*j;
			//else
				res += p[n][i]*j;
		}
		for(i = i;i <= n;i++)
		{
			j = readInt();
			res += p[n][n+1-i]*j;
		}
		printf("%lf\n",res);
	}
	
	/*for(i = 1;i <= 10;i++)
	{
		for(j = 1;j <= (i+1)/2;j++)
		{
			printf("%f  ",p[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
