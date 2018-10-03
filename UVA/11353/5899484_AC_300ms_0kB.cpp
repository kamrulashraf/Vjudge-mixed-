#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int a[2000005];
vector <int> prime;

bool comp(pi a , pi b){
    if(a.second < b.second) return true;
    else{
       if(a.second == b.second){
          if(a.first < b.first) return true;
          else return false;
       }
       else return false;
    }

}
inline void seive(long long num){
memset(a,0,sizeof(a));
for(int i = 2 ; i*i <= num ; i++)
  if(!a[i])
     for(int j = i*i ; j<= num ; j+= i)
       a[j] = i;
prime.push_back(2);
for(int i = 3 ; i<= num ; i+= 2)
    if(!a[i])
       prime.push_back(i);
}

int fac(int num){
   int counter = 0;
   while(a[num]){
      counter++;
   //   cout << a[num] << ' ';
      num = num/a[num];
   }
 //  cout << num << endl;
   counter++;
   return counter;
}
int main()
{
//  freopen("a.txt","w",stdout);
  seive(2000000);
  int num , cs = 1;
  vector < pair <int,int> > v;
  v.push_back(make_pair(1,0));

  for(int i = 2; i<= 2000000 ; i++){
     v.push_back(make_pair(i,fac(i)));
  }


  sort(v.begin() , v.end() , comp );
  while(scanf("%d", &num)){
     if(num == 0) break;
     printf("Case %d: %d\n", cs++ , v[num-1].first);
  }

}
