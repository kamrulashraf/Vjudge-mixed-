// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI            2.0*acos(0.0)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define fst(x)        v[x].first
#define sd(x)         v[x].second
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
int fx[] = {0,0,1,-1,1,-1,1,-1};
int fy[] = {1,-1,0,0,1,-1,-1,1};
int main()
{
    vector < ll > v;
    ll test, p , q,save,temp,cse = 0, n , a[1010];
    double mmin= 1000000005.0;
    double sum=0.0;
    cin >> test ;
    while(test--)
    {
        mmin = 1000000005.0;
        sum = 0.0;
        cin >> n >> p >> q;
        rep(i,0,n){
          cin >> a[i];
          sum += a[i];
        }
        double avg = sum/n;
        rep(i,0,p){
          if(abs( avg - a[i]) < mmin){
            save = a[i];
          //  cout << save << endl;
            mmin = abs(avg-a[i]);
          }
          temp = i;
        }
        v.clear();
        rep(i,0,p){
          if(abs(avg-a[i]) == abs(avg-save)){
               v.push_back(a[i]);
             }
        }
        sort(v.begin() , v.end());
        printf("Case #%d: ", ++cse);
        cout << v[0] << ' ' ;
        mmin = 1000000005.0;
        ++temp;
        int f = temp;
        rep(j,0,q){
            if(abs( avg - a[temp]) < mmin){
            save = a[temp];
            mmin = abs(avg-a[temp]);
          }
          temp++;
        }
        v.clear();
        rep(j,0,q){
          if(abs(avg-a[f]) == abs(avg-save)){
               v.push_back(a[f]);
             }
             f++;
        }
        sort(v.begin() ,  v.end());
        cout << v[0] << endl;

    }
}
