#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N];
int main()
{
     int n;
     scanf("%d",&n);
     bool flag = 0;
     map < int , int > mark;
     int save = 0, mmin = 1e9+3;
     for(int i = 0 ; i< n ; i++){
         int temp;
         scanf("%d",&temp);
         a[i] = temp;
         mark[temp]++;

//         if(mark[temp] > 1) flag = 1;
         if(temp < mmin){
             mmin = temp;
             save = i+1;
         }
     }

     if(mark[a[save-1]] > 1){
          cout << "Still Rozdil" << endl;
     }
     else cout << save << endl;
}
