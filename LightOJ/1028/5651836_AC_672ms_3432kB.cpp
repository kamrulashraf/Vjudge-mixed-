#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define N     1000100
#define DEB           cout << "DEB" << endl;
bool a[1000100];
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

int nod(ll num){
ll temp = num, ans = 1;
int Size = save.size();
for(int i = 0; save[i]*save[i] <= num && i < Size ; i++){
     if(num%save[i] == 0){
            int counter=1;
        while(num%save[i]==0){
            counter++;
            num /= save[i];
        }
        ans *= counter;
     }
}
if(num >1) ans*= 2;
return ans;
}
int main()
{
    ll test , n, cse = 1;
    seive();
    scanf("%lld", &test);
    while(test--){
        scanf("%lld", &n);
        ll ans = nod(n);
        printf("Case %lld: %d\n", cse++ ,ans-1);    }
}
