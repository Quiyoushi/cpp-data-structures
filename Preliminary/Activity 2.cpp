#include <iostream>
#include <sstream>
#include <string>

using namespace std; // using std for the library

//main function or main program
int main(){
	
	//space for the numbers
	cout<<"\t";
	
	//numbers above the table
	for(int i=11;i<=20;i++){
		
		cout<<i<<"\t";
		
	};
	
	//spacing
	cout<<"\t"<<endl;

	//main loop
	for(int i=11;i<=20;i++){
		
		// for columns
		cout<<"\n"<<i<<"\t";
			
			//for rows
			for(int j=11;j<=20;j++){
	
				cout<<i*j<<"\t";
				
			};
			
		//spacing
		cout<<"\n";
	
	};
	
	
	return 0;
}
