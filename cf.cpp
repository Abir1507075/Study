#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 200005

int n,m;
int arr[lim+10];

int cnt[lim+10];

vector< pair<int,int> >edge[lim+10];
map<pair<int,int>,int>mp;
pair<int,int>p[lim+10];
vector<pair<int,int> >res;
int vis[lim+10];
int col[lim+10];
int dfs(int src,int pl,int par){
    int cnt=1;
    vis[src]=1;
    col[lim]=pl;
    for(int i=0;i<edge[src].size();i++){
        int u=edge[src][i].first;
        int idx=edge[src][i].second;
        if(u!=par){
            if(!vis[u]){
                if(pl==0)res.push_back(make_pair(src,u));
                else res.push_back(make_pair(u,src));
                cnt=min(cnt,dfs(u,1-pl,src));
            }
            else{
                if(col[u]==(1-pl)){
                    cnt=0;
                }
                else{
                    if(pl==0)res.push_back(make_pair(src,u));
                    else res.push_back(make_pair(u,src));
                    cnt=min(cnt,dfs(u,1-pl,src));
                }
            }
        }
    }
    return cnt;
}



int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[make_pair(a,b)]=1;
        edge[a].push_back(make_pair(b,i));
        edge[b].push_back(make_pair(a,i));
        p[i]=make_pair(a,b);
    }
    int f=dfs(1,0,-1);
    if(f==1){
            cout<<"YES"<<endl;
             for(int i=0;i<res.size();i++){
        if(mp[res[i]]==0){
            cout<<"0";
        }
        else cout<<"1";
    }
    }
    else cout<<"NO"<<endl;

}
