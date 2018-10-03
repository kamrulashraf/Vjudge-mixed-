#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 3000005
#define PI acos(-1.0)


const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

bool chech(int n){
   if(n == 0 || n== 1) return 0;
   for(int i = 2 ; i*i <=n ; i++){
      if(n%i==0) return 0;
   }
   return 1;

}

int myRand(){
    return (rand() << 15) + rand();
}
int main()
{
       ios_base::sync_with_stdio(0); cin.tie(0);

       //ios_base::sync_with_stdio(true);cin.tie(NULL);
//       freopen("in.txt", "r" , stdin);
       int n;
       cin >> n;
       if(chech(n)){
         cout << 1 << endl;
         cout << n << endl;
         return 0;
       }
       else{

         n -= 3;
         // cout << "bal" << endl;
         cout << 3 << endl;
         cout << 3 << ' ' ;
         while(1){
            int temp = 1+myRand()%n;
            if(temp < 0) temp += n;
//            cout << temp << endl;
            if(chech(temp) && chech(n-temp)){
                cout << temp << ' ' << n-temp << endl;
                break;
            }

         }
      }



}
