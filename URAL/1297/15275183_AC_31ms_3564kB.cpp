#include <bits/stdc++.h>
using namespace  std;

#define N 400005
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
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)

const long long MOD[] = {1572872831LL, 100000037};
const long long BASE[] = {1572872831LL, 1971536491LL};

ll mod = MOD[1];
ll mod1 = MOD[0];
ll base = BASE[1];
ll hashString[N], hashPattern[N], pp[N] , qq[N];
ll power[N];
long long hashFuntion(string s, ll hashVal[]){
    ll temp = 0;
    for(int i =  0 ; i< s.size() ; i++){
         temp = temp*base + s[i]-'a'+1;
         temp = temp%mod;
         hashVal[i+1] = (temp+mod)%mod;
    }
    return (temp+mod)%mod;
}

long long hashFuntion1(string s, ll hashVal[]){
    ll temp = 0;
    for(int i =  0 ; i< s.size() ; i++){
         temp = temp*base + s[i]-'a'+1;
         temp = temp%mod1;
         hashVal[i+1] = (temp+mod)%mod1;
    }
    return (temp+mod1)%mod1;
}

void preCalculate(){
   power[0] = 1;
   for(int i = 0 ; i< N;i++){
      power[i+1] = (power[i]*base)%mod;
   }
}


ll hashValBetween(int i , int j,ll hashVal[]){
    return (hashVal[j] - (hashVal[i-1]*power[j-i+1])%mod + mod)%mod; // 1 based indx
}

string s;
string rev;
int check(int m){
     int n = s.size();
     for(int i = 0 ; i< s.size() ; i++){
           int j = i+m-1;
           if(j >= s.size()) break;
           int p = n-i-1;
           int q = n-j-1;
           swap(p,q);
           if(hashValBetween(i+1, j+1, hashString) == hashValBetween(p+1, q+1, hashPattern)){
              return i;
           }
     }
     return -1;
}

int main()
{
     cin >> s;
     rev = s;
     reverse(rev.begin(),rev.end());

     preCalculate();
     hashFuntion(s, hashString);

     hashFuntion(rev, hashPattern);

     int mmax = 1;
     for(int i = 1 ; i<= s.size() ; i++){
          if(check(i)>=0){
             mmax = i;
          }
     }

     int pos = check(mmax);
     for(int i = pos ; i< pos+mmax ; i++){
        cout << s[i];
     }
     cout << endl;
     return 0;
}
