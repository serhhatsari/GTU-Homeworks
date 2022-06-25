/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/


#include <stdio.h>
#include "hw5_lib.h"


void test_operate_polynomials () 
{
       double zero_val,first_val,second_val,third_val;
       double zero_value,first_value,second_value,third_value;
	double a3,a2,a1,a0,b3,b2,b1,b0;
	char operat;
	char enterspace;
	
 int zero,first,second,third;
   printf("Please enter the first polynomials coefficients :  \n");
   scanf("(%d, %lf), (%d, %lf), (%d, %lf), (%d, %lf)",&zero,&zero_val,&first,&first_val,&second,&second_val,&third,&third_val);
   enterspace = getchar();
  
  switch(zero){ /* assigning the coefficient */
  
  case 0:
  a0 = zero_val;
  break;
  case 1:
  a1 = zero_val;
  break;
  case 2:
  a2 = zero_val;
  break;
  case 3:
  a3= zero_val;
  break;
  
  }
    switch(first){ /* assigning the coefficient */
  
   case 0:
  a0 = first_val;
  break;
  case 1:
  a1 = first_val;
  break;
  case 2:
  a2 = first_val;
  break;
  case 3:
  a3= first_val;
  break;
  
  }
    switch(second){ /* assigning the coefficient */
  
  case 0:
  a0 = second_val;
  break;
  case 1:
  a1 = second_val;
  break;
  case 2:
  a2 = second_val;
  break;
  case 3:
  a3= second_val;
  break;
  
  }
    switch(third){ /* assigning the coefficient */
  
   case 0:
  a0 = third_val;
  break;
  case 1:
  a1 = third_val;
  break;
  case 2:
  a2 = third_val;
  break;
  case 3:
  a3= third_val;
  break;
  
  }
  
   
   printf("Please enter the second polynomials coefficients : \n");
   scanf("(%d, %lf), (%d, %lf), (%d, %lf), (%d, %lf)",&zero,&zero_value,&first,&first_value,&second,&second_value,&third,&third_value);
   
   enterspace = getchar();
   
     switch(zero){ /* assigning the coefficient */
  
  case 0:
  b0 = zero_value;
  break;
  case 1:
  b1 = zero_value;
  break;
  case 2:
  b2 = zero_value;
  break;
  case 3:
  b3= zero_value;
  break;
  
  }
    switch(first){ /* assigning the coefficient */
  
   case 0:
  b0 = first_value;
  break;
  case 1:
  b1 = first_value;
  break;
  case 2:
  b2 = first_value;
  break;
  case 3:
  b3= first_value;
  break;
  
  }
    switch(second){ /* assigning the coefficient */
  
  case 0:
  b0 = second_value;
  break;
  case 1:
  b1 = second_value;
  break;
  case 2:
  b2 = second_value;
  break;
  case 3:
  b3= second_value;
  break;
  
  }
    switch(third){ /* assigning the coefficient */
  
   case 0:
  b0 = third_value; 
  break;
  case 1:
  b1 = third_value; 
  break;
  case 2:
  b2 = third_value; 
  break;
  case 3:
  b3= third_value; 
  break;
  
  }
   
   printf("Choose the operator you want to use. you can choose (+) , (-), (*) only!");
   scanf("%c",&operat);
   operate_polynomials(&a3,&a2,&a1,&a0,&b3,&b2,&b1,&b0, operat);
}


void test_four_d_vectors ()
{
	double mean_a0=0.0, mean_a1=0.0, mean_a2=0.0, mean_a3=0.0, longest_distance=0.0;
	int N=5;
	four_d_vectors (&mean_a0, &mean_a1, &mean_a2, &mean_a3, &longest_distance, N);
	printf("Mean a0: %f\nMean a1: %f\nMean a2: %f\nMean a3: %f\nThe longest distance between two points: %f\n\n\n", mean_a0, mean_a1, mean_a2, mean_a3, longest_distance);
}


void test_dhondt_method ()
{
	int partyA=0, partyB=0, partyC=0, partyD=0, partyE=0, numberOfSeats=0;
	dhondt_method (&partyA, &partyB, &partyC, &partyD, &partyE, numberOfSeats);
	printf("Party A: %d seat(s).\nParty B: %d seat(s).\nParty C: %d seat(s).\nParty D: %d seat(s).\nParty E: %d seat(s).\n\n\n", partyA, partyB, partyC, partyD, partyE);
}


void test_order_2d_points_cc ()
{
	double x1=0.0, y1=0.0, x2=0.0, y2=0.0, x3=0.0, y3=0.0;
	order_2d_points_cc (&x1, &y1, &x2, &y2, &x3, &y3);
	printf("Counter-Clockwise Order: (%f,%f) - (%f,%f) - (%f,%f)\n\n\n", x1, y1, x2, y2, x3, y3);
}


void test_number_encrypt ()
{
	unsigned char number=0;
	number_encrypt (&number);
	printf("Encrypted number: %d\n\n\n", number);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_operate_polynomials ();
	test_four_d_vectors ();
	test_dhondt_method ();
	test_order_2d_points_cc ();
	test_number_encrypt ();
	return (0);
} /* end main */
