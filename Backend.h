#include<iomanip>
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdio.h>

using namespace std;


class Oracle
{
	private:
	int nos; //number of seats.
	int maxs; //max Seats.
	int p; //platform
	int tno; //train no.
	char tname[30]; //train name.
	float f;
	char bp[30]; //Boarding Point
	char dp[30]; //Destination.
	char uname[30];
	int uage;


	public:

	void getdata(){
		cout<<"Enter Train no:";
		cin>>tno;
		fflush(stdin);
		cout<<"Enter Train name:";
		gets(tname);
		cout<<"Enter Platform No.:-";
		cin>>p;
		fflush(stdin);
		cout<<"Enter Boarding Point:";
		gets(bp);
		cout<<"Enter Destination:";
		gets(dp);
		cout<<"Enter Maximum Bookings in Train :-";
		cin>>maxs;
	}
	void putdata(){
		cout<<"Train no:"<<tno<<endl;
		cout<<"Train name:";
		puts(tname);
		cout<<"Platform :-"<<p<<endl;
		cout<<"Boarding Point:";
		puts(bp);
		cout<<"Destination:";
		puts(dp);
		cout<<"Maximum Bookings in Train :-";
		cout<<maxs<<"\n";
	}

	int getid(){
		return this->tno;
	}

	void modifyMaxSeats(int nos){
	    maxs = maxs - nos;
        }

	char *getname(){
	return uname;
	}
	void displaydetail();
	void modifyrec(int);
	void newrec();
	void findrec();
	void showrec();
	void addrec();
	void deleterc(int m);
	void bookTicket();
    void searchUser();
}obj;

void Oracle::searchUser(){
        ifstream fin3;
		char n[50];
		fin3.open("User.dat",ios::in|ios::binary);

		cout<<"Enter user's name :";
		cin>>n;


		while(fin3.read((char*)&obj,sizeof(Oracle))){
				if(strcmpi(obj.getname(),n)==0){
                    //cout<<"Found";
        cout<<"Name:";
		puts(uname);
		cout<<"Your Age:";
		cout<<uage<<"\n";
		fflush(stdin);
		cout<<"Boarding Point:";
		puts(bp);
		cout<<"Destination:";
		puts(dp);
		cout<<"No. of Bookings :-";
		cout<<nos;


				}
		}

  			fin3.close();
}
void Oracle::bookTicket(){
        int st,s;
        long pos;
		cout<<"Enter Train no:";
		cin>>st;
		fflush(stdin);

		ifstream fin2;
		fstream fio;

		int k=0,l=0;



		fin2.open("Rail.dat",ios::in|ios::binary);

		while(fin2.read((char*)&obj,sizeof(Oracle))){

				if(obj.getid()==st){
					k=1;
					break;

				}
				else
					k=0;

                }

					if(k==1){
        ofstream fout2;
		fout2.open("User.dat",ios::out|ios::binary|ios::app);

        cout<<"\nTrain is Availabe :) \n";
        cout<<"\n-------------Ticket Booking------------\n";
		cout<<"Enter  Name:";
		gets(uname);
		cout<<"Enter  Your Age:";
		cin>>uage;
		fflush(stdin);
		cout<<"Enter Boarding Point:";
		gets(bp);
		cout<<"Enter Destination:";
		gets(dp);
		cout<<"Enter No. of Bookings :-";
		cin>>s;
		nos=s;
            fout2.write((char*)&obj,sizeof(Oracle));
            fout2.close();

	}
	else if(k==0){
       cout<<"\nTrain is not Available  \n";

	}
	fin2.close();

    fio.open("Rail.dat",ios::in|ios::out);

    while(!fio.eof()){
        pos = fio.tellg();
        fio.read((char*)&obj,sizeof(Oracle));

        if(obj.getid()==st && maxs>=s){
            obj.modifyMaxSeats(s);
            fio.seekg(pos);
            fio.write((char *)&obj,sizeof(Oracle));
            l=1;
            break;
        }
        else{
            l=0;
        }
    }
    if(l==1){
        cout<<"\n		    Your Ticket is Booked\n\n";
		cout<<"\n**************Have a Good Journey****************\n\n";
    }
    else if(l==0){
        cout<<"Does not have required seats\n";
    }
    fio.seekg(0);


}
void Oracle::addrec(){
		ofstream fout;
		fout.open("Rail.dat",ios::out|ios::binary|ios::app);

				obj.getdata();
				fout.write((char*)&obj,sizeof(Oracle));

  			fout.close();
	}
	void Oracle::showrec(){
		ifstream fin;
		fin.open("Rail.dat",ios::in|ios::binary);
			while(fin.read((char*)&obj,sizeof(Oracle))){
				obj.putdata();
				cout<<endl;
			}
  			fin.close();
	}
    void Oracle::findrec(){
		ifstream fin2;
		int sea1;
		cout<<"Enter Train No to search:";
		cin>>sea1;

		fin2.open("Rail.dat",ios::in|ios::binary);
		while(fin2.read((char*)&obj,sizeof(Oracle))){
				if(obj.getid()==sea1)
					obj.putdata();
				}

  			fin2.close();
	}



void Oracle::newrec(){
		cout<<endl;
	    cout<<"Enter New Details:-"<<endl;
	    fflush(stdin);
		cout<<"Enter Train name:";
		gets(tname);
		cout<<"Enter Platform :-";
		cin>>p;
		fflush(stdin);
		cout<<"Enter Boarding Point:";
		gets(bp);
		cout<<"Enter Destination:";
		gets(dp);
	}
void Oracle::modifyrec(int n){
	  int found=0;
      Oracle obj1;
	  fstream fin3;
	fin3.open("Rail.dat",ios::binary|ios::in|ios::out);
	if(!fin3)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(fin3.read((char *) &obj1,sizeof(Oracle)) && found==0)
	{
		if(obj1.getid()==n)
		{
			obj1.putdata();

			obj1.newrec();
			int pos=(-1)*sizeof(Oracle);
			fin3.seekp(pos,ios::cur);
			fin3.write((char *) &obj1,sizeof(Oracle));
			cout<<"\n\n\t Record Updated"<<endl;
			found=1;
		}
	}
	fin3.close();
	if(found==0)


		cout<<"\n\n Record Not Found ";
}

void Oracle::deleterc(int m)
{
	Oracle obj3;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Rail.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp2.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &obj3,sizeof(Oracle)))
	{
		if(obj3.getid()!=m)
		{
			outFile.write((char *) &obj3,sizeof(Oracle));
		}

	}
	inFile.close();
	outFile.close();

	remove("Rail.dat");
	rename("Temp2.dat","Rail.dat");
	cout<<"\n\n\tRecord Deleted .!.!.!.!.!."<<endl;

}
