#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N];
vector < int > v[N];
int main()
{
   //freopen("inputf.in","r" ,stdin);
   int  n , c,q;
   scanf("%d%d",&n , &c);
   for(int i = 1 ; i<= n ; i++){
      scanf("%d",&a[i]);
      v[a[i]].push_back(i);
   }
   for(int i = 1 ; i<= c ; i++)
      sort(v[i].begin(),v[i].end());

   scanf("%d",&q);
   while(q--){
      int l , r;
      scanf("%d%d",&l,&r);
      bool flag = 0;
      for(int i = 0; i < 50 ; i++){
          int temp = l+ rand()%(r-l+1);
          temp = a[temp];
          int t  = upper_bound(v[temp].begin(),v[temp].end(),r)-v[temp].begin();
           t -= lower_bound(v[temp].begin(),v[temp].end(),l)-v[temp].begin();


          if(t > (r-l+1)/2){
             flag = 1;
             printf("yes %d\n",temp);
             break;
          }
      }
      if(flag==0) printf("no\n");

   }

}
