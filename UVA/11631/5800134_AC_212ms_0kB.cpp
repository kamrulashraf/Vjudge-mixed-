#include <bits/stdc++.h>
using namespace std;
struct data{
 int a, b ;
 long long c;
 data(int x , int y , long long z){
    a= x;
    b = y;
    c= z;
 }
};
class comp{
   public:
   bool operator()(const data& x , const data& y){
      if(x.c > y.c) return true;
      else return false;

   }

};
class DSU{
 int parent[200005], rank[200005],sz = 200005;
 public:
       DSU(){
            memset(rank,0,sizeof(rank));
            for(int i = 0 ; i< sz ; i++)
               parent[i] = i;
       }
    bool makeUnion(int a , int b){
       int parA = dsuFind(a);
       int parB = dsuFind(b);
       if(parA ==  parB) return 0;
       else{
           if(rank[parA] >= rank[parB]) swap(parA,parB);
           parent[parA] = parB;  // rank of parB is greater than parA
           if(rank[parA] == rank[parB]) rank[parB]++;   // increasing rank of parB( with whom connect anoter child)
           return 1;
       }
    }
    int dsuFind(int a){
        if(parent[a] == a) return a;
        return parent[a] = dsuFind(parent[a]);

    }

};
int main()
{
   int node , edge;
   while(scanf("%d %d", &node , &edge) == 2){
      priority_queue < data , vector < data > , comp > q;
      if(!node && !edge) break;
      for(int i = 0 ; i< edge ; i++){
         int a ,b ;
         long long c;
         scanf("%d%d%lld", &a , &b , &c);
         q.push(data(a,b,c));
      }
      DSU temp;
      long long sum = 0;
      while(!q.empty()){
         int a = q.top().a;
         int b = q.top().b;
         long long c = q.top().c;
         if(!temp.makeUnion(a,b)){
            sum += c;
         }
         q.pop();
      }
      cout << sum << endl;

   }
}
