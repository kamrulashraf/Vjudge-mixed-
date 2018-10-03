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
template < class T> inline T big(T b, T p, T M){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2,M);
    return (x%M * x%M)%M;
   }
   return (b%M * big(b,p-1,M)%M)%M;
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
bool a[1005];
vector <int> prime;
void seive(void){
  int n  = 1003;
  for(int i = 3 ; i*i <= n ; i+=2)
    if(a[i] == 0)
       for(int j = i*i ; j<= n ; j+= 2*i)
         a[j] = 1;
  prime.push_back(2);
  for(int i = 3 ; i<= n ; i+=2)
     if(a[i] == 0) prime.push_back(i);
}

int factor(int num){
int counter = 0;
for(int i = 0 ; prime[i]*prime[i] <= num && i < prime.size() ; i++){
      if(num%prime[i] == 0){
        counter++;
        while(num%prime[i] == 0)
           num /= prime[i];
      }
}
if(num > 1) counter++;
return counter;
}
int main()
{
  seive();
 // for(int i = 0 ; i < 20 ; i++ ) cout << prime[i] << ' ';
  int num;
  while(scanf("%d", &num)==1){
    if(!num) break;
    printf("%d : %d\n",num ,factor(num));
  }

}

