#include<bits/stdc++.h>
using namespace std;
int freq[100],ok[100];

int main()
{
    int n,m,maxi=0;
    cin>>n>>m;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            freq[i+j]++;
            maxi=max(maxi,freq[i+j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(freq[i+j]==maxi && ok[i+j]==0){
                ans.push_back(i+j);
                ok[i+j]=1;
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
