#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
long long mod  = 1000000009;
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

int main()
{
   long long n, m;
   while(cin >> n){
   	    n--;
   	    if(n == -1) break;
   	    long long arr[]={1,1,1,1,0,0,0,1,0};
        MAT root(3,3);
        root.init(arr);
        if(n == 0){
        	cout << 0 << endl;
        	continue;
        }

        MAT temp = root*root;
       // temp.print();
        MAT res = pow(root,n);
        // res.print();
        long long ans = res.a[0][1];
        ans %= mod;
        cout << ans << endl;
   }
}
