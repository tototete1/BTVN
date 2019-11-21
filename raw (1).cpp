#include <bits/stdc++.h>

using namespace std;
#define X(A,B,C) A.x=C.x-B.x
#define Y(A,B,C) A.y=C.y-B.y

struct data
{
    float x,y;
};
#define tcheo(A,B) (A.x*B.y-B.x*A.y)

#define tvh(A,B) (A.x*B.x+A.y*B.y)
data AB,AC,DC,BC,AD,BD,DB,CB,CA,DA,BA;
data A,B,C,D;
void xl()
{
    X(BC,B,C), Y(BC,B,C);
    X(AD,A,D), Y(AD,A,D);
    X(BD,B,D), Y(BD,B,D);
    X(DA,D,A), Y(DA,D,A);
    X(CA,C,A), Y(CA,C,A);
    X(CB,C,B), Y(CB,C,B);
    X(BA,B,A), Y(BA,B,A);
    X(DB,D,B), Y(DB,D,B);
    if (tvh(AC,BC)<0 || tvh(AD,BD)<0) {cout <<"TRUNG";return; }
    else if (tvh(CA,DA)<0 || tvh(CB,DB)<0) {cout <<"TRUNG";return;}
    else
    {
        if ((tvh(AC,BC)>0 && tvh(AD,BD)>0) || (tvh(CA,DA)>0 && tvh(CB,DB)>0)) cout <<"NO";
        if (tvh(AC,BC)==0){
            if (A.x==C.x && tvh(AB,DB)<0) cout <<"TRUNG";
            if (A.x==C.x && tvh(AB,DB)>0) cout <<"YES"<<endl<<fixed<<A.x<<" "<<A.y;
            if (B.x==C.x && tvh(AB,DB)<0) cout <<"YES"<<endl<<fixed<<B.x<<" "<<B.y;
            if (B.x==C.x && tvh(AB,DB)>0) cout <<"TRUNG";
        }
        else if (tvh(AD,BD)==0){
            if (A.x==D.x && tvh(CA,BA)>0) cout <<"TRUNG";
            if (A.x==D.x && tvh(CA,BA)<0) cout <<"YES"<<endl<<fixed<<A.x<<" "<<A.y;
            if (B.x==D.x && tvh(CA,BA)<0) cout <<"TRUNG";
            if (B.x==D.x && tvh(CA,BA)>0) cout <<"YES"<<endl<<fixed<<B.x<<" "<<B.y;
        }
        if (tvh(AC,BC)==0 && tvh(AD,BD)==0) cout <<"TRUNG";
        return ;
    }
}
int main()
{

    //freopen("doanthang.inp","r",stdin);
    //freopen("doanthang.out","w",stdout);
    float d,dl,dk,k,l;
    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;
    X(AC,A,C), Y(AC,A,C);
    X(AB,A,B);
    Y(AB,A,B);
    X(DC,D,C);
    Y(DC,D,C);
    d = tcheo(AB,DC);
    dk = tcheo(AC,DC);
    dl = tcheo(AB,AC);
    k = dk/d*1.0;
    l = dl/d*1.0;
    cout.precision(1);
    if (d!=0)
    {
        if (k>=0 && k<=1 && l>=0 && l<=1)
        {
            cout << "YES" <<endl;

            cout <<fixed<< k*(B.x-A.x)*1.0+A.x << " " << k*(B.y-A.y)+A.y;
        }
        else
            cout << "NO";
    }
    else
    {
        if (dk==0 && dl==0)
        {
            xl();
        }
        else
            cout <<"NO";
    }
    return 0;
}
