#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define ff first
#define ss second
#define NN 200005
int x[NN] , y[NN]  , a[NN];
long long tree[4*NN], ans[NN];
map < int ,int > vis;
int n , q;
void update(int i , int val){
    while(i <= n){
        tree[i]+= val;
        i += i & -i;
    }
}
ll query(int i){
    ll sum = 0;
    while(i){
        sum += tree[i];
        i -= i & -i;
    }
    return sum;
}

void clr(){
    vis.clear();
    memset(tree,0,sizeof(tree));
    memset(ans,0,sizeof(ans));
}
int main()
{
  int test , cs = 1;

    clr();
    scanf("%d",&n);
    for(int i = 1 ; i<= n ; i++){
        scanf("%d",&a[i]);
    }
    vector < pii > v;
    scanf("%d",&q);
    for(int i = 1 ; i<= q ; i++){
        scanf("%d%d",&x[i], &y[i]);
        v.push_back({y[i],i});
    }
    sort(v.begin() , v.end());
    int j = 0;
    for(int i = 1 ; i<= n  ; i++){
        if(vis[a[i]])
            update(vis[a[i]],-1);

        vis[a[i]] = i;
        update(i,1);
        while( j < v.size() && v[j].ff == i){
         //   cout << x[v[j].ss] << ' ' << v[j].ff << ' ' ;
            ans[v[j].ss] = query(i) - query(x[v[j].ss]-1);
            j++;
        }
    }
  //  printf("Case %d:\n",cs++);
    for(int i = 1 ; i<= q ; i++){
       printf("%lld\n",ans[i]);
    }
    v.clear();

}
