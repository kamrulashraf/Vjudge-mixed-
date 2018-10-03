#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define N 2000005
int mmax = 2000002;
int tree[N];
int lucky[136419];
void update(int indx , int val){
     while(indx < mmax){
         tree[indx] += val;
         indx += indx & - indx;
     }
}
 
 
int find(int x){
     int ret = 0, num = 0;
     for(int i = 20 ; i>= 0 ; i--){
        ret += (1<<i);
        if(ret >= 2000002 || num + tree[ret] >= x){ // >= means x theke soto upper bound
            ret -= (1<<i); // not taken this fragment
        }
        else{
            num += tree[ret]; // taken this fragment
        }
     }
     return ret+1;  // explain before
}
 
 
 
int main()
{
    int test , cs = 1;
    for(int i = 1 ; i<= 2000005 ; i+=2) update(i,1);
 //    update(2,-1);
 //    update(3,-1);
    // int pos = find(5);
    int total = 2000002;
    lucky[0] = 1;
    int cur = 1;
    for(int i = 2 ; i <= 136414 ; i++){
          int temp, counter = 0;
          temp = i;
          int inc = find(temp);
          lucky[cur++] = inc;
          for(int j = inc ; j <= total ; j+= inc){
              int tt = find(j-counter);
              counter++;
              update(tt,-1);
          }
    }
    scanf("%d",&test);
    while(test--){
         int n;
         scanf("%d",&n);
         
         printf("Case %d: %d\n",cs++ , lucky[n-1]);
    }
 
}
 