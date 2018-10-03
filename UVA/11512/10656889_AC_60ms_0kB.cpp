#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 3000005
#define PI acos(-1.0)
#define ll long long
string s;

ll hashVal[N];
ll p[N];
ll base = 101;
ll mod = 1e9+7;
int sz;


void init(){
     p[0] = 1;
     for(int i = 1 ; i<= 1000 ; i++){
         p[i] = (p[i-1]*base)%mod;
     }
}

ll hashValBetween(int i , int j){
//     cout << i << ' ' << j << endl;
//     cout << (p[j-i+1]*hashVal[i-1])%mod << endl;
     ll temp = (hashVal[j]- (p[j-i+1]*hashVal[i-1])%mod + mod)%mod;
     if(temp < 0) temp += mod;
     return temp;
}

int call(int len){
     unordered_map < int , int > mark;
     int mmax = 0;
     for(int i = 1 ; i<= sz-len+1 ; i++){
        int temp = hashValBetween(i,i+len-1);
        mark[temp]++;
        mmax = max(mmax,mark[temp]);

     }
     return mmax;
}



string call1(int len){
     unordered_map < ll , int > mark;
     int mmax = 0;
     for(int i = 1 ; i<= sz-len+1 ; i++){
        ll temp = hashValBetween(i,i+len-1);
        mark[temp]++;
        mmax = max(mmax,mark[temp]);
     }
     vector < string > v;
     for(int i = 1 ; i<= sz-len+1 ; i++){
        int temp = hashValBetween(i,i+len-1);
        if(mark[temp] == mmax){
            string tt = s.substr(i-1,len);
            v.push_back(tt);
        }
     }

     sort(v.begin() , v.end());

     return v[0];

}
int main()
{
//   freopen("in.txt","r" , stdin);
//  freopen("out.txt","w",stdout);
   init();
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
      cin >> s;
      sz = s.size();
      for(int i = 1 ; i <= sz ; i++){
          hashVal[i] = hashVal[i-1]*base+s[i-1];
          if(hashVal[i] >= mod) hashVal[i]%=mod;
      }



      int b = 1 , e = sz, flag = 0 ;
      while( b  <= e ){
           int m = (b+e)/2;
//           cout <<  b << ' ' << e << ' ' <<  m << ' ' << call(m) << endl;
           if(call(m) > 1){
             flag = 1;
             b = m+1;
           }
           else e = m-1;
      }

      if(flag == 0){
        printf("No repetitions found!\n");
        continue;
      }
      string res = call1(e) ;
      int r = call(e);
      printf("%s %d\n", res.c_str() , r);
   }
}
