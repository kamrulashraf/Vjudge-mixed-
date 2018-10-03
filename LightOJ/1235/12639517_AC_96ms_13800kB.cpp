#include <bits/stdc++.h>
using namespace  std;

#define N 3000000
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

int n , k ;
int a[N];
std::vector< ll > v;
std::vector< int > fs, sd;
int fssize , sdsize;
void call(int indx , ll sum){
       if(sum > k) return ;
	   if(indx >= fssize){
	   	 v.push_back(sum);
	   	 return;
	   }
       call(indx+1,sum+fs[indx]);
       call(indx+1,sum+2*fs[indx]);
       call(indx+1,sum);
}

bool flag = 0;
void call1(int indx , ll sum){
      if(flag == 1) return;
      if(sum > k) return;
      if(indx >= sdsize){
          ll temp = k - sum;
          int pos =  lower_bound(v.begin() , v.end() , temp) - v.begin();
          if(v[pos] == temp) flag = 1;
          return;
      }

      call1(indx + 1 , sum+sd[indx]);
      call1(indx + 1 , sum+2*sd[indx]);
      call1(indx+1,sum);
}
int main()
{
	int test , cs = 1;
	sca(test);
	while(test--){
		 v.clear();
		 fs.clear();
		 sd.clear();
		 scaa(n,k);

		 for(int i = 0 ; i< n ; i++){
		 	 cin >> a[i];
		 	 if(i&1) sd.push_back(a[i]);
		 	 else fs.push_back(a[i]);
		 }

        fssize = fs.size();
        sdsize = sd.size();
		 call(0,0LL);
		 flag = 0;

         sort(v.begin() , v.end());
//         for(auto x : v){
//          cout << x << ' ';
//         } cout << endl;
         call1(0,0LL);

		 if(flag == 1){
		 	 printf("Case %d: Yes\n",cs++);
		 }
		 else printf("Case %d: No\n",cs++);
	}
}
