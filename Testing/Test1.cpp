#include<iostream>
#include<iomanip>
using namespace std;

class P
{
	protected:
		char ht[100];
		int d,m,y;
		char qq[100];
};

class Ks : public P
{
	private:
		char nganh[100];
		int namTN;
	public:
		void nhap();
		void xuat();
	friend void max(Ks a[],int n);
};
void Ks::nhap()
{
	cout<<"\n Nhap ho ten: ";				fflush(stdin);			gets(ht);
	cout<<"\n Nhap ngay sinh: ";									
	cout<<"\n -nhap ngay: ";										cin>>d;
	cout<<"\n -nhap thang: ";										cin>>m;
	cout<<"\n -nhap nam: ";											cin>>y;	
	cout<<"\n Nhap que quan: ";				fflush(stdin);			gets(qq);
	cout<<"\n Nhap ten nganh: ";			fflush(stdin);			gets(nganh);
	cout<<"\n Nhap nam tot nghiep: ";								cin>>namTN;
}
void Ks::xuat()
{
	cout<<left
		<<setw(20)<<ht
		<<d<<"/"<<m<<"/"<<setw(20)<<y
		<<setw(20)<<qq
		<<setw(20)<<nganh
		<<setw(20)<<namTN
		<<endl;
}
void max(Ks a[],int n)
{
	int temp=a[0].namTN;
	for(int i=0;i<n;i++)
	{
		if(a[i].namTN>=temp)
		{
			temp=a[i].namTN;
		}
	}
	cout<<"Cac ki su tot nghiep gan day nhat: "<<endl;
	cout<<left
		<<setw(20)<<"Ho va ten: "
		<<setw(20)<<"Ngay sinh: "
		<<setw(20)<<"Que quan: "
		<<setw(20)<<"Ten nganh: "
		<<setw(20)<<"Nam tot nghiep: "
		<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i].namTN==temp)
		{
			a[i].xuat();
		}
	}
}

int main()
{
	int n;
	Ks a[100];
	//Ham nhap cac ki su
	cout<<"Nhap so ki su: ";										cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap ki su thu "<<i+1<<": ";
		a[i].nhap();
	}
	//Ham hien tt
	cout<<left
		<<setw(20)<<"Ho va ten: "
		<<setw(20)<<"Ngay sinh: "
		<<setw(20)<<"Que quan: "
		<<setw(20)<<"Ten nganh: "
		<<setw(20)<<"Nam tot nghiep: "
		<<endl;
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
	max(a,n);
}
