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

ll base  = BASE[0];
ll mod = MOD[0];
ll p[N];
ll a[N] , b[N];
void init(){
   p[0] = 1;
   for(int i = 1 ; i < N-5 ; i++){
         p[i] = (p[i-1]*base + mod)%mod;
   }
}
long long hashFun(string s, ll hashVal[]){
    ll temp = 0;
    for(int i =  0 ; i< s.size() ; i++){
         temp = temp*base + s[i];
         temp = temp%mod;
         hashVal[i+1] = (temp+mod)%mod;
    }
    return (temp+mod)%mod;
}


ll hashValBetween(int i , int j,ll hashVal[]){
    return (hashVal[j] - (hashVal[i-1]*p[j-i+1])%mod + mod)%mod; // 1 based indx
}


int main()
{
    string s;

    init();
    while(cin >> s){
        string temp;
        temp = s;
        reverse(temp.begin() , temp.end());

//        for(int i = 0 ; i< s.size() ; i++){
//           cout << a[i+1] << ' ';
//        } cout << endl;
        hashFun(s,a);
        hashFun(temp,b);

        int sz = s.size();
        int res = 0;
        for(int i = 0 ; i< s.size() ; i++){
            int x = 1;
            int y = sz;
            int xx = s.size() - (sz-1);
            int yy = s.size();

//            cout << x << ' ' << y << ' ' << xx << ' ' << yy << ' ' << hashValBetween(x,y,b) << ' ' <<  hashValBetween(xx,yy,a) << endl;
            sz--;
            if(hashValBetween(x,y,b) == hashValBetween(xx,yy,a)){
               res = y;
               break;
            }
        }

        for(int i = 0 ;  i < s.size() ; i++){
           cout << s[i] ;
        }
        for(int i = res ; i< temp.size() ; i++){
           cout << temp[i];
        }
        cout << endl;



    }
}
