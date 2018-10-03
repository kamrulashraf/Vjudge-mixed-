#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	int test;
	int n, m, i, k;
	long long int arr[20000];
	cin >> test;
	while (test--){
		cin >> m >> n;
		for (i = 0; i<m; i++){
			scanf("%lld", &arr[i]);
		}
		sort(arr, arr + m);
		long long int min = 10000000000;
		for (i = 0; i<=m - n; i++)
		{

			if (arr[i + n - 1] - arr[i] < min)
				min = arr[i+n-1] - arr[i];
		}
		cout << min << endl;


	}
}
