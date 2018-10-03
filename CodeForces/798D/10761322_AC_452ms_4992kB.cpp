#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 100005
#define PI acos(-1.0)
#define ll long long

const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

#define N 100005

int a[N], b[N], n;
ll sum , sum1;

struct node
{
    int a , b;
    int indx;
    node(int x , int y , int z){
       a = x;
       b = y;
       indx = z;
    }
};

vector < node > v;
bool fun(){
   int k = (n/2)+1;
   ll temp=0 , temp1 = 0;
   for(int i = 0; i < k ;i++){
        temp += v[i].a;
        temp1 += v[i].b;
   }

   if( 2*temp > sum && 2*temp1 > sum1){
       cout << k << endl;
//       cout << sum << ' ' << temp << ' '  << sum1 << ' ' << temp1 << endl;
       for(int i = 0 ; i< k ; i++){
          printf("%d ",v[i].indx);
       }
       return true;
   }

   return false;
}
int main()
{
//     freopen("in.txt", "r" ,stdin);
     scanf("%d",&n);
     F(i,n){
        scanf("%d",&a[i]);
        sum +=(ll) a[i];
     }

     F(i,n){
        scanf("%d",&b[i]);
        sum1 +=(ll) b[i];
     }

     F(i,n){
        v.push_back(node(a[i],b[i],i+1));
     }


     while(fun() == false){
        random_shuffle(v.begin(),v.end());
     }
}
