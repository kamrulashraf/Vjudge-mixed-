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
int main()
{
     int n , q,a[10005], cse = 1, key, b , e ;
     while(cin  >> n >> q && n && q)
     {
         printf("CASE# %d:\n",cse++);
         int pos[10005] = {0};
         rep(i,0,n){
             cin >> a[i];
         }
         sort(a,a+n);
         rep(i,0,q){
           cin >> key;
           b = 0, e = n-1;
           while(b<=e){
            int m = (b+e)/2;
            if( a[m] < key)
                b = m+1;
            else e = m-1;
           }
         if(a[b] == key)
            printf("%d found at %d\n", key , b+1);
         else printf("%d not found\n", key);
         }

     }
}
