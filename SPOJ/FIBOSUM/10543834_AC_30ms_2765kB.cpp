#include <bits/stdc++.h>
using namespace std;
#define rep( i ,x , y) for(int i = x ; i< y ; i++)
#define ll long long
#define ul unsigned int
ll mod = 1000000007;

struct MAT
{
   long long r,c;
   long long a[10][10];
   MAT(long long a,long long b){
    r = a;
    c = b;
   }
     void init(long long temp[]){
      for(long long i = 0 ; i<r*c ; i++){
        a[i/c][i%c] = temp[i];
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
                      sum.a[i][j] += (a[i][k]*b.a[k][j])%mod;
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
   scanf("%d",&test);
   ll  n  , m;
   while(test--){
      ll temp[] = {1,1,1,0,1,1,0,1,0};
      ll n ;
      scanf("%lld %lld",&n, &m);
      n--;

     long long res = 0;


      ll  res1 = 0;
      if(n <= 2){
        if(n == 0)
          res = 0;
        if(n == 1 || n==2)
          res = n;
      }
      else{
          MAT a(3,3);
          a.init(temp);
          a = pow(a,n-1);
          MAT b(3,1);
          ll tt[] = {1,1,0};
          b.init(tt);

          MAT temp = a*b;
          res = temp.a[0][0];

      }
      if(m <= 2){
        if(m == 0)
          res1 = 0;
        if(m == 1 || m==2)
          res1 = m;
      }
      else{
          MAT c(3,3);
          c.init(temp);
          c=  pow(c,m-1);

          MAT b(3,1);
          ll tt[] = {1,1,0};
          b.init(tt);

          c = c*b;
          res1 = c.a[0][0];
//          cout <<"sum"<< ' ' <<  res1 << endl;

      }

      res = (res1-res)%mod;
      if(res < 0) res += mod;
      cout << res << endl;
   }

}
//
