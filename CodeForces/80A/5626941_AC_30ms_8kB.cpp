#include <bits/stdc++.h>
using namespace std;
bool a[55];
vector <int> prime;
void seive(){
int n = 51;
for(int i = 3 ; i*i <= n ; i+=2)
   if(a[i]==0)
     for(int j = i*i ; j<= n ; j+= 2*i)
        a[j] = 1;
prime.push_back(2);
for(int i = 3 ; i<= n ; i+= 2)
   if(a[i] == 0) prime.push_back(i);


}
int main()
{
  int a , b;
  seive();
 // for(int i = 0 ; i< 10 ; i++) cout << prime[i] << ' ';
  while(cin >> a >> b){
     int temp = lower_bound(prime.begin() , prime.end() , a) - prime.begin();
     if(prime[temp+1] == b)
       cout << "YES" << endl;
     else cout << "NO" << endl;
  }
  return 0;
}
