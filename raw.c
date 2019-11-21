#include <bits/stdc++.h>

using namespace std;
#define X(A,B,C) A.x=C.x-B.x;
#define Y(A,B,C) A.y=C.y-B.y;
#define tc(A,B) A.x*B.y-B.x*A.y
#define tch(A,B) A.x*B.x+A.y*B.y
struct data{float x,y;};
data A,B,C,D,AB,AC,DC,CA,CD,BA,DA,AD,BC,CB;

int check(data X,data Y,data Z,data W){
    int t1=0, t2=0, t3=0, t4=0, d=0;
    if ((X.x==Z.x && X.y==Z.y)) t1=1,d++;
    if ((X.x==W.x && X.y==W.y)) t2=2,d++;
    if ((Y.x==Z.x && Y.y==Z.y)) t3=3,d++;
    if ((Y.x==W.x && Y.y==W.y)) t4=4,d++;
    if (d==1) return max(t1, max(t2, max(t3,t4)));
    else return 0;
}
void xl(){
    cout.precision(1);
    if (check(A,B,C,D)>0) {
    int kk=check(A,B,C,D);
        if (kk==1){
            if (tch(DA,BA)<=0) cout <<"YES"<<endl<<fixed<<A.x<<" "<<A.y;
            else cout <<"TRUNG";
        }
        if (kk==2){
            if (tch(CA,BA)<=0) cout <<"YES"<<endl<<fixed<<A.x<<" "<<A.y;
            else cout <<"TRUNG";
        }
        if (kk==3){
            if (tch(AC,DC)<=0) cout <<"YES"<<endl<<fixed<<B.x<<" "<<B.y;
            else cout <<"TRUNG";
        }
        if (kk==4){
            if (tch(AD,CD)<=0) cout <<"YES"<<endl<<fixed<<B.x<<" "<<B.y;
            else cout <<"TRUNG";
        }
    return ;
    }
    data BD,DB;
    X(BD,B,D); Y(BD,B,D);
    X(DB,D,B); Y(DB,D,B);
    if ((tch(AC,BC)<=0 || tch(AD,BD)<=0) || (tch(AC,BC)<=0 && tch(AD,BD)<=0)) {cout <<"TRUNG";return ;}
    if ((tch(CA,DA)<=0 || tch(CB,DB)<=0) || (tch(CA,DA)<=0 && tch(CB,DB)<=0)) {cout <<"TRUNG";return ;}
    cout <<"NO";
}
int main()
{

    //freopen("doanthang.inp","r",stdin);
    //freopen("doanthang.out","w",stdout);
    float d,dl,dk,k,l;
    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;
    X(AB,A,B);    Y(AB,A,B);
    X(AC,A,C);    Y(AC,A,C);
    X(DC,D,C);    Y(DC,D,C);
    X(CA,C,A);    Y(CA,C,A);
    X(BA,B,A);    Y(BA,B,A);
    X(DA,D,A);    Y(DA,D,A);
    X(AD,A,D);    Y(AD,A,D);
    X(CD,C,D);    Y(CD,C,D);
    X(BC,B,C);    Y(BC,B,C);
    X(CB,C,B);    Y(CB,C,B);
    cout.precision(1);
    d = tc(AB,DC);
    dk = tc(AC,DC);
    dl = tc(AB,AC);
    k = dk/d*1.0;
    l = dl/d*1.0;
    if (d!=0){
    if (k>=0 && k<=1 && l>=0 && l<=1){
        cout << "YES" <<endl;

        cout <<fixed<< k*(B.x-A.x)*1.0+A.x << " " << k*(B.y-A.y)+A.y;
    }
    else cout << "NO";
    }
    else{
        if (dk==0 && dl==0){ xl();}
        else cout <<"NO";
    }
    return 0;
}