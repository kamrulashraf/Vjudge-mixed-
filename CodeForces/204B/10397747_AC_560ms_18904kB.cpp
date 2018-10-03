#include <bits/stdc++.h>
using namespace std;
int main()
{

      int n ;
      scanf("%d",&n);
      map < int ,int > ma , mb;
      set < int > fa,fb;
      for(int i = 0 ; i< n ; i++){
           int a , b;
           scanf("%d%d",&a,&b);
           ma[a]++;
           if(a != b)
              mb[b]++;
           fa.insert(a);
           fb.insert(b);
      }

      bool flag = 0;
      int mmin = 1e9+7;
      int save = mmin;
      int tt = (n+1)/2;
      for(auto x : fa){
           if(ma[x] >= (n+1)/2){
              cout << 0 << endl;
              return 0;
           }
           else{
               if(mb[x] + ma[x] >= tt)
                  mmin = min(mmin,tt-ma[x]);
           }
      }

      for(auto x : fb){
          int temp = tt-ma[x];
          if(mb[x] >= temp)
          mmin = min(mmin,temp);
      }

       if(mmin == save)
         cout << -1 << endl;
       else
      cout << mmin << endl;
}
