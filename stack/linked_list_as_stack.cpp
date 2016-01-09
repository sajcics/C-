//In this example, linked list represents stack
#include <iostream>
#include <cstdlib>
using namespace std;

//defining structure elem and pointer
struct elem{
	int broj;
	elem *sljedeci;
};

elem *glava; //declaring a head of linked list

//adding elements in stack (linked list)
void dodaj_na_stog(int br, elem *glava){
	elem *novi=new elem; 
	elem *tek=glava;
	while(tek->sljedeci) tek=tek->sljedeci;
	novi->sljedeci=NULL;
	novi->broj=br;
	tek->sljedeci=novi;	
}

//getting data from stack (linkedlist)
void uzimanje_sa_stoga(elem *glava){
	elem *tek=glava;
	elem *pret, *slje;
	if(tek->sljedeci==NULL && cout<<"\n@Don't have elements in stack\n") return;
	while(tek->sljedeci){
		pret=tek;
		if(pret->broj>100) cout<<"\nPrevious is Null";
		else cout<<"\nPrevious number is: "<<pret->broj;
		
		tek=tek->sljedeci;
		cout<<"\nTekuci broj je: "<<tek->broj;
		
		
		if(tek->sljedeci==NULL) {
			tek=pret;
			tek->sljedeci=NULL;
			cout<<"\n@Don't have elements in stack\n";
			break;
		} 
		
		slje=tek->sljedeci;
		
		cout<<"\nNext number is: "<<slje->broj;
		cout<<"\n........\n";
		
		if(slje->sljedeci==NULL) {
			slje=slje->sljedeci;
			tek->sljedeci=slje;
			cout<<"\n@Number of the top of stack is: "<<tek->broj<<endl;
			break;
		}
	}
}


void broj_na_pocetku(elem *glava){
	cout<<"\n@Number in beginning of stack is: "<<glava->sljedeci->broj<<endl;
}


int main(){
	short int odabir;
	int broj;
	glava=new elem;
	glava->sljedeci=NULL;
	
	do{
	
		cout<<"\n###########################\nMain\n-------"
		<<"\n1. Add numbers in stack"
		<<"\n2. Get numbers from stack"
		<<"\n3. Top number in stack"
		<<"\nChoose : ";
		cin>>odabir;
		
		if(odabir==1 && cout<<"Enter a number: "){
			do{
				cin>>broj;
			}while((broj<0 || broj>9) && cout<<"\n@ Enter a number again.\nBroj: ");
			dodaj_na_stog(broj, glava);
		}
		
		else if(odabir==2) uzimanje_sa_stoga(glava);
		else if(odabir==3) broj_na_pocetku(glava);
		else cout<<"\n@ Incorrect input. Try again.\n";
	
	}while(odabir!=9);
	
	system("pause");
	return 0;
}
