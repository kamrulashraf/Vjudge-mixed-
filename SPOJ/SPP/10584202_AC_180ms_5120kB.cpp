#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define N 35
#define ll long long
ll b[N],c[N];
long long arr[2*N];
ll mod;
struct matrix
{
     ll a[32][32];
     int r , c;
     matrix(int x, int y){
        r = x;
        c = y;
        memset(a,0,sizeof a);
     }

      void print(){
               cout << "*************" << endl;
                rep(i,0,r){
                  rep(j,0,c)
                    cout << a[i][j] << ' ' ;
                    cout << endl;
                }
               cout << "*************" << endl;

      }
    matrix operator*(matrix b){
        matrix sum(r,b.c);
         for(long long i = 0 ; i< r ; i++){   // row 1st mat
              for(long long j = 0 ; j< b.c ; j++){  // col 2nd mat
                    for(long long k=0; k<c ;k++){   // col 1st matss
                       sum.a[i][j] = (sum.a[i][j]%mod + (a[i][k]*b.a[k][j])%mod)%mod;
                    }
              }
          }
          return sum;

    }

};

matrix power(matrix b , ll p){
     if(p == 1) return b;
     matrix x = power(b,p/2);
     x = x*x;
     if(p&1) x = x*b;
     return x;
}


ll call(matrix a , ll n, int k){
  ll sum = 0;
   if(n <= k){

      for(int i = 0 ; i< n ; i++){
         sum =  (sum+b[i])%mod;
      }
      return sum%mod;
   }
   assert(n-k > 0);
   rep(i,0,k) sum += b[i];
   a = power(a,n-k);
   matrix f(k+1,1);
   f.a[0][0] = sum;
   for(int i = k-1, j = 0 ; i >= 0; i--){
       f.a[++j][0] = b[i];
   }
//   cout << n-k << '#' << endl;
//   a.print();
//  f.print();
   a = a*f;
//   a.print();
   return a.a[0][0];
}
int main()
{


    int test , cs = 1 ;
    scanf("%d",&test);
    while(test--){
         int n;
         scanf("%d",&n);
         rep(i,0,n) scanf("%lld",&b[i]);
         rep(i,0,n) scanf("%lld",&c[i]);
         rep(i,0,n) arr[i] = b[i];
//         for(int i = n ; i< 2*n ; i++){
//              for(int j = 0 ; j< n ; j++){
//                 arr[i] += arr[i-j-1]*c[j];
//              }
//         }

         matrix a(n+1,n+1);

         for(int i = 0 ; i <= n ; i++){
            if(i == 0)
                 a.a[i][0] = 1;
             if(i == 0 || i == 1 ){
                for(int j = 1, k = 0 ; k < n ; j++,k++){
                     a.a[i][j] = c[k];
                }
             }
             else{
                a.a[i][i-1] = 1;
             }
         }


         ll l  , r;
         scanf("%lld%lld%lld",&l,&r,&mod);
         assert(mod != 0);
         ll res = call(a,r,n)%mod ;
//         cout << res << endl;
         ll res1 = call(a,l-1,n)%mod;
//         cout << res1 << endl;
         if(res <0) res += mod;
         if(res1 < 0) res1 += mod;
         res  = (res -res1) %mod;
         if(res < 0) res += mod;
         printf("%lld\n",res);

    }
    return 0;
}
