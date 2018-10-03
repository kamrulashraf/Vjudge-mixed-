#include <bits/stdc++.h>
#define pi pair<int,int>
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
using namespace std;
int histogram(int a[ ] , int n){
       int dp[105] = {0};
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
       int ans = 0;
       for(int i = 0 ; i< n ; i++){
          ans = max(ans , dp[i]*a[i]);
       }
       while(!st.empty()) st.pop();
  return ans;
}

int main()
{
 // freopen("a.txt","w",stdout);
  int r , c;
  while(cin >> r >> c){
     if(!r && !c) break;
     int mat[105][105];
     memset(mat,0,sizeof(mat));
     rep(i,0,r){
        rep(j,0,c){
           int temp;
           cin >> temp;
           temp = abs(1-temp);
           if(temp == 1  && i > 0) mat[i][j] = mat[i-1][j]+1;
           else mat[i][j] = temp;
        }
     }
     int ans = 0;
     for(int i = 0 ; i < r ; i++){
        int temp[105];
        for(int j = 0 ; j < c ; j++){
           temp[j] = mat[i][j];
        }
        ans = max(ans, histogram(temp,c));
     }
     cout << ans << endl;
  }

}

