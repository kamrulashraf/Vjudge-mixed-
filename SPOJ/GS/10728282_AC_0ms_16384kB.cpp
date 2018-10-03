#include <bits/stdc++.h>
using namespace std;
#define N 105
#define MAXROW N
#define MAXCOL N
#define EPS 1e-8
#define pii pair <int,int>
#define ff first
#define ss second
#define F(i,n) for(int i = 0 ; i< n ; i++)


int n, m;
double ar[MAXROW][MAXCOL];
 vector <double> res;
int hit[105];

map < int , vector<pii> > adj;
int gauss(int n, int m, double ar[MAXROW][MAXCOL], vector<double>& res){
    res.assign(m, 0);
    vector <int> pos(m, -1);
    int i, j, k, l, p, free_var = 0;

    for (j = 0, i = 0; j < m && i < n; j++){
        for (k = i, p = i; k < n; k++){
            if (abs(ar[k][j]) > abs(ar[p][j])) p = k;
        }
        if (abs(ar[p][j]) > EPS){
            pos[j] = i;
            for (l = j; l <= m; l++) swap(ar[p][l], ar[i][l]);

            for (k = 0; k < n; k++){
                if (k != i){
                    double x = ar[k][j] / ar[i][j];
                    for (l = j; l <= m; l++) ar[k][l] -= (ar[i][l] * x);
                }
            }
            i++;
        }
    }

    for (i = 0; i < m; i++){
        if (pos[i] == -1) free_var++;
        else res[i] = ar[pos[i]][m] / ar[pos[i]][i];
    }

    for (i = 0; i < n; i++) {
        double val = 0.0;
        for (j = 0; j < m; j++) val += (res[j] * ar[i][j]);
        if (abs(val - ar[i][m]) > EPS) return -1;
    }

    return free_var;
}



int main()
{
//     freopen("in.txt", "r" , stdin);
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
        int  n , s , e;
        scanf("%d%d%d",&n,&s,&e);

        for(int i = 0 ; i< n-1 ; i++){
           int u , v , c;
           scanf("%d%d%d",&u,&v,&c);
           adj[u].push_back({v,c});
           adj[v].push_back({u,c});
        }

        for(int i = 0 ; i< n ; i++){
            double sum = 0;
            for(auto x : adj[i+1]){
               sum += x.ss;
            }
            ar[i][i] = 1;
            if(i == e-1) continue;
            for(auto x: adj[i+1]){
               int v = x.ff-1;
               double c = x.ss;
//               if(i == 1) cout << v << ' ' << c << ' ' << sum << endl;
               ar[i][v] = c/-sum;
            }
            ar[i][n] = 1;
        }

        ar[e-1][n] = 0;

        int free = gauss(n,n,ar,res);
//        for(auto x : res)
//          cout <<  x << endl;
        printf("%.5lf\n",res[s-1]);
                F(i,101){
          F(j,101)
            ar[i][j] = 0;
        }
        res.clear();
        adj.clear();

     }
}
