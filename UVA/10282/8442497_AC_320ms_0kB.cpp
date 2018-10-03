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
map < string , string > mark;
int main()
{
   string s;
   while(getline(cin, s)){
      if(s.size()==0) break;
      // cout << '#' << s << ' ' << s.size() << endl;
      string temp, save;
      for(int i = 0 ; i < s.size() ; i++){
          if(s[i] == ' '){
             save = temp;
             temp.clear();
          }
          else temp += s[i];
      }
      mark[temp] = save;
   }
   while(cin >> s){
       if(mark[s].size())
       cout << mark[s] << endl;
       else cout << "eh" << endl;
   }
}
