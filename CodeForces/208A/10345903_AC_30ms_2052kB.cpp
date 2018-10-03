#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin >> s;
  string save;
  vector  < string > v;
  for(int i = 0 ; i< s.size() ; i++){
       if(s[i] == 'W'){
          string temp;
          for(int j = 0 ; j< 3 && i+j < s.size() ; j++){
                temp += s[i+j];
          }
          if(temp == "WUB"){
             i += 2;
             if(save.size()){
                v.push_back(save);
                save.clear();
             }
          }
          else{
              save += s[i];
          }
       }
       else save += s[i];
  }

  if(save.size()) v.push_back(save);
  for(auto x : v){
     cout << x << ' ';
  }
}
