
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define DEB           cout << "DEB" << endl;
#define PI            2.0*acos(0.0)   // acos(-1)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define ff(x)        v[x].first
#define ss(x)         v[x].second
#define X(i)          x+fx[i]
#define Y(i)          y+fy[i]
#define N 105
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
bool a[105];
vector <int > save;
void seive(){
    int sq = sqrt(N);
    for(int i = 3 ; i<= sq ; i+=2)
        if(a[i]==0)
          for(int j = i*i ; j <= N ; j+= 2*i)
            a[j] = 1;
    save.push_back(2);
    for(int i = 3 ; i<= N ; i+= 2)
        if(a[i] == 0)
         save.push_back(i);
}
int fun(int p , int num){
 int sum = 0;
 while(num){
    sum += (num/=p);
 }
 return sum;
}

int main()
{
  seive();
  int test , n, cse = 1;
  vector < pi > v;
  cin >> test;
  while(test--){
    scanf("%d", &n);
    for(int i = 0 ; save[i] <= n ; i++){
        int temp = fun(save[i],n);
        v.push_back(make_pair(save[i], temp));
    }
    printf("Case %d: %d =",cse++, n);
    for(int i = 0 ; i < v.size() ; i++){
        printf(" %d (%d)", v[i].first , v[i].second);
        if(i != v.size()-1){
            printf(" *");
        }
    }
    puts("");
    v.clear();
  }
}
