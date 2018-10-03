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
ll a[N] , p[N];
ll b[N];
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


bool fun(int n){
    ll temp  = hashValBetween(1,n,a);


    for(int i = 0 ;  ; i++){
         int x = i+1;
         int y = x + n-1;
         if(y > s.size()) break;
         ll temp1 = hashValBetween(x,y,b);
         if(temp == temp1) return x;
    }

    return 0;
}

int main()
{

    // freopen("in.txt" , "r" , stdin);
    init();
    int test , cs  = 1;
    cin >> test;
 //   cin.get();

    while(test--){
        cin >> s;

        hashFuntion(s,a);

         string temp = s;
         reverse(temp.begin() , temp.end());
         hashFuntion(temp,b);

         int be = 0 , e = s.size();


         while(be <= e){
             int m = (be+e) >> 1;
//             cout << b << ' ' << e << ' ' << m << endl;
             if(fun(m)){
                 be = m+1;
             }
             else e = m-1;
         }

         // cout << be << ' ' << e << endl;
         for(int i  = e-1 ; i >= 0 ; i--){
            printf("%c",s[i]);
         }
         printf("\n");
    }
}
