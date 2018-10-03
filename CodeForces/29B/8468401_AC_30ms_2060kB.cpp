#include <bits/stdc++.h>
using namespace std;
int arr[3000] , brr[3000];
map < int , int > mark;
int  l , d , v , g , r;
int fun(int n){

    int temp = n/2*g;
    temp += n/2*r;
    if(n&1) temp += g;
    return temp;
}
int call(double key){
    int b = 0 , e = 1e5;
    while(b <= e){
        int m = (b+e);
        int val = fun(m);
        if(val > key)
            e = m-1;
        else b = m+1;
    }
    return b;
}
int main()
{

    cin >> l >> d >> v >> g >> r;
    double res = (double) d/v;
    double temp = l-d;

    int n = call(res);
    if((n&1)==0){
        int s = n-1;
        double ss= fun(s);
        double need = r - (res-ss); 
        res += need;
    }

    res += temp/v;
    printf("%.8lf\n",res);
}
