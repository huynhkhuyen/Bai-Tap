#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;
fstream fi("D:/NhapTuFile.txt");
fstream fo("D:/XuatTuFile.txt");
class DANHBA{
	string gt,sdt,email,diachi,ten;
	vector <DANHBA> S;
	vector <DANHBA> P;
	public:
		// Xuat 1 danh ba ra man hinh
		xuat(){
			cout<<"\nTen: "<<ten<<"\tGioi tinh: "<<gt <<"\tSDT: "<<sdt<<endl<<"\tEmail: "<<email<<"/tDia chi: "<<diachi;
		}
		nhapF(){

			getline( fi, ten);
			getline( fi, gt);
			getline( fi, sdt);
			getline( fi, email);
			getline( fi, diachi);
		}
		nhap(){
			cout<<"Nhap ten: ";
			cin.sync();
			getline( cin, ten);
			cout<<"Nhap gioi tinh: ";
			cin.sync();
			getline( cin, gt);
			cout<<"Nhap sdt: ";
			cin.sync();
			getline( cin, sdt);
			cout<<"Nhap email: ";
			cin.sync();
			getline( cin, email);
			cout<<"Nhap dia chi: ";
			cin.sync();
			getline( cin, diachi);		
		}
		// xuat1 danh ba ra file
		xuatF()
		{
			fo<<ten<<endl;
			fo<<gt<<endl;
			fo<<sdt<<endl;
			fo<<email<<endl;
			fo<<diachi<<endl;
		}
		void nhaptufile(){
			int n;
			string h;	
			getline( fi, h);
			n=atoi(h.c_str());
			S.resize(n);
			for(int i=0;i<S.size();i++)
				S[i].nhapF();
		}
		// xuat danh ba duoc them vao ra man hinh
		void xuatmh(){
			for(int i=0;i<P.size();i++){
				P[i].xuat();
				cout<<endl;
				cout<<"------------------------------"<<endl;
			}
		}
		// xuat danh ba ra man hinh
		void xuatmhfile(){
			for(int i=0;i<S.size();i++){
				S[i].xuat();
				cout<<endl;
				cout<<"------------------------------"<<endl;
			}
		}
		// xuat danh ba chinh ra file 
		void xuatfileC(){
			for(int i=0;i<S.size();i++)
				S[i].xuatF();
		}
		// them 1 danh ba
		void them(){
			DANHBA moi;
			moi.nhap();
			P.insert(P.end(), 1, moi);
			S.insert(S.end(), 1, moi);
		}
		// xoa 1 danh ba
		void xoa(){
			int vt;
			cout<<"Nhap vi tri xoa:";
			cin>>vt;	
			S.erase(S.begin()+vt);
		}
		// chinh sua 1 danh ba
		void chinhsua(){
			int vt;
			DANHBA moi;
			cout<<"Nhap vi tri sua:";
			cin>>vt;
			cout<<"Nhap thong tin chinh sua:"<<endl;
			moi.nhap();
			S.erase(S.begin()+vt);
			S.insert(S.begin()+vt,moi);
		}
		// tim kiem danh ba theo ten
		void Timkiem(){
			string k;
			cout<<"Nhap ten: ";
			cin>>k;
			for(int i = 0; i < S.size(); i++)
			if(k.compare(S[i].ten)== 0){
				S[i].xuat();
				cout<<endl;
			}
				
		}
};
int main(){
	int x;
	DANHBA A;
	A.nhaptufile();
	cout<<"Danh sanh danh ba: "<<endl;
	cout<<"------------------------------"<<endl;
	A.xuatmhfile();
	cout<<"------------------------------"<<endl;
	do {
		cout<<"Nhap yeu cau:"<<endl<<"1: Them"<<endl<<"2: Liet ke cac ban ghi them vao"<<endl<<"3: Chinh sua ban ghi"<<endl<<"4: Xoa ban ghi"<<endl<<"5: Tim kiem"<<endl<<"0: Ket thuc"<<endl;
		cin>>x;
		switch (x) {
			case 1:{
				system("cls");
				A.them();
				system("cls");
				break;
			}
			case 2:{
				system("cls");
				A.xuatmh();
				system("cls");
				break;
			}
			case 3:{
				system("cls");
				A.chinhsua();
				system("cls");
				break;
			}
			case 4:{
				system("cls");
				A.xoa();
				system("cls");
				break;
			}
			case 5:{
				system("cls");
				A.Timkiem();
				system("cls");
				break;
			}
		}
		cout<<"------------------------------"<<endl;
	}
	while (x!=0);
	cout<<"Danh sanh danh ba: "<<endl;
	cout<<"------------------------------"<<endl;
	A.xuatmhfile();
	A.xuatfileC();
	fi.close();
	fo.close();	
	
}
