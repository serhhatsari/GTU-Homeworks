#include <stdio.h>
#include <stdlib.h>
void expression0 (int x, int *result){
    int i,myresult;
    *result = 0;
    
	for(i= 0; i<= x;i++){ /* sigma calculation */
		
		myresult = i*i + 5;
		
		*result += myresult;
		
	}
	
/* calculation of the expression0 for the value of x*/ }

void expression1 (int x, int *result){
	
     int i,myresult;
    *result = 0;
	for(i= 0; i<= x;i++){ /* sigma calculation */
		
		myresult = 2*i + 1;
		
		*result += myresult;	
	}
	
/* calculation of the expression1 for the value of x*/ }

void expression2 (int x, int *result){
	int i,myresult;
    *result = 0;
    
	for(i= 0; i<= x;i++){ /* sigma calculation */
		
		myresult = i*i;
		
		*result += myresult;
			
	}
	
/* calculation of the expression2 for the value of x*/ }

void addition (void (*func)(int, int *), int *sum, int n){
	
	int mysum;
	
	func(n, &mysum); /* it will find the value of it */
	
	*sum = mysum; /* assign it to sum */
	
/* obtaining the calculations for a single expression and return the result */ }

void calculation (int *sumArray, int n){
	
	*sumArray = n; /* it will put the result into the array */
	
	
/* Obtaining the summations and assinging them to sumArray respectively*/ }


void createArray(int (*array)[10]){
	int i,j;
	for(i =0;i<10;i++){
		for(j =0;j<10;j++){
			
			 array[i][j] = rand () %90 + 10; /* initiliazing array elements with numbers between 0 and 100 */
		}
	}
	
		for(i =0;i<10;i++){
		for(j =0;j<10;j++){
			printf("%d \t",array[i][j]); /* printing the array */
					}
					printf("\n \n");
	}
	while(1){
	
	printf("Which element of the matrix do you want to reach?\n");
	printf("i :");
	scanf("%d",&i);
	printf("j: ");
	scanf("%d",&j);
		if(i >= 10 || i < 0 || j >= 10 || j < 0){
			printf("Invalid input. Terminating...\n");
			return;
		
	}
	printf("%d.row  %d.column of the matrix is %d \n",i,j,array[i][j]);
   }
}


int main(){
	
int n,sum,sumArray[3];
int myarray [10][10];

    printf("Please enter the number:  "); /* taking the value */
    scanf("%d",&n);
    printf("n: %d \n",n);

	addition((&expression0), &sum, n); 
	calculation(&sumArray[0], sum);
	printf("Sum of expression0: %d\n", sumArray[0]); /*printing the resultr */
	
	
	addition((&expression1), &sum, n);
	calculation(&sumArray[1], sum);
	printf("Sum of expression1: %d\n", sumArray[1]); /* print the result */
	
	
	addition((&expression2), &sum, n);
	calculation(&sumArray[2], sum);
	printf("Sum of expression0: %d\n", sumArray[2]);
	
	
createArray(myarray);
/* Declaring array, reading “n”, obtaining the results by using functions, and printing them. Nothing else.*/ 
}

