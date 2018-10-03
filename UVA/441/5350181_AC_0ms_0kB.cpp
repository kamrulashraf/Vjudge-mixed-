#include <bits/stdc++.h>
#define ss v.size()
#define rep(i,x,y) for(int i = x; i< y ; i++)
using namespace std;
int n,a[100], vis[100];
vector <int> v;
void call()
{
    if(v.size() == 6){
        rep(i,0,6){
             if(i == 0)
             cout << v[i];
             else cout << ' ' << v[i];
        }
        cout << "\n";
        return;
    }
    rep(i,0,n){
     if(ss == 0 || (vis[i] == 0 && v[ss-1] < a[i]) ){
        vis[i] = 1;
        v.push_back(a[i]);
        call();
        vis[i] = 0;
        v.pop_back();
     }
    }
}

int main()
{
    int cse = 0;
    while(cin >> n && n){
        if(cse > 0) printf("\n");
        cse++;
        memset(vis,0,sizeof(vis));
        rep(i,0,n){
         cin >> a[i];
        }
        call();
    }
}
