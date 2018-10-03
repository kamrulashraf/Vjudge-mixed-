#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,maxi=0,sum=0;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int m;
    cin>>m;
    int x[m];
    for(int i=0;i<m;i++){
        cin>>x[i];
        sum+=x[i];
    }
    cout<<(maxi*m)+(sum)<<endl;
}
