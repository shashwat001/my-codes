#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

int main()
{
	srand(time(NULL));
	int t = rand()%10 + 1;
	int n,m,a,b;
	printf("%d\n",t);
	while(t--)
	{
		n = rand()%400000+2;
		m = rand()%400000+2;
		a = rand()%(n-1)+1;
		b = rand()%(m-1)+1;
		printf("%d %d %d %d\n",n,m,a,b);
	}
	return 0;
}
