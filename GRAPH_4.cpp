#include <iostream>
#include <queue>
using namespace std;
int n,oo=1e9;
int cx[101],b[101],d[101],Truoc[101],a[101][101];
void Dijsktra(int x,int y)
{
    int u,i,k;
    queue <int> q;
    q.push(x);
    for (i=1;i<=n;i++) d[i]=oo;
    d[x]=0;
    cx[x]=0;
    while (!q.empty())
    {
        u=q.front();
        q.pop();
        for (i=1;i<=n;i++)
        {
            if (cx[i]==1)
            {
                d[i]=d[u]+a[u][i];
                cx[i]=0;
                Truoc[i]=u;
                q.push(i);
            }
            else
            {
                if (d[i]>d[u]+a[u][i])
                {
                    d[i]=d[u]+a[u][i];
                    Truoc[i]=u;
                    q.push(i);
                }
            }
        }
    }
    cout <<d[y]<<endl;
    k=1,b[k]=y;
    while (y!=x)
    {
        y=Truoc[y];
        k++;
        b[k]=y;
    }
    for (i=k;i>0;i--) cout <<b[i]<<" ";
}
int main()
{
    int m,s,t,i,j,w,u,v;
    cin >>n>>m>>s>>t;
    for (i=1;i<=m;i++)
    {
        cin >>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
    {
        if (a[i][j]==0) a[i][j]=oo;
    }
    Dijsktra(s,t);
    return 0;
}
