#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i = x ; i < y ; i++)
#define N 40
#define ff first
#define ss second
#define ll long long
#define read(x) freopen(x , "r" ,stdin)
ll mod = 1000000007;
struct MAT
{
   long long r,c;
   long long a[40][40];
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
       MAT sum(r,c);
       long long temp[r*c];
       memset(temp,0,sizeof temp);
       sum.init(temp);
       for(long long i = 0 ; i< r ; i++){   // row 1st mat
         for(long long j = 0 ; j< b.c ; j++){  // col 2nd mat
                   for(long long k=0; k<c ;k++){   // col 1st matss
                      sum.a[i][j] =  (sum.a[i][j] + (a[i][k]*b.a[k][j]) ) %mod;
                   }
         }
       }
       return sum;

     }
} var(35,35);


MAT power(MAT b , ll p){
    if(p == 1) return b;
     MAT x = power(b,p/2);
     x = x*x;
     if(p&1) x = x*b;
     return x;
}
vector < vector < int > > v1;
#define vii vector <int>

bool posible(vii x , vii y){
    //is this posible to come x position moving from y
    do{
       bool flag = 0;
       for(int i = 0 ; i< x.size() ; i++){
          if( abs(x[i]-y[i]) != 1){
             flag = 1;
             break;
          }
       }
       if(flag==0) return 1;
    } while(next_permutation(y.begin(),y.end()));
    return 0;
}
void init(){
    for(int i = 0 ; i< 7 ; i++){
        for(int j = i+1 ; j< 7 ; j++){
            for(int k = j+1 ; k< 7 ; k++){
               for(int l = k+1 ; l< 7 ; l++){
                   std::vector< int > v;
                   v.push_back(i);
                   v.push_back(j);
                   v.push_back(k);
                   v.push_back(l);
                   v1.push_back(v);
               }
            }
        }
    }


    for(int i = 0 ; i< v1.size() ; i++){
        for(int j = 0 ; j< v1.size() ; j++){
            if(posible(v1[i],v1[j])){
               var.a[i][j] = 1;
            }
        }
    }
}
int main(){
    // read("in.txt");
    int test , cs = 1;
    scanf("%d",&test);
    init();
    while(test--){
       ll n;
       scanf("%lld",&n);
       vii mask;
       for(int i = 0 ; i< 7 ; i++){
          int temp;
          scanf("%d",&temp);
          if(temp) mask.push_back(i);
       }
       int save ;
       for(int i = 0 ; i< v1.size() ; i++){
         if(mask == v1[i]) save = i;
       }


       if(n == 1) printf("Case %d: 1\n",cs++);
       else{
          MAT a = power(var,n-1);
          MAT b(35,1);
          for(int i = 0 ; i< 35 ; i++)
            b.a[i][0] = 1;

          a = a*b;
          ll res = a.a[save][0];
          printf("Case %d: %lld\n",cs++ ,res);
       }


    }

    return 0;
}
