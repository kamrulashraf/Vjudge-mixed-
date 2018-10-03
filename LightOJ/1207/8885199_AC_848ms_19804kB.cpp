
#include <bits/stdc++.h>
#include <utility>
#include <algorithm>
#include <vector>
 
//  http://ideone.com/kxcEk8
using namespace std;
#define inf                  1e7
#define white                0
#define grey                 1
#define black                2
#define ll                   long long
#define ull                  unsigned long long
#define PI                   2.0*acos(0.0)   // acos(-1)
#define pii                  pair <int,int>
#define pll                  pair <ll,ll>
#define rep(i,x,y)           for(int i = x ; i < y ; i++)
#define ff                   first
#define ss                   second
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
inline void take(int &x) {scanf("%d",&x);}
inline void take(int &x ,int &y)  {scanf("%d %d",&x, &y);}
 
#define NN 200005
long long tree[4*NN] ,lazy[4*NN];
void update(int node,int b,int e,int i,int j,int val){
    int left = 2*node;
    int right = left+1;
    int m = (b+e)/2;
    if(lazy[node]){
      tree[node] = (e-b+1)*lazy[node];
      if(b!=e){
        lazy[left] = lazy[node];
        lazy[right] = lazy[node];
      }
      lazy[node] = 0;
    }
    if( b > j || e < i) return;
    if(b >= i && e <= j){
        tree[node] = (e-b+1)*val;
        if(b!=e){
          lazy[left] = val;
          lazy[right]= val;
        }
        return;
    }
    update(left ,b,m,i,j,val);
    update(right,m+1,e,i,j,val);
    tree[node] = tree[left]+tree[right];
}
map < int , bool > hit;
int counter = 0;
void makeTree(int node,int b,int e){
    int left = 2*node;
    int right = left+1;
    int m = (b+e)/2;
    if(lazy[node]){
      tree[node] = (e-b+1)*lazy[node];
      if(b!=e){
        lazy[left] = lazy[node];
        lazy[right] = lazy[node];
      }
      lazy[node] = 0;
    }
    if(b==e){
      if(!hit[tree[node]] && tree[node]) counter++ , hit[tree[node]] = 1;
   //   cout << b << ' ' << e << ' ' << tree[node] << endl;
      return;
    }
    makeTree(left,b,m);
    makeTree(right,m+1,e);
}
int main()
{
  int test,cs = 1;
  scanf("%d",&test);
  while(test--){
     memset(tree,0,sizeof(tree));
     memset(lazy,0,sizeof(lazy));
     counter = 0;
     int q;
     scanf("%d",&q);
     int mmax = 0,x,y;
     vector < pii > v;
     rep(i,0,q){
       scanf("%d%d",&x,&y);
       v.push_back({x,y});
       mmax = max(mmax,y);
     }
     int i = 0;
     for(int j = 0 ;  j< v.size() ; j++){
       x = v[j].ff;
       y = v[j].ss;
       update(1,1,mmax,x,y,++i);
     }
     makeTree(1,1,mmax);
     printf("Case %d: %d\n",cs++ , counter);
     v.clear();
     hit.clear();
  }
}