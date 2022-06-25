/*
** hw1_io.c:
**
** The source file implementing output functions...
**
** Author: Yakup Genc. (c) 2018-2021
****
** Revision: 2021.03.03.20.16
** 
*/


#include <stdio.h>
#include "hw1_io.h"


void write_polynomial3(double a0, double a1, double a2, double a3)
{
 double coefficents[4]; /* coefficents of our polynomial */
 int i, pow; /* i is for loop, pow represents the exponent of our x */
       coefficents[0] = a3;
       coefficents[1] = a2;
       coefficents[2] = a1;
       coefficents[3] = a0;
    pow= 3; 
 
 
for(i=0; i < 4; i++,pow--){ /* we will check all elements of coefficients array by this loop.*/

if(coefficents[i] > 0 ){  /* this will print plus (+) or blank if the value (coefficient) is positive */

    if(i==0){  /* it will print blank if its the initial value even though it is positive.*/
  	    printf(" ");
	}
	
    else{ /* it will print plus (+) with this else code*/
	    printf("+");
	 } 
}

else if(coefficents[i] < 0){ /* this will print just blank to avoid sign replications if the value(coefficient) is negative */
	
printf(" ");
} 

else{ /* if the value(coefficient) equals zero it will skip the rest of the loop and print anything  */
continue;
} 


if(pow != 0){ /* with this if statement, we are gonna print coefficients and pows. */

        if((coefficents[i] - (int)coefficents[i])==0 ){ /* this will check if its 1.0, 2.0 etc. type of double. i mean a.b and b = 0 kind of inputs.*/
        
                if(coefficents[i]==1){ /* this will check if the coefficient is one, if it is one, it'll go here and wont print the coefficient which is 1*/
            
                   printf("x^%d ",(pow)); 
                }
		  	    else{ /* if the coefficient isnt one, it will go here */
		 	
                   printf("%.dx^%d ",(int)coefficents[i],(pow));
                }
        }	
		else{  /*if its not that kind of input it will go here */
        printf("%.1fx^%d ",coefficents[i],(pow));
        }
}

else{ /* if the pow is 0 , that means we are printing our constant value, so we dont need to print pow */

          if((coefficents[i] - (int)coefficents[i])==0){ /* this will check if its 1.0, 2.0 etc. type of double. i mean a.b and b = 0 kind of inputs.*/
        
               printf("%.d ",(int)coefficents[i]); 
           }
           else{ /*if its not that kind of input it will go here */
        	
               printf("%.1f ",coefficents[i]); 
           }
    }
}
printf("\n");
}


void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
   double coefficents[5]; /* coefficents of our polynomial */
   int i, pow; /* i is for loop, pow represents the exponent of our x */
       coefficents[0] = a4;
       coefficents[1] = a3;
       coefficents[2] = a2;
       coefficents[3] = a1;
       coefficents[4] = a0;
   
   pow= 4; 
   
for(i =0 ; i < 5; i++,pow--){ /* we will check all elements of coefficients by this loop.*/
	
if(coefficents[i] > 0 ){  /* this will print plus (+) if the value (coefficient) is positive */

    if(i==0){ /* but it wont print plus if its the initial value even though it is positive.*/
    
         printf(" ");
    }
  
    else{    /* it will print plus (+) by this else code*/
    
         printf("+");
	 }
 } 

else if(coefficents[i] < 0){ /* this will print just blank to avoid sign replications if the value(coefficient) is negative */
  printf(" "); 
} 

else{  /* if the value(coefficient) equals zero it will skip rest of the loop and wont print anything. */
continue;
} 

if(pow != 0){ /* with this if statement, we are gonna print coefficients and pows. */

        if((coefficents[i] - (int)coefficents[i])==0 ){ /* this will check if its 1.0, 2.0 etc. type of double. i mean a.b and b = 0 kind of inputs.*/
        
                 if(coefficents[i]==1){ /* this will check if the coefficient is one, if it is one, it'll go here and wont print the coefficient which is 1*/
              
                     printf("x^%d ",(pow));
                 }
			    else{  /* if the coefficient isnt one, it will go here */
			    
                     printf("%.dx^%d ",(int)coefficents[i],(pow)); 
                     
                 }
        }
		else{  /*if its not that kind of input it will go here */
		
        printf("%.1fx^%d ",coefficents[i],(pow));
        }

}
else{  /* if the pow is 0 , that means we are printing our constant value, so we dont need to print pow */

        if((coefficents[i] - (int)coefficents[i])==0){ /* this will check if its 1.0, 2.0 etc. type of double. i mean a.b and b = 0 kind of inputs.*/
        	
          printf("%.d ",(int)coefficents[i]);
        }
        else{ /*if its not that kind of input it will go here */
        
            printf("%.1f ",coefficents[i]);
        }
   }
 }
 printf("\n");
}
