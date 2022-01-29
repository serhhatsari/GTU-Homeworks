#include <stdio.h>
#include <stdlib.h>
void average_finder(int arr[][5],int arr1[][9]);
void array(int arr[][5],int arr1[][9]);
void intervew(const char *s1, const char *s2, char * s3);

int main(){
    int first_array[3][5];
	int second_array[4][9];
	
	char first[50],second[50],third[100];
	
	
    array(first_array,second_array);
	average_finder(first_array,second_array);

	printf("Enter the first string :");
	scanf("%s",first);
	
	printf("Enter the second string: ");
	scanf("%s",second);
	
	intervew(first,second,third);
	printf("Ouput is = %s",third);
	
	
	return 0;
}

void average_finder(int arr[][5],int arr1[][9]){
	
	printf("Average Finder \n\n");
	int i,k;
		for(i=0;i<3;i++){
		for(k = 0;k<5;k++){
		
				printf("%d  ",arr[i][k]); /* printing the matrix */
							
			}
			printf("\n");
		}
	
	
	int sum=0; /* it will hold my sum */
	int counter1=0;
	double average1=0;
	
	for(i=0;i<3;i++){
		for(k = 0;k<5;k++){
			if((i+k) % 2 == 0){ /* it will check the condition */
				sum += arr[i][k]; /* it will do calculation */
				counter1++;
				
			}
		}
	}

	average1 = (double)(sum) / counter1; /* calculating the average */
    printf("Result = %f ",average1);	
    
    
    
    	printf("Average Finder \n\n");
     
		for(i=0;i<4;i++){
		for(k = 0;k<9;k++){
		
				printf("%d  ",arr1[i][k]); /* printing the matrix */
							
			}
			printf("\n");
		}
	
	
 sum=0;
 counter1=0;
 average1=0;
	
	for(i=0;i<4;i++){
		for(k = 0;k<9;k++){
			if((i+k) % 2 == 0){ /* checking the condition */
				sum += arr1[i][k]; /* calculating the sum */
				counter1++;
				
			}
		}
	}
	
	average1 = (double)(sum) / counter1; /* printing the result */
    printf("Result = %f \n\n",average1);	
	
	
}

void array(int arr[][5],int arr1[][9])
{
	int i,k;
	int counter = 1;
	
 for(i = 0;i <3; i++){
 	
 	for(k=0;k<5;k++){
 		
 		arr[i][k] = 2*counter*counter  -3; /* it will fill my arrat */
 		counter++;
 		
	 }
 	
 }
 
 i=0;
 k=0;
 counter = 1;
	
 for(i = 0;i <4; i++){
 	
 	for(k=0;k<9;k++){
 		
 		arr1[i][k] = 2*counter*counter  -3; /* it will fill the second array */
 		counter++;
 		
	 }
 	
 }
 
 
 
 
}
  


void intervew(const char *s1, const char *s2, char * s3){
	    
    int i = 0, j = 0,flag = 0;

    while (s1[j] != '\0' && s2[j] != '\0') /* assigning the elements to the output parameter */
    {
     if(s1[j] == '\0'){
     	flag = 1; /* it means first string is over */
     	break;
	 }
	 if(s2[j] == '\0'){
	 	flag = 2; /* it means second string is over */
	 	break;
	 }
        s3[i] = s1[j];
        s3[i + 1] = s2[j];
        i += 2;
        j++;
    }
    
    
    switch(flag) /* checking if any of numbers has finished */
    {
    case 1:	
        while (s2[j] != '\0')
        {
            s3[i] = s2[j];
            j++;
            i++;
        }
    break;
    case 2:
    	
        while (s1[j] != '\0')
        {
            s3[i] = s1[j];
            j++;
            i++;
        }
    break;
    }


}






