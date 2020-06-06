#include<bits/stdc++.h>
using namespace std;
#define vertex second
#define weight first


typedef pair<int,int> pairs;

class und_graph
{
private: 
    int V,E;
    vector<pair<int,int>> *adj;
public:
    
    und_graph(int v, int e)
    {
        V=v; E=e;
        adj = new vector<pair<int,int>>[V];
    }

    void addedge(int s, int e, int w)
    {
        adj[s].push_back({w,e});
        adj[e].push_back({w,s});
    }
    void printgraph()
    {
        for(int i=0;i<V;i++)
        {   
            cout<<i<<"-> ";
            for(auto x:adj[i])
            {
                cout<<"{"<<x.weight<<","<<x.vertex<<"} ";
            }
            cout<<endl;
        }
    }
    int MST_weight()
    {
        
        priority_queue<pairs,vector<pairs>,greater<pairs>> q;
        vector<bool> inMST(V,false);
        int minweight=0;
        inMST[0]=true;
        for(auto x: adj[0])
            q.push(x);
        int count=V-1;
        while(count>0)
        {   
            pairs p = q.top();
            q.pop();
            int w=p.weight;
            int v=p.vertex;
            inMST[v]=true;
            minweight+=w;
            count--;
            for(auto x:adj[v])
            {
                if(!inMST[x.vertex])
                {
                    q.push(x);
                }
            }
        }
    return minweight;
    
    }
};
int main()
{
    int V,E;
    cin>>V>>E;
    und_graph G(V,E);
    for(int i=0;i<E;i++)
    {
        int v1,v2,w;
        cin>>v1>>w>>v2;
        G.addedge(v1,v2,w);
    }
    // G.printgraph();
    cout<<G.MST_weight()<<endl;

}