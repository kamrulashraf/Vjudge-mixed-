#include <bits/stdc++.h>
using namespace std;

bool comp(int a , int b){
   return a>b;
}
int main()
{
  int a[50], n;
  scanf("%d",&n);
  for(int i = 1 ; i<= n ; i++){
      if(i==1){
         cout << '*' ;
         for(int j = 0 ; j< n-2 ; j++){
             cout << ' ';
         }
         cout << "* ";

         for(int j = 0 ; j< n ; j++)
            cout << "*";

         cout << endl;
      }
      else if(i == n){
            for(int j = 0 ; j< n ; j++)
            cout << "*";
            cout << " *";
            for(int j = 0 ; j< n-2 ; j++){
             cout << ' ';
            }
            cout << "*" << endl;

      }
      else{
           cout << "*";
           for(int j = 0 ; j< n-2 ; j++){
             cout << ' ';
           }
           cout << "* *";
           for(int j = 0 ; j< n-2 ; j++){
             cout << ' ';
         }
          cout << "*" << endl;
      }


  }
}
