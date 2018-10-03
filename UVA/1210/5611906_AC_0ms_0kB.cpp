#include <bits/stdc++.h>
using namespace std;
bool a[10005];
vector <int> prime;
void seive(void){
for( int i = 3 ; i*i < 10005 ; i+=2)
    if(a[i] == 0)
      for( int j = i*i ; j<= 10005 ; j += 2*i)
        a[j] = 1;
prime.push_back(2);
for( int i = 3 ; i< 10005 ; i+= 2)
    if(a[i] == 0) prime.push_back(i);
}
int main()
{
   int num, arr[10005], ans, hit[10005] = {0};
   seive();
   for(int i = 0 ; i< prime.size() ; i++)
      arr[i] = arr[i-1]+ prime[i];
          for(int i = 0 ;i< prime.size() ; i++)
             for(int j = i ; j< prime.size() ; j++){
                int temp = arr[j]-arr[i-1];
                if(temp > 10000)
                    continue;
                hit[temp]++;
             }
   while(cin >> num){
           if(num == 0) break;
           cout << hit[num] << endl;
       }

}
