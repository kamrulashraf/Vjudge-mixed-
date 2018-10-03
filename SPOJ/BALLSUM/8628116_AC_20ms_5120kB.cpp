// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int a[N] , b[N];
double x[N];
double element[N];
int main()
{

     long long n , k;
     while(scanf("%lld%lld",&n,&k)==2){
         if(n==-1 && k==-1) break;
         if(k <= 2){
            printf("0\n");
            continue;
         }
         long long sum = 0;
         k-=2;
         long long term = (k+1)/2;
         if(k&1){

            sum += term + term*(term-1);
         }
         else{
            sum += term*(term+1);
         }

         long long div ;
         if(n&1) div = (n-1)/2 * n;
         else div = (n/2)*(n-1);
         long long g = __gcd(sum,div);
         // cout << g << endl;
         sum /= g;
         div /= g;
         if(div == 1){
            printf("%lld\n",sum);
         }
         printf("%lld/%lld\n",sum,div);
     }
}
