#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 200005
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define ll long long
#define READ()  freopen("in.txt","r" , stdin)
#define scana(x) scanf("%d",&x)
#define scanaa(x,y) scanf("%d%d",&x,&y)
#define scanaaa(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define MEMO(arr)  memset(arr , 0 , sizeof arr)
#define MEM(arr)  memset(arr,-1,sizeof arr)
#define inf 1e9
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
int tree[N];
int id[N];



void update(int indx, int val){
	while(indx < N){
		tree[indx]+=val;
		indx += indx & -indx;
	}
}


int totol(int indx){
	int sum = 0;
	while(indx){
		sum += tree[indx];
		indx -= indx & -indx;
	}
	return sum;
}


int nextPos(int sum){
    int b = 1 , e = N-1;

    while(b <= e){
    	 int m = (b+e)/2;
//    	 cout << b << ' ' << e << ' ' << m <<' ' << totol(m) <<  endl;
    	 if(totol(m) < sum){
    	   b = m+1;
    	 }
    	 else e = m-1;

    }
    return b;
}
int main(){
	// READ();
	int test , cs = 1;
	scana(test);
	while(test--){
		printf("Case %d:\n",cs++);
		int n , q;
		scanaa(n,q);
		rep(i,0,n){
			 int temp;
			 scana(temp);
			 update(i+1,1);
			 id[i+1] = temp;
		}

		while(q--){
			char ch ;
			int t;
			getchar();
			scanf("%c %d",&ch,&t);
			// cout << ch << ' ' << t << endl;
            if(ch == 'c'){
                int pos = nextPos(t);
             //   cout << pos << endl;
                if(pos > 200000){
                	printf("none\n");
                }
                else
                printf("%d\n",id[pos]);
                update(pos,-1);
            }
            else{
               int pos = nextPos(totol(N-5))+1;
               update(pos,1);
               id[pos] = t;
            }
		}

		MEMO(tree);
		MEMO(id);


	}
}
