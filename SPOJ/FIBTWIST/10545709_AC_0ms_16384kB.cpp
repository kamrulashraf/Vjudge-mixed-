#include <bits/stdc++.h>
using namespace std;
#define rep( i ,x , y) for(int i = x ; i< y ; i++)
#define ll long long
#define ul unsigned int
ll mod = 1000000007, n;

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
    while(test--){
       scanf("%lld%lld",&n,&mod);
       MAT a(4,4), b(4,1);
       ll temp[] = {1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1};
       ll temp1[] = { 1 , 0 , 1 , 1};
       if(n <= 1){
         int temp = n%mod;
         printf("%d\n",temp);
         continue;
       }
       a.init(temp);
       b.init(temp1);
       a = pow(a,n-1);
       a = a*b;
       ll res = a.a[0][0];
       res %= mod;
       if(res < 0) res += mod;
       printf("%lld\n",res);

    }

}
//
