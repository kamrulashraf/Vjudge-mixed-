#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
void solve(int a[]){
 
 
}
 
int main()
{
   int test , cs = 1;
   cin >> test;
       while(test--){
       int n ,a[30005],dp[30005] = {0};
       cin >> n;
       for(int i = 0 ; i< n ; i++){
         cin >> a[i];
       }
       stack < pi > st;
       st.push(make_pair(-99999,-1));
       for(int i = 0 ; i < n ; i++){
           while(st.top().first >= a[i])
              st.pop();
            dp[i] += i-st.top().second;
            st.push(make_pair(a[i],i));
       }
       reverse(a,a+n);
       while(!st.empty()) st.pop();
       st.push(make_pair(-9999999,-1));
       for(int i = 0 ; i < n ; i++){
           while(st.top().first >= a[i])
              st.pop();
            dp[n-i-1] += i-st.top().second-1;
            st.push(make_pair(a[i],i));
       }
       reverse(a,a+n);
       long long ans = 0;
       for(int i = 0 ; i < n ; i++){
            ans = max((long long)dp[i]*a[i] ,ans);
       }
       printf("Case %d: %lld\n", cs++ , ans);
   }
 
}