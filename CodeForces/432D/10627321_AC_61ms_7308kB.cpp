#include <bits/stdc++.h>
using namespace std;

#define N 1000005
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


int tree[N], tar;


void update(int indx, int val){
     while(indx <= tar){
         tree[indx] += val;
         indx += indx & - indx;
     }
}

int tot(int indx){
    int sum =  0;
    while(indx){
        sum += tree[indx];
        indx -= indx & -indx;
    }
    return sum;
}

int main()
{
   // freopen("in.txt","r" , stdin);
   string s;
   cin >> s;
   tar = s.size()+1;
   string temp;
   temp += s ; 
   temp += '#';
   temp += s;
   vector < int > v;

   v = zAlgorihm(temp);

   // for(int i = 0 ; i< v.size() ; i++ )
   //    cout << v[i] << ' ' ;
   // cout << endl;
   int sz = v.size();

   for(int i = tar ; i< sz ; i++){
       // cout << i << ' ' << v[i] << endl;
       update(1,1);
       update(v[i]+1,-1);
   }
   int it = 1;
   vector < pair < int , int > > res;
   for(int i = sz-1 ; i >= tar ; i--){
       // cout << i << '#' << v[i] << endl;
       if(v[i] == it){
          int x = it;
          int y = tot(it);
          res.push_back(make_pair(x,y));
       }
       it++;
   }
   
   printf("%d\n", (int) res.size());
   for(int i = 0 ; i< res.size() ; i++){
      int x = res[i].first;
      int y = res[i].second;
      printf("%d %d\n",x,y);
   }


return 0;
}