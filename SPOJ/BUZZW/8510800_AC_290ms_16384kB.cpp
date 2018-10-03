#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define WRITE       freopen("input.txt","r",stdin)
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



int main()
{
   // WRITE;
   string s;
   while(getline(cin,s)){
      if(s.size()==0) break;
      HashClass var;
      string temp;

      int sz = s.size();
      for(int i=0;i<sz;i++)
        if(s[i] != ' ')
         temp += s[i];
      var.hashFuntion(temp);
      sz = temp.size();
      bool flag = 0;
      for(int i = 1 ; i<sz ; i++){
          int mmax = 0;
          map < int , int > mark;
          for(int j = 0 ; i+j <= sz ; j++){
               int ret = var.hashValBetween(j+1,j+i);
               mark[ret]++;
               mmax = max(mmax,mark[ret]);
          }
          if(mmax > 1){
            printf("%d\n",mmax);
            flag = 1;
          }
      }
      cout << endl;
   }
}
