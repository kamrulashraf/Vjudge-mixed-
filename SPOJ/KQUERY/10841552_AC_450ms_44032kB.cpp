#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 3*200005
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define ll long long
#define READ()  freopen("in.txt","r" , stdin);
#define scana(x) scanf("%d",&x);
#define scanaa(x,y) scanf("%d%d",&x,&y);
#define scanaaa(x,y,z) scanf("%d%d%d",&x,&y,&z);


const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
int a[N] ,x[N] , y[N] ,k[N];
struct node
{
    int a, b , c ,d;
    node(int p , int q ,int r, int z){
         a= p ; b = q;c = r; d = z;
    }
};


int tree[N];
void update(int indx , int val){
     while(indx <= N){
       tree[indx] += val;
       indx += indx & -indx;
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

bool cmp(node a , node b){
    return a.a < b.a;
}
int main()
{
       // READ();
       std::vector< node > decom;
       map < int , int > mark;
       int n;
       scana(n);
       rep(i,0,n){
         scana(a[i]);
         decom.push_back(node(a[i],i,0,0));
       }


       int q;
       scana(q);

      for(int i =  0; i< q ; i++){
        scanaaa(x[i],y[i],k[i]);
        decom.push_back(node(k[i],i,1,0));
      }


       sort(decom.begin() , decom.end(),cmp);
       int counter = 0;
       for(int i = 0 ; i< decom.size() ; i++){
            if(decom[i].c==0){
               if(mark[decom[i].a] == 0){
                   counter++;
                   a[decom[i].b] = counter;
                   mark[decom[i].a] = counter;
               }
               else a[decom[i].b]  = mark[decom[i].a];
            }
            else{
               if(mark[decom[i].a] == 0){
                 counter++;
                 k[decom[i].b] = counter;
                 mark[decom[i].a] = counter;
               }
               else{
                  k[decom[i].b]  = mark[decom[i].a];
               }
            }
       }

       // rep(i,0,n) cout << a[i] << ' ' ; cout << endl;
       // rep(i,0,q) cout << x[i] << ' ' << y[i] << ' ' << k[i] << endl;

       /////////////

       std::vector<node> v;
       vector < int > need;
       rep(i,0,q){
          int l , r , kk;
          l = x[i];
          r = y[i];
          kk = k[i];
          need.push_back(r-l+1);
          l--;
          v.push_back(node(l,kk,i,0));
          v.push_back(node(r,kk,i,1));

       }


       sort(v.begin() , v.end(),cmp);


//       for(auto x : v){
//          cout << x.a << ' ' << x.b << ' ' << x.c << ' ' << x.d << endl;
//       }

       int sz = v.size();
       int cur = 0;
       pii res[q+1];

       for(int i  = 0 ; i< sz ; i++){
          int tempa = v[i].a;
          int tempb = v[i].b;
          int tempc = v[i].c;
          int tempd = v[i].d;
//          cout << '#' << tempa << ' ' << tempb <<  ' ' << tempc << ' ' << tempd << ' ' << cur << endl;

          while(cur < tempa && cur <= n){
//             cout << a[cur] << "*******" << endl;
             update(a[cur++],1);
          }
//          cout << i << '#' << cur << ' ' << tempa <<  endl;
//          for(int j = 1 ; j<= 10 ; j++){
//             int temp = sum(j)-sum(j-1);
//             cout << temp << ' ' ;
//          } cout << endl;

          int save = sum(tempb);
//          cout << tempc << ' ' << tempd << ' ' << save << endl;
          if(tempd == 0){
            res[tempc].ff = save;
          }
          else res[tempc].ss = save;

       }
//       cout << q << endl;
       for(int i = 0 ; i< q ; i++){
          int ans = res[i].ss - res[i].ff;
          printf("%d\n",need[i]-ans);
       }

}
