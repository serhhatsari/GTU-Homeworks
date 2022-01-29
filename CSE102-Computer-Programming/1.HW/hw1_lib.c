/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
**
*/

#include <stdio.h>
#include "hw1_lib.h"


double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{
/* I will be using a3 as x^3's coefficients. a2 as x^2 etc.. */

       double first_value_of_xs; /* first value of x , we need it to use trapezoidal rule */

       double integralsum = 0; /* this variable will hold integral sum */
       
       double our_result; 

       first_value_of_xs = xs; 
    
  /* our function = a3*xs*xs*xs + a2*xs*xs + a1*xs + a0  */
        
        while(xs != xe){ /* loop will continue until the upper bound because of trapezoidal rule usage */

        if(xs != xe && xs !=first_value_of_xs){ /* if our value x isnt the first value or the last value it will go here */

		 integralsum += (a3*xs*xs*xs + a2*xs*xs + a1*xs + a0);
        }

	    else if(xs == first_value_of_xs){ /* if our value is the first value of x , it will go here */

		 integralsum += (a3*xs*xs*xs + a2*xs*xs + a1*xs + a0)/2;
	    }

       xs += delta; /* it will increment x as much as delta because of trapezoidal rule usage. */

       if(xs == xe){ /* if our value is the xe which is the upper bound , it will go here before ending the loop */
       
			 integralsum += (a3*xs*xs*xs + a2*xs*xs + a1*xs + a0)/2;
		}


       }

	
	our_result = delta*integralsum;  /* Trapezoidal rule = delta * ((f(xs) / 2) + f(x1) + f(x2) ... + (f(xe)/2) */

    return our_result;
}



double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{
 /* I will be using a4 as x^4's coefficients. a3 as x^3 etc.. */

   double first_value_of_xs; /* first value of x , we need it to use trapezoidal rule */

       double integralsum = 0; /* this variable will hold our integralsum */
       
       double our_result;

       first_value_of_xs = xs;
       
       /*our function = a4*xs*xs*xs*xs + a3*xs*xs*xs + a2*xs*xs + a1*xs + a0 */

        while(xs != xe){  /* loop will continue until the upper bound because of trapoizedal rule usage */

        if(xs != xe && xs !=first_value_of_xs){ /* if our value x isnt the first value or the last value it will go here */

		 integralsum += (a4*xs*xs*xs*xs + a3*xs*xs*xs + a2*xs*xs + a1*xs + a0);
        }

	    else if(xs == first_value_of_xs){ /* if our value is the first value of x , it will go here */

		 integralsum += (a4*xs*xs*xs*xs + a3*xs*xs*xs + a2*xs*xs + a1*xs + a0)/2;
	    }

       xs += delta;  /* it will increment x as much as delta because of trapezoidal rule usage. */

       if(xs == xe){ /* if our value is the xe which is the upper bound , it will go here before ending the loop */

			 integralsum += (a4*xs*xs*xs*xs + a3*xs*xs*xs + a2*xs*xs + a1*xs + a0)/2;
		}


       }

	our_result = delta*integralsum;   /* Trapezoidal rule = delta * ((f(xs) / 2) + f(x1) + f(x2) ... + (f(xe)/2) */

    return our_result;
}


double root3(double a0, double a1, double a2, double a3, double xs, double xe)
{
/* I will be using a3 as x^3's coefficients. a2 as x^2 etc.. */
     double x = 1 ,realroot; /* x represents the variable x in our function. we need it to use newtons method */

     while((realroot-x)!=0){ /* if the difference between real root and x is zero that means we found the root by using Newton Raphson Method*/

     double func = a3*x*x*x + a2*x*x + a1*x + a0; /* our main function... */
     double derivfunc =3*a3*x*x + 2*a2*x + a1; /* derivate form of our main function */

	  realroot = x;
	  x = x -((func)/(derivfunc)); /* Newton Raphson Method usage */

   }

   return realroot;
}


double root4(double a0, double a1, double a2, double a3, double a4, double xs, double xe)
{
/* I will be using a4 as x^4's coefficients. a3 as x^3 etc.. */
    double x= 1 ,realroot; /* x represents the variable x in our function. we need it to use newtons method */

    while((realroot-x)!=0){ /* if the difference between real root and x is zero that means we found the root by using Newton Raphson Method*/

   	double func = a4*x*x*x*x + a3*x*x*x + a2*x*x + a1*x + a0; /* our main function */
    double derivfunc =4*a4*x*x*x + 3*a3*x*x + 2*a2*x+ a1;     /* derivatived form of our main function */

    realroot = x;
    x = x -(( func )/(derivfunc )); /* Newton Raphson Method usage*/

   }
   return realroot;
}
 
