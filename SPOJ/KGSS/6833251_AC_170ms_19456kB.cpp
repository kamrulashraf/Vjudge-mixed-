#include <bits/stdc++.h>
#define NN 100005
#define pii pair <long long, long long>
#define ff first
#define ss second
long long sub[4][4*NN], tree[4*NN] , a[NN];
using namespace std;

    void makeSegment(int node , int b ,int e){
        int left = 2*node;
        int right = left+1;
        if(b == e){
            sub[0][node] = a[e];
            tree[node] = a[e];
            return;
        }
        int m = (b+e)>>1;
        makeSegment( node<<1,b,m);
        makeSegment((node<<1)+1,m+1,e);

        int i=0,j=0,k=0;
        while( i< 2 && j < 2){
           if(sub[i][left] > sub[j][right])
              sub[k][node] = sub[i][left],
              i++;
           else sub[k][node] = sub[j][right],
                j++;
           k++;
        }
        while(i<2){ sub[k][node] = sub[i][left] , i++ , k++;}
        while(j<2) sub[k][node] = sub[j][right] ,j++ , k++;

        tree[node] = sub[0][node]+sub[1][node];
    }

pii query(int node, int b ,int e , int l , int u){
        if( l > e || u < b) return {0,0};
        if(b >= l && e <= u) return {sub[0][node] ,sub[1][node]};
        int m = (b+e)>>1;
        pii x,y;
        x = query(node<<1,b,m,l,u);
        y = query((node<<1)+1,m+1,e,l,u);
        vector < long long > v;
        v.push_back(x.ff);
        v.push_back(x.ss);
        v.push_back(y.ff);
        v.push_back(y.ss);
        sort(v.begin(), v.end());
        v.clear();
        return {v[3],v[2]};

}


   void update(int node ,int b , int e , int indx, int val){
        int left = 2*node;
        int right = left+1;
        if(indx > e || indx < b) return;
        if(b >= indx && e <= indx){
             sub[0][node] = val;
             tree[node] = val;
             return;
        }

        int m = (b+e)>>1;
        update(node<<1,b,m,indx,val);
        update((node<<1)+1,m+1,e,indx,val);

        int i=0,j=0,k=0;
        while( i< 2 && j < 2){
           if(sub[i][left] > sub[j][right])
              sub[k][node] = sub[i][left],
              i++;
           else sub[k][node] = sub[j][right],
                j++;
           k++;
        }
        while(i<2) sub[k][node] = sub[i][left] , i++ , k++;
        while(j<2) sub[k][node] = sub[j][right] ,j++ , k++;

        tree[node] = sub[0][node]+sub[1][node];

    }

int main()
{
   int n ;
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
     scanf("%lld",&a[i]);
   }
   makeSegment(1,1,n);
 //  for(int i = 1;i<= 10;i++) cout << i << ' ' << tree[i] << ' ' << endl;
   int q;
   scanf("%d",&q);
   for(int i = 0 ; i< q ; i++){
      char ch;
      int p,q;
       ch = getchar();
       scanf("%d%d",&p,&q);
      cin >> ch >> p >> q;
      if(ch == 'Q'){
         pii x;
         x = query(1,1,n,p,q);
         printf("%lld\n",x.ff+x.ss);
      }
      else update(1,1,n,p,q);
   }
  return 0;
}
