#include<iostream>

#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
#include<string>
#include<set>
#include<vector>
using namespace std;
vector<char> v1[5],v2[5];
int k,cnt;
char s[6];
void dfs(int cur)
{
    if(cnt>k) return ;
    if(cur==5)
    {
        cnt++;
        if(cnt==k)
        {
            for(int i=0; i<5; i++) cout<<s[i];
            cout<<endl;
        }
        return ;
    }
    for(int i=0; i<v1[cur].size(); i++)
    {
        s[cur]=v1[cur][i];
        dfs(cur+1);
    }
    return ;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>k;
        cnt=0;
        getchar();
        char c;
        for(int i=0;i<5;i++)
        {
            v1[i].clear();
            v2[i].clear();
        }
        for(int i=0; i<6; i++)
            for(int j=0; j<5; j++)
            {
                cin>>c;
                v1[j].push_back(c);
            }
        for(int i=0; i<6; i++)
            for(int j=0; j<5; j++)
            {
                cin>>c;
                v2[j].push_back(c);
            }
        for(int i=0; i<5; i++)
        {
            sort(v1[i].begin(),v1[i].end());
            sort(v2[i].begin(),v2[i].end());
        }
        for(int i=0; i<5; i++)
        {
            int j;
            for(j=0; j<v1[i].size() && j<v2[i].size();)
            {
                if(v1[i][j]==v2[i][j]) j++;
                else if (v1[i][j]<v2[i][j]) v1[i].erase(v1[i].begin()+j);
                else if (v1[i][j]>v2[i][j]) v2[i].erase(v2[i].begin()+j);
            }
            while(j!=v1[i].size()) v1[i].erase(v1[i].begin()+j);
            while(j!=v2[i].size()) v2[i].erase(v2[i].begin()+j);
        }
        for(int i=0;i<5;i++)
        for(int j=1;j<v1[i].size();)
        {
            if(v1[i][j]==v1[i][j-1]) v1[i].erase(v1[i].begin()+j);
            else j++;
        }
        dfs(0);
        if(cnt<k) cout<<"NO"<<endl;
    }
    return 0;
}