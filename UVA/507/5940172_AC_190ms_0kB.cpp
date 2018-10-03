#include <bits/stdc++.h>
using namespace std;
int main()
{
 //  freopen("a.txt","w",stdout);
   int test , cs = 1;
   int a[20005];
   cin >> test;
   while(test--){
      int n;
      cin >> n;
      for(int i  = 1 ; i< n ; i++){
         cin >> a[i];
      }
      long long sum = 0;
      int counter = 0;
      int len = 0;
      int b = 0 , e = 0;
      long long ans = -10000000;
      for(int i = 1, j = 1 ; i< n ; i++){
         sum += a[i];
         counter++;
         if(sum > ans){
            ans= sum;
            b = j;
            e = i;
            len = counter;
         }
         if(sum == ans){
            if( counter > len){
               len = counter;
               b = j;
               e = i;
            }
         }
         if(sum < 0){
            sum = 0;
            counter = 0;
            j = i;
         }
      }
//      cout << len << endl;
      b++ ; e++;
      b = e - len ;
      if(ans <= 0) cout << "Route "<< cs++ << " has no nice parts" << endl;
      else  cout << "The nicest part of route " << cs++ << " is between stops " << b << " and " << e << endl;
   }

}
