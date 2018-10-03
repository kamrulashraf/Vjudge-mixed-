#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a, b , i , j, save, sum, flag = 0;
    double mmin = 1000007.00;
    cin >> a >> b;
    if(a<= 1) cout << 1 << endl;
    else
    for(i = b ; i>= a ; i--)
    {
        flag = 0;
        for(j = 2, sum = 0 ; j*j <= i ; j++)
        {
            if(i%j==0){
                sum += j;
                sum += i/j;
                flag = 1;
            }
        }
        if(flag == 0){
            cout << i << endl;
            break;
        }
        else{
            ll temp = sqrt(i);
            if(temp*temp == i) sum -= temp;
            sum ++;
            double mmm= (double) sum / (double) i;
          //  cout << i << ' ' << mmm << endl;
            if(mmm < mmin){
                mmin = mmm;
                save = i;
            }
        }
    }
    if(flag) cout << save << endl;
}
