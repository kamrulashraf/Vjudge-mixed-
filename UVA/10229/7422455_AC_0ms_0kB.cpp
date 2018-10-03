#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
long long mod;
struct MAT
{
   ll r,c;
   ll a[2][2];
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
                      sum.a[i][j] += (a[i][k]*b.a[k][j]) %mod;
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
     if(p == 0) return 1;
     if(p&1) return b*power(b,p-1);
     else{
        long long x = power(b,p/2);
        return x*x;
     }
}
int main()
{
   long long n, m;
   while(cin >> n >> m){
   	    long long arr[]={1,1,1,0};
        MAT root(2,2);
        root.init(arr);
        mod = power(2,m);
        if(n == 0){
        	cout << 0 << endl;
        	continue;
        }
        MAT res = pow(root,n-1);
        long long ans = res.a[0][0]%mod;
        cout << ans << endl;
   }
}