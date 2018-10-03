#include <bits/stdc++.h>
using namespace std;
#define N 105
#define EPS 1e-9
#define ll long long
ll k , pp , ar[N][N];
map < int ,vector < int > > adj;
ll mod = 1000000007;
void show(int n){

      for(int i = 0 ; i< n ; i++){
         for(int j = 0 ; j< n ; j++){
             cout << ar[i][j] << ' ';
         }
         cout << endl;
      }
}



ll bigmod(ll b , ll p , ll mod){
      if(p == 0) return 1;
      if(p&1){
          return b*(bigmod(b,p-1,mod))%mod;
      }
      else{
         ll x = bigmod(b,p/2,mod);
         return (x*x)%mod;
      }
}

ll modInverse(ll b , ll p){
    return bigmod(b,p-2,p);
}


int gauss(int n, int m, ll ar[N][N]){
    vector <int> pos(m, -1);
    int i, j, k, l, p, free_var = 0;

    for (j = 0, i = 0; j < m && i < n; j++){
        for (k = i, p = i; k < n; k++){
            if (abs(ar[k][j]) > abs(ar[p][j])) p = k;
        }

        if (ar[p][j]){
            pos[j] = i;
            for (l = j; l <= m; l++) swap(ar[p][l], ar[i][l]);
            ll temp = modInverse(ar[i][j],pp);
            for (k = 0; k < n; k++){
                if (k != i){
                    ll x = (ar[k][j] * temp)%pp;
                    for (l = j; l <= m; l++) ar[k][l] = (ar[k][l] - (ar[i][l] * x))%pp;
                }
            }
            i++;
        }
    }

    for (i = 0; i < m; i++){
        if (pos[i] == -1) free_var++;
    }

    return free_var;
}



int main()
{
   int test , cs = 1, n , m, u , v ;
   scanf("%d",&test);
   while(test--){
      scanf("%d %d %lld", &n , &m , &k);
      pp = k;
      for(int i = 0 ; i< m ; i++){
            scanf("%d%d",&u,&v);
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
      }


      for(int i = 0 ; i< n ; i++){
          ar[i][i] = 1;
          for(int j = 0 ; j< adj[i].size() ; j++){
              int v = adj[i][j];
              ar[i][v] = k-1;
          }
      }
      ll res = 0;
      int ret = gauss(n,n,ar);

      res = bigmod(k,ret,mod);
      if(res < 0) res += mod;
      printf("Case %d: %lld\n",cs++  , res);
      adj.clear();
      memset(ar,0,sizeof ar);

   }
}
