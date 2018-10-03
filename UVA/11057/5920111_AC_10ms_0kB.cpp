// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define fst(x)        v[x].first
#define sd(x)         v[x].second
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
map < ll , ll> hit;
int main()
{
  ll n, a[10005] , num, s1 , s2;
  while(cin >> n){
      rep(i,0,n){
        scanf("%lld", &a[i]);
      }
      cin >> num;
      sort(a, a+n);

      ll mmin = (ll) pow(2,31);
      for(int i = 0 ; i< n ; i++){
        int temp = num - a[i];
        int pos = lower_bound(a,a+n,temp)-a;
        if(a[pos] == temp){
                ll nn = abs(a[i] - temp);
                if(nn < mmin){
                    mmin = nn;
                    s1 = a[i];
                    s2 = temp;
                }

        }
      }
      if(s1 > s2) swap(s1,s2);
      printf("Peter should buy books whose prices are %lld and %lld.\n\n", s1 , s2);
  }

}

