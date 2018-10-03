#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
ll mod = 1000000007;


struct  matrix
{
   ll a[5][5];
   int r , c;
   matrix(){
     r = 2;
     c = 2;
      memset(a,0,sizeof a);
   }


  void init(ll temp[]){
      int n = r*c;
      rep(i,0,n)
        a[i/c][i%c] = temp[i];
  }

  void print(){
        cout << "************" << endl;
        rep(i,0,r){
           rep(j,0,c)
             cout << a[i][j] << ' ';
             cout << endl;
        }

        cout << "***********" << endl;

   }

   matrix operator*(matrix b){
      matrix sum;
      for(int i = 0 ; i< r ; i++){
         for(int j = 0 ; j< b.c ; j++){
            for(int k = 0 ; k<c ; k++){
                sum.a[i][j]  += (a[i][k] * b.a[k][j]);
                if(sum.a[i][j] > mod) sum.a[i][j] %= mod;
            }
            sum.a[i][j] %= mod;
         }
      }
      return sum;
   }

   matrix operator+(matrix b){
      matrix sum;
      for(int i = 0 ; i< 2 ; i++){
          for(int j = 0 ; j< 2 ; j++){
             sum.a[i][j] = (a[i][j] + b.a[i][j])%mod;
           }
      }
      return sum;
   }
} zero;


struct nextMatrix{
    matrix a[5][5];
    nextMatrix(){
        rep(i , 0 , 2)
          rep(j,0,2)
            a[i][j] = zero;
    }

    void print(){
        rep(i ,  0 , 2)
          rep(j,0,2)
            a[i][j].print();
    }

    nextMatrix operator*(nextMatrix b){
          nextMatrix sum;
          rep(i,0,2)
            rep(j,0,2)
              rep(k,0,2)
                sum.a[i][j] = sum.a[i][j] + (a[i][k]*b.a[k][j]);

          return sum;
    }

} base ;

matrix power1(matrix b , ll p){
    if(p == 1) return b;
    matrix x = power1(b,p/2);
    x  = x*x;
    if(p&1) x = x*b;
    return x;
}


nextMatrix power(nextMatrix b , ll p){
    if(p == 1) return b;
    nextMatrix x = power(b,p/2);
    x  = x*x;
    if(p&1) x = x*b;
    return x;
}

matrix a;
ll call(ll n, ll k){
    if(n == 0) return 0;

    matrix b = power1(a,k);
    matrix bb = b*a;
    matrix x = bb*b;


    base.a[1][1] = b;
    nextMatrix ta;
    ta.a[1][0] = bb;

    nextMatrix res = power(base,n);
    res = res*ta;
//    res.print();
    return res.a[0][0].a[0][0];
}
int main()
{

//       ios_base::sync_with_stdio(0); cin.tie(0);
//freopen("in.txt","r" , stdin);
       int test , cs = 1;
       scanf("%d",&test);
       matrix identity;
       identity.a[0][0] = identity.a[1][1] = 1;
       base.a[0][0] = identity;
       base.a[0][1] = identity;
       ll temp[] = {1,1,1,0};
       a.init(temp);
       while(test--){
          ll  l , r ,  k;
          scanf("%lld%lld%lld",&l,&r,&k);
          ll be , en;
          if(l%k == 0) be = l;
          else be = ( (l/k)+1)*k;

          l--;
          ll templ = l/k;
          ll tempr = r/k;
          ll term = tempr-templ;
//          cout << be << ' ' << term << endl;
          if(term == 0){
              printf("Case %d: 0\n",cs++);
              continue;
          }
          matrix b = power1(a,k);
          base.a[1][1] = b;
          matrix bb = power1(a,be+1);

          nextMatrix ta;
          ta.a[1][0] = bb;

            nextMatrix res = power(base,term);
            res = res*ta;

            ll res1 = res.a[0][0].a[0][0]%mod;
            if(res1 < 0) res1 += mod;
            printf("Case %d: %lld\n",cs++ ,res1);


       }
}
