#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 2000005
int mmax = 2000002;
int tree[N];
int lucky[136419];
int mark[N];
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
    mark[1] = 1;
    int cur = 1;
	for(int i = 2 ; i <= 136414 ; i++){
		  int temp, counter = 0;
		  temp = i;
		  int inc = find(temp);
   	      lucky[cur++] = inc;
   	      mark[lucky[cur-1]] = 1;
		  for(int j = inc ; j <= total ; j+= inc){
		  	  int tt = find(j-counter);
		  	  counter++;
		  	  update(tt,-1);
		  }
	}

	int n;
	while(~scanf("%d",&n)){
		 int save = n;
		 if(n&1){
		 	printf("%d is not the sum of two luckies!\n",save);
		 	continue;
		 }
         n = n/2;
         int temp = lower_bound(lucky,lucky+136414,n)-lucky;
         int flag = 0;
         for(int i = temp ; i >= 0 ; i--){
         	int num  =lucky[i];
            if(mark[save-lucky[i]]==1){
            	printf("%d is the sum of %d and %d.\n",save , min(save-lucky[i],lucky[i]),max(save-lucky[i],lucky[i]));
            	flag = 1;
            	break;
            }
         }
         if(flag == 0){
            printf("%d is not the sum of two luckies!\n",save);
         }
	}

}
