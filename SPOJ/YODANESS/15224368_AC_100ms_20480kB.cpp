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

int tree[N];
void update(int indx , int val){
   while(indx < N-2){
      tree[indx] += val;
      indx += indx&-indx;
   }
   return;

}

int total(int indx){
   int res = 0;
   while(indx){
      res += tree[indx];
       indx -= indx & -indx;
   }
   return res;
}
int main()
{
    int test , cs = 1;
    sca(test);
    while(test--){
        memset(tree,0,sizeof tree);
        int n;
        sca(n);
        std::vector< string > v;
        map < string , int > mark;
        for(int i = 0 ; i< n ; i++){
             string s;
             cin >> s;
             v.PB(s);
             mark[s] = i;
        }
        std::vector< int > numberorder;
        for(int i = 0 ; i <n ; i++){
             string s;
             cin >> s;
             numberorder.push_back(mark[s]+1);
        }
//        for(int i = 0 ; i< v.size() ; i++){
//             cout << numberorder[i] << endl;
//        }
        ll res = 0;
        for(int i = 0 ; i< n ; i++){
            int temp  = total(numberorder[i]);
            update(numberorder[i],1);
            res += i-temp;
//            cout << temp << endl;
        }

        cout << res << endl;
    }
}
