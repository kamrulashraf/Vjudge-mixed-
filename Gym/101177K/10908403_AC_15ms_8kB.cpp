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

int main()
{
       ios_base::sync_with_stdio(0); cin.tie(0);

       string s ;
       s = "KANGAROO";
       string sa = "KIWIBIRD";
       map  < char , int > mark, hit;
       for(int i = 0 ; i < s.size() ; i++){
           mark[s[i] | 32]++;
       }

       F(i,sa.size()) hit[sa[i] | 32]++;

       string a ;
       cin >> a;

       int tempa = 0 , tempb = 0;       
       for(int i = 0 ; i< a.size() ; i++){
          tempa += mark[a[i] | 32];
          tempb += hit[a[i] |32];
       }
       if(tempa == tempb){
          cout << "Feud continues" << endl;
       }
       if(tempa > tempb) cout << "Kangaroos" << endl;
       if(tempa < tempb) cout << "Kiwis" << endl;
 }