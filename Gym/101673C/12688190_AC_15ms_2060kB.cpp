#include <bits/stdc++.h>
using namespace  std;

#define N 3000000
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)

map < char , int > mark;
char rot(char ch , int sum){
      int temp = mark[ch];
      temp += sum;
      temp %= 26;

      char ret = (char) (temp+'A');
      return ret;
}
int main()
{
	string s;
	cin >> s ;
	string a  , b;

	int len = s.size();
	for(int i = 0 ; i< len ; i++){
		 if(i < len/2) a += s[i];
		 else b += s[i];
	}

	// cout << a << ' '<< b << endl;

	string temp;

	int cur = 0;
	for(int i = 'A' ; i<= 'Z' ; i++){
	   temp += (char) i;
	   mark[i] = cur++;
	}

    int sum = 0;
    for(int i = 0 ; i< a.size() ; i++){
       sum += mark[a[i]];
    }

    for(int i = 0 ; i< a.size() ; i++){
       a[i] = rot(a[i],sum);
    }

    sum = 0;
    for(int i = 0 ; i< b.size() ; i++){
    	sum += mark[b[i]];
    }

    for(int i = 0 ; i< b.size() ; i++){
    	b[i] = rot(b[i],sum);
    }

    string res ;
    for(int i = 0 ; i <a.size() ; i++){
       int temp = a[i]+b[i];
       char ch = temp%26;
       ch = (char) (ch+'A');
       res += ch;
    }

    cout << res << endl;
}
