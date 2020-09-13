#include <iostream>
#include <string>
#include <math.h>

using namespace std;


// Returns the sum of the first n natural numbers
int recursiveSum(int n){
	
	// stop recursion when n is 0 or 1
	if(n <= 1){
		return n;
	}
	else{
		// return sum of each number
		return n + recursiveSum(n-1);
	}
}

// Returns the sum of the first n even numbers' squares
int evenSquares(int n){
	
	// stop recursion when n is 0
	if(n == 0){
		return n;
	// check if n is even
	} else if(n % 2 == 0){
		// sum of even numbers squares
		return n*n + evenSquares(n-1);
	} else {
		// if number is off - do nothing and call function again
		return evenSquares(n-1);
	}
}

// Returns the sum of the first n even numbers' squares
int evenSquares2(int n){
	// stop recursion when n is 0
	if(n == 0){
		return n;
	// check if n is even
	} else {
		return pow(n+n,2) + evenSquares2(n-1);
	}
}

// return the nth Finonacci number
int fibNumber(int n){

	// stop recursion when n is 0 or 1
	if(n <= 1){
		return n;
	} else {
		return fibNumber(n-1) + fibNumber(n-2);
	}
}

// return true if string s with the lenght l contains char c - otherwise false
bool linear(string s, char c, int l){

	// Do linear search from back to front
	if(l < 0){
		return false;
	// if string index == char - return true
	} else if(s[l] == c){
		return true;
	// repeat linear search and decrement index
	} else {
		return linear(s, c, l-1);
	}
}


int main(){

	int sumOfNumbers = recursiveSum(3);
	int sumOfEvenSquares = evenSquares(5);
	int sumOfEvenSquares2 = evenSquares2(2);
	int nthFibNumber = fibNumber(9);
	string hello = "Hello";
	char substring = 'e';
	bool containsString = linear(hello, substring, hello.length()-1);

	//cout << "Sum: " << sumOfNumbers << endl;
	//cout << "Even squares: " << sumOfEvenSquares << endl;
	//cout << "Even squares2: " << sumOfEvenSquares2 << endl;
	//cout << "Fibonacci number: " << nthFibNumber << endl;
	cout << "Char is in string: " << containsString << endl;

	return 0;
}