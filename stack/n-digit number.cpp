#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main(){
	stack <int> stog1;
	stack <int> stog2;
	stack <int> result;
	int preljev=0;
	int max=0;
	char broj[10];
	
	cout<<"Enter first number: ";
	cin>>broj;
	
	for(int i=0; i<strlen(broj); i++) stog1.push(broj[i]-48);
	cout<<endl<<"Enter second number: ";
	cin>>broj;
	
	for(int i=0; i<strlen(broj); i++) stog2.push(broj[i]-48);
		int a, b,d;
		while(!stog1.empty() || !stog2.empty()){
			if(stog1.empty()) {
				while(!stog2.empty()){
					int d=stog2.top();
					stog2.pop();
					if(preljev!=0 && preljev--) d+=1;
					result.push(d);
				}
				goto resultat;
			}
		if(stog2.empty ()) {
			while(!stog1.empty()){
				int d=stog1.top();
				stog1.pop();
				if(preljev!=0 && preljev--) d+=1;
				result.push(d);
			}
			goto resultat;
		}

		stog1.pop();
		b=stog2.top();
		stog2.pop();
		
		int c=a+b;
		cout<<endl<<"Sum : "<<c;
		
		if(preljev!=0) c+=1;
		
		if(c>9 && cout<<" PRELJEV !!") {
			c-=10;
			preljev++;
		}
	
		result.push(c);
	}
	
	resultat:
		cout<<endl<<"RESULT: ";
		while(!result.empty()){
			cout<<result.top();
			result.pop();
		}
		
	system("pause");
	return 0;
}