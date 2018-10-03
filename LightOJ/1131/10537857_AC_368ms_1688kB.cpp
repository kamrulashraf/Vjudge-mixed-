#include <bits/stdc++.h>
using namespace std;
int mod;
struct MAT
{
     long long r,c;
     long long a[6][6];
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
                      sum.a[i][j] %= mod;
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
long long power(long long b, long long p){
     if(p == 0 || p == 1) return b;
     if(p&1) return b*power(b,p-1);
     else{
        long long x = power(b,p/2);
        return x*x;
     }
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        int a2 , b2 , c2,q;
        int a1,b1,c1;
        int f0,f1,f2;
        int g0,g1,g2;
        scanf("%d%d%d",&a1,&b1,&c1);
        scanf("%d%d%d",&a2,&b2,&c2);
        scanf("%d%d%d",&f0,&f1,&f2);
        scanf("%d%d%d",&g0,&g1,&g2);
        scanf("%d%d",&mod,&q);
        long long temp[] = {a1,b1,0,0,0,c1,
                          1,0,0,0,0,0,
                          0,1,0,0,0,0,
                          0,0,c2,a2,b2,0,
                          0,0,0,1,0,0,
                           0,0,0,0,1,0};
       MAT mat(6,6);
       mat.init(temp);
//       mat.print();
       printf("Case %d:\n",cs++);
       for(int i = 0 ; i<q ; i++){
          int n;
          scanf("%d",&n);
          long long ans , ans1;
          if(n == 0){
            ans = f0;
            ans1 =g0;
          }
          else if(n==1){
            ans = f1;
            ans1 = g1;
          }
          else if(n == 2){
            ans = f2;
            ans1 = g2;
          }
          else{
              n-=2;
              MAT tempMat = pow(mat,n);
              ans = tempMat.a[0][0]*f2+tempMat.a[0][1]*f1+tempMat.a[0][2]*f0+tempMat.a[0][3]*g2+tempMat.a[0][4]*g1+tempMat.a[0][5]*g0;
              ans1 = tempMat.a[3][0]*f2+tempMat.a[3][1]*f1+tempMat.a[3][2]*f0+tempMat.a[3][3]*g2+tempMat.a[3][4]*g1+tempMat.a[3][5]*g0;
//              tempMat.print();
         }
         ans = (ans+mod)%mod;
         ans1 = (ans1+mod)%mod;
         printf("%lld %lld\n",ans,ans1);
       }
 
    }
}