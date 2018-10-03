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
void factor(ll p , ll l){
 vector < ll > v;
 ll q = p-l;
 ll root = sqrt(q);
 for(int i = 1 ; i <= root ; i++){
    if(q%i == 0){
        if(i>l)
        v.push_back(i);
        ll temp = q/i;
        if(i*i != q && temp > l){
            v.push_back(temp);
        }
    }
 }
 sort(v.begin() , v.end());
 if(v.size())
    rep(i,0,v.size()){
      printf(" %lld",v[i]);
    }
 else cout << " impossible";
 cout << "\n";
 v.clear();
}

int main()
{
  ll test , p , l;
  int cse = 1;
  cin >> test;
  while(test--){

    scanf("%lld %lld", &p , &l);
    printf("Case %d:",cse++);
    factor(p,l);


  }
}
