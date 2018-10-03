#include <bits/stdtr1c++.h>
 
#define EPS 1e-9
#define MAXROW 105
#define MAXCOL 105
#define clr(ar) memset(ar, 0, sizeof(ar))
 
using namespace std;
 
/***
 
Gauss-Jordan Elimination
 
n = number of linear equations
m = number of variables
ar[i][m] = right-hand side value of constants
 
For instance, the system of linear equations becomes:
 
2x + y -z = 8      ----->  (i)
-3x -y + 2z = -11  ----->  (ii)
-2x + y + 2z = -3  ----->  (iii)
 
n = 3 (x, y, z), m = 3 (i, ii, iii)
ar[0] = {2, 1, -1, 8}    ----->  (i)
ar[1] = {-3, -1, 2, -11} ----->  (ii)
ar[2] = {-2, 1, 2, -3}   ----->  (iii)
 
 
Returns -1 when there is no solution
Otherwise returns the number of independent variables (0 for an unique solution)
Contains a solution in the vector res on successful completion
Note that the array is modified in the process
 
***/
 
int n, m;
double ar[MAXROW][MAXCOL];
 vector <double> res;
int hit[105];
 
 
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
   int test , cs = 1 , pos;
   scanf("%d",&test);
   while(test--){
      memset(ar,0,sizeof ar);
      int n, u , v;
      scanf("%d",&n);
      for(int i = 0 ; i < 101 ; i++) hit[i] = i;
      for(int i = 0 ; i< n ; i++){
         scanf("%d %d",&u,&v);
         u--,v--;
         hit[u] = v;
      }
 
      // start at 0 and final destination 99
      double p = 1/6.0;
      for(int i = 0 ; i< 99 ; i++){
            ar[i][i] = 1.0;
            for(int j = 1 ; j<= 6 ; j++){
                 pos = i+j;
                 if(pos <= 99)
                     ar[i][hit[pos]] -= p;
                 else ar[i][i] -= p;
            }
            ar[i][100] = 1.0;
      }
      ar[99][99] = 1.0;
 
//      for(int i = 0 ; i< 100 ; i++){
//         for(int j = 0 ; j< 100 ; j++){
//             cout << ar[i][j] << ' ' ;
//         }
//         cout << endl;
//      }
 
      int ret = gauss(100,100,ar,res);
      printf("Case %d: %.8lf\n",cs++ , res[0]);
   }
 
}