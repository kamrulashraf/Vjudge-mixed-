#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
vector <ll> v;
ll a[N],save[N] = {2};
void seive(void){
 for(ll i = 3 ; i*i <= N ; i++)
    for(ll j = i*i ; j<= N ; j+= 2*i)
       a[j] = 1;
 for(ll i = 3 , j = 1 ; i<= N ; i+=2)
 if(a[i] == 0){
    save[j] = i;
    j++;
 }
}

ll sod(ll num){
   ll temp = num, ans = 1, m,i, counter;
   for(i = 0 ; save[i] <= sqrt(temp) ; i++)
   {
       if(num%save[i] == 0){
        m = save[i];
        counter = 0;
        while(num%save[i]==0){
            m *= save[i];
            counter++;
            num /= save[i];
        }
        ans *= (m-1)/(save[i]-1);
        if(counter>0) v.push_back(counter+1);
       }
   }
   if(num>1){
    ans = (ans*((num*num-1))/(num-1));
    v.push_back(2);
   }
   return ans;
}


int main()
{
    seive();
    ll test, a , b , k,sum1 , sum2 ,i , j, nod;
    scanf("%lld", &test);
    while(test--){
        scanf("%lld %lld %lld", &a, &b , &k);
        ll temp = a/k*k;
        if(temp < a ) temp += k;
        for(i = temp, sum1 = 0, sum2 = 0 ; i <= b ; i+= k)
        {
            v.clear();
            sum2 += sod(i);
            for( j = 0, nod = 1 ; j<v.size() ;j++)
                nod *= v[j];
            sum1 += nod;
        }
        cout << sum1 << ' ' << sum2 << endl;

    }
}
