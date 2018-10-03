#include <bits/stdc++.h>
using namespace std;
int main()
{
    int hit[10];
    int num;
    while(cin >> num){
        memset(hit,0,sizeof(hit));
        for(int i = 0 ; i< 5 ; i++){

            int a ;
            cin >> a ;
            hit[a]++;
        }
        cout << hit[num] << endl;
    }
}
