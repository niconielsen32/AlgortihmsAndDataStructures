#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <algorithm> 
#include <math.h> 
#include <bits/stdc++.h> 

using namespace std;

const int numberOfBins = 10007;

int bins[numberOfBins];
int bins1[numberOfBins];
int bins2[numberOfBins];
int balls = 10007;

int ballsInBin, randomNumber, randomNumber1, randomNumber2;




int max_value(int arr[], int elements){

	for(size_t i = 0; i < elements; i++)
    {
       // Change < to > if you want to find the smallest element
       if(arr[0] < arr[i])
           arr[0] = arr[i];
    }

    return arr[0];
}


float average_value(int arr[], int elements, float numOfAverage){

	float numberOfBalls = 0;

	sort(arr, arr+elements, greater<int>());

	for(size_t i = 0; i < numOfAverage; i++)
    {
     	numberOfBalls += arr[i];
    }

    return numberOfBalls/numOfAverage;
}



int main(){

	srand(time(NULL));

	for(size_t i = 0; i < balls; i++){

		randomNumber = rand() % numberOfBins;

		bins[randomNumber]++;

		cout << bins[i] << " ";
	}

	cout << endl;


	int maxVal = max_value(bins, balls);

	cout << "Largest number of balls: " << maxVal << endl;

	float averageVal = average_value(bins, balls, 10);

	cout << "Average number of balls: " << averageVal << endl;


	for(size_t i = 0; i < balls; i++){

		randomNumber1 = rand() % numberOfBins;
		randomNumber2 = rand() % numberOfBins;

		if(bins1[randomNumber1] > bins2[randomNumber2]){
			bins2[randomNumber2]++;
		} else {
			bins1[randomNumber1]++;
		}
	
		cout << bins1[i] << " ";
		cout << bins2[i] << " ";
	}


	cout << endl;

	int maxVal1 = max_value(bins1, balls);
	int maxVal2 = max_value(bins2, balls);

	cout << "Largest number of balls bin 1: " << maxVal1 << endl;
	cout << "Largest number of balls bin 2: " << maxVal2 << endl;

	float averageVal1 = average_value(bins1, balls, 10007);
	float averageVal2 = average_value(bins2, balls, 10007);

	cout << "Average number of balls bin 1: " << averageVal1 << endl;
	cout << "Average number of balls bin 2: " << averageVal2 << endl;



	return 0;
}