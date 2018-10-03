#include <bits/stdc++.h>
using namespace  std;

#define N 1000005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int a[N];
map < int , int > mark;
int main()
{
  int test, cs = 1;
  sca(test);
  while(test--){
      mark.clear();
      int n;
      sca(n);
      F(i,n){
         sca(a[i]);
      }

      int i = 0 , j = 0 ,mmax = 0;
      
      while(i < n){
         mark[a[i]]++;
         while(mark[a[i]] > 1 && j < i){
             mark[a[j]]--;
             j++;
             mmax = max(mmax,i-j+1);
         }
         mmax = max(mmax,i-j+1);
         // cout << i << ' ' << mmax << endl;
         i++;
      }

      printf("%d\n",mmax);

  }


}