#include <iostream>
#include<string>
#include <string.h>
#include<fstream>
#include<stdlib.h>
#include <stack>
#include<vector>
using namespace std;
ifstream f("D:/NhapTuFile.txt");
ofstream g("D:/XuatTuFile.txt");
class DB{
	public:
	string Ten;
	string GioiTinh;
	string SDT;
	string Email;
	string DiaChi;
		NhapTuFile(){
			string  s;				
			getline(f, s); Ten = s;
			getline(f,s); GioiTinh = s;
			getline(f, s); SDT = s;
			getline(f, s); Email = s;
			getline(f, s); DiaChi = s;
		}
		NhapDB(){
			cout << " Nhap Ten : " ; cin >> Ten;
			cin.sync();
			cout << "Nhap gioi tinh "; cin >> GioiTinh;
			cin.sync();
			cout << " Nhap so dien thoai : "; cin >> SDT;
			cin.sync();
			cout << "Nhap dia chi email : " ; cin >> Email;
			cin.sync();
			cout << "Nhap dia chi noi o : "; cin >> DiaChi;
			
		}
		XuatFile(){
			g << Ten << "\t" << GioiTinh << "\t" << SDT << "\t" << Email << "\t" << DiaChi << endl << "------------------------" <<  endl;
		}
		Xuat()
		{
			cout << Ten << "\t" << GioiTinh << "\t" << SDT << "\t" << Email << "\t" << DiaChi << endl << "------------------------" <<  endl;
		}
};
class DBDT{
	vector <DB>H;
	vector <DB>K;
	public :
	void NhapDB(){
		int n;
		string s;
		getline(f,s); n = atoi(s.c_str());
		H.resize(n);
		for(int i = 0; i < H.size(); i++)
			H[i].NhapTuFile();
	}
	void XuatRaFile()
	{
		for(int i = 0; i < H.size(); i++)
			H[i].XuatFile();
	}
	void Them(){
		DB d;
		int n;
		cin >> n;
		while(n == 0){
			d.NhapDB();
			d.Xuat();
			H.push_back(d);
			K.push_back(d);
		}
	}
	void XuatThem(){
		printf(K);
	}
	void Xoa(){ 
	string s;
	getline(cin, s);
	for(int i = 0; i < H.size(); i++)
		if(k.compare(H[i].Ten)== 0)
			H.
	}
	void Tim(){
		string k;
		getline(std::cin, k);
		for(int i = 0; i < H.size(); i++)
			if(k.compare(H[i].Ten)== 0)
				H[i].Xuat();
	}
	void chon()
	{
		int n ;
		cin >> n;
		cout << " Nhap Gia tri N = ";
		
		
	}
};
int main()
{
	DBDT db;
	db.NhapDB();
	db.Them();
	db.Tim();
}
