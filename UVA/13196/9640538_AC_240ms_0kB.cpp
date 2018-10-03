#include <bits/stdc++.h>
using namespace std;
#define ll long long
int v[50000];
int main()
{
    int n;
    int sz = 0;
    for(int i = 0 ; i*i <= 5000000 ; i++)
        v[sz++] = i*i;

    while(scanf("%d",&n)==1){
        n = 5*n;
        int counter = 0;
        for(int i = 0 ; 36*i*i <= n ; i++){
             for(int j = 0 ; ; j++){
                int temp = 36*i*i+18*j*j ;
                if( temp > n) break;
                int temp1 = n-temp;
//                if(i==1 && j == 1){
//                    cout << temp << ' ' << temp1 <<  endl;
//                }
                if(temp1%6==0){
                        temp1 /= 6;
                        int pos = lower_bound(v,v+sz,temp1)-v;
                        if(v[pos] == temp1){
//                            cout << i << ' ' << j << ' ' << pos << endl;
                            int res = 1;
                            if(i) res *= 2;
                            if(j) res *= 2;
                            if(pos) res *= 2;
                            counter += res;
                        }
                }
             }
        }

        printf("%d\n",counter);
    }
    return 0;
}
