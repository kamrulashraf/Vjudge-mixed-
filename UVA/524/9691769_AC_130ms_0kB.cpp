#include <bits/stdc++.h>
using namespace std;

int vis[17];
std::vector< int > v;
int n, mark[50];
int f[] = {2,3,5,7,11,13,17,19,23,29,31,37};
void call(int prev){
   if(v.size() == n && mark[1+prev] == 1){
         for(int i = 0 ; i< v.size() ; i++){
             if(i) printf(" ");
             printf("%d",v[i]);
         }
          printf("\n");
          return;
   }
   if(v.size() == n) return;
   for(int i = 1 ; i<= n ; i++){
        if(vis[i] == 0 && mark[i+prev]==1){
//            cout << prev << '#' << vis[i] << ' ' << i <<  endl;
            vis[i] = 1;
            v.push_back(i);
            call(i);
            v.pop_back();
            vis[i] = 0;
        }

   }
}
int main()
{
//    freopen("in.txt","r",stdin);
     v.push_back(1);
     for(int i = 0 ; i< 12 ; i++) mark[f[i]] = 1;
        int cs = 1;
     while(scanf("%d",&n) == 1){
          if(cs>1) cout << endl;
          printf("Case %d:\n",cs++);
          memset(vis,0 ,sizeof vis);
          vis[1] = 1;

          call(1);
     }
}
