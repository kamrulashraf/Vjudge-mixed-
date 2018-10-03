#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test , cs  = 1, n;
	scanf("%d",&test);
	while(test--){
		 int n;
		 scanf("%d",&n);
		 int sum = 0;
		 for(int i = 1 ; i < n ; i++){
		 	 if(n%i==0){
		 	 	  // cout << i << endl;
		 	 	  sum += i;
		 	 }
		 }
		 if(sum == n)
		 	 printf("perfect\n");
		 else if(sum > n)
		 	 printf("abundant\n");
		 else printf("deficient\n");
	}
}
