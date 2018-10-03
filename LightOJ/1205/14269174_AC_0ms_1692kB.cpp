
#include <bits/stdc++.h>
using namespace  std;

#define N 100005
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
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
int digit[21], res[22];
string cnv(ll a){
  string ret;
  if(!a) ret +='0';
  while(a){
     ret += a%10+48;
     a /= 10;
  }
  reverse(ret.begin() , ret.end());
  return ret;

}

string minusOne(string s){
   string ret;
   int carry = 1;


   for(int i = s.size()-1 ; i>= 0 ; i--){
//        cout << s[i] << ' ' << carry << endl;
        if(s[i] < carry+48){
           ret += '9';
//           cout << '*' << endl;
        }
        else{

//            cout << '#' << ' ' << (char) (s[i]-carry) <<  endl;
            ret += (char) (s[i] - carry);
            carry = 0;
        }
   }
   reverse(ret.begin() , ret.end());
   return ret;
}

bool notAllZero(string temp){
    for(int i = 0 ; i< temp.size() ; i++){
       if(temp[i] != '0') return true;
    }
    return false;

}

int call(string s,int flag = 0){
    string temp, temp1;
    int sz = s.size()-1;
    if(s.size() == 0) return 1;
    if(s.size() == 1) return s[0]-48+ flag;

//    cout << s << endl;
    for(int i =1 ; i< sz ; i++){
       temp += s[i];
    }
    int ret = 0;
    temp1 = minusOne(temp);


    sz = temp.size();
//    cout << temp <<  ' ' << temp1 << ' ' << sz << endl;
    if(flag == 1){
       if(s[sz+1] < s[0]){
//           cout << s << ' ' <<  s[l]-48-1 << '#' << digit[sz] << ' ' << sz <<  endl;
           ret = (s[0]-48)*digit[sz];
           if(notAllZero(temp))
           ret += call(temp1,1);
       }
       else{
         ret = (s[0]-48)*digit[sz];
         ret += call(temp,1);
       }
    }

    else{
        if(s[sz+1] < s[0]){

           ret = (s[0]-48-1)*digit[sz];
//           cout << ret << ' ' << notAllZero(temp) << ' ' << temp1 <<  endl;
           if(notAllZero(temp))
           ret += call(temp1,1);
       }
       else{
         ret = (s[0]-48-1)*digit[sz];
         ret += call(temp,1);
       }
    }
    return ret;
}
ll call(ll a){
    string s = cnv(a);
}
int main()
{
    digit[0] = 1;
    digit[1] = 10;
    digit[2] = 10;
    for(int i = 3 ; i <= 18 ; i++) digit[i] = digit[i-2]*10;
    res[1] = 9;
    res[2] = 18;
    for(int i = 3 ; i<  18 ; i++){
          res[i] = res[i-1] + 9*digit[i-2];
    }

    int test , cs = 1;
    sca(test);
    while(test--){
       ll p , q;
       string a , b;
       scanf("%lld %lld",&p,&q);
       if(p > q) swap(p,q);
       p--;
       a = cnv(p);
       b = cnv(q);
//       cout << a << ' ' << b << endl;

       int res1 = call(b,0) ;
//       cout << res1 << endl;

       if(b.size() > 0)
       res1 += res[b.size()-1];
//       cout << res1 << endl;

       int res2 = call(a,0);
       res2 += res[a.size()-1];
       res1 -= res2;

//       cout << res1 << ' ' << res2 << ' ' << a << ' ' << b << endl;
       printf("Case %d: %d\n",cs++ , res1);

    }


}
