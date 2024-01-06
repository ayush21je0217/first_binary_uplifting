#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
#define ninf -1e18
#define p_b push_back
#define frl(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i>=b;i--)
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define min_pq_of_pair priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
#define max_pq priority_queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vvvvi vector<vector<vector<vector<int>>>>
#define print(x) cout<<x<<"\n";
#define sort(v) sort(v.begin(),v.end())
void binary_lifting(int node,int par,vi g[],vvi &up)
{
    up[node][0]=par;
    frl(i,1,20)
    {
        if(up[node][i-1]!=-1)
        {
            up[node][i]=up[up[node][i-1]][i-1];
        }
        else 
        up[node][i]=-1;
    }
    for(auto it:g[node])
    {
        if(it==par)continue;
        binary_lifting(it,node,g,up);
    }
}
int find_xth_parent(int node,int x,vvi &up)
{
    if(node==-1 || x==0)return node;
    frr(i,19,0)
    {
        if(x>=(1<<i))
        {
            return find_xth_parent(up[node][i],x-(1<<i),up);
        }
    }
}
void s()
{
    int n,q;
    cin>>n>>q;
    vi g[n+1];
    frl(i,2,n+1)
    {
        int a;
        cin>>a;
        g[i].push_back(a);
        g[a].push_back(i);
    }
    vvi up(n+1,vi(20));
    binary_lifting(1,-1,g,up);
    while(q--)
    {
        int node,x;
        cin>>node>>x;
        cout<<find_xth_parent(node,x,up)<<"\n";
    }
}
int32_t main()
{
int t=1;
// cin>>t;
while(t--)s();
}


