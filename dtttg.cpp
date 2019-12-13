#include <bits/stdc++.h>
#define tcheo(A,B) (A.x*B.y-A.y*B.x)
using namespace std;
struct data {float x,y;};
vector <data> res;
data Cr(data B,data C)
{
    data A;
    A.x=C.x-B.x;
    A.y=C.y-B.y;
    return A;
}
bool check(data A,data B,data C,data D,data &E)
{
    //kt cac doan thang AB,AC,BC co giao diem voi DE k
    //co thi tra ve true k thi tra ve false
    data AB,DC,AC;
    float k=20000,l=20000;
    AB=Cr(A,B),DC=Cr(D,C),AC=Cr(A,C);
    float d,dk,dl;
    d = tcheo(AB,DC)*1.0;
    dk = tcheo(AC,DC)*1.0;
    dl = tcheo(AB,AC)*1.0;
    if (d!=0)
    {
        k=dk/d*1.0;
        l=dl/d*1.0;
    }
    if (k>=0 && k<=1 && l>=0 && l<=1)
    {
        E.x=A.x+k*(B.x-A.x);
        E.y=A.y+k*(B.y-A.y);
        return 1;
    }
    return 0;
}
bool check2(data A)
{
    //kt diem N,P,D,E co trung voi cac diem khac k
    int i=0;
    while (i<res.size())
    {
        if (res[i].x==A.x && res[i].y==A.y) return false;
        i++;
    }
    return true;
}
bool check3(data A,data B,data C,data H)
{
    //kt D,E co nam trong tam giac k
    data HA,HB,HC,AB,AC;
    HA=Cr(H,A),HB=Cr(H,B),HC=Cr(H,C),AB=Cr(A,B),AC=Cr(A,C);
    float s1=tcheo(HA,HB)*1.0,s2=tcheo(HA,HC)*1.0,s3=tcheo(HB,HC)*1.0,s4=tcheo(AB,AC)*1.0;
    if (abs(s1)+abs(s2)+abs(s3)<=abs(s4)) return 1;
    //if (abs(tcheo(HA,HB))+abs(tcheo(HA,HC))+tcheo(HC,HB)<=tcheo(AB,AC)) return 1;
    return 0;
}

float kc(data A,data B)
{
    float kc=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y))*1.0;
    return kc;
}
int main()
{
    data A,B,C,D,E,M,N,P;
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    cin >>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
    cin >>D.x>>D.y>>E.x>>E.y;
    if (check(A,B,D,E,M)) res.push_back(M);
    if (check(B,C,D,E,N))
    {
        if (check2(N))  res.push_back(N);
    }
    if (check(A,C,D,E,P))
    {
        if  (check2(P)) res.push_back(P);
    }
    if (check3(A,B,C,D))
    {
        if (check2(D)) res.push_back(D);
    }
    if (check3(A,B,C,E))
    {
        if  (check2(E)) res.push_back(E);
    }
    if (res.size()==2)
    {
        cout.precision(2);
        cout <<fixed<<kc(res[0],res[1]);
    }
    else cout <<0;
    return 0;
}
