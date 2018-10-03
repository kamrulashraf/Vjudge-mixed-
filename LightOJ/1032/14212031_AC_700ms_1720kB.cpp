#include <bits/stdc++.h>
using namespace std;
#define NN 32
string upperBound;
long long dp[NN][2][2][NN];
string convertBinary(long long n){
    string temp;
    while(n){
        char ch = (n%2)+48;
        temp += ch;
        n/=2;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
 
long long digitDp(int indx , int flag,int prev, int counter){
    if(indx == upperBound.size()){
        return counter;
    }
//  cout << indx << ' ' << flag << ' ' << prev << ' ' << counter << endl;
    long long res = 0;
    if(dp[indx][flag][prev][counter] != -1) return dp[indx][flag][prev][counter];
    if(prev == 1){
         if(flag == 1 && upperBound[indx] == '1'){
            res += digitDp(indx+1,0,0,counter);
            res += digitDp(indx+1,flag,1,counter+1);
         }
         if(flag == 1 && upperBound[indx] == '0'){
           res += digitDp(indx+1,1,0,counter);
         }
         if(flag == 0){
            res += digitDp(indx+1,0,1,counter+1);
            res += digitDp(indx+1,0,0,counter);
         }
    }
    if(prev == 0){
        if(flag == 1 && upperBound[indx] == '0'){
            res += digitDp(indx+1,1,0,counter);
        }
        if(flag == 1 && upperBound[indx] == '1'){
            res += digitDp(indx+1,0,0,counter);
            res += digitDp(indx+1,1,1,counter);
        }
        if(flag == 0){
            res += digitDp(indx+1,0,0,counter);
            res += digitDp(indx+1,0,1,counter);
        }
    }
 
    return dp[indx][flag][prev][counter]=res;
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        long long n;
        cin >> n;
        upperBound = convertBinary(n);
        // cout << upperBound.size() << endl;
        memset(dp,-1,sizeof dp);
        long long res = digitDp(0,1,0,0);
        printf("Case %d: %lld\n",cs++ ,res);
    }
}
 