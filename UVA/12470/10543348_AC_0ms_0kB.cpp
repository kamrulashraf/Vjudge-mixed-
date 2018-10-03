#include <bits/stdc++.h>
using namespace std;
#define rep( i ,x , y) for(int i = x ; i< y ; i++)
#define ll long long
#define ul unsigned int
ll mod = 1000000009;

struct MAT
{
   ll r,c;
   ll a[3][3];
   MAT(ll a,ll b){
    r = a;
    c = b;
   }
     void init( ll temp[]){
     // temp ekta array pathabo 1d jar modhe base matrix er
      // sob value thakbe serially
      // a er moddhe init korbo
      for(int i = 0 ; i<r*c ; i++){
        a[i/r][i%c] = temp[i];
      }
     }
     void print(){
          for(long long i = 0 ; i< r ; i++){
             for(long long j = 0; j < c ; j++){
               cout << a[i][j] << ' ';
             }
             cout << endl;
          }
     }
     MAT operator*(MAT b){
       MAT sum(r,c);
       long long temp[r*c];
       memset(temp,0,sizeof temp);
       sum.init(temp);
       for(long long i = 0 ; i< r ; i++){   // row 1st mat
         for(long long j = 0 ; j< b.c ; j++){  // col 2nd mat
                   for(long long k=0; k<c ;k++){   // col 1st matss
                      sum.a[i][j] = ( (sum.a[i][j] + a[i][k]*b.a[k][j]) ) %mod;
                   }
         }
       }
       return sum;

     }
};


MAT pow(MAT b , long long p){
    if(p == 0 || p == 1)
      return b;
    if(p&1){
        return b*pow(b,p-1);
    }
    else{
        MAT temp = pow(b,p/2);
        return temp*temp;
    }

}


int main()
{
  // freopen("in.txt","r" , stdin);
   int test , cs = 1;
   ll n;
   while(1){
      ll temp[] = {1,1,1,1,0,0,0,1,0};
      ll n ;
      scanf("%lld",&n);
      if(!n) break;
      if(n == 1){
         printf("0\n");
         continue;
      }
      MAT a(3,3);
      a.init(temp);
      a = pow(a,n-1);
      ll res = a.a[0][1];
      res %= mod;
      if(res < 0) res += mod;
      printf("%lld\n", res);
   }

}
// 