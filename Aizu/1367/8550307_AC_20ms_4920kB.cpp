#include <bits/stdc++.h>
using namespace std;
#define pii pair < int , int >
#define ff first
#define ss second
int mark[300005];
int main()
{

   int n , m;
   scanf("%d%d",&n,&m);
   stack < int > q;
   for(int i = 0 ; i< m ; i++){
      int temp;
      scanf("%d",&temp);
      q.push(temp);
   }
   int i = 0;
   vector < int > v;
   while(!q.empty()){
      int temp = q.top();
      if(mark[temp] == 0)
      v.push_back(temp);
      mark[temp] = 1;
      q.pop();
   }

   for(int i = 1 ; i<= n ; i++){
      if(mark[i] == 0)
         v.push_back(i);
   }
   for(int i = 0 ; i< v.size() ; i++)
      printf("%d\n",v[i]);

}
