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
  int test;
  cin >> test;
  getchar();
  getchar();
  while(test--){
     int mat[25][25] = {0};
     int i = 0;
     string s[26];
     while(getline(cin , s[i])){
        if(s[i].empty()) break;
        for(int j = 0 ; j < s[i].size() ; j++){
            if( i == 0) mat[i][j] = s[i][j] - 48;
            else if(s[i-1][j] == '1' && s[i][j] == '1')
                mat[i][j] = mat[i-1][j]+1;
            else mat[i][j] = s[i][j] - 48;
        }
        i++;
     }
     int r = i;
     c = s[0].size();
//     rep(i,0,r){
//        rep(j,0,c)
//           cout << mat[i][j] << '*' << s[i][j] << "  ";
//        cout << "\n";
//     }
     int ans = 0;
     for(int i = 0 ; i < r ; i++){
        int temp[105];
        for(int j = 0 ; j < c ; j++){
           temp[j] = mat[i][j];
        }
        ans = max(ans, histogram(temp,c));
     }
     cout << ans << endl;
     if(test) cout << "\n";
  }

}

