// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;

#define NN 66000
#define white                0
#define grey                 1
#define black                2
#define ll                   long long
#define ull                  unsigned long long
#define PI                   2.0*acos(0.0)   // acos(-1)
#define pi                   pair <int,int>
#define rep(i,x,y)           for(int i = x ; i < y ; i++)
#define fst(x)               v[x].first
#define sd(x)                v[x].second
#define X(i)                 x+fx[i]
#define Y(i)                 y+fy[i]
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))
//***********************************************

#define ashraf
#ifdef ashraf
     #define so(args...) {cerr<<"so: "; dbg,args; cerr<<endl;}
#else
    #define so(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;


//******************************************************
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int kfx[] = {2,2,-2,-2,1,1,-1,-1};
int kfy[] = {1,-1,1,-1,2,-2,2,-2};
bool a[NN+10];
vector <int> prime;

inline void seive(){
long long num = NN;
memset(a,0,sizeof(a));
for(int i = 3 ; i*i <= num ; i+= 2)
  if(!a[i])
     for(int j = i*i ; j<= num ; j+= 2*i)
       a[j] = 1;
for(int i = 3 ; i<= num ; i+= 2)
    if(!a[i])
       prime.push_back(i);
}
long long nod(long long num){
  long long res = 1;
  while(num%2 == 0) num/=2;
  for(int i = 0 ; prime[i]*prime[i] <= num && i < prime.size() ; i++){
        if(num%prime[i] == 0){
            int counter = 0;
            while(num%prime[i] == 0){
                counter++;
               // cout << prime[i] << endl;
                num /= prime[i];
            }
           res *= (counter+1);
        }
  }
  if(num > 1) res *= 2;
  return res;
}
int main(){
  int test , cs = 1;
  cin >> test;
  seive();
 // rep(i,0,20) cout << prime[i] << ' ';

  while(test--){
    int a;
    long long n;
    scanf("%d%lld",&a,&n);
    printf("%d ",cs++);
    if(!n){
      cout << 0 << endl;
      continue;
    }
    long long ans = nod(n);
    cout << ans-1 << endl;

  }

}

