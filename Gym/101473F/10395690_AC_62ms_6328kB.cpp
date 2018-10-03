#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define ull unsigned long long
int a[100005], cul[N];
map < int ,int > mark;
int main()
{
      int  n ;
      ll sum = 0;
      scanf("%d",&n);
      for(int i = 0 ; i< n ; i++){
            scanf("%d",&a[i]);
            sum += a[i];
      }

//      cout << sum << endl;

      cul[0] = a[0];
      for(int i = 1 ; i< n ; i++){
        cul[i] = cul[i-1]+a[i];
      }

      for(int i = 0 ; i< n ; i++){
           mark[cul[i]]++;
      }

      int counter = 0;
      if(sum % 3 == 0){
           int div = sum/3;
          for(int i = 0 ; i< n ; i++){
              int aa  =  cul[i]-a[i];
              if(aa >= sum) aa %= sum;
              int bb =   aa+div;
              if(bb > sum) bb %= sum;
              int cc = bb+div;
              if(cc > sum) cc %= sum;

              int dd  = cc + div;
              if(dd >= sum) dd %= sum;
//                     cout << aa << ' ' << bb << ' ' << cc << endl;

              if( (mark[bb] & mark[cc])  && aa == dd){
//                                        cout << aa << ' ' << bb << ' ' << cc << endl;

                    counter++;
              }
          }

      }


      printf("%d\n",counter/3);

}
