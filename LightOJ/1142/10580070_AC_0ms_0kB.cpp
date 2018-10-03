#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i = x ; i< y ; i++)
#define ll long long
ll mod = 1000000007;
int n;
struct matrix
{
     ll a[31][31];
     int r , c;
     matrix(){
        r = n;
        c = n;
        memset(a,0,sizeof a);
     }

     void init(ll temp[]){
        int n = r*c;
        rep(i,0,n)
          a[i/c][i%c] = temp[i];

     }
     void print(){
        rep(i,0,r){
           rep(j,0,c){
             a[i][j] %= 10LL;
             printf("%lld",a[i][j]);
           }
           printf("\n");
        }

     }
     matrix operator*(matrix b){
          int tempr = r;
          int tempc = b.c;
          matrix sum;
          rep(i,0,r){
            rep(j,0,b.c){
              rep(k,0,c){
                 sum.a[i][j] += a[i][k]*b.a[k][j];
              }
              sum.a[i][j] %= 10;
            }
          }
          return sum;
     }

     matrix operator+(matrix b){
         matrix sum;
         rep(i,0,r)
           rep(j,0,c)
             sum.a[i][j] = a[i][j]+b.a[i][j];
        return sum;
     }
};

struct MAT{
   matrix a[2][2];

  MAT(){
      matrix zero;
      rep(i,0,2)
        rep(j,0,2)
           a[i][j] = zero;
  }

  MAT operator*(MAT b){
     MAT sum;
     rep(i,0,2){
         rep(j,0,2){
            rep(k,0,2){
               sum.a[i][j] = sum.a[i][j] + (a[i][k] * b.a[k][j]);
            }
         }
     }
     return sum;
  }

  void print(){
      rep(i,0,2){
          rep(j,0,2){
              a[i][j].print();
          }
          cout << endl;
      }
  }
};

MAT power(MAT b , ll p){
    if( p == 1 ) return b;
    MAT x = power(b,p/2);
    x = x*x;
    if(p&1) x = x*b;
    return x;
}

// equation
// [ 1 1 ] * [sum] = [sum+1]
// [ 0 A ] * [A  ] = [A*A]
int main()
{
     // freopen("in.txt","r",stdin);
     int test , cs = 1 ;
     scanf("%d",&test);
     while(test--){
         int k;
         scanf("%d%d",&n,&k);
         matrix var,one;
         for(int i = 0 ; i< n ; i++){
              for(int j = 0 ; j< n ; j++){
                    scanf("%lld",&var.a[i][j]);
                    if(i==j)
                      one.a[i][j] = 1;
              }
         }

         MAT a;
         a.a[0][0] = one;
         a.a[0][1] = one;
         a.a[1][1] = var;


        MAT b;
        b.a[1][0] = var;
        a = power(a,k);
//        a.print();
        a = a*b;
        printf("Case %d:\n",cs++);
//        matrix res = a[0][0];
        rep(i,0,n){
            rep(j,0,n){
                int res = a.a[0][0].a[i][j] %= 10;
                printf("%d",res);
            }
            printf("\n");
        }



     }
}

