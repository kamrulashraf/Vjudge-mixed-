#include <stdio.h>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
int tree[100005];
int lucky[100005], a[100005];
bool mark[100005];
int cur = 0;
    int n , q;

void generate(int x){
    if(x > 100005) return;
    if(x){
      lucky[cur++] = x;
      mark[x] = 1;
    }
    generate(x*10+4);
    generate(x*10+7);
    return;

}


void update(int indx , int val){
    while(indx <= n){
        tree[indx] += val;
        indx += indx & - indx;
    }
}


int sum(int indx){
    int ret = 0;
    while(indx){
        ret += tree[indx];
        indx -= indx & -indx;
    }
    return ret;
}
int main()
{
    // freopen("inputf.in","r" , stdin);
    scanf("%d %d",&n, &q);
    generate(0);

    sort(lucky,lucky+cur);
    for(int i = 1 ; i<= n  ; i++){
         scanf("%d",&a[i]);
         if(mark[a[i]])
            update(i,1);
    }
    char s[10];
    int l , r,x;
    for(int i = 0 ; i < q ; i++){
        getchar();
        scanf("%s",s);
        if(s[0] == 'c'){
             scanf("%d%d",&l,&r);
             int res = sum(r)-sum(l-1);
             printf("%d\n",res);
        }
        else{
             scanf("%d%d%d",&l,&r,&x);
             for(int j = l ; j<= r ; j++){
                if(mark[a[j]] == 1)
                    update(j,-1);
                a[j] += x;
                if(mark[a[j]] == 1)
                    update(j,1);
             }
        }
    }

}
