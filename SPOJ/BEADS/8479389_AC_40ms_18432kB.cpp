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
HashClass var;
string s;
int compare(int mmin , int indx, int sz){
       int b = 0;
       int e = sz;
       while(b <= e){
       	  int m = (b+e)/2;
       	  bool flag = (var.hashValBetween(mmin+1,mmin+m) == var.hashValBetween(indx+1,indx+m));
       	  if(flag)
       	  	  b = m+1;
       	  else e = m-1;
       }
//       cout << b << ' ' << e << endl;
       if(s[mmin+e] <= s[indx+e])
          return mmin;
       return indx;
}

int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){

   	   cin >> s;
   	   int sz = s.size();
   	   s += s;
   	   var.hashFuntion(s);
   	   int mmin = 0;
   	    for(int i = 1 ; i< sz ; i++){
           mmin = compare(mmin,i,sz);
//           cout << i << ' ' << mmin << endl;
   	    }

   	   cout << mmin+1 << endl;
   }
   return 0;
}
