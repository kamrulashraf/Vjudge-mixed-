#include <bits/stdc++.h>
using namespace std;
int b[300005];

    void kmpPreprocess(string sub)
    {
        int i = 0, j = -1; // 1  based
        b[i] = j;
        int m = sub.size();
        while(i < m){
            while(j >= 0 && sub[i] != sub[j])
                j = b[j];
            i++, j++;
            b[i] = j;
        }
    }

    int kmp(char *s , char *sub){
      int i=0,j=0,counter=0;
      int n = strlen(s);
      int m = strlen(sub);
      while(i<n){
        while( j>= 0 && s[i] != sub[j])
           j = b[j];
         i++ , j++;
         if(j==m) counter++ , j = b[j];
      }
      return counter;
    }



#define N 100005

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


string call(string x ,string y){
        string temp = y;
        temp += '#';
        temp += x;

        string tt;
        tt += x;
        tt +='#';
        tt += y;
        kmpPreprocess(tt);
        for(int i = 0 ; i<= tt.size() ; i++)
             if(b[i] == x.size()) return y;
        kmpPreprocess(temp);
        int sz = x.size()+y.size()+1;

        // cout << b[sz] << endl;
         sz = b[sz];
        string ret;
        ret += x;
        for(int i = sz ; i < y.size() ; i++)
           ret += y[i];
        return ret;


}



int calculateMin(string a, string b, string c){

    int mmin = 1e9,sz;
   string save = call(a,b);
   string temp = call(save,c);
   mmin = min((int)temp.size(),mmin);
   temp = call(c,save);
   mmin = min((int)temp.size(),mmin);

   save = a+b;
   temp = call(save,c);
   mmin = min((int)temp.size(),mmin);
   temp = call(c,save);
   mmin = min((int)temp.size(),mmin);

   return mmin;
}
string A ,B , C;
int main()
{
   cin >> A >> B >> C;
   int res = 1e9;
   res = min(res,calculateMin(A,B,C));
   res = min(res,calculateMin(B,A,C));

   res = min(res, calculateMin(B,C,A));
   res = min(res, calculateMin(C,B,A));

   res = min(res, calculateMin(A,C,B));
   res = min(res, calculateMin(C,A,B));

   cout << res << endl;

}
