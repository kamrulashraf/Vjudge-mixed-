#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long 
long long mod = 1000000007;
ll base = 1000000003;
int hashString[N], hashPattern[N];
long long hashFuntion(string s, int hashVal[]){
    ll temp = 0;
    for(int i =  0 ; i< s.size() ; i++){
         temp = temp*base + s[i]-'a'+1;
         temp = temp%mod;
         hashVal[i+1] = (temp+mod)%mod;
    }
    return (temp+mod)%mod;
}

template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}


int main()
{
    int test , cs = 1;

    while(cin >> test){
        string a , b;
        cin >> a >> b;
        int target = hashFuntion(a,hashPattern);
        hashFuntion(b,hashString);
        ll sz = a.size();
        long long res = 0, counter = 0;

        // for(int i = 0 ; i<= b.size() ; i++)
        //     cout << hashString[i] << ' ' ;
        // cout << endl;
        for(int i = sz ; i <= b.size() ; i++){
             int temp  = (hashString[i]- (hashString[i-sz]*big(base,sz,mod))%mod + mod)%mod;
             // cout << i << ' ' << temp << endl;
             if(temp == target){
                res = i-sz;
                counter++;
                printf("%lld\n",res);
             }
        }
        if(counter == 0) printf("\n");
    }
}
