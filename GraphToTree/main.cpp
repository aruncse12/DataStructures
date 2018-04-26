#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <cmath>
#define MAX 10
using namespace std;
bool isTree(vector <long long int> graph[], set <pair <long long int, bool> > nodes)
{
    long long int i, temp;
    set <pair <long long int, bool> >::iterator it;
    for(it=nodes.begin();it!=nodes.end();it++)
    {
        for(i=0;(*it).second==false&&i<graph[(*it).first].size();i++)
        {
            temp=(*it).first;
            nodes.erase(it);
            nodes.insert(make_pair(temp,true));
            if(nodes.find(make_pair(graph[(*it).first][i],false))!=nodes.end())
            {
                temp=(*nodes.find(make_pair(graph[(*it).first][i],false))).first;
                nodes.erase(nodes.find(make_pair(graph[(*it).first][i],false)));
                nodes.insert(make_pair(temp,true));
            }
        }
    }
    for(it=nodes.begin();it!=nodes.end();it++)
    {
        if((*it).second==false)
            return false;
    }
    return true;
}
void printGraph(vector <long long int> graph[])
{
    long long int i, j;
    cout<<endl;
    for(i=0;i<MAX;i++)
    {
        if(graph[i].size())
        {
            for(j=0;j<graph[i].size();j++)
                cout<<i<<"-->"<<graph[i][j]<<endl;
        }
    }
}
void printNodes(set <pair <long long int, bool > > nodes)
{
    set <pair <long long int,bool> >::iterator i;
    cout<<endl;
    for(i=nodes.begin();i!=nodes.end();i++)
        cout<<(*i).first<<" "<<(*i).second<<" ";
}
int main()
{
    vector <long long int> graph[MAX];
    set <pair <long long int,bool> > nodes;
    set < pair <long long int, bool> >::iterator it1;
    long long int it2, node;
    long long int numTc, n, m, t1, t2, i, j, visited[MAX], minCost;
    cin>>numTc;
    while(numTc)
    {
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>t1>>t2;
            graph[t1].push_back(t2);
            nodes.insert(make_pair(t1,false));
            nodes.insert(make_pair(t2,false));
        }
        
        minCost=((*nodes.end()).first)-((*nodes.begin()).first);
        printGraph(graph);
        printNodes(nodes);
        
        for(it1=nodes.begin();it1!=nodes.end();it1++)
        {
            for(it2=0;it2<graph[(*it1).first].size();it2++)
            {
                node = graph[(*it1).first].at(it2);
                graph[(*it1).first].erase(graph[(*it1).first].begin()+it2);
                printGraph(graph);
                if(isTree(graph,nodes))
                {
                    if(minCost>abs((*it1).first-graph[(*it1).first][it2]))
                        minCost=abs((*it1).first-graph[(*it1).first][it2]);
                    cout<<endl<<"TREE"<<endl;
                }
                    
                graph[(*it1).first].insert(graph[(*it1).first].begin()+it2,node);
            }
        }
        
        printGraph(graph);
        printNodes(nodes);
        cout<<endl<<endl<<minCost;
        numTc--;
    }
    return 0;
}