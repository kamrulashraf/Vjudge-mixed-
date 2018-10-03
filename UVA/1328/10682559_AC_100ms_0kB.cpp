#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 1000005
#define PI acos(-1.0)
#define ll long long

char s[1000005];

ll hashVal[N];
ll p[N];
ll base = 101;
ll mod = 1e9+7;


void init(){
     p[0] = 1;
     for(int i = 1 ; i<= 1000001 ; i++){
         p[i] = (p[i-1]*base)%mod;
     }
}

ll hashValBetween(int i , int j){
     ll temp = (hashVal[j]- (p[j-i+1]*hashVal[i-1])%mod + mod)%mod;
     if(temp < 0) temp += mod;
     return temp;
}

int mark[N];
int main()
{
  // freopen("in.txt","r" , stdin);
//  freopen("out.txt","w",stdout);
   init();
   int len, cs = 1;
   while(scanf("%d",&len)==1){
       if(!len) break;
       memset(mark,0,sizeof mark);
       memset(hashVal,0,sizeof hashVal);
       getchar();
       scanf("%s",s);
       for(int i = 1 ; i<= len ; i++){
          hashVal[i] = (hashVal[i-1]*base+s[i-1])%mod;
       }

//       cout << hashValBetween(3,3) << endl;

       for(int i = 1 ; i<= len ; i++){
             ll temp = hashVal[i];
             for(int j = 2*i ; j<= len ; j+= i){
               
                     ll temp1 = hashValBetween(j-i+1,j);
                     if(temp == temp1){
                        if(mark[j] == 0)
                            mark[j] = j/i;
                     }
                     else break;
             }
       }
       printf("Test case #%d\n",cs++);
       for(int i = 1 ; i<= len ; i++){
          if(mark[i]){
             printf("%d %d\n",i , mark[i]);
          }
       }
       printf("\n");


   }

}
