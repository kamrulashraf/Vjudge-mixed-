#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll mod = 1e9+7;
ll base = 1e9+3;


ll hashVal1[N];
ll hashVal2[N];

void hashFuntion(string s, long long hashVal[]){
     for(int i = 0 ; i < s.size() ; i++){
     	  hashVal[i+1] =  (hashVal[i]*base+s[i]-64)%mod;
     }
}

template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}


int hashValBetween(int i , int j,ll hashVal[]){
    return (hashVal[j] - (hashVal[i-1]*big(base,(ll) j-i+1,mod))%mod + mod)%mod;
}

int main()
{
    string s;
    while(cin >> s){

    	string rev = s;
    	reverse(rev.begin(),rev.end());
    	hashFuntion(s,hashVal1);
    	hashFuntion(rev,hashVal2);

    	// for(int i = 0 ; i<= s.size() ; i++){
    	// 	 cout << hashVal1[i] << '*' << hashVal2[i] << endl;
    	// }
    	int save = 0;
    	int sz = s.size();
    	for(int i = 1;  i <= s.size() ; i++){
    		 int temp = hashValBetween(i,s.size(),hashVal1);
    		 if(temp == hashVal2[sz-i+1]){
    		 	 save = i;
    		 	 break;
    		 }
    	}
    	for(int i = 0 ; i< save-1 ; i++){
    		cout << s[i];
    	}cout << rev << endl;
    }
}
