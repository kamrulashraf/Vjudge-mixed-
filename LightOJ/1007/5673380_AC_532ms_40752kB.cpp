
// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)   // acos(-1)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define fst(x)        v[x].first
#define sd(x)         v[x].second
#define X(i)          x+fx[i]
#define Y(i)          y+fy[i]
#define NUM           5000005
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> inline T big(T b, T p, T N){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2,N);
    return (x%N * x%N)%N;
   }
   return (b%N * big(b,p-1,N)%N)%N;
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
ull phi[NUM];
void EulerSeive(){
 for(int i = 1 ; i<= NUM ; i++)
    phi[i] = i;

 for(int i = 2 ; i<= NUM ; i++){
    if(phi[i] == i){
        phi[i] = phi[i]-1;
        for(int j = 2*i ; j<= NUM; j+=i)
            phi[j] = phi[j]/i*(i-1);
    }
 }
}

void make_dp(){
 for(int i = 1 ; i<= 5000000 ; i++){
    phi[i] = phi[i-1]+ phi[i]*phi[i];
 }
}
int main()
{
  EulerSeive();
  make_dp();
  ll test,a,b,cse = 1;

  cin >> test;
  while(test--){
    scanf("%lld %lld",&a , &b);
    printf("Case %lld: %llu\n",cse++ , phi[b]-phi[a-1]);
  }
}
