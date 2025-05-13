#include <iostream>
using namespace std;

int main(){
	
	//variable declaration
	int number, numberSquared;
	
	//inputed value
	cout << "Enter a number: ";
	cin >> number;
	cout<< endl;
	
	//squaring the number
	numberSquared = number*number;
	
	//main loop
	for(int loop = 0; loop <  number; loop++){
		
			//looping for rows
		 	for (int loop1 = 0; loop1 < number; loop1++ ){
		 		cout<<numberSquared<<"\t"<<"|";
		 		numberSquared --;
		 		
			 }; 
			 
		//spacing	 
		cout<<endl;
	}; 
	
	return 0;
}