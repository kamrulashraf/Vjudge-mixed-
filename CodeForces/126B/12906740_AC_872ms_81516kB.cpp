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
ll base = BASE[0];
ll mod = MOD[1];

ll val[N] , a[N];
ll p[N];
int sz;
void init(){
    p[0] = 1;

    for(int i = 1 ; i < N ; i++){
         p[i] = (p[i-1]*base)%mod;
    }

}
void hashFun(string s , ll has[]){

    ll temp = 0;

    for(int i = 0 ; i < s.size() ; i++){
        temp = (temp*base)+s[i];
        temp %= mod;
        has[i+1] = (temp+mod)%mod;
    }

}

ll hashValBetween(int i , int j,ll hashVal[]){
    return (hashVal[j] - (hashVal[i-1]*p[j-i+1])%mod + mod)%mod; // 1 based indx
}



bool fun(int n){
   for(int i = 2 ; i+n<= sz ; i++){
      ll temp = hashValBetween(i,i+n-1,a);
//      cout << n << '#' << temp << endl;
      if(temp == hashValBetween(1,n,a)){
         return true;
      }
   }

   return false;
}
int main()
{
    init();
    string s;
    cin >> s;
    hashFun(s,a);
    std::vector< int > v;

    sz = s.size();


    for(int i = 1 ; i <= s.size() ; i++){
        ll temp = hashValBetween(1,i,a);
        ll temp1 = hashValBetween(sz-i+1,sz,a);

        if(temp == temp1){
            v.push_back(i);
        }
    }



    if(v.size() == 0){
        cout << "Just a legend" << endl;
        return 0;

    }

    int b = 0 , e = v.size()-1;

    while(b <= e){
         int m = (b+e)/2;
//         cout << b << ' ' << e << ' ' << m << '#' << fun(m) << endl;
         if(fun(v[m]) == true){
            b = m+1;
         }
         else e = m-1;
    }

//    cout << v[e] << ' ' << fun(v[e]) <<  endl;

//    cout << b << ' ' << e << ' ' << v[b] << ' ' << v[e] << endl;
    if(e < 0 && e >= v.size() || fun(v[e]) == false || v[e] == 0){
       cout << "Just a legend" << endl;
    }
    else{

         for(int i = 0 ; i< v[e] ; i++){

             cout << s[i];
         } cout << endl;
    }
}