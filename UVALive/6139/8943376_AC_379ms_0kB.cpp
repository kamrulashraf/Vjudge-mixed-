#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n;
int tree[N], zero[N], a[N];
void update(int indx, int val,int val0){
	 while(indx <= n+2){
	 	 tree[indx] += val;
	 	 zero[indx] += val0;
	 	 indx += indx & -indx;
	 }
}

int sum(int indx,int s){
	 int ret = 0;
	 int ret0 = 0;
	 while(indx){
        ret += tree[indx];
        ret0 += zero[indx];
        indx -= indx & -indx;
	 }
	 if(s == 0) return ret0;
	 else return ret;
}
int main()
{
	 // freopen("inputf.in" , "r" , stdin);
	 int  q;

	 while(scanf("%d%d",&n , &q)==2){
	 		 memset(tree,0,sizeof tree);
	         memset(zero,0,sizeof zero);
             for(int i = 1 ; i<= n ; i++){
                  scanf("%d",&a[i]);
                  if(a[i] < 0){
                     update(i,1,0);
                  }
                  if(a[i] == 0){
                    update(i,0,1);
                  }
             }

             for(int i = 0 ; i< q ; i++){
                  char ch;
                  cin >> ch;
                  if(ch == 'C'){
                      int temp, x;
                      scanf("%d%d",&temp,&x);
                      int res = sum(temp,1)-sum(temp-1,1);
                      update(temp,-res,0);
                      res = sum(temp,0) - sum(temp-1,0);
                      update(temp,0,-res);

                      if(x < 0) update(temp,1,0);
                      if(x==0) update(temp,0,1);
                  }
                  else{
                    int l , r ;
                    scanf("%d%d",&l,&r);
                    int res = sum(r,1)-sum(l-1,1);
                    int z = sum(r,0)-sum(l-1,0);
                    if(z >=1) printf("0");
                    else{
                        if(res&1) printf("-");
                        else printf("+");
                    }
                  }
             }
             printf("\n");
        }


}
