#include <bits/stdc++.h>
using namespace std;

string a[150005],b[150001];
map < string , int > mark;
int main()
{
   int test , cs = 1;
   scanf("%d",&test);

   while(test--){
   	  int n , m;
   	  cin >> n >>m ;
   	  getchar();
   	  for(int i=0;i<n;i++) getline(cin,a[i]);

   	  for(int j=0;j<m;j++) getline(cin,b[j]);
      int counter = 0;
   	  for(int i = 0 ; i< n ; i++){
   	  	  for(int j=0;j<m;j++){
   	  	  	 string temp = a[i]+b[j];
   	  	  	 if(mark[temp] == 0){
   	  	  	 	 mark[temp] =1;
   	  	  	 	 counter++;
   	  	  	 }
   	  	  }
   	  }
   	  printf("Case %d: %d\n",cs++ , counter);
   	  mark.clear();
   }
}
