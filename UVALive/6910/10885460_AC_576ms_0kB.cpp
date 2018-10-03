#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 20005
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

int a[N] , par[N];

int find(int a){
    if(par[a] == a) return a;
    else return find(par[a]);
}
int main()
{
    // READ();
    int test ,cs = 1;
    scana(test);
    while(test--){
       int n , k;
       scanaa(n,k);
       for(int i = 0 ; i<= 20000 ; i++)
          par[i] = i;

       rep(i,0,n){
          scana(a[i]);
          if(a[i] == 0) continue;
          par[i+1] = a[i];
       }
       printf("Case #%d:\n",cs++);
       while(k--){
           char ch;
           getchar();
           scanf("%c",&ch);
           if(ch == 'C'){
              int temp;
              scana(temp);
              par[temp] = temp;
           }
           else{
              int tempa , tempb;
              scanaa(tempa, tempb);
              if(find(tempa)==find(tempb)){
                 printf("YES\n");
              }
              else printf("NO\n");
           }
       }
    }
    return 0;
}
