#include <bits/stdc++.h>
using namespace  std;

#define N 3000000
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)

    string s;
bool call(int a , int b){

    string temp;

    for(int i = a ; i<= b ; i++ )
         temp += s[i];
    
    string save = temp;
    reverse(save.begin() , save.end());

    if(temp == save){
         int tt = b-a+1;
         if(tt&1) return true;
         else return false;
    }
    else return true;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >>  s;
    bool flag = 1;
    for(int i = 0 ; i< s.size() ; i++){
         for(int j = i+1 ; j < s.size() ; j++){
             flag &=  call(i,j);
         }
    }
    if(flag == 1) cout << "Odd." << endl;
    else cout << "Or not." << endl;
}