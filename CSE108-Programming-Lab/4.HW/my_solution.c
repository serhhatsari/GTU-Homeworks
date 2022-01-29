#include <stdio.h>

void russian_multiplication(unsigned int*  multiplicand,unsigned int*multiplier);
void  multiply_polynomials(double *a3, double *a2, double *a1, double *a0, double *b3, double  *b2, double *b1, double b0);

int main() {
	
	int num_on,num_tw; /* our numbers */
	printf("Enter the first num: "); /* taking the first value */
	scanf("%d",&num_on);
	printf("Enter the second num: "); /* taking the second value */
	scanf("%d",&num_tw);
	
    russian_multiplication(&num_on, &num_tw);
	 
    printf("Multiplicant: %d Multiplier: %d\n\n", num_on, num_tw); /* printing the result */

    double thi_first,tw_first,on_first,zer_first; /* coefficients */
	double thi_sec,two_sec,on_sec,zer_sec; /*coefficients */
			
			
	printf("Please enter the third coefficients of the first function:\n");
	printf("Like this = 2.1 3.2 1.2 3.2\n");
	printf("Please enter the coefficients:"); /* taking the values for the first one*/
	scanf("%lf %lf %lf %lf",&thi_first,&tw_first,&on_first,&zer_first);
	
	printf("Please enter the third coefficients of the second function:\n");
	printf("Like this = 2.1 3.2 1.2 3.2\n");
	printf("Please enter the coefficients: "); /* taking the values for the second one */
	scanf("%lf %lf %lf %lf",&thi_sec,&two_sec, &on_sec, &zer_sec);
	
	multiply_polynomials(&thi_first,&tw_first,&on_first,&zer_first,&thi_sec,&two_sec,&on_sec,zer_sec);
	
	printf(" %.3fx^6 %+.3fx^5 %+.3fx^4 %+.3fx^3 %+.3fx^2 %+.3fx %+.3f\n", thi_first,tw_first,on_first,zer_first, thi_sec, two_sec, on_sec); /* printing the result */
	
	return 0;
}

void russian_multiplication(unsigned int*  multiplicand,unsigned int*multiplier){
	
  int sum = 0;
	
	while(*multiplier != 1) /* loop */
	{                      
		if(*multiplier % 2 == 1) /*checking the remainder */ 
		{
		
			sum +=  *multiplicand; /* adding it to sum if the remainder equals 1 */
	     }
	     
		*multiplier /= 2;
		*multiplicand *= 2;
	}
	
	*multiplicand += sum; /* return sum with output parameter */
    
}
	
	

void  multiply_polynomials(double*  a3,  double*  a2,  double*  a1,  double*  a0,  double*  b3, double* b2, double* b1, double b0){
	
	double six,five,four,three,two,one,zero; /* my coeficients */
	
	
	six = (*a3 * *b3); /* i will calculate the coefficients with these */

	
	five = ( *a3 * *b2) + ( *a2 * *b3); /* i will calculate the coefficients with these */

	
	four = ( *a2 * *b2) +(*a3 * *b1) + (*b3 * *a1); /* i will calculate the coefficients with these */
	
	
	three = (*a3 * b0) + (*a0 * *b3) + ( *a2 * *b1) + (*a1 * *b2); /* i will calculate the coefficients with these */
	
	
	two = (*a1 * *b1) + (*a2 * b0) + (*a0 * *b2); /* i will calculate the coefficients with these */
	
	
	one = (*a1 * b0) + (*b1 * *a0); /* i will calculate the coefficients with these */
	
	zero = (*a0 * b0); /* i will calculate the coefficients with these */
	
	*a3 = six; /* to return the value i will assign it to pointer */
	*a2 = five; /* to return the value i will assign it to pointer */
	*a1 = four; /* to return the value i will assign it to pointer */
	*a0 = three; /* to return the value i will assign it to pointer */
	*b3 = two; /* to return the value i will assign it to pointer */
	*b2 = one; /* to return the value i will assign it to pointer */
	*b1 = zero; /* to return the value i will assign it to pointer */
    	
	
}

