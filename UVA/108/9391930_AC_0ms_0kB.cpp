#include <bits/stdc++.h>
using namespace std;
#define N 105
#define inf 1e9
int a[N][N], cul[N][N];

int main()
{
	 int n;
	 scanf("%d",&n);
	 for(int i = 1 ; i<= n ; i++){
	 	  for(int j = 1 ; j<= n ; j++){
	 	  	  scanf("%d",&a[i][j]);
	 	  	  cul[i][j] = cul[i-1][j]+a[i][j];
	 	  }
	 }

	 int mmax = -inf;

     for(int i=1 ; i<=n;i++){
     	 for(int j=i+1;j<=n;j++){
     	     int sum = 0;
             for(int k=1,l=1;k<=n;k++){
                 sum += cul[j][k]-cul[i-1][k];
                 mmax = max(mmax,sum);
                 while(sum <= 0 && l<=k){
                 	 sum -= cul[j][l]-cul[i-1][l];
                 	 mmax = max(mmax,sum);
                 	 l++;
                 }
             }
     	 }
     }
     printf("%d\n",mmax);

}
