//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

int main ()
{
	int i,j,n;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		for(j = 1;j <= n/2;j++)
		{
			printf("%d ",i*n+j);
			printf("%d ",n*n+1-i*n-j);
		}
		printf("\n");
	}
	return 0;
}