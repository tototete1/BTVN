#include <iostream>

using namespace std;
long long n,s,t,i,j,thoat,u,v,oo=1e9,k;
long long a[101][101],d[101],Truoc[101],b[101];
int main()
{
    cin >>n>>s>>t;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            cin >>a[i][j];
            if (a[i][j]==0) a[i][j]=oo;
        }
        a[i][i]=0;
    }
    for (i=1;i<=n;i++)
    {
        d[i]=a[s][i];
        Truoc[i]=s;
    }
    for (i=1;i<=n-2;i++)
    {
        thoat=true;
        for (v=1;v<=n;v++)
            for (u=1;u<=n;u++)
                {
                    if (d[v]>d[u]+a[u][v])
                    {
                        d[v]=d[u]+a[u][v];
                        Truoc[v]=u;
                        thoat=false;
                    }
                }
        if (thoat==true) break;
    }
    cout <<d[t]<<endl;
    k=1,b[k]=t;
    while (t!=s)
    {
        t=Truoc[t];
        k++;
        b[k]=t;
    }
    for (i=k;i>0;i--) cout <<b[i]<<" ";
    return 0;
}
