#include    "iostream"
using namespace std;
typedef struct DATE
{
    int d;
    int m;
    int y;
};
bool KiemTraDate(DATE D)
{
    if(D.m>0 && D.y>0 && D.d>0)
    { 
        if(D.m==2)
        {   
            if((D.y%400==0) || (D.y%4==0 && D.y%100==0))
            {
                if(D.d<=29)
                    return true;
                else
                    return false;
            }
            else
            {
                if(D.d<29)
                    return true;
                else
                    return false;
            }  
        }
        if(D.m==1 || D.m==3 || D.m==5 || D.m==7 || D.m==9 || D.m==11)
        {
            if(D.d>31)
                return false;
            else
                return true;
        }  
        if(D.m==4 || D.m==6 || D.m==8 || D.m==10 || D.m==12)
        {
            if(D.d>30)
                return false;
            else
                return true;
        }  
   
    }
    else
        return false;
}


void NhapDate(DATE &D)
{
    do
    {  
        cout<<"\nNhap vao ngay thang nam:\n";
        cout<<"Nhap ngay: ";
        cin>>D.d;
        cout<<"Nhap thang: ";
        cin>>D.m;
        cout<<"Nhap nam: ";
        cin>>D.y;
        if(KiemTraDate(D)==false)
            cout<<"\nBan da nhap sai, moi ban nhap lai: ";
        else
            break;
    }while(true);
}
void XuatDate(DATE D)
{
    cout<<"\nThoi gian: Ngay "<<D.d<<" thang "<<D.m<<" nam "<<D.y;
}
DATE KhoangCachDate(DATE D1,DATE D2)
{
    int d1,m1,y1;
    DATE t;
    
    d1=D1.d-D2.d;
    if(d1>0)
        t.d=d1;
    else
        t.d=d1*(-1);
    m1=D1.m-D2.m;
    if(m1>0)
        t.m=m1;
    else
        t.m=m1*(-1);
    y1=D1.y-D2.y;
    if(y1>0)
        t.y=y1;
    else
        t.y=y1*(-1);
    return t;
}
DATE	CongThem(DATE D1){
	int n;
	cin >> n;
	while(n != 0){
		if((D1.d <32 &&(D1.m==1 || D1.m==3 || D1.m==5 || D1.m==7 || D1.m==9 || D1.m==11)) || (D1.d < 31 && (D1.m==4 || D1.m==6||D1.m == 9||D1.m ==11))||((D1.d < 30)&&((D1.y%400==0) || (D1.y%4==0 && D1.y%100==0))) ||((D1.d < 29&&(D1.y%4 !=0 && D1.y%100 == 0))) )
			D1.d++;
		else{
			if(D1.m < 13){
				D1.m++;
				D1.d = 1;	
			}
			else{
				D1.y++;
				D1.m = 1;
				D1.d = 1;
			}
}	n--;
	}
	return D1;
	
}
DATE TruRa(DATE D1){
	int n;
	cin >> n;
	while(n != 0)
		{
			if(D1.d  > 1 )
				D1.d--;
			else
			{
				if(D1.m >1)
				{
					D1.m--;
					if(D1.m == 1 || D1.m == 3 || D1.m == 5 || D1.m == 7 || D1.m == 8 || D1.m ==10 || D1.m == 12)
						D1.d = 31;
					else
						if(D1.m == 4 || D1.m == 6 || D1.m == 9 || D1.m == 11)
						D1.d = 30;
						else
							{
							if(D1.y% 400 == 0 || (D1.y % 4 == 0 && D1.y % 100 != 0))
							D1.d = 29;
							else
							D1.d = 28;
						}
		
				}
				else{
				D1.y --;
				D1.m = 12;
				D1.d = 31;
			}
			}
				n--;
		}
		return D1;
}
int main()
{  
             DATE D1,D2,D;
    NhapDate(D1);
   // XuatDate(D1);
   // NhapDate(D2);
    //XuatDate(D2);
     //        cout<<"\nKhoang cach giua 2 ngay: ";
    //D=KhoangCachDate(D1,D2);
    //XuatDate(D);
    D=TruRa(D1);
    XuatDate(D);
}
