#include <bits/stdc++.h>
using namespace  std;

#define N 400005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

string s;


struct st
{
    int sum;
    int maxClose;
    st(){
      sum = 0;
      maxClose = 0;
    }
} tree[4*N];
void make(int node , int b ,int e){
     int left = node*2;
     int right = left+1;
     int m = (b+e)/2;
     if(b==e){
        int val ;
        if(s[b-1] == '(') val = 1;
        else val = -1;
        tree[node].sum = val;
        tree[node].maxClose =val;
        return;
     }
     make(left , b , m);
     make(right, m+1 , e);
     tree[node].sum = tree[left].sum+tree[right].sum;
     tree[node].maxClose = min(tree[left].maxClose , tree[left].sum + tree[right].maxClose);
     return;
}

void update(int node ,int b , int e , int pos){
     int left = node*2;
     int right = left+1;
     int m = (b+e)/2;

     if( b > pos || e < pos) return;
     if(b == pos && e == pos){
        tree[node].sum = tree[node].maxClose = -1*tree[node].sum;
        return;
     }
     update(left, b, m , pos);
     update(right,m+1,e,pos);

     tree[node].sum = tree[left].sum+tree[right].sum;
     tree[node].maxClose = min(tree[left].maxClose , tree[left].sum + tree[right].maxClose);
     return;


}
int main()
{
    int test , cs = 1;
    int n;
    while(~sca(n)){
        cin >> s;
    //    cout << s << endl;
        int q;
        sca(q);
        int sz = s.size();
        make(1,1,sz);

    //    cout << tree[1].sum << ' ' << tree[1].maxClose << endl;
        printf("Test %d:\n",cs++);
        while(q--){
             int a;
             sca(a);
             if(a) update(1,1,sz,a);
             if(a == 0){

                 int temp =  (tree[1].sum | tree[1].maxClose);
        //         cout << tree[1].sum << ' ' << tree[1].maxClose << endl;
                 if(temp == 0){
                    printf("YES\n");
                 }
                 else printf("NO\n");
            }

         }
     }
}
