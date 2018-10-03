#include <bits/stdc++.h>
#define inf   999999
using namespace std;
#define rep(i,x,y)  for(int i = x; i<y ; i++)
int a[1000000], sub[1000001],f[100000];
int lis(int n){
   int len = 0;
   rep(i,0,n+1) sub[i] = inf;
   sub[0] = -inf;
   for(int i = 0 ; i< n ; i++){
      f[i] = lower_bound(sub,sub+len+1, a[i]) - sub;
      sub[f[i]] = a[i];
      len = max(len , f[i]);
   }
  return len;
}
int main()
{
 //  freopen("a.txt","w",stdout);
    int n, i = 0;
    while(cin >> n){
     //  if(n==0) break;
       a[i] = n;
       i++;
    }
    n = i;
    int len = lis(i);
    cout << len << endl;
    cout << "-" << endl;
      int temp = len;
      stack <int> st;
      for(int i = n ; i >= 1 ; i--){
        if(f[i-1] == temp){
            st.push(a[i-1]);
            temp--;
        }
      }
      while(!st.empty()){
         cout << st.top() << endl;
         st.pop();
      }
 return 0;
}

