#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 3000005
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define ll long long
#define READ()  freopen("in.txt","r" , stdin);
#define scana(x) scanf("%d",&x);
#define scanaa(x,y) scanf("%d%d",&x,&y);
#define scanaaa(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define MEMO(arr)  memset(arr , 0 , sizeof arr);
#define MEM(arr)  memset(arr,-1,sizeof arr);

const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
std::vector< ll > v;

int fx[] = {0,1,0,-1};
int fy[] = {1,0,-1,0};
pii call(ll a){
   if(a == 1) return MP(0,0);
   int save;
   for(ll i = 0 ; i < v.size() ; i++){
      save = i;
      if(a >= v[i] && a< v[i+1])
         break;
   }
   ll x = -save;
   ll y = -save;
   ll tt = 2*save;
//   cout << x << ' ' << y << ' ' << save << endl;
   int counter = 0;



        x += fx[counter/tt];
        y += fy[counter/tt];
        counter++;
   for(ll i = v[save] ; i< a ; i++){
//        cout <<  i << ' ' << x << ' ' << y << ' ' << ' ' << counter <<  endl;
        ll temp = counter/tt;
//        cout << fx[temp] << endl;
        x += fx[temp];
        y += fy[temp];
        counter++;
   }
   return MP(x,y);

}
int main()
{
       ios_base::sync_with_stdio(0); cin.tie(0);

       ll  a , b;

       v.push_back(1);
       for(ll i = 1 ; i<= 32001 ; i+=2){
             ll temp = (i*i)+1LL;
             v.push_back(temp);
       }


       cin >> a >> b;
       pii res = call(a);
       pii temp = call(b);

       int ans = abs(res.ff - temp.ff)+abs(res.ss-temp.ss);
       cout << ans << endl;


}
