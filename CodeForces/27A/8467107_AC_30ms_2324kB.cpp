#include <bits/stdc++.h>
using namespace std;
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
#define N 10000

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
   string s;

 HashClass var;
int fun(int n){
    map < int , int > mark;
    for(int i = 0 ; i+n <= s.size() ; i++){
        long long temp = var.hashValBetween(i+1,n+i);
        if(mark[temp]) return 1;
        mark[temp] = 1;
    }
    return 0;
}
int main()
{
   int n;
   map < int , int> mark;
   scanf("%d",&n);
   for(int i = 0 ; i< n ; i++){
      int arr;
      scanf("%d",&arr);
      mark[arr] = 1;
   }

   for(int i = 1 ; i<= 3001 ; i++){
       if(mark[i] == 0)
       {
         cout << i << endl;
         break;
       }
   }
}
