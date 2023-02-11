/*
 * Program2.c
 *
 *  Created on: Feb 10, 2023
 *      Author: cjanderson
 */
#include <stdio.h>
#include <stdbool.h>

// this edition committed to gitHub from the terminal
// attempt 2

int main(){
	bool isRunning = true;
	int score = 0;

	while(isRunning){

		printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
		scanf("%d", &score);

		if(score <= 1)
			isRunning = false;
		else
		{
			printf("possible combinations of scoring plays:\n");
			for (int viii = 0; viii <= score; viii += 8){
				for(int vii = 0; vii <= score; vii += 7){
					for(int vi = 0; vi <= score; vi += 6){
						for(int iii = 0; iii <= score; iii += 3){
							for(int ii = 0; ii <= score; ii += 2){
								if(viii+vii+vi+iii+ii == score){
									printf("%d TD + 2pt, "
											"%d TD + FG, "
											"%d TD, "
											"%d 3pt FG, "
											"%d Safety\n",
											viii/8, vii/7, vi/6, iii/3, ii/2);
								}
							}
						}
					}
				}
			}
		}

	}

	// end of main
	return 0;
}
