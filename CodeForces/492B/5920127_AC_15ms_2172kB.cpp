#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
bool comp(int a , int b)
{
    return a>b;
}
int main()
{
    long long int i , j , k, arr[1000];
    double maxi= 0.0;
    long long int n , l;
    while(scanf("%I64d %I64d", &n , &l)==2)
    {
        for( i = 0 ; i< n ; i++)
            scanf("%I64d", &arr[i]);
        sort(arr, arr+n, comp);
        for(i = 0 ; i<n-1 ; i++)
            maxi = max( (arr[i] - arr[i+1])/2.0 , maxi);

        maxi = max(maxi , (double)arr[n-1]);
        maxi = max(maxi , (double) ((double) l -arr[0]));
      
        printf("%lf\n", maxi);

    }
}