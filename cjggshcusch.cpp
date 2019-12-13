#include <bits/stdc++.h>

#define tichcheo(a, b) (a.x*b.y - a.y*b.x)
#define tichdodai(a, b) ((sqrt(a.x*a.x + a.y*a.y))*(sqrt(b.x*b.x + b.y*b.y)))
#define tichvohuong(a, b) (a.x*b.x + a.y*b.y)
#define dodai(a) (sqrt(a.x*a.x + a.y*a.y))

using namespace std;

struct Point{
	float x, y;
};

Point A, B, C, D, AC, AB, DC, res, DA, DB, CA, CB, CD, BD, AD, BC, BA;
float d, Dk, Dl, k, l;
int t = 0;

Point Creat(Point A, Point B){
	Point k;
	k.x = B.x - A.x;
	k.y = B.y - A.y;
	return k;
}
bool F(Point A, Point B){
	if (A.x == B.x && A.y == B.y) return true;
	else
		return false;
}

int main()
{
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    AB = Creat(A, B);
    DC = Creat(D, C);
    AC = Creat(A, C);
    DA = Creat(D, A);
    DB = Creat(D, B);
    CA = Creat(C, A);
    CB = Creat(C, B);
    CD = Creat(C, D);
    BD = Creat(B, D);
    AD = Creat(A, D);
    BC = Creat(B, C);
    BA = Creat(B, A);
    d = tichcheo(AB, DC);
    Dk = tichcheo(AC, DC);
    Dl = tichcheo(AB, AC);
    k = Dk/d;
    l = Dl/d;
    cout << fixed;
	cout.precision(1);
    if (d != 0){
		if (k >= 0 && l >= 0 && k <= 1 && l <= 1){
			cout << "YES" << endl;
			res.x = A.x + k*(B.x - A.x);
			res.y = A.y + k*(B.y - A.y);
			cout << res.x << " " << res.y;
		}
		else
			cout << "NO";
    }
    else{
		if ((F(A, C) && F(B, D)) || (F(A, D) && F(B, C))){
			t = 1;
			cout << "Trung";
		}
		else{
            if (F(A, C))
				if (tichdodai(DA, DB) == tichvohuong(DA, DB)){
					if (tichvohuong(DA, BA) <= 0){
						t = 1;
						cout << "YES" << endl;
						cout << A.x << " " << A.y;
					}
				}
				else{
					t = 1;
					cout << "Trung";
				}
			if (F(B, C))
				if (tichdodai(DA, DB) == tichvohuong(DA, DB)){
					if (tichvohuong(DB, AB) <= 0){
						t = 1;
						cout << "YES" << endl;
						cout << B.x << " " << B.y;
					}
				}
				else{
					t = 1;
					cout << "Trung";
				}
			if (F(A, D))
				if (tichdodai(CA, CB) == tichvohuong(CA, CB)){
					if (tichvohuong(CA, BA) <= 0){
						t = 1;
						cout << "YES" << endl;
						cout << A.x << " " << A.y;
					}
				}
				else{
					t = 1;
					cout << "Trung";
				}
			if (F(B, D))
				if (tichdodai(CA, CB) == tichvohuong(CA, CB)){
					if (tichvohuong(CB, AB) <= 0){
						t = 1;
						cout << "YES" << endl;
						cout << B.x << " " << B.y;
					}
				}
				else{
					t = 1;
					cout << "Trung";
				}
		}
		if (tichvohuong(AC, BC) <= 0 || tichvohuong(AD, BD) <= 0 ||
		   (tichvohuong(AC, BC) <= 0 && tichvohuong(AD, BD) <= 0) ||
			tichvohuong(AC, BD) <= 0){
			if (t == 0){
				cout << "Trung";
				t = 1;
			}
		}
		if (t == 0) cout << "NO";
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////
//doan thang trong tam giac
#include <bits/stdc++.h>

#define tichcheo(a, b) (a.x*b.y - a.y*b.x)
#define dodai(a, b) (sqrt(((b.x-a.x)*(b.x-a.x)) + ((b.y-a.y)*(b.y-a.y))))

using namespace std;

struct Point{
	double x, y;
};

Point A, B, C, D, E, x, y;
Point AB, AC, DE, res;
int t = 0;

Point Creat(Point A, Point B){
	Point k;
	k.x = B.x - A.x;
	k.y = B.y - A.y;
	return k;
}
bool InTri(Point X){
	int s = abs(tichcheo(AB, AC)) / 2;
	int s1, s2, s3;
	Point XA, XB, XC;
	XA = Creat(X, A);
	XB = Creat(X, B);
	XC = Creat(X, C);
	s1 = abs(tichcheo(XA, XB)) / 2;
	s2 = abs(tichcheo(XB, XC)) / 2;
	s3 = abs(tichcheo(XC, XA)) / 2;
	if (s1 + s2 + s3 <= s) return true;
	else
		return false;
}
bool IsCut(Point X, Point Y){
	Point XY, XE;
	float d, Dk, Dl, k, l;
	XY = Creat(X, Y);
	XE = Creat(X, E);
	d = tichcheo(XY, DE);
	Dk = tichcheo(XE, DE);
	Dl = tichcheo(XY, XE);
	if (d != 0){
		k = Dk / d;
		l = Dl / d;
		if (k >= 0 && l >= 0 && k <= 1 && l <= 1){
			res.x = X.x + k*XY.x;
			res.y = X.y + k*XY.y;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
bool check(Point D){
	if ((D.x != A.x && D.y != A.y) &&
		(D.x != B.x && D.y != B.y) &&
		(D.x != C.x && D.y != C.y))
		return true;
	else
		return false;
}

int main()
{
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	cin >> D.x >> D.y >> E.x >> E.y;
	cout << fixed;
	cout.precision(5);
	AB = Creat(A, B);
	AC = Creat(A, C);
	DE = Creat(D, E);
	if (InTri(D) && InTri(E)){
		t = 1;
		cout << dodai(D, E);
	}
	else{
		if (InTri(D) && check(D)){
			if (IsCut(A, B) ||
				IsCut(B, C) ||
				IsCut(A, C)){
				cout << dodai(res, D);
				t = 1;
			}
		}
		if (InTri(E) && check(E)){
			if (IsCut(A, B) ||
				IsCut(B, C) ||
				IsCut(A, C)){
				cout << dodai(res, E);
				t = 1;
			}
		}

		if (IsCut(A, B)){
			x = res;
			if (IsCut(A, C)){
				y = res;
				if (t == 0 && ((x.x != y.x && x.y == y.y) ||
					       (x.x == y.x && x.y != y.y) ||
					       (x.x != y.x && x.y != y.y))){
					cout << dodai(x, y);
					t = 1;
				}
			}
			if (IsCut(B, C)){
				if (t == 0){
					y = res;
					cout << dodai(x, y);
					t = 1;
				}
			}
		}
		if (IsCut(A, C)){
			x = res;
			if (IsCut(B, C)){
				if (t == 0){
					y = res;
					cout << dodai(x, y);
					t = 1;
				}
			}
		}
	}
	if (t == 0) cout << 0;
	return 0;
}
