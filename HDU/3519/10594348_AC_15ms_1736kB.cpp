#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 10007;
struct MAT
{
     long long r,c;
     long long a[5][5];
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
          for(long long i = 0 ; i< r ; i++){
             for(long long j = 0; j < c ; j++){
                 cout << a[i][j] << ' ';
             }
             cout << endl;
          }
     }
     MAT operator*(MAT b){
         MAT sum(r,b.c);
         long long temp[r*c];
         sum.init(temp);
         for(long long i = 0 ; i< r ; i++){   // row 1st mat
             for(long long j = 0 ; j< b.c ; j++){  // col 2nd mat
                   ll ss = 0;
                   for(long long k=0; k<c ;k++){   // col 1st matss
                      ss =  (ss%mod + (a[i][k]*b.a[k][j]) %mod);
                   }
                   sum.a[i][j] = ss;
             }
         }
         return sum;

     }
};


MAT power(MAT b , ll p){
        if(p == 1) return b;
        MAT x = power(b,p/2);
        x   = x*x;
        if(p&1) x = x*b;
        return x;
}

//f(n) = 2*f(n-1) + g(n-1);
//g(n) = h(n-1) - g(n-1)
// h(n) = 2^(n) - f(n)
int main()
{
//     freopen("in.txt","r" ,stdin);
     ll n;
     MAT b(3,1);
     ll tt[] = {2,2,8};
     b.init(tt);
     while(cin >> n){
         if(n < 3){
            printf("0\n");
            continue;
         }
         MAT a(3,3);
         ll temp[] = {2,1,0,-1,-1,1,0,0,2};

         a.init(temp);
         if(n == 3){
           printf("2\n");
           continue;
         }
         else{
             n -= 3;
             a = power(a,n);
             a = a*b;
             int res = a.a[0][0]%mod;
             if(res < 0) res += mod;
             printf("%d\n",res);

         }
     }
}
