#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NN 30005
std::vector<ll > tree[4*NN];
ll a[NN];
void update(int node,int b,int e){
   int left = 2*node;
   int right = left+1;
   int m = (b+e)/2;
   if(b == e){
     tree[node].push_back(a[b]);
     return;
   }
   update(left,b,m);
   update(right,m+1,e);
   int len1 = tree[left].size();
   int len2 = tree[right].size();
   tree[node].resize(len1+len2);
   merge(tree[left].begin() , tree[left].end() , tree[right].begin(), tree[right].end() , tree[node].begin());
   return;
}

int  query(int node,int b,int e, int i , int j, int key){
    int m = (b+e)/2;
    int left = 2*node;
    int right = left+1;
    if( b > j || e < i) return 0;
    if( b >= i && e <= j){
       int pos = upper_bound(tree[node].begin() , tree[node].end() , key) - tree[node].begin();
       return tree[node].size()-pos;
    }
    int p1 = query(left,b,m,i,j,key);
    int p2 = query(right,m+1,e,i,j,key);
    return p1+p2;
}
int main()
{
   int n ;
   scanf("%d", &n);
   for(int i =  1 ; i<= n ; i++)
     scanf("%lld", &a[i]);
   update(1,1,n);

   int q;
   scanf("%d",&q);
   int res = 0;
   for(int i = 0 ; i < q ; i++){
     int x, y , z;
     scanf("%d%d%d",&x,&y,&z);
     x = x^res;
     y = y^res;
     z = z^res;
  //   cout << x << ' ' <<  y << ' ' << z << endl;
     int val = query(1,1,n,x,y,z);
     res = val;
     if(i) printf(" ");
     printf("%d",val);

   }
}
