#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main()
{
   long long  n  , test , cs = 1;
   string s[1005];
   cin >> test;
   while(test--){
     cin >> n;
     for(int i = 0 ; i< n ; i++){
        cin >> s[i];
     }
     string str;
     cin >> str;
     printf("Case %lld:\n", cs++);
     for(int i = 0 ; i < n ; i++){
        int counter = 0;
        for(int j = 0 ; j< str.size() ; j++){
            if(s[i][j] != str[j])
                 counter++;
        }
        if(counter < 2)
             cout << s[i] << endl;
     }
   }
 return 0;
}
