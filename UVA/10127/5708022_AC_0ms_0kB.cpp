 #include <bits/stdc++.h>
 using namespace std;
 int main()
 {
    long long n;
    while(cin >> n){
       long long temp = 0;
       int counter = 1;
       while(1){
         temp = (temp*10 +1 )%n;
         if(temp==0) break;
         counter++;
       }
       cout << counter << endl;
    }


 }