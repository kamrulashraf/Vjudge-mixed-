#include <bits/stdc++.h>
using namespace  std;

#define N 100005
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
int main()
{
	// freopen("in.txt","r" , stdin);
     int n , a , b;
     scaaa(n,a,b);
     string s;
     a--; b--;
     cin >> s;
     if(s[a] == s[b]) cout << '0' << endl;
     else cout << '1' << endl;
}
