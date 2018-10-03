#include <bits/stdc++.h>
using namespace std;
int res ;

void fun(string s){
     if(s[0] == '+'){
         res ++ ;
         return;
     }
     if(s[0] == '-'){
         res -- ;
         return;
     }
     if(s[1] == '+'){
         res ++ ;
         return;
     }
     if(s[1] == '-'){
         res -- ;
         return;
     }

}
int main()
{
     int n;
     cin >> n;
     while(n--){
         string s;
         cin >> s;
         fun(s);

     }
     cout << res << endl;
}
