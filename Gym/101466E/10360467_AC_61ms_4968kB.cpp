#include <bits/stdc++.h>
using namespace std;
#define N 100010
int tree[N];


vector < int > zAlgorithm(string s){
   vector < int > z(s.size());
   int l = 0 ,r  = 0, len = s.size();

   for(int i = 1 ; i< len ; i++){
      if(i <= r)
         z[i] = min(r-i+1,z[i-l]);
      while(i < len && s[z[i]] == s[i+z[i]])
         z[i]++;

      if(i+z[i]-1 > r){
        l = i;
        r = i+z[i]-1;
      }
   }
   return z;
}

void update(int indx,int val){
   while(indx <= 100003){
      tree[indx] += val;
      indx += indx & -indx;
   }
}

int query(int indx){
    int sum = 0;
    while(indx){
        sum += tree[indx];
        indx -= indx & -indx;
    }
    return sum;
}
int main()
{
     string a , b ;
     int n;
     getline(cin,a);
     getline(cin,b);
     cin >> n;
     string temp;
     temp += b;
     temp += '#';
     temp += a;
     vector < int >  v;
     v = zAlgorithm(temp);

//     for(auto x : v){
//         cout << x << ' ';
//     } cout << endl;

     for(int i = b.size()+1 ; i < v.size() ; i++){
             int temp = v[i];
             update(1,1);
//             cout << i << ' ' << temp << endl;
             update(temp+1,-1);
     }
     bool flag = 0;
     for(int i = b.size() ; i >= 1 ; i--){
         int res =  query(i);
//         cout << i << ' ' << query(i) << endl;
         if(res >= n){
             for(int j = 0 ; j< i ; j++)
                printf("%c",b[j]);
             flag = 1;
             break;
         }
     }

     if(flag == 0){
        printf("IMPOSSIBLE\n");
     }

}