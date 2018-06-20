#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define MAX 100
vector <int> tree[MAX];
queue <int> q;
int visited[MAX];
void dfs(int i)
{
    q.push(i);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        cout<<t<<endl;
        visited[1]=1;
        for(i=0;i<tree[t].size();i++)
        {
            if(!visited[tree[t][i]])
            {
                dfs(tree[t][i]);
            }
        }
    }
}
int main()
{
    set <int> nodes;
    set <int>::iterator it;
    int m, n, num, i, j;
    cin>>num;
    for(i=0;i<MAX;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<num;i++)
    {
        cin>>m>>n;
        tree[m].push_back(n);
        //tree[n].push_back(m);
        nodes.insert(m);
        nodes.insert(n);
    }
    for(it=nodes.begin();it!=nodes.end();it++)
    {
        cout<<(*it);
        for(j=0;j<tree[(*it)].size();j++)
        {
            cout<<"-->"<<tree[(*it)][j];
        }
        cout<<endl;
    }
    cout<<endl;
    dfs(1);
}