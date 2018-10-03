#include <bits/stdc++.h>
using namespace std;
#define NN 1000005
#define N 10005
#define ll long long
string s;


int main()
{
     int n;
     cin >> n;
     cin >> s;
     int mmax = 0;
     map < int , int > mark;
     for(int i = 0 ; i<= n ; i++){
         mark[s[i]]++;
         mmax = max(mmax,mark[s[i]]);
     }
     int counter = 0;
     for(int i = '0' ; i<= '9';i++){
        if(mark[i]==mmax) counter++;
     }
     cout << counter << endl;
        for(int i = '0' ; i<= '9';i++){
        if(mark[i]==mmax){
            for(int j = 0 ; j < mmax ; j++){
                cout << (char) i ;
            } cout << endl;
        }
     }
}
