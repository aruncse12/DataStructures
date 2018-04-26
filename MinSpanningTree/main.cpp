#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define MAX 100
int main()
{
    vector < pair <long long int, long long int> > graph[MAX];
    long long int minDist=0;
    bool visited[MAX];
    long long int n,m,a,b,w,i,j;
    //multiset <pair <long long int, long long int> > s;
    priority_queue < pair <long long int, long long int>, vector < pair <long long int, long long int> >, greater < pair <long long int, long long int> > > s;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(w,b));
    }
    for(i=1;i<n+1;i++)
    {
        visited[i]=false;
    }
    s.push(make_pair(0,1));
    while(!s.empty())
    {
        pair <long long int, long long int> temp = s.top();
        s.pop();
        
        if(visited[temp.second])
            continue;
        visited[temp.second]=true;
        minDist+=temp.first;
        for(i=0;i<graph[temp.second].size();i++)
        {
            if(!visited[graph[temp.second][i].second])
            {
                s.push(graph[temp.second][i]);
            }
        }
    }
    cout<<minDist;
    return 0;
}