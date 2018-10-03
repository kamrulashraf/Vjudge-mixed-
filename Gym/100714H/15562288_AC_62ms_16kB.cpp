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
#define mp make_pair
#define pb push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int main()
{
    // read();
    // write();
    int n;
    cin >> n;

    int flag = 0;
    for(int i =  2 ; i*i <= n; i++){
         if(n%i == 0){
             flag = 1;
             break;
         }
    }
    if(n == 4){
         cout << "NO" << endl;
         return 0;
    }
    if(flag == 0 && n > 1){
         cout << "NO" << endl;
    }
    else cout << "YES" << endl;
}
