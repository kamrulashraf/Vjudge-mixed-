#include <bits/stdc++.h>
using namespace std;
#define N 100
int a[N],b[N];
int main()
{
//    freopen("in.txt","r",stdin);
    int r , c;
    int dp[50][50];
    while(scanf("%d %d",&r,&c)==2){

        int mark[100] = {0};
        if(r== 0 && c==0) break;


        for(int i = 0 ; i< r ; i++){
            cin >> a[i];
        }


        for(int i = 0 ; i< c ; i++){
            cin >> b[i];
        }


        int res = 0;

        for(int i = 0 ; i < r ; i++){
             res += a[i];
        }


//        cout << res << '*' << endl;

        for(int j = 0 ; j< c ; j++){
            bool flag = 0;
            for(int i = 0 ; i < r ; i++){
                 if(mark[i] == 0 && a[i] == b[j]){
                        mark[i]++;
                        flag = 1;
                        break;
                 }
            }
            if(!flag) res += b[j];
        }
        cout << res << endl;
    }
}
