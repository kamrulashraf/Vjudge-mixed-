#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define PI acos(-1)
#define pll pair < ll , ll >

int a[10015];
void mobiusSeieve(int n){
      for(int i = 2 ; i <= n ; i++){
           if(a[i]==0){
               int temp = i*i;
               for(int j = i ; j<= n ; j+=i){
                    if(j%temp==0){
                         a[j] = -1;
                    }
                    else if(a[j] >= 0)
                       a[j]++;
               }
           }
      }
}
int main()
{  
    mobiusSeieve(10005);
    int temp;
    // for(int i = 0 ; i<37 ; i++){
    //      cout << i << ' ' << a[i] << endl;
    // }
    a[1] = 0;
    int counter = 0;
    while(scanf("%d",&temp)){
         if(temp==-1) break;
         if(counter) printf("\n");
         counter++;         
         int res;
         if(a[temp] == -1) res = 0;
         else{
             if(a[temp]&1) res = -1;
             else res = 1;
         }
         printf("M(%d) = %d\n",temp ,res);
    }
    return 0;
}
