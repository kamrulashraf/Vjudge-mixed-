#include <bits/stdc++.h>
using namespace std;


vector < int > zAlgorihm(string s){
  vector< int > z(s.size());
  int l=0, r=0,len=s.size();

  for(int i = 1 ; i< len ; i++){
        if(i <= r) z[i] = min(r-i+1 , z[i-l]);

        while( i < len && s[z[i]] == s[i+z[i]])
            z[i]++;

        if( i+z[i]-1 > r){
            l = i;
            r = i+z[i]-1;
        }
  }
  return z;
}


int main()
{
    string s;
    cin >> s;
    std::vector< int > v;
    v = zAlgorihm(s);
    int mmax=  0;
    int res = 0;
    bool flag = 0;
    for(int i = 1 ; i< v.size() ; i++){
          int temp = v.size()-i;
          if(temp == v[i]){
             if(mmax >= v[i]){
                res = i;
                flag = 1;
                break;
             }
          }
          mmax = max(mmax, v[i]);
    }
    if(flag == 0){
        cout << "Just a legend" << endl;
    }
    else
    for(int i = res ; i < v.size() ; i++)
         cout << s[i] ;
     cout << endl;

}