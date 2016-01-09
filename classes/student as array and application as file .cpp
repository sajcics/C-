

#include <iostream>
#include <fstream> // for data file
#include <cstring>
using namespace std; 

fstream dat; 

class cstudent{
	public: 
		int ident; //identification of student
		char prezime[10]; //last name of student
		float ocjena; // his grade
		
		//entery data of student
		void unos(){
			cout<<"\nIdent: ";
			cin>>ident;
			cout<<"Last name: ";
			cin>>prezime;
			cout<<"Grade: ";
			cin>>ocjena;
		}
		
		//print all data of student
		void ispis(){
			cout<<"\n . . . . . \n"
			<<endl<<ident<<endl<<prezime<<endl<<ocjena<<endl;
		}
};


//array of 100 students
cstudent student[100];

//index array of student
int br_stud=0;

// class of applies
class cprijava{
	public:
		int rbp; //application number
		int idp; //identification
		int br_dv; // number of hall
		char napomena[10]; //remark
	
		//construct
		//opening data file dat
		cprijava(){
			dat.open("prijave2.dat", ios::out);
			dat.close();
			dat.clear();
		}
		
		//entery application
		void upis(){
			cout<<"\nApplication number ";
			cin>>rbp;
			cout<<"Identification: ";
			cin>>idp;
			cout<<"Hall number: ";
			cin>>br_dv;
			cout<<"Remark: ";
			cin.ignore();
			cin.getline(napomena, 10);
			
			//opening data for writting
			dat.open("prijave2.dat", ios::binary | ios::app | ios::out);
			dat.write((char *)this, sizeof(*this));
			dat.close();
			dat.clear();
		}
		
		//print all data from file dat
		void ispis(){
			dat.open("prijave2.dat", ios::in | ios::binary);
			while(1){
				dat.read((char *)this, sizeof(*this));
				if(dat.eof()) break;
				cout<<"\n.....\n"<<endl
				<<rbp<<endl<<idp<<endl<<br_dv<<endl<<napomena<<endl;
			}
			dat.close();
			dat.clear();
			
		}
};

cprijava p;

int main(){
	int odabir;
	
	/* MAIN */
	do{
	cout<<"\nIzbornik"<<endl
	<<"1. Entery student"<<endl
	<<"2. Print all students"<<endl
	<<"3. Entery application"<<endl
	<<"4. Print all applications"<<endl;
	cin>>odabir;
	
	if(odabir==1) student[br_stud].unos();
	if(odabir==1) br_stud++;

	if(odabir==2) 
		for(int i=0; i<br_stud; i++)
			student[i].ispis();
			
	if(odabir==3) p.upis();
	if(odabir==4) p.ispis();
		
	}while(odabir!=9);
	
	
	system("pause");
	return 0;
}


