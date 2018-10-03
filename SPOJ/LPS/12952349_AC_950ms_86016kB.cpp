#include <bits/stdc++.h>
using namespace  std;

#define N 3000000
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

ll mod = MOD[1];
int base = BASE[0];
ll arr[N] , brr[N];
ll p[N];
string s;
void init(){
    p[0] = 1;

    for(int i  = 1 ; i< N ; i++){
         p[i] = (p[i-1]*base+mod)%mod;
    }


}


long long hashFuntion(string s, ll hashVal[]){
    ll temp = 0;
    for(int i =  0 ; i< s.size() ; i++){
         temp = temp*base + s[i]-'a'+1;
         temp = temp%mod;
         hashVal[i+1] = (temp+mod)%mod;
    }
    return (temp+mod)%mod;
}



ll hashValBetween(int i , int j,ll hashVal[]){
    return (hashVal[j] - (hashVal[i-1]*p[j-i+1])%mod + mod)%mod; // 1 based indx
}





int filp(int x){
    return s.size() - (x-1);
}

bool fun(int n){
    for(int i = 0 ; i< s.size() ; i++){
         int x = i+1;
         int y = x+n-1;
         int xx = filp(y);
         int yy = filp(x);

         if(y > s.size()) break;
//                  cout << x << ' ' << y << ' ' << xx << ' ' << yy << endl;

         ll temp = hashValBetween(x,y,arr);
         ll temp1 = hashValBetween(xx,yy,brr);
         if(temp1 == temp) return true;
    }
    return false;
}
int main()
{
      init();

      int obohelito;
      cin >> obohelito;
      cin >> s;


      int b = 0 ;
      int e = s.size();



      string temp = s;
      reverse(temp.begin() , temp.end());

      hashFuntion(s,arr);
      hashFuntion(temp,brr);


      std::vector< int > v1 , v2;


      for(int i = 1 ; i<= s.size() ; i++){
            if(i&1) v1.push_back(i);
            else v2.push_back(i);
      }

      b = 0;
      e = v1.size()-1;

      if(e > 0)
      while(b <= e){
         int m = (b+e) >> 1;


         if(fun(v1[m]) == true) b = m+1;
         else e = m-1;
      }

//      cout << b << ' ' << e << endl;

      int mmax = 1;

      if( e < v1.size() && e >= 0)
         mmax = v1[e];
      else mmax = 1;


      b = 0  ; e = v2.size()-1;

      if(e > 0)
      while(b <= e){
         int m = (b+e) >> 1;

         if(fun(v2[m]) == true) b = m+1;
         else e = m-1;
      }
      if( e < v2.size() && e >= 0)
      mmax = max(mmax, v2[e]);

      cout << mmax << endl;

}
