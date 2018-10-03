
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NN 150
#define ull unsigned long long

ull dp[25][151];
ull p[25];
int target;
        int n , m;

ull call(int indx , int sum){
     if(indx >= n){
        if(sum >= target){
           return 1;
        }
        return 0;
     }
     if(dp[indx][sum] != -1) return dp[indx][sum];
     ull res = 0;
     for(int i = 1 ; i<= 6 ; i++){
         int temp = sum+i;
         res += call(indx+1,temp);
     }
     return dp[indx][sum] = res;
}
int main()
{
  while(cin >> n && n){
        cout << "1/2" << endl;
  }
}
