#include <bits/stdc++.h>
using namespace std;
int main()
{
    int  test , cs = 0;
    scanf("%d",&test);
    while(test--){
         unordered_map < long long , int > mark;
         std::vector< int >  a, b, c , d;
         int n;
         scanf("%d",&n);
         for(int i = 0 ; i< n ; i++){
             int x,y,z,w;
             scanf("%d%d%d%d",&x,&y,&z,&w);
             a.push_back(x);
             b.push_back(y);
             c.push_back(z);
             d.push_back(w);
         }

         for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< n ; j++){
                mark[a[i]+b[j]]++;
            }
         }
         int res = 0;
         for(int i = 0 ; i< n ; i++){
             for(int j = 0 ; j< n ; j++){
                 res += mark[-(c[i]+d[j])];
             }
         }
         if(cs) printf("\n");
         printf("%d\n",res);
         cs++;
    }
}
