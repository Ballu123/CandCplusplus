/*
*Name:Balram Panwar,
*Email id: balram.panwar@gmail.com
*Name of the file: C2A1E2_main.c
*Win7
*Microsoft Visual Studio
*
*Structure PersonInfo : Definition of the structure
*Function DeclareCppStruct() : Declare the variable of type PersonInfo
*Function PrintSomething() : Display when user pass double or no  data type argument to the calling function
*Function PrintSomething() : Display when user pass float data type to the calling function
*Function PrintSomething() : Display when user pass char* data type or no argument to the calling function
*Function TestPrintSomething() : Calling to the function PrintSomething() as per the data types
*Function DisplayBases() : Display decimal, octal, and hexadecimal value of an Integral part of a value
*Function DisplayCharValues() : Display the decimal numeric values of the variables
*Function Main(): Display content of printf statement
*/
#include<iostream>
#include <ostream>

using namespace std;
/*
*structure PersonInfo : Definition of the structure having member function and data members
*/
struct PersonInfo{
private:
	int age;
protected:
	bool error;
	void DoNothing(double **ppDbl)const;
public:
	int GetAge(const int *pInt) const{
		return age + *pInt;
	}
};
/*
*Function DeclareCppStruct : Declare the variable of type PersonInfo
*/
PersonInfo* DeclareCppStruct(){
	PersonInfo person;
	return &person;
}
/*
*Function PrintSomething : Display when user pass double or no  data type argument to the calling function
*/
void PrintSomething(double param = 0){
	cout << param << "\n";
}
/*
*Function PrintSomething : Display when user pass float data type to the calling function
*/
void PrintSomething(float param){
	cout << param << "\n";
}
/*
*Function PrintSomething : Display when user pass char* data type or no argument to the calling function
*/
void PrintSomething(char *param){
	cout << param << "\n";
}
/*
*Function TestPrintSomething : Calling to the function PrintSomething() as per the data types
*/
void TestPrintSomething(){
	double valuedo = 23.4;
	float valueft = 1825e-1;
	char *s = "Hello world";
	PrintSomething();
	PrintSomething(valuedo);
	PrintSomething(valueft);
	PrintSomething(s);
}
/*
*Function DisplayBases : Display decimal, octal, and hexadecimal value of an Integral part of a value
*/
long DisplayBases(double value){
	int inteval = (long)value;
	cout << dec << inteval << '\n' << oct << inteval << '\n' << hex << inteval << '\n';
	return inteval;
}
/*
*Function DisplayCharValues : Display the decimal numeric values of the variables
*/
void DisplayCharValues(){
	const char a = 'a';
	const char b = 'b';
	const char c = 'c';
	cout << "Decimal of a is " << (int)a << "\n";
	cout << "Decimal of b is " << (int)b << "\n";
	cout << "Decimal of c is " << (int)c << "\n";
}
/*
*Main: Display content of printf statement
*/
int main(){
	cout << "Assignment 1 Exercise 2 Complete!";
	return 0;
}