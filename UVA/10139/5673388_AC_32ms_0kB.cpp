#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <cstring>
#include <list>
#include <limits>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define ll long long
using namespace std;
ll a[50000], save[50000] = { 2 };
vector< long long int> v;

void seive(void)
{
	ll i, j;
	for (i = 3; i*i < 50000; i += 2)
	if (a[i] == 0)
	for (j = i*i; j <= 50000; j += 2 * i)
		a[j] = 1;
	for (i = 3, j = 1; i< 50000; i += 2)
	if (a[i] == 0){ save[j] = i; j++; }
}
int main()
{
	long long m, n, i, j, savem, saven;

	seive();
	while (scanf("%lld %lld", &m, &n) != EOF)
	{
		ll flag = -1;
		savem = m;
		saven = n;
		map <long long,int > hit;
		for (i = 0; save[i] <= sqrt(n); i++)
		{
			while (n%save[i] == 0)
			{
				if (n%save[i] == 0)
				{
					if (hit[save[i]] == 0)
						v.push_back(save[i]);
					hit[save[i]]++;
				}
				n /= save[i];
			}

		}
		if (n>1) { v.push_back(n); hit[n]++; }
		int k = v.size();
		for (i = 0; i<k; i++)
		{
			m = savem;
			ll sum = 0;
			while (m)
			{
				sum += m / v[i];
				m /= v[i];
			}
			if (sum < hit[v[i]])
			{
				flag = 1;
				printf("%lld does not divide %lld!\n", saven, savem);
				break;
			}

		}
		if (flag == -1) printf("%lld divides %lld!\n", saven, savem);
		v.clear();
		hit.clear();
	}
	return 0;
}
