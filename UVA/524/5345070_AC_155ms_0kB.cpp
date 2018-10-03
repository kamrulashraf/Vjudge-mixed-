#include <bits/stdc++.h>
using namespace std;
#define ss v.size()
int n;
int a[30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17}, vis[20],temp;
vector < int > v;
int isprime(int n){
 for(int i = 2 ; i*i <= n ; i++){
    if(n%i == 0) return 0;
 }
 return 1;
}
int f(int num, int i){
 if(num != n-1) return 1;
 else{
    if(isprime(a[i]+1)) return 1;
    else return 0;
 }
}
void call()
{
    if(v.size() == n){
        for(int i = 0 ; i<n ; i++){
            if(i==0) cout << v[i];
            else cout << ' ' << v[i];
        }
        cout << "\n";
        return;
    }
    for(int i = 1 ; i< n ; i++){
        if(!vis[i]){
            if(isprime(v[ss-1]+a[i])  && f(ss,i)){
            vis[i]=1;
            v.push_back(a[i]);
            call();

            v.pop_back();
            vis[i] = 0;
            }

        }
    }
}
int main()
{
    int cse = 1;
    v.push_back(1);
    while(cin >> n)
    {
        if(cse > 1) printf("\n");
        temp = 0;
        memset(vis,0,sizeof(vis));
        vis[0]=1;
        printf("Case %d:\n", cse++);
        call();
    }
}
