#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define ull unsigned long long
int sa , sb;
string a , b;
ull p[22];
ull save[22];
long long dp[20][2][10];
void init(){
   p[0] = 1;
   for(int i = 1 ; i<= 18 ; i++)
      p[i] = p[i-1]*10;

   save[0] = 0;
   save[1] = 10;
   save[2] = 19;

   for(int i = 3 ; i<= 18 ; i++){
       save[i] = save[i-1]+p[i-2]*9;
   }
}

long long call(int indx , int n, int ishigh, int aa , int bb){
    if(indx >= n){
        if(aa == bb) return 1;
        else return 0;
    }
//    cout << indx << ' ' << ishigh << ' ' << aa << ' ' << bb << endl;
    if(dp[indx][ishigh][aa] != -1) return dp[indx][ishigh][aa];
    long long res = 0;
    for(int i = 0 ; i< 10 ; i++){
         if(indx == 0 && i == 0) continue;
         if(ishigh && i > a[indx]-'0') continue;
         int temp , temp2;
         if(indx==0) temp  = i;
         else temp = aa;
         if( indx == n-1) temp2 = i;
         else temp2 = -1;

//         cout << i << ' ' << temp << ' ' << temp2 << endl;
         res += call(indx+1, n , ishigh&(i==a[indx]-48),temp,temp2);
    }
    return dp[indx][ishigh][aa] = res;
}

long long call1(int indx , int n, int ishigh, int aa , int bb){
    if(indx >= n){
        if(aa == bb) return 1;
        else return 0;
    }
//    cout << indx << ' ' << ishigh << ' ' << aa << ' ' << bb << endl;
    if(dp[indx][ishigh][aa] != -1) return dp[indx][ishigh][aa];
    long long res = 0;
    for(int i = 0 ; i< 10 ; i++){
         if(indx == 0 && i == 0) continue;
         if(ishigh && i > b[indx]-'0') continue;
         int temp , temp2;
         if(indx==0) temp  = i;
         else temp = aa;
         if( indx == n-1) temp2 = i;
         else temp2 = -1;

//         cout << i << ' ' << temp << ' ' << temp2 << endl;
         res += call1(indx+1, n , ishigh&(i==b[indx]-48),temp,temp2);
    }
    return dp[indx][ishigh][aa] = res;
}
int main()
{
     init();


//     for(int i = 0 ; i< 10 ; i++)
//          cout << i << ' ' << save[i] << endl;
     cin >> a >> b;
     sa = a.size();
     sb = b.size();

     memset(dp,-1,sizeof dp);
     long long res = call(0 , sa , 1 , 0 , -1);
//     cout << res << endl;
     res += save[sa-1];
//     cout << res << endl;
     res -= (a[0] == a[sa-1]);
     if(sa == 1) res++;


     memset(dp,-1,sizeof dp);
     long long res1 = call1(0,sb,1,0,-1);
     res1 += save[sb-1];
     if(sb == 1) res1++;
//     cout << res << ' '<< res1 << endl;

     cout << res1 - res << endl;
}
