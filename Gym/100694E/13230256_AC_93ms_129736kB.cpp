#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define pii pair < double , int >
#define ff first
#define ss second
struct bal{
    double per;
    double a  , b;
    double avg;

} tree[4*N];

void update(int node , int b , int e , int indx, double val){
    if(  b > indx || e < indx) return;
    if(b == indx && e == indx){
         tree[node].per=tree[node].per+1.0;
         tree[node].a = tree[node].b;
         tree[node].b = val;
         if(tree[node].per==1)tree[node].avg = (tree[node].a+tree[node].b);
         else tree[node].avg = (tree[node].per*(tree[node].a+tree[node].b))/2.0;
         return;
    }
    int left = 2*node;
    int right = left + 1;
    int m = (b+e)/2;
    //cout<<left<<" "<<right<<" "<<m<<endl;
    update(left,b,m,indx, val);
    update(right,m+1,e,indx , val);
    tree[node].avg = min(tree[left].avg , tree[right].avg);
}


int query(int node , int b ,int e){
    if(b == e){
         return b;
    }
    int left = 2*node;
    int right = left + 1;
    int m = (b+e)/2;

    double temp1 , temp2;
    temp1= tree[left].avg;
    temp2 = tree[right].avg;

    if(temp1 <= temp2){
       return query(left,b,m);
    }
    else return query(right,m+1,e);


}
int main()
{

    int n;
    double d;
    scanf("%d %lf",&n,&d);
    double a[n+10];
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    for(int i=0;i<n;i++){
        int ans=query(1,1,d);
        printf("%d ",ans);
        update(1,1,d,ans,a[i]);
    }
    printf("\n");
}
