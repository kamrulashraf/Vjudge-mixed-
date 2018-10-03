#include <bits/stdc++.h>
using namespace std;
int a[3005];
std::vector< int > prime;
void seive(){
    for(int i = 2 ; i<= 3000 ; i++){
        if(a[i] == 0){
            for(int j = i*i ; j<= 3000 ; j+=i){
                a[j] = 1;
            }
        }
    }
    for(int i = 2 ; i<= 3000 ; i++)
        if(a[i] == 0)
            prime.push_back(i);
}


bool factor(int n){
    int counter = 0;
    for(int i = 0 ; prime[i]*prime[i] <= n ; i++){
        int p = prime[i];
        if(n%p==0){
            counter++;
            while(n%p==0){
               n/=p;
            }
        }
    }
    if(n>1) counter++;
    return (counter==2);
}
int main()
{
   seive();
   std::vector<int > v;
   for(int i = 3 ; i<= 3000 ; i++){
       bool f = factor(i);
       if(f) v.push_back(i);
   }
   int n;
   cin >> n;
   int pos = upper_bound(v.begin(),v.end(),n)-v.begin();
   cout << pos << endl;
return 0;
}
