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
    
    int n , d;
    cin >> n >>d;
    for(int i = 0 ; i< n ; i++){
        cin >> a[i];
    }

    int temp = 0;
    int counter = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j< n ; j++){
                temp++;

                if(i != j && abs(a[i]-a[j])<= d){
                   // cout << i << ' ' << j << ' ' << a[i]-a[j] << endl;
                   counter++;
                }
        }
    }
    // cout << temp << ' ' << counter << endl;
    cout << counter << endl;

}