#include<iostream>
#include<fstream>
using namespace std;

class PhanSo
{
    private :
        int Ts;
        int Ms;
    public :
    	PhanSo();
    	PhanSo(int ts,int ms);
    friend PhanSo operator*(PhanSo &a,PhanSo &b);
    friend double GiaTri(PhanSo &p);
    friend ostream& operator<<(ostream &out,PhanSo p);
    friend istream& operator>>(istream &in,PhanSo &p);
};
PhanSo::PhanSo()
{
	Ts = 1; Ms = 2;
}
PhanSo::PhanSo(int ts,int ms)
{
	Ts = ts; Ms = ms;
}
PhanSo operator*(PhanSo &a,PhanSo &b)
{
	PhanSo kq;
	kq.Ts = a.Ts*b.Ts;
	kq.Ms = a.Ms*b.Ms;
	return kq;
}
double GiaTri(PhanSo &p)
{
	return static_cast<double>(p.Ts) / p.Ms;
}
istream& operator>>(istream &in,PhanSo &p)
{
	cout << "Nhap tu so: ";				cin >> p.Ts;
	cout << "Nhap mau so: ";			cin >> p.Ms;
	return in;
}
ostream& operator<<(ostream &out,PhanSo p)
{
	out << p.Ts << "/" << p.Ms << endl;
	return out;
}

int main()
{
	PhanSo p1,p2;
	cout << "Nhap phan so thu nhat: " << endl;
	cin >> p1;
	cout << "Nhap phan so thu hai: " << endl;
	cin >> p2;
	
	PhanSo t;
	t = p1 * p2;
	ofstream file("PHANSO.txt");
	
	file << "Tich hai phan so: " << t << endl;
	file << "Gia tri cua phan so: " << GiaTri(t) << endl;
	file.close();
	return 0;
}
