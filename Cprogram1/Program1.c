/*
 * Program1.c
 *
 *  Created on: Feb 10, 2023
 *      Author: c653a603
 */
#include <stdio.h>


// helper function that translates an int (0-11) into a string of the month it represents
char* getMonth(int m)
{
	char* month;
	switch(m){
			case 0:
				month = "January";
				break;
			case 1:
				month = "February";
				break;
			case 2:
				month = "March";
				break;
			case 3:
				month = "April";
				break;
			case 4:
				month = "May";
				break;
			case 5:
				month = "June";
				break;
			case 6:
				month = "July";
				break;
			case 7:
				month = "August";
				break;
			case 8:
				month = "September";
				break;
			case 9:
				month = "October";
				break;
			case 10:
				month = "November";
				break;
			case 11:
				month = "December";
				break;
	}
	return month;
}


// start of main function ------------------------

int main(){

	// get the name of the input file
	char fileName[20] = "";
	printf("Enter the name of the input file: \n");
	scanf("%s", fileName);

	// open the file
	FILE *fptr;
	fptr = fopen(fileName, "r");

	// read the file into an array
	float myFloat;
	float monthArray[12];
	float i = fscanf(fptr, "%f", &myFloat);
	int j = 0;

	while(i != EOF)
	{
		monthArray[j] = myFloat;
		i = fscanf(fptr, "%f", &myFloat);
		j++;
	}
	// done reading the file -- close it
	fclose(fptr);


	// Monthly Sales Report
	printf("\n\nMonthly Sales Report for 2022: \n\nMonth\tSales\n\n");
	for(int i = 0; i < 12; i++){
		printf("%s\t$%.2f\n", getMonth(i), monthArray[i]);
	}


	//Sales Summary
	int maxIndex = 0;
	int minIndex = 0;
	float totalSales = monthArray[0];
	for (int i = 1; i < 12; i++){
		if(monthArray[i] > monthArray[maxIndex]){
			maxIndex = i;
		} else if (monthArray[i] < monthArray[minIndex]) {
			minIndex = i;
		}
		totalSales += monthArray[i];
	}
	printf("\nSales summary: \n\nMinimum Sales:\t%f\t(%s)\nMaximum Sales:\t%f\t(%s)\nAverage Sales:\t%f\n", monthArray[minIndex], getMonth(minIndex), monthArray[maxIndex], getMonth(maxIndex), totalSales/12);


	// Six-Month moving average report
	printf("\nSix-Month Moving Average Report:\n\n");
	for (int i = 0; i < 7; i++){

		float sixMonthSum = 0;
		for(int j = 0; j < 6; j++){
			sixMonthSum += monthArray[i+j];
		}
		printf("%s\t-\t%s\t$%.2f\n", getMonth(i), getMonth(i+6), sixMonthSum/6);
	}


	// Sales Report: Highest to Lowest
	printf("\nSales Report (Highest to Lowest):\n\nMonth\tSales\n\n");
	// make a temp array that can be altered
	float temp[12];
	for(int i = 0; i < 12; i++){
		temp[i] = monthArray[i];
	}
	// each iteration will find the highest grossing month, print it, then set it to zero to flag it
	for(int i = 0; i < 12; i++){
		maxIndex = 0;
		for(int j = 1; j < 12; j++)
		{
			if(temp[j] > temp[maxIndex])
			{
				maxIndex = j;
			}
		}
		printf("%s\t$%.2f\n", getMonth(maxIndex), temp[maxIndex]);
		temp[maxIndex] = 0;
	}

	//end of main
	return 0;
}


