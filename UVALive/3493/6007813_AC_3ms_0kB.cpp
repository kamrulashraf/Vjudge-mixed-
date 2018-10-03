// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
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
void make_equal(string &a , string &b){
    if(a.size() == b.size()) return;
    if(a.size() < b.size()){
            swap(a,b);
    }
    string temp;
    for(int i = 0 ; i< a.size() - b.size() ; i++){
        temp += '0';
    }
    temp += b;
    b =temp;
}
int main()
{
   int test,cs = 1;
   cin >> test;
   while(test--){
       string a , b;
       cin >> a >> b;
       make_equal(a , b);
       reverse(a.begin() , a.end());
       reverse(b.begin() , b.end());
       int carry = 0;
       vector <int> ans;
       for(int i = 0 ; i< a.size() ; i++){
          int temp = a[i]+b[i]-48-48+carry;
          if(temp >= 2){
              carry = 1;
          }
          else carry = 0;
          ans.push_back(temp%2);
       }
       ans.push_back(carry);
       int flag = 0;
       reverse(ans.begin() , ans.end());
       printf("%d ",cs++);
       for(int i = 0 ; i< ans.size() ; i++){
           if(ans[i] != 0) flag = 1;
           if(ans[i] == 0 && flag == 0)
              continue;
           cout << ans[i];
       }
       if(flag == 0) cout << '0';
       puts("");
   }

}
