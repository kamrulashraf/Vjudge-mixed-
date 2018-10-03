// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define inf                  1e7
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
#define WRITE                freopen("a.txt","w",stdout);
//***********************************************
#define MOD
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
void take(int &a){ scanf("%d",&a);}
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
char s[100005];
ll tree[100005];
ll arr[100005], as;
ll sum(int indx){
  ll sum = 0;
  as = 0;
  while(indx != 0){
     sum += tree[indx];
     as += arr[indx];
     indx -= indx & (-indx);
  }
 return sum;
}
 
void update(int n , int indx , int val, bool flag){
   while(indx <= n){
      tree[indx] += val;
      if(flag == 1) arr[indx] += val;
      indx += indx & (-indx);
   }
}
int main()
{
//   WRITE;
 
   int len, test , cs = 1;
   take(test);
   while(test--){
        printf("Case %d:\n",cs++);
      memset(tree,0,sizeof(tree));
      memset(arr,0,sizeof(arr));
      getchar();
      gets(s);
      len = strlen(s);
      for(int i = 1 ; i <= len ; i++){
         update(len , i ,s[i-1]-48 , 1);
      }
      int q;
      take(q);
      while(q--){
          char ch;
          getchar();
          ch = getchar();
          if(ch == 'I'){
             int a , b;
             scanf("%d%d",&a,&b);
             update(len ,a,1, 0);
             if(b+1 <= len)
             update(len ,b+1,-1, 0);
//             rep(j,1,len+1) cout << sum(j) << ' ';
//             puts("");
          }
          else{
             int a;
             take(a);
    //          int temp = query(1,0,strlen(s)-1 , a , a , 0);
              ll temp = sum(a) - as + s[a-1]-48;
              temp = temp&1;
              printf("%lld\n",temp);
          }
      }
   }
}