// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>

//  http://ideone.com/kxcEk8
using namespace std;
#define inf                  1e13
#define white                0
#define grey                 1
#define black                2
#define ll                   long long
#define ull                  unsigned long long
#define PI                   2.0*acos(0.0)   // acos(-1)
#define pii                  pair <int,int>
#define pll                  pair <ll,ll>
#define rep(i,x,y)           for(int i = x ; i < y ; i++)
#define ff                   first
#define ss                   second
#define X(i)                 x+fx[i]
#define Y(i)                 y+fy[i]
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))
#define WRITE                freopen("a.txt","w",stdout);
//***********************************************
#define MOD
#define ashraf
#ifdef ashraf
     #define so(args...) {cerr<<"so: "; dbg,args; cerr<<endl;}
#else
    #define so(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
#define NN 100000

int main()
{
     ios_base::sync_with_stdio(0); cin.tie(0);
     int a , b , l;
     cin >> a >> b >> l;
     std::vector<char> v;
     int temp = a;
     while(temp){
        char save = (temp%10)+48;
        temp /= 10;
        v.push_back(save);
     }
     reverse(v.begin() , v.end());
     int need = v.size();
     temp = a;
     temp = temp%b;
     for(int i = 0 ; i< l ; i++){
         for(int j = 0 ; j<= 9 ; j++){
             int temp1 = temp*10+j;
             if(temp1%b == 0){
                temp = temp1%b;
                char save = j+48;
                v.push_back(save);
                break;
             }

         }
     }
     if(v.size() -need == l){
        for(auto x : v) cout << x;
            cout << endl;
     }
     else cout << -1 << endl;

}
