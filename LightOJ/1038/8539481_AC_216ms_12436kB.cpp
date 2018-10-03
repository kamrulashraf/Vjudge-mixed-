#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i=x;i<y;i++)
#define ull    unsigned long long
#define N 100011
vector < int > v[100011];
double dp[100011];
bool vis[100011];
void divisorGenerate(int n){
    for(int i = 2 ; i< n ; i++){
        for(int j = i ; j< n ; j+=i){
           v[j].push_back(i);
        }
    }
}


double call(int n){
    if(n==1) return 0;
    if(vis[n] == 1) return dp[n];
    double noOfDivisor = v[n].size()+1;
    double ret = 1/noOfDivisor;
    for(int i=0;i<v[n].size();i++){
       int temp = n/v[n][i];
       ret += (1/noOfDivisor)*(call(temp)+1);
    }
    double temp = (1-1/noOfDivisor);
    vis[n] =1;
    return dp[n] = ret*(1/temp);
}
int main(){
   divisorGenerate(100005);
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
       int n;
       memset(vis,0,sizeof vis);
       scanf("%d",&n);
       double res = call(n);
       printf("Case %d: %.8lf\n",cs++ ,res);
   }
   return 0;
}
