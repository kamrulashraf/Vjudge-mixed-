#include <bits/stdc++.h>
using namespace std;
#define NN 35
int a[NN], n, b[NN];
long long maxW;
std::vector< long long >  subset(int n, int a[]){
    std::vector< long long > v;
    for(int i = 0 ; i< (1<<n) ; i++){
         long long sum = 0;
         for(int j = 0 ; j< n ; j++){
             if(i & (1<< j)){
                sum += a[j];
             }
         }
   
         v.push_back(sum);
    }
    return v;
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        scanf("%d%lld",&n, &maxW);
        int tempA = n/2, tempB = 0;
        for(int i = 0 ; i< tempA ; i++){
            scanf("%d",&a[i]);
        }
        for(int j = tempA, i = 0 ; j< n ; j++ , i++){
           scanf("%d",&b[i]);
           tempB++;
        }
 
        std::vector< long long  > v1,v2;
        v1 = subset(tempA, a);
        v2 = subset(tempB , b);
        sort(v2.begin() , v2.end());
        long long counter = 0;
        for(int i = 0 ; i< v1.size() ; i++){
              long long temp= maxW - v1[i];
              if(temp < 0) continue;
              int pos = upper_bound(v2.begin(),v2.end(), temp) - v2.begin();
              counter += pos;
        }
 
        printf("Case %d: %lld\n",cs++ , counter);
 
    }
}