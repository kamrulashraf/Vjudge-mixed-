#include <bits/stdc++.h>
using namespace  std;

#define N 100005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int cnv(int n){
   int save = n;
   string s;
   if(n== 0) s += (char) 0;
   while(n){
      int temp = n%10;
      n /= 10;
      if(temp == 4 || temp == 7){
         s += temp;
      }
   }
   reverse(s.begin() , s.end());
   int ret = 0;
   for(int i = 0 ; i< s.size() ; i++){
       ret = ret * 10 + s[i];
   }
   return ret;
}

int count4(int a){
   int cnt = 0;
   while(a){
     if(a%10 == 4) cnt++;
     a/=10;
   }
   return cnt;
}

int count7(int a){
   int cnt = 0;
   while(a){
     if(a%10 == 7) cnt++;
     a/=10;
   }
   return cnt;
}


int main()
{
   int a , b;
   int res = 0;
   cin >> a >> b;

   for(int i = a+1 ; i<= 2000000 ; i++){
       int temp = i;
       int save = cnv(temp);
//       cout << i << ' ' <<  save << ' ' << count4(save) << ' ' << count7(save) << endl;
       if(save == b){
          res = i;
          break;
       }
   }
   cout << res << endl;
}
