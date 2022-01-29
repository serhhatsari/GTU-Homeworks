/*
Third lab
*/
#include <stdio.h>
#include <stdlib.h>

int find_max_distance(int num_inputs); /* first part */
void find_odd_average(); /* second part */

int main() {
	
    printf("Max dist between two consecutive nums = %d \n\n",find_max_distance(5));
	find_odd_average();

	return 0;
}

int find_max_distance(int num_inputs){
	
 int counter,num ,biggest_dif;
 int difference,num_one,num_two; 

     printf("\t \t FIND MAX DISTANCE \n \n");
     
     	printf("You are gonna enter 5 numbers \nPlease enter number 1 :"); /* taking the first value */
		scanf("%d",&num);
		
		num_one = num; /* assigning the first value to num one */
    
	for(counter=2; counter <= num_inputs ; counter ++){ /* it will go until counter is bigger than num_imputs */
		
		printf("Please enter number %d :",counter);
		scanf("%d",&num);
		
	   num_two = num; /* second num will be held in num two */
	   
	   difference = abs(num_two - num_one); /* it will calculate the difference */
	   
	  if(counter == 2 ){ /* i need it to biggest dif variable to have first value */
	  
	  	biggest_dif = difference;
	  	
	  }
	  
	  if(difference > biggest_dif){ /* it will check if the difference is bigger than the biggest dif */
	  
	  biggest_dif = difference;
	  
      }
      
      num_one = num_two; /* it is needed for loop to continue correctly */
      
   }
	
	
	return biggest_dif;
	
}




void find_odd_average(){
	
	int sum = 0, num= 0; /* sum will be our result */
    int odd_counter = 0; /* odd counter will be the number of odd numbers */
	
	while(num != -1){ /* if user enters 1 it will end the loop and print the sum */
	
	printf("Please enter a number...");
	
	scanf("%d",&num); /* taking the number */
	
	if(num % 2 != 0 && num != -1){ /* it will check if its odd or not */
		
		sum += num; /* it will add the number into sum if its odd */
		
		odd_counter++; /* number of odd numbers will be incremented */
		
	 }
	
   }
   
   printf("Average  of the odd numbers = %f ", sum /(double) odd_counter); /* printing the result */
   
}


