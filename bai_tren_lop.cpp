#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;

class Dh
{
	private	:
		char ten[50];
		int cs;
		float gia;
	public :
		Dh();
		Dh(char Ten[50],int Cs,float Gia);
	friend istream& operator>>(istream& in,Dh &p);
	friend ostream& operator<<(ostream& out,Dh p);
	friend bool operator==(Dh a,Dh b);
};
Dh::Dh()
{
	strcpy(ten,"aaa");	cs = 1;	gia = 5,66;
}
Dh::Dh(char Ten[50],int Cs,float Gia)
{
	strcpy(ten,Ten);cs = Cs;gia = Gia;
}
istream& operator>>(istream& in,Dh &p)
{
	cout<<"\n -Nhap ten dieu hoa: ";				fflush(stdin);			gets(p.ten);
	cout<<"\n -Nhap cong suat: ";											cin>>p.cs;
	cout<<"\n -Nhap gia thanh: ";											cin>>p.gia;
	return in;
}
ostream& operator<<(ostream& out,Dh p)
{
	out	<<p.ten<<setw(20)<<p.cs<<setw(20)<<p.gia<<endl;
	return out;
}
bool operator==(Dh a,Dh b)
{
	if(strcmp(a.ten,b.ten)==0 && a.cs==b.cs && a.gia==b.gia)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Dh a;
	Dh b;
	cout<<"Nhap thong tin dieu hoa thu nhat: "<<endl;		cin>>a;
	cout<<"Nhap thong tin dieu hoa thu hai: "<<endl;		cin>>b;
	ofstream file("Ket_qua.txt",ios::out);
	cout<<"===========================THONG TIN DIEU HOA==========================="<<endl;
	cout<<"Thu tu"<<setw(20)<<"Ten"<<setw(20)<<"Cong suat"<<setw(20)<<"Gia thanh"<<endl;
	cout<<"   1  "<<setw(20)<<a;
	cout<<"   2  "<<setw(20)<<b;
	file<<"===========================THONG TIN DIEU HOA==========================="<<endl;
	file<<"Thu tu"<<setw(20)<<"Ten"<<setw(20)<<"Cong suat"<<setw(20)<<"Gia thanh"<<endl;
	file<<"   1  "<<setw(20)<<a;
	file<<"   2  "<<setw(20)<<b;
	if(a==b)
	{
		cout<<"====>"<<"Hai dieu hoa nay deu co cung thong so."<<endl;
		file<<"====>"<<"Hai dieu hoa nay deu co cung thong so."<<endl;
	}
	else
	{
		cout<<"====>"<<"Hai dieu hoa nay khong co cung thong so."<<endl;
		file<<"====>"<<"Hai dieu hoa nay khong co cung thong so."<<endl;
	}
	file.close();
	return 0;
}
