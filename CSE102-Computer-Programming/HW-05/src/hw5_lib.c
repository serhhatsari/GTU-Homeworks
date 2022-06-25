/*
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/

#include <stdio.h>
#include <math.h>
#include "hw5_lib.h"


void operate_polynomials  (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double* b0, char op)
{
		double six,five,four,three,two,one,zero;
	
     if(op == '+'){ /* if the sign is positive it will go here */
	 
			*a3 = *a3 + *b3;
			*a2 = *a2 + *b2;
			*a1 = *a1 + *b1;
			*a0 = *a0 + *b0;
			printf("x^3 = %.2f   x^2 = %.2f   x = %.2fx   x^0 = %.2f",*a3,*a2,*a1,*a0);
     }
	 else if(op == '-'){ /* if the sign is negative it will go here */

			*a3 = *a3 - *b3;
			*a2 = *a2 - *b2;
			*a1 = *a1 - *b1;
			*a0 = *a0 - *b0;
			printf("x^3 = %.2f   x^2 = %.2f   x =  %.2fx   x^0 = %.2f",*a3,*a2,*a1,*a0);
    }
	else if(op == '*'){
		six = (*a3 * *b3); /* i will calculate the coefficients with these */
	    five = ( *a3 * *b2) + ( *a2 * *b3); /* i will calculate the coefficients with these */
	    four = ( *a2 * *b2) +(*a3 * *b1) + (*b3 * *a1); /* i will calculate the coefficients with these */
	    three = (*a3 * *b0) + (*a0 * *b3) + ( *a2 * *b1) + (*a1 * *b2); /* i will calculate the coefficients with these */
	    two = (*a1 * *b1) + (*a2 * *b0) + (*a0 * *b2); /* i will calculate the coefficients with these */
	    one = (*a1 * *b0) + (*b1 * *a0); /* i will calculate the coefficients with these */
	    zero = (*a0 * *b0); /* i will calculate the coefficients with these */
	    printf("x^6: %.2f  x^5 : %.2f   x^4 : %.2f  x^3 : %.2f x^2 : %.2f  x^1 : %.2f x^0 : %.2f",six,five,four,three,two,one,zero);
   }
    
    
}


void four_d_vectors (double* mean_a0, double* mean_a1, double* mean_a2, double* mean_a3, double* longest_distance, int N)
{
	int ctr;                                          
    double d0, d1, d2, d3, euclidian_distance = 0; 
    double first, second, third, fourth;                   
    
    for (ctr = 0; ctr < N ; ctr++)
    {
        printf("\nEnter dimensions of %d. 4D vector \n ", ctr + 1);
        scanf("%lf %lf %lf %lf", &d0, &d1, &d2, &d3);       

        if (d0 == -1 && d1 == -1 && d2 == -1 && d3 == -1)  /* if user input -1 -1 -1 -1 it will end the loop */
        {
            break;
        }
        if (ctr == 0) /* just for the first time we will assign these variables */
        {
            first = d0;
            second = d1;
            third = d2;
            fourth = d3;
        }
        else        
        {
            distance_between_4d_points (d0 - first, d1 - second , d2 - third, d3 - fourth, &euclidian_distance);        
            
            printf("\nDif between 2 vector =  %.2f\n", euclidian_distance);

            first = d0;
            second = d1;
            third = d2;
            fourth = d3;
        }

        if (euclidian_distance > *longest_distance) /* it will check if longest is changed or not */
        {
            *longest_distance = euclidian_distance;
        }

        
        *mean_a0 +=  d0; /* they will calculate the sum of them */
        *mean_a1 += d1;
        *mean_a2 += d2;
        *mean_a3 += d3;

   
    }

    *mean_a0 /= ctr; /* they will calcualte the average */
    *mean_a1 /= ctr;
    *mean_a2 /= ctr;
    *mean_a3 /= ctr;
}


void distance_between_4d_points (double d0, double d1, double d2, double d3, double* euclidian_distance)
{
    *euclidian_distance = sqrt((d0 * d0 + d1 * d1 + d2 * d2 + d3 * d3)); 
}


