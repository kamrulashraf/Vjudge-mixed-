#include <bits/stdc++.h>
using namespace std;

int a[1005];
int dp[105][105];
int vis[105][105];
int n , m;
int call(int in , int rem){
     if(in >= n || rem == 0) return 0;
     if(vis[in][rem] != -1) return dp[in][rem];
     int p1 = 0 , p2 = 0;
     p1 = a[in] + call(in+1,rem-1); 
     p2 = call(in+1,rem);
     vis[in][rem] = 1;
     return dp[in][rem] =  max(p1,p2);
}
int main()
{
    
 int n;
 cin >> n;
 for(int i = 0 ; i< n ; i++)
    cin >> a[i];
 int mmin = 1e9;
 for(int i = 0 ; i<n ; i++){
    mmin = min(abs(a[i]-a[(i+1)%n]) , mmin);
 }

 for(int i = 0 ; i<n ; i++){
   if(abs(a[i]-a[(i+1)%n]) == mmin){
      int p = (i+2 == n) ? n :(i+2)%n;
      cout << i+1 << ' ' << p << endl;
      break;
   }
 }

}