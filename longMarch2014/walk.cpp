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
#include <list>
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
	int k,t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int maxval = 0;
		for(i = 0;i < n;i++)
		{
			cin>>k;
			maxval = max(maxval,i+k);
		}
		cout<<maxval<<endl;
	}
	return 0;
}