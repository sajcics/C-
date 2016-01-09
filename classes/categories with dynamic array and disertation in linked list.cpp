// This program is an example of dynamic array and linked list withouth liberies <list> using classes
// we have main with possible task what we can execute like entery and print data
// all names of variable are in croatian so I put in comments what they mean 

#include <iostream>
#include <cstring>
using namespace std;
int indexkat=0; // for array when we entery data of categories

//class categories
class ckat{
	public:
		int mat; //identification of category
		char naziv[10]; // name of category
		
		//entry data of categories in array
		void unos(){
			cout<<"\nIdentification: ";
			cin>>mat;
			cout<<"Name: ";
			cin.ignore();
			cin.getline(naziv, 10);
			indexkat++; //we want next filed of array how is empty
		}
		
		//print all data of categories
		void ispis(){
			cout<<endl<<mat
			<<endl<<naziv<<endl;
		}
};

ckat *k=new ckat[100]; //we need 100 data of categories and k pointer is showing a array of ckat data type

//class disertation
class crad{
	private:
		crad *slje; //pointer
	public:
		int br_rada; //disertation
		int mat; //indentification of disertation
		float ocjena; // grade
		char napomena[10]; //remark
	
	//construct
	crad(){
		slje=NULL; 
	}
	
		//writting data of disertation in linked list
		void upis(){
			
			crad *tekuci=this; //allocate the head of linked list
			crad *novi=new crad; //create a new link which will become a part of linked list in tekuci->slje=novi (in the end of method upis)
			while(tekuci->slje) tekuci=tekuci->slje; //going on to next link
			
			//entry data for disertation
			cout<<"\nID of work:";
			cin>>novi->br_rada;
			cout<<"Identification: ";
			cin>>novi->mat;
			cout<<"Grade: ";
			cin>>novi->ocjena;
			cout<<"Remark: ";
			cin.ignore();
			cin.getline(novi->napomena, 10);
			tekuci->slje=novi; //created link which we had created in beginning of upis method and now
								// is a part of linked list
		}
		
		//print all data of disertation
		void ispis(){
			crad *tek=this; //defining pointer
			// we want to print all data from linked list to console
			while(tek->slje) {
				tek=tek->slje;
				cout<<endl<<tek->br_rada<<endl
				<<tek->mat<<endl<<tek->ocjena<<endl
				<<tek->napomena<<endl;
				}
		}
};

crad *r=new crad; // pointer r is type of crad class

int main(){
	
	int odabir;
	
	/* MAIN */
	do{
		cout<<"\n1. Entery categories"<<
		endl<<"2. Print categories"<<
		endl<<"3. Entry disertation"<<
		endl<<"4. Print disertation"<<endl;
		cin>>odabir;
		
		if(odabir==1) k[indexkat].unos(); //pointer entries in 'indexkat' field of array
		else if(odabir==2) 
			for(int i=0; i<indexkat; i++)
				k[i].ispis();
		else if(odabir==3) r->upis(); 
		else if(odabir==4) r->ispis();
	}while(odabir!=9);
	system("pause");
	return 0;
}
