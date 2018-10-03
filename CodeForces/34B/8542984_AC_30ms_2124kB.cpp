#include <bits/stdc++.h>
using namespace std;

int a[105];
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
    
    memset(vis,-1,sizeof vis);
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i< n ;  i++){
        scanf("%d",&a[i]);
        a[i] = -a[i];
    }

    int res = call(0,m);
    cout << res << endl;
}