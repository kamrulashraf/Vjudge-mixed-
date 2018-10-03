#include <bits/stdc++.h>
using namespace std;
int arr[3000] , brr[3000];
map < int , int > mark;
int main()
{
     int  n;
    cin >> n;
    int temp = ((n)*(n-1))/2;
    set < int > s;
    std::vector< int > v;
    temp--;
    for(int i = 0 ; i< temp ; i++){
        cin >> arr[i] >> brr[i];
        mark[arr[i]]++;
        mark[brr[i]]++;
        s.insert(arr[i]);
        s.insert(brr[i]);
    }
    for(auto x : s){
        if(mark[x] != n-1){
           v.push_back(x);
         }
    }
    std::vector< int > lost;
    for(int i = 0 ; i< temp ; i++){
        if(arr[i] == v[0]){
             lost.push_back(brr[i]);
        }
    }

    bool ll = false;
    for(int i = 0 ; i< temp ; i++){
        if(brr[i] == v[1]){
            for(auto x : lost){
                if(x==arr[i]){
                   ll = true;
                   break;
                }
            }
        }
        if(ll==true) break;
    }
    if(ll){
       cout << v[0] << ' ' <<  v[1] << endl;
    }
    else cout << v[1] << ' ' << v[0] << endl;
}
