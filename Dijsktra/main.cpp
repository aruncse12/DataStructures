#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAX 100
int main()
{
    vector < pair <long long int, long long int> > graph[MAX];
    long long int dist[MAX];
    bool visited[MAX];
    long long int n,m,a,b,w,i,j;
    multiset <pair <long long int, long long int> > s;
    scanf("%lld %lld", &n, &m);
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(w,b));
    }
    for(i=1;i<n+1;i++)
    {
        visited[i]=false;
        dist[i]=1000000000;
    }
    s.insert(make_pair(0,1));
    dist[1]=0;
    while(!s.empty())
    {
        pair <long long int, long long int> temp = *s.begin();
        s.erase(s.begin());
        
        if(visited[temp.second])
            continue;
        visited[temp.second]=true;
        for(i=0;i<graph[temp.second].size();i++)
        {
            if(dist[graph[temp.second][i].second]>graph[temp.second][i].first+dist[temp.second])
            {
                dist[graph[temp.second][i].second]=graph[temp.second][i].first+dist[temp.second];
                s.insert(make_pair(dist[graph[temp.second][i].second],graph[temp.second][i].second));
            }
        }
    }
    
    for(i=2;i<n+1;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}