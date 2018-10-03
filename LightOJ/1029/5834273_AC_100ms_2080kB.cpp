#include <bits/stdc++.h>
using namespace std;
class data{
  public :
     int a , b , c;
     data(int a , int b , int c){
       this -> a = a;
       this -> b = b;
       this -> c = c;
     }
};
bool comp(data x , data y){
    if(x.c < y.c) return true;
    else return false;
};

bool comp1(data x , data y){
    if(x.c > y.c) return true;
    else return false;
};

class DSU{
 int parent[105], rank[105],sz = 105;
 public:
       void clr(){
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
vector < data > v;
int mst(){
    DSU temp;
    temp.clr();
    int sum = 0;
    for(int i = 0 ; i< v.size() ; i++){
        int a = v[i].a;
        int b = v[i].b;
        int c = v[i].c;
        if(temp.makeUnion(a,b)){
           sum += c;
        }
    }
return sum;
}
int main()
{
  int test , cs = 1;
  cin >> test;
  while(test--){
      int node;
      v.clear();
      scanf("%d", & node);
      int a, b , c;
      while(scanf("%d%d%d", &a, &b , &c) == 3){
            if(!a && !b && !c) break;
            v.push_back(data(a,b,c));
      }
      sort(v.begin() , v.end(), comp);
      int mintemp = mst();
      sort(v.begin(),v.end() , comp1);
      int maxtemp = mst();
      mintemp = mintemp+maxtemp;
      printf("Case %d: ",cs++);
      if(mintemp%2==0) printf("%d\n",mintemp/2);
      else printf("%d/%d\n",mintemp,2);
  }

}
