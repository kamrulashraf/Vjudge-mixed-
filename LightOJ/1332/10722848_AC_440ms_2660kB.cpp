#include <bits/stdc++.h>
using namespace std ;
#define N 37
#define ff first
#define  ss second
#define pii pair<int,int>
#define mp make_pair
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define ll long long

struct MAT
{
	 int r,c;
	 unsigned int a[N][N];
	 MAT(int x,int y){
	 	r = x;
	 	c = y;
	 	memset(a,0,sizeof a);
	 }
     void init(unsigned int temp[]){
     	for(int i = 0 ; i<r*c ; i++){
     		a[i/c][i%c] = temp[i];
     	}
     }
     void print(){
          for(long long i = 0 ; i< r ; i++){
          	 for(long long j = 0; j < c ; j++){
          	 	 cout << a[i][j] << ' ';
          	 }
          	 cout << endl;
          }
     }
     MAT operator*(MAT b){
     	 MAT sum(r,b.c);
     	 unsigned int temp[r*c];
     	 memset(temp,0,sizeof temp);
     	 sum.init(temp);
     	 for(long long i = 0 ; i< r ; i++){   // row 1st mat
     	 	 for(long long j = 0 ; j< b.c ; j++){  // col 2nd mat
                   for(long long k=0; k<c ;k++){   // col 1st matss
                   	  sum.a[i][j] += (a[i][k]*b.a[k][j]);
                   }
     	 	 }
     	 }
     	 return sum;

     }
};

MAT pow(MAT b , long long p){
    if(p == 0 || p == 1)
      return b;
    if(p&1){
        return b*pow(b,p-1);
    }
    else{
        MAT temp = pow(b,p/2);
        return temp*temp;
    }

}


int main()
{
//    freopen("in.txt","r", stdin);
     // ios_base::sync_with_stdio(0); cin.tie(0);


     vector < pii > v;

     for(int i = 0 ; i<10;i++){
         for(int j = i+2 ; j<10;j++){
            v.push_back(mp(i,j));
         }
     }

     MAT base(36,36);


     for(int i = 0 ; i< v.size() ; i++){
         for(int j = 0 ; j< v.size() ; j++){
            // if both are not attacking
            // one can transition to other place
            int x ,y , p,q;
            x = v[i].ff;
            y = v[i].ss;
            p = v[j].ff;
            q = v[j].ss;
            if( abs(x-p) > 1 && abs(x-q) >1 && abs(y-p) > 1 && abs(y-q) > 1){
                base.a[i][j] = 1;
            }
         }
     }

     MAT b(36,1);
     rep(i,0,36) b.a[i][0] = 1;


     int test , cs = 1;
     scanf("%d",&test);

     while(test--){
        int n;
        scanf("%d",&n);
        if(n == 1){
           printf("Case %d: 36\n",cs++);
        }
        else{
           MAT temp = pow(base,n-1);

           temp = temp*b;
           unsigned int sum = 0;
           rep(i,0,36) sum += temp.a[i][0];
           printf("Case %d: %u\n",cs++ , sum);
        }

     }

     return 0;
}
