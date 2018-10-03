#include <bits/stdc++.h>
using namespace std;
#define N 2000005
#define ll long long
ll tree[N], lazy[N];


void update(int node , int b , int e , int i , int j , int val){
    int left = 2*node;
    int right = left+1;
    if(lazy[node]){
         tree[node] += (e-b+1)*lazy[node];
         if(b != e){
             lazy[left] += lazy[node];
             lazy[right] += lazy[node];
         }
         lazy[node] = 0;
    }
    if( e < i || b > j ) return;

    if( b >= i && e <= j){
         tree[node] += (e-b+1)*val;
         if(b != e){
            lazy[left] += val;
            lazy[right] += val;
         }
         return;
    }

    int m = (b+e)/2;
    update(left,b,m,i,j,val);
    update(right,m+1,e,i,j,val);
    tree[node] = tree[left]+tree[right];
}

ll query(int node , int  b ,int e, int i , int j){
        int left = 2*node;
    int right = left+1;
    if(lazy[node]){
         tree[node] += (e-b+1)*lazy[node];
         if(b != e){
             lazy[left] += lazy[node];
             lazy[right] += lazy[node];
         }
         lazy[node] = 0;
    }
    if( e < i || b > j ) return 0;

    if(b >= i && e <= j) return tree[node];

    int m = (b+e)/2;
    ll x =  query(left , b  , m , i , j );
    ll y = query(right, m+1 , e , i , j );
    return x + y;
}
int main()
{

     int n ;
     scanf("%d",&n);

     int cur = 0;
     cur++;
     while(n--){
          int a , b, c;
          scanf("%d",&a);
          if(a == 1){
                scanf("%d%d",&b,&c);
                cur = max(b,cur);
                update(1,1,200002,1,b,c);
                double sum = query(1,1,200002,1,200002);
//                 cout << cur << " sum=" << sum << endl;

                printf("%.10lf\n",sum / (double) (cur));
          }
          if(a == 2){
                scanf("%d",&b);

                cur++;
                update(1,1,200002,cur,cur,b);
                double sum = query(1,1,200002,1,200002);
//                cout << cur << " sum=" << sum << endl;

                printf("%.10lf\n",sum/(double) (cur));
          }
          if(a == 3){
               if( cur >= 2){
                   ll temp = query(1,1,200002,cur,cur);
    //               cout << temp << '$' << endl;
                   update(1,1,200002,cur,cur,-temp);
                   cur--;
                }
                double sum = query(1,1,200002,1,200002);
//                cout << cur << " sum=" << sum << endl;
                sum /= (cur);
                printf("%.10lf\n",sum);
          }

//          for(int i = 1 ; i<= cur ; i++){
//               cout << query(1,1,200002,i,i) << ' ';
//          } cout << endl;
     }

}
