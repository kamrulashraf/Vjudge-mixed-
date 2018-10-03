#include <bits/stdc++.h>
using namespace std;
#define N 100005
int main()
{
	 int test ;
	 cin >> test;
	 while(test--){
	 	 string s;
	 	 cin >> s;
	 	 int counter = 0;
	 	 for(int i = 0 ; i< s.size()  ;i++){
	 	 	  if(s[i] == 'D')
	 	 	  	 counter++;
	 	 }
	 	 if(counter){
	 	 	 printf("You shall not pass!\n");
	 	 }
	 	 else printf("Possible\n");
	 }
}