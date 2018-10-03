#include <bits/stdc++.h>
using namespace std;
class data{
public:
int a,b;
int c;
  data(int a , int b , int c){
     this -> a = a;
     this -> b = b;
     this -> c = c;

  }
};
class comp{
    public:
       bool operator()(const data& x, const data& y){
           if(x.c < y.c) return true;
           else return false;
       }

};

class DSU{
 int parent[105], rank[105],sz = 105;
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
  int test , cs = 1;
  cin >> test;
  while(test--){
     int node , edge;
     cin >> node >> edge;
     priority_queue < data , vector < data >  , comp > q;
     for(int i = 0 ; i< edge ; i++){
        int a, b , c;
        cin >> a >> b >> c;
        q.push(data(a,b,c));
     }
     DSU temp;
     long long sum = 0;
     long long mmin = 1e15;
     while(!q.empty()){
        int a = q.top().a;
        int b = q.top().b;
        long long c = q.top().c;
        q.pop();
        if(temp.makeUnion(a,b)){
           mmin  = min(mmin,c);
      //     sum += c;
        }
     }

    printf("Case #%d: %lld\n",cs++, mmin);
  }

}
