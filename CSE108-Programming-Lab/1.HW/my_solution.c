/* 

First homework

*/

#include <stdio.h>

void trigonometry_calculation(int a, int b, int c)
{
	double sinx,cosx,tanx;

	sinx = (double) a / c; // we found sinx
	cosx = (double) b / c; // we found cosx
	tanx = (double) a / b; // we found tanx
	
    printf("Sin(x) = %.2f \n",sinx);
    printf("Cos(x) = %.2f \n", cosx);
    printf("Tan(x) = %.2f \n", tanx);
    
    return;
}


void age_calculation(int x)
{
    unsigned long long int sec = 365*24*60*60 * x; /* calculating the age in seconds */
    
    printf("You are %llu seconds",sec);
}


int main()
{ 

int a,b,c,ourage,seconds;

printf("Enter a side: ");
scanf("%d",&a); /* taking the a side */
printf("Enter b side: ");
scanf("%d",&b); /* taking the b side */
printf("Enter c side: ");
scanf("%d",&c); /* taking the c side */

trigonometry_calculation(a,b,c); 

printf("Enter the age: ");

scanf("%d",&ourage);

printf("Your age = %d \n",ourage);

age_calculation(ourage);

    return 0;
}











