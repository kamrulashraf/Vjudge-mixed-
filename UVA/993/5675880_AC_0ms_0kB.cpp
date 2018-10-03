#include <bits/stdc++.h>
using namespace std;
int main()
{
 // freopen("a.txt" , "w", stdout);
  int test;
  long long num;
  cin >> test;
  while(test--){
     cin >> num;
     stack < int > st;
     if(num == 0 || num == 1){
       cout << num << endl;
       continue;
     }
     for(int i = 9 ; i > 1 ; i--){
        while(num%i == 0){
           st.push(i);
           num /= i;
        }
     }
     if(num != 1){
       cout << -1 << endl;
     }
     else {
          while(!st.empty()){
            cout << st.top() ;
            st.pop();
          }
          cout << "\n";
     }
  }
 return 0;
}