void dhondt_method (int* partyA, int* partyB, int* partyC, int* partyD, int* partyE, int numberOfSeats)
{
		int aseat=0,counterA = 2,bseat=0,counterB =2 , cseat=0,counterC = 2 , dseat= 0,counterD = 2, eseat= 0, counterE = 2;
	int real_A = *partyA,real_B=*partyB,real_C=*partyC,real_D=*partyD,real_E=*partyE; /* it will hold the real value of my partynumbs */
	
	int A = *partyA, B=*partyB, C=*partyC, D = *partyD, E=*partyE; /* it will also hold the real value */
	
	while((aseat+bseat+cseat+dseat+eseat)!=numberOfSeats){ /* it will go until the number of seats are equal the sum of seats */
		
		if(*partyA >= *partyB && *partyA >= *partyC && *partyA >= *partyD && *partyA >= *partyE){ /* if the conditionds are true it will go this if statement */
			aseat++; /* increasing the number of seat */
			real_A = real_A / counterA;
			*partyA = real_A;
			real_A = A;
			counterA++;
		}
		else if(*partyB > *partyA && *partyB >= *partyC && *partyB >= *partyD && *partyB >= *partyE){ /* if the conditionds are true it will go this if statement */
			bseat++; /* increasing the number of seat */
			real_B = real_B / counterB;
			*partyB = real_B;
			real_B = B;
			counterB++;
		}
		else if(*partyC > *partyA && *partyC > *partyB && *partyC >= *partyD && *partyC >= *partyE){ /* if the conditionds are true it will go this if statement */
			cseat++; /* increasing the number of seat */
			real_C = real_C / counterC;
			*partyC = real_C;
			real_C = C;
			counterC++;
		}
		else if(*partyD > *partyA && *partyD > *partyC && *partyD > *partyB && *partyD >= *partyE){ /* if the conditionds are true it will go this if statement */
			dseat++; /* increasing the number of seat */
			real_D = real_D / counterD;
		    *partyD = real_D;
		    real_D = D;
			counterD++;
		}
		else if(*partyE > *partyA && *partyE > *partyC && *partyE > *partyD && *partyE > *partyB){ /* if the conditionds are true it will go this if statement */
			eseat++; /* increasing the number of seat */
			real_E = real_E / counterE;
			*partyE = real_E;
			real_E = E;
			counterE++;
		}	
	}
	
	*partyA = aseat; /* assigning */
	*partyB = bseat; /* assigning */
	*partyC = cseat; /* assigning */
	*partyD = dseat; /* assigning */
	*partyE = eseat;  /* assigning */	 
}


void order_2d_points_cc (double* x1, double* y1, double* x2, double* y2, double* x3, double* y3)
{
   
	
}


void number_encrypt (unsigned char* number)
{
	char b7='-', b6='-', b5='-', b4='-', b3='-', b2='-', b1='-', b0='-';
	get_number_components (*number, &b7, &b6, &b5, &b4, &b3, &b2, &b1, &b0);
	reconstruct_components (number, b7, b6, b5, b4, b3, b2, b1, b0);
	
}


void get_number_components (unsigned char number, char* b7, char* b6, char* b5, char* b4, char* b3, char* b2, char* b1, char* b0)
{
	
int i,num;  
*b7 = 0, *b6 = 0, *b5 = 0, *b4 = 0 , *b3 = 0, *b2 = 0, *b1 = 0, *b0 = 0; /* we will assign a first value */

*b0 = number % 2;  /* it will check if the bit is 1 or 0 */
number = number / 2;    
if(number <= 0){

    return;
}

*b1 = number % 2;   /* it will check if the bit is 1 or 0 */
number = number / 2;  
if(number <= 0){

    return;
}

*b2 = number % 2;   /* it will check if the bit is 1 or 0 */
number = number / 2;  

if(number <= 0){
    return;
}


*b3 = number % 2;   /* it will check if the bit is 1 or 0 */
number = number / 2; 
   
if(number <= 0){

    return;
}


*b4 = number % 2;  /* it will check if the bit is 1 or 0 */
number = number / 2;    

if(number <= 0){

    return;
}


*b5 = number % 2;   /* it will check if the bit is 1 or 0 */
number = number / 2;    
if(number <= 0){

    return;
}


*b6 = number % 2;  /* it will check if the bit is 1 or 0 */
number = number / 2;    
if(number <= 0){

    return;
}


*b7 = number % 2;  /* it will check if the bit is 1 or 0 */
number = number / 2;    
if(number <= 0){

    return;
}

}


void reconstruct_components (unsigned char* number, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0)
{
	   char temp,seven,six,five,four,three,two,one,zero;
   int whole=0; /* it will hold my value */
   *number = 0;
   seven = b7; /* it will assign the real value */
   six = b6;  /* it will assign the real value */
   five = b5;  /* it will assign the real value */
   four = b4;  /* it will assign th e real value */
   three = b3; /* it will assign the real value */
   two = b2;  /* it will assign the real value */
   one = b1;  /* it will assign the real value */
   zero = b0;  /* it will assign the real value */
   
   b7 = zero; /* making some swaps */
   b6 = one; /* making some swaps */
   b5 = six; /* making some swaps */
   b4 = seven; /* making some swaps */
   b3 = four; /* making some swaps */
   b2 = five; /* making some swaps */
   b1 = two; /* making some swaps */
   b0 = three; /* making some swaps */
   
   if(b7 == 1){ /* calculating the number */

    whole += 128;

   }
      if(b6 == 1){ /* calculating the number */
   
   whole += 64;
   }
      if(b5 == 1){ /* calculating the number */
   
    whole += 32;
   }
      if(b4 == 1){ /* calculating the number */
   
   whole += 16;
   }
   
    if(b3 == 1){ /* calculating the number */
   
   whole += 8;
   }   
   if(b2 == 1){ /* calculating the number */
   
    whole += 4;
   }
      if(b1 == 1){ /* calculating the number */
   
    whole += 2;
   }
      if(b0 == 1){ /* calculating the number */
   
    whole += 1;
   }
  
  *number = whole;
}
