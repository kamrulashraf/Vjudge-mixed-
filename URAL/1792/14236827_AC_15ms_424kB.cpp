#include <bits/stdc++.h>
using namespace  std;

#define N 100005
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
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
int main()
{
	int a[7], b[4];
	int temp = 0;
	F(i,4){
		sca(a[i]);
		if(a[i] == 1){
			temp |= (1<<i);
		}
	}
	F(i,3){
		sca(b[i]);
	}


    int res = 0;
    int flag = 0;
	for(int i = 0 ; i< 16 ; i++){
        int save = temp^i;
        if(__builtin_popcount(save) <= 1){
           save = i;
           int aa = 0 , bb = 0 , c= 0 , d = 0;
           if(save& (1<<0)){
             aa = 1;
           }
           if(save& (1<<1)){
             bb = 1;
           }
           if(save& (1<<2)){
             c = 1;
           }
           if(save& (1<<3)){
             d = 1;
           }
           if( (bb+c+d)%2 == b[0] && (aa+c+d)%2 == b[1] && (aa+bb+d)%2 == b[2]){
             res = save;
//             break;
             flag = 1;

           }

        }
	}
//	cout << flag << endl;
	if(flag == 0){
       b[0] = (a[1] + a[2] + a[3])%2;
       b[1] = (a[0] + a[2] + a[3])%2;
       b[2] = (a[0] + a[1] + a[3])%2;
       F(i,4){
          if(i) cout << ' ';
          cout << a[i];
       }
       F(i,3) cout << ' ' << b[i];
	}
	else{
        int save = res;
        int aa = 0 , bb = 0 , c= 0 , d = 0;
               if(save& (1<<0)){
                 aa = 1;
               }
               if(save& (1<<1)){
                 bb = 1;
               }
               if(save& (1<<2)){
                 c = 1;
               }
               if(save& (1<<3)){
                 d = 1;
               }

        cout << aa << ' ' << bb << ' ' << c << ' ' << d;
        F(i,3){
          cout << ' ';
          cout << b[i] ;
        }
    }
    return 0;
}
