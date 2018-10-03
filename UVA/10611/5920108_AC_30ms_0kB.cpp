#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    int n , q;
    memset(a,55555,sizeof(a));
    cin >> n;
    for(int i = 1 ; i<= n ; i++)
        cin >> a[i];
    cin >> q;
    for(int i = 0 ; i< q ; i++)
    {
        int key;
        cin >> key;
        int temp = lower_bound(a+1,a+n+1,key)-a;
        int k = temp,flag = 0;
        while(a[k] >= key){
            if(k == 1){
                flag = 1;
                cout << 'X' << ' ';
                break;
            }
            k--;
        }
        if(flag == 0) cout << a[k] << ' ';
        k = temp;
        flag = 0;
        if(k>n){
            flag = 1;
            cout << 'X'<< endl;
        }
        while(a[k] <= key){
            if(k>= n){
                flag = 1;
                cout << 'X' << endl;
            }
            k++;
        }
        if(!flag) cout << a[k] << endl;
    }
}
