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
    int arr[6000000];
    int mark[10000000];
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

    int n;
    cin >> n;

    for(int i = n+1 ; i<= n+10000000 ; i++){
         int temp = i;
         int flag = 0;
         while(temp){
            if(temp%10==0){
                flag = 1;
                break;
            }
            temp /= 10;
         }
         if(flag == 0){
            cout << i << endl;
            break;
         }
    }
}
