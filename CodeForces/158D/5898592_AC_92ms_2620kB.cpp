#include <bits/stdc++.h>
using namespace std;
vector <int> v;
void factor(int n){
   for(int i = 2 ; i*i <= n ; i++){
       if(n%i == 0){
           v.push_back(i);
           if(i*i != n) v.push_back(n/i);
       }
   }
}
int main()
{
   int n, a[20002];
   vector <int> ans;
   cin >> n ;
   long long sum = 0 , s1 = 0, s2 = 0;
   for(int i = 0 ; i< n ; i++) cin >> a[i];
   factor(n);
    for(int i = 0 ; i< v.size() ; i++){
        for(int j = 0 ; j< v[i] ; j++){
           int counter = 0;
           sum = 0;
           for(int k = j; k< n ; k+= v[i]){
              sum += a[k];
              counter++;
           }
          if(counter > 2) ans.push_back(sum);
        }
    }
    sum = 0;
    for(int i = 0 ; i< n ; i++)
      sum += a[i];
    ans.push_back(sum);
    sort(ans.begin() , ans.end());
    cout << ans[ans.size()-1] << endl;
}
