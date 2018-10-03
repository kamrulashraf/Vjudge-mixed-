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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n , mid , temp ;
    cin >> n;

    if(n&1){
       temp = (n-1)/2 * n;
    }
    else temp = n/2 * (n-1);

    if(temp&1) mid = temp/2+1;
    else mid = temp/2 ;

    int tt = n;
    ll sum = 0;
    int save1 , save2 ;
//    cout << mid << endl;
    for( int i = 1 ; i <= n ; i++){
          sum += tt-i;
//          cout << sum << endl;
          if(sum >= mid){
             save2 = i;
             break;
          }
          else save1 = i;
    }

//    cout << save1 << ' ' << save2 << endl;
    cout << save2 << endl;
}
