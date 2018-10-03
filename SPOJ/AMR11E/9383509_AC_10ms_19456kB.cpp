#include <bits/stdc++.h>
using namespace std;
#define N 100005
int a[1000010];
vector < int > prime;
void seive(){
	 for(int i = 2 ; i*i<= 1000000 ; i++){
	 	 if(a[i] == 0){
              for(int j = 2*i ; j <= 1000005 ; j+=i){
              	   a[j]++;
              }
	 	 }
	 }
	 int counter = 0;
	 for(int i = 0 ; i<= 1000000 ; i++){
	     if(a[i] >=3) prime.push_back(i);
	 }
}
int main()
{
	 seive();
	 int test ;
	 cin >> test;
	 while(test--){
        int n;
        scanf("%d",&n);
        printf("%d\n",prime[n-1]);
     }

}
