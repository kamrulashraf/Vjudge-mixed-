#include <bits/stdc++.h>
using namespace std;
#define  NN 44725
#define ll long long
ll dp[NN];
int main()
{
    for(int i = 0 ; i <= NN -1 ; i++){
        long long temp;
        if(i&1){
           temp = (i+1)/2 * i;
        }
        else{
            temp = (i/2) *(i+1);
        }
        dp[i] = temp;
    }
    long long n;
    cin >> n;
    int pos = upper_bound(dp, dp+NN-1 , n) - dp;
    if(dp[pos-1] == n) pos--;
    string s;
//    for(int i = 0 ; i< pos ; i++){
//       s += ')';
//    }
//    for(int i = 0 ; i< pos ; i++){
//       s += '(';
//    }
    int rem = dp[pos] - n;
//    cout << rem << endl;
    int first = 0;
    int dd = pos-rem;
    int flag = 0;
    for(int i = 0 ; i< pos ; i++){
       if(dd == i){
          cout << "()";
          flag = 1;
          continue;
       }
       cout << ")";
    }
    for(int i = 0 ; i< pos-flag; i++){
       cout << "(";
    }
    cout << endl;
}
