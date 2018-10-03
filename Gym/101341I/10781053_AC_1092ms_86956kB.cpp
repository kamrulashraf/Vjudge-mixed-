
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 1005
#define PI acos(-1.0)
#define ll long long

const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};


ll mod = 1e9+7;


struct MAT
{
   long long r,c;
   long long a[1005][1005];
   MAT(long long x,long long y){
    r = x;
    c = y;
    memset(a,0,sizeof a);
   }
     void init(long long temp[]){
      for(long long i = 0 ; i<r*c ; i++){
        a[i/c][i%c] = temp[i];
      }
     }
     void print(){
          cout << "************" << endl;
          for(long long i = 0 ; i< r ; i++){
             for(long long j = 0; j < c ; j++){
               cout << a[i][j] << ' ';
             }
             cout << endl;
          }

          cout << "**************" << endl;
     }
} ;

MAT sum(N,N);
MAT a(N,N) , b(N,N) , c(N,N),savea(N,N) , saveb(N,N) , savec(N,N), d(N,1),tt(N,N),dd(N,N);
MAT mul(){
   memset(sum.a,0,sizeof sum.a);
   sum.r = tt.r;
   sum.c  = dd.c;

  for(long long i = 0 ; i< tt.r ; i++){   // row 1st mat
     for(long long j = 0 ; j< dd.c ; j++){  // col 2nd mat
               for(long long k=0; k<tt.c ;k++){   // col 1st matss
                  sum.a[i][j] += (tt.a[i][k]*dd.a[k][j])%mod;
                  if(sum.a[i][j] >= mod) sum.a[i][j] = sum.a[i][j]%mod;
               }
     }
   }
   return sum;

}




int main()
{
//       freopen("in.txt" , "r" , stdin);
       int r;
       scanf("%d",&r);
       a.r = r , a.c = r;
       b.r = r , b.c = r;
       c.r = r , c.c = r;
       d.r = r, d.c = 1;
       int n = r;


       F(i,n)
         F(j,n)
           scanf("%lld",&a.a[i][j]);
       F(i,n)
         F(j,n)
           scanf("%lld",&b.a[i][j]);
       F(i,n)
         F(j,n)
           scanf("%lld",&c.a[i][j]);



//       a.print();
//       b.print();
//       c.print();

       srand(time(0));
       int counter = 0;
       int flag1 = 0;
       savea = a;
       saveb = b;
       savec = c;
       while(counter++ < 5){
          for(int i = 0 ; i< n ; i++){
                 d.a[i][0] = rand()%mod;
          }
          a = savea;
          b = saveb;
          c = savec;


          tt = b;
          dd = d;
          b = mul();
          tt = a;
          dd = b;
          a = mul();




          tt=  c;
          dd = d;
          b = mul();

//          a.print();
//          b.print();



          bool flag = 0;
          F(i,n)
             if(a.a[i][0] != b.a[i][0])
                flag = 1;

          if(flag == 0) continue;
          else{
           flag1 = 1;
           break;
         }
       }
       if(flag1 == 0) cout << "YES" << endl;
       else cout << "NO" << endl;

}
