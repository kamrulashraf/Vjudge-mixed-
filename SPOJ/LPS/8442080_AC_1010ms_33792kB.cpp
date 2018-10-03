#include <bits/stdc++.h>
using namespace std;
#define N 1000005
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

class HashClass{
       public:
          long long hashVal[N],power[N],base,mod,SZ;
       HashClass(){
            SZ = N-1;
            mod = MOD[0];
            base = BASE[0];
            power[0] = 1;
            hashVal[0] = 0;
            for(int i = 1 ; i<SZ;i++)
                 power[i]=(power[i-1]*base)%mod;
       }

       void hashFuntion(string s){
            for(int i = 0 ; i< s.size();i++)
                hashVal[i+1] = (hashVal[i]*base+s[i])%mod; // 1 base indx
       }

       long long hashValBetween(int i ,int j){
           long long ret = (hashVal[j]-hashVal[i-1]*power[j-i+1])%mod; // 1 based indx
           return (ret+mod)%mod;
       }
};
HashClass var, var1;

bool fun(int len,  int indx, int sz){
    int i = indx-len;
    int j = indx-1;
    int ii = indx+1;
    int jj = indx+len;
    int x = sz-jj-1;
    int y = sz-ii-1;
    // cout << '#' << i << ' ' << j << ' ' << x << ' ' << y << '*' << indx <<  endl;
    long long a = var.hashVal[i];
    long long b = var1.hashVal[x];
    if(var.hashValBetween(i+1,j+1) == var1.hashValBetween(x+1,y+1))
        return true;
    return 0;
}

bool fun1(int len , int indx , int sz){
    int i = indx-len;
    int j = indx-1;
    int ii = indx+2;
    int jj = indx+len+1;
    int x = sz-jj-1;
    int y = sz-ii-1;
    if(var.hashValBetween(i+1,j+1) == var1.hashValBetween(x+1,y+1))
        return true;
    return 0;
}
int main()
{
   int n;
   cin >> n;
   string s;
   cin >> s;


   string rev = s;
   reverse(rev.begin() , rev.end());
   var.hashFuntion(s);
   var1.hashFuntion(rev);
   int sz = s.size();
   int mmax = 1;
   for(int i = 0 ; i< s.size() ; i++){
       int e = min(i,sz-i-1);
       int b = 0;
       bool triger = 0;
       while(b<=e){
          int m=(b+e)/2;
          bool flag=fun(m,i,sz);
          triger |= flag;
          // cout << b << ' ' << e << ' ' << m << ' ' << flag << endl;
          if(flag) b = m+1;
          else e = m-1;
       }
       if(triger)
       mmax = max(mmax,e*2+1);

       e = min(i,sz-i-2);
       b = 0;
       if(i < s.size()-1 && s[i] == s[i+1]){
         while(b<=e){
            int m=(b+e)/2;
            bool flag=fun1(m,i,sz);
            // cout << b << ' ' << e << ' ' << m << ' ' << flag << endl;
            if(flag) b = m+1;
            else e = m-1;
         }
         mmax = max(mmax,e*2+2);
         // cout << i << endl;
      }
   }
   printf("%d\n",mmax);
}
