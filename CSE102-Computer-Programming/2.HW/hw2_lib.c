/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/

#include <stdio.h>
#include <math.h> /* i used acos and sqrt func from this library */
#include "hw2_lib.h"

void print_left(unsigned int num);
void print_middle(double sayi);
void triangle_exists(double a,double b,double c);

int find_weekday_of_data(int day, int month, int year)
{
	/* i used zeller's rule to find the day of the date */
	int thatday; /* this will be my result */
	
	int twoyear; /* i will use it in the formula */
	
	int threeyear; /* i will use it in the formula */
	
	if(year < 0 ){ /* checking whether year is negative or positive */
	
		printf("Year cant be negative... \n");
		
		return 0;
	}
	
	if(month < 1 || month > 12 ){ /* checking if the month number is logical or not */
		
		printf("Month number should be in [1,12] interval... \n");
		
		return 0;
		
	}
	
	switch(month){ /* to be able to use the algorithm, we are gonna change some months number */
	 
	case 1: /* January will be 13 */
	
	year--; /*if our month is january, we will decrease our year to use algorithm */
	
	month = 13; 
	
	     if(day < 1 || day > 31 ){ /* checking if the number of day is in the interval or not */
	 	
	       printf("For January, the number of day can be between 1-31, NOT ANYTHİNG ELSE... \n");
	  
	       return 0;
	  
	     }
	 
  	 break;
	
	case 2:  /* February will be 14 */
	
	   if(year % 4 == 0) { /*it will check if february 28, or 27. if we divide the year to 4, and we got remainder that means february is 28 in that year */
	   
		     if(year % 100 == 0 && year % 400 != 0) { /* if its a year whose remainder is 0 when divided to 100 but not 400, that year February is 28 */
	    	        if(day < 1 || day > 28 ){ /* checking if the number of day is in the interval or not */
	 	
	                 printf("For February, the number of day can be between 1-28, NOT ANYTHİNG ELSE... \n");
	  
	                 return 0;
	                  }
	       }else{
	                 if(day < 1 || day > 29 ){ /* checking if the number of day is in the interval or not */
	 	
	                  printf("For February, the number of day can be between 1-29, NOT ANYTHİNG ELSE... \n");
	  
	                  return 0;
	                   }
	   
	           }
	   }else{ /*it will check if february 28, or 27. Ýf it divide the year to 4 and we got remainder that means february is 27 in that year */
		
	  	    if(day < 1 || day > 28 ){ /* checking if the number of day is in the interval or not */
	 	
	          printf("For February, the number of day can be between 1-28, NOTT ANYTHİNG ELSE... \n");
	  
	        return 0;
	  
	    }
		
   	  }
   	  
   	  year--; /*if our month is february, we will decrease our year to use algorithm */
	  month = 14; /* we do this to use the algorithm */
	
	 
	   break;
	
	case 3:  /* March will be 3 */
	
	
	     if(day < 1 || day > 31 ){ /* checking if the number of day is in the interval or not */
	 	
	      printf("For March, the number of day can be between 1-31, NOT ANYTHÝNG ELSE... \n");
	  
	      return 0;
	   
	     }
	break;
	
	case 4:  /* April will be 4 */
	
	
	    if(day < 1 || day > 30 ){ /* checking if the number of day is in the interval or not */
	 	
	      printf("For April, the number of day can be between 1-30, NOT ANYTHÝNG ELSE... \n");
	  
	  return 0;
	  
	 }
	 
	break;
	
	case 5:  /* May will be 5 */
	
	
	    if(day < 1 || day > 31 ){ /* checking if the number of day is in the interval or not */
	 	
	    printf("For May, the number of day can be between 1-31, NOT ANYTHÝNG ELSE... \n");
	  
	    return 0;
	  
	 }
	 
	break;
	
	case 6:  /* June will be 6 */
	
	
	    if(day < 1 || day > 30 ){ /* checking if the number of day is in the interval or not */
	 	
	     printf("For June, the number of day can be between 1-30, NOT ANYTHÝNG ELSE... \n");
	  
	    return 0;
	  
	 }
	 
	break;
	
	case 7:  /* July will be 7 */
	
	
     	if(day < 1 || day > 31 ){ /* checking if the number of day is in the interval or not */
	 	
	    printf("For July, the number of day can be between 1-31, NOT ANYTHÝNG ELSE... \n");
	  
	    return 0;
	  
	 }
	 
	break;
	
	case 8:  /* August will be 8 */
	
	
	     if(day < 1 || day > 31 ){ /* checking if the number of day is in the interval or not */
	 	
	     printf("For August, the number of day can be between 1-31, NOT ANYTHÝNG ELSE... \n");
	  
	    return 0;
	  
	 }
	 
	break;
	
	case 9:  /* September will be 9 */
	
	
     	if(day < 1 || day > 30 ){ /* checking if the number of day is in the interval or not */
	 	
	    printf("For September, the number of day can be between 1-30, NOT ANYTHÝNG ELSE... \n");
	  
	   return 0;
	  
	 }
	 
	break;
	
	case 10:  /* October will be 10 */
	
	
	   if(day < 1 || day > 31 ){ /* checking if the number of day is in the interval or not */
	 	
	     printf("For October, the number of day can be between 1-31, NOT ANYTHÝNG ELSE... \n");
	  
	   return 0;
	  
	  }
	 
	break; 
	
	case 11:  /* November will be 11 */
	
	
	   if(day < 1 || day > 30 ){ /* checking if the number of day is in the interval or not */
	 	
	    printf("For November, the number of day can be between 1-30, NOT ANYTHÝNG ELSE... \n");
	  
	   return 0;
	  
	  }
	 
	break;
	
	case 12:  /* December will be 12 */
	
	
    	if(day < 1 || day > 31 ){ /* checking if the number of day is in the interval or not */
	   	
	    printf("For December, the number of day can be between 1-31, NOT ANYTHÝNG ELSE... \n");
	  
	    return 0;
	  
	 }
	 
	break;
}



twoyear = year % 100; /* i will need it to use my formula */


threeyear = year / 100; /* i will need it to use my formula */



thatday = day + 13 * (month + 1) / 5 + twoyear + twoyear / 4 + threeyear / 4 + 5 * threeyear; /* zellers rule usage */

thatday = thatday % 7; /* we are gonna take the mode of the result */



if(thatday == 0){ /* if our remainder equals 0 that means that day is  saturday*/

  thatday = 6;
}
else if(thatday == 1){ /* if our remainder equals 1 that means that day is  sunday*/

  thatday = 7;
}

else if(thatday == 2){ /* if our remainder equals 2 that means that day is  monday*/

  thatday = 1;
}

else if(thatday == 3){ /* if our remainder equals 3 that means that day is  tuesday*/

  thatday = 2;
}
else if(thatday == 4){ /* if our remainder equals 4 that means that day is  wednesday*/

  thatday = 3;
}

else if(thatday == 5){ /* if our remainder equals 5 that means that day is  thursday*/

  thatday = 4;
}
else if(thatday == 6){ /* if our remainder equals 6 that means that day is  friday*/

  thatday = 5;
}



    return thatday; /* we will return the number of day */

    
}


int count_day_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)
{
	/* i will be using an formula to find the number of days:
	
	number of days  = day_of_date + 1461* ( x ) / 4 + 367 * ( y ) / 12 - 3* ( z ) / 4;
	
	x = year + 4800 + ( month - 14 ) / 12;
    y =  month - 2 - ( month - 14 ) / 12 * 12 ;
    z = ( year + 4900 + ( month - 14 ) / 12 ) / 100;
    
    i will be using gregorian calendar in this algorithm 
    */
    
    int firstdate,seconddate; /* number of days for the dates are gonna be assign to these variables */
    
    int x_of_first,y_of_first,z_of_first; /* the variables i will be using for the first date */
    
    int x_of_second,y_of_second,z_of_second; /* the variables i will be using for the second date */
    
    /* firstdate is the number of days for the first date */
    /* seconddate is the number of days for the second date */
    
    
    x_of_first= start_year + 4800 + ( start_month - 14 ) / 12; /* finding the x  of the formula for the first date*/
    y_of_first =  start_month - 2 - ( start_month - 14 ) / 12 * 12 ;  /* finding the y  of the formula for the first date*/
    z_of_first = ( start_year + 4900 + ( start_month - 14 ) / 12 ) / 100; /* finding the z of the formula for the first date*/
    
    x_of_second = end_year + 4800 + ( end_month - 14 ) / 12; /* finding the x of the formula for the second date*/
    y_of_second = end_month - 2 - ( end_month - 14 ) / 12 * 12 ; /* finding the y of the formula for the second date*/
    z_of_second = ( end_year + 4900 + ( end_month - 14 ) / 12 ) / 100; /* finding the z of the formula for the second date*/
    
    firstdate = start_day  + 1461*(x_of_first) / 4 + 367*(y_of_first) / 12 - 3*(z_of_first) / 4; /* calculating the number of days for the first date */
    seconddate = end_day  + 1461*(x_of_second) / 4 + 367*(y_of_second) / 12 - 3*(z_of_second) / 4; /* calculating the number of days for the second date */
    
	if(firstdate < seconddate){ /* if seconddate is bigger than firstdate */
		
		return seconddate - firstdate; 	/*return the difference */
	}
	
	else if(firstdate > seconddate){ /* if seconddate is bigger than firstdate */
		
		return firstdate - seconddate; /* return the difference */
	}
	
    else{ /* if they are equal */
    	
    	return 0; /* return 0 */
	}
	
}



double find_angle(double a, double b, double c)
{
	
 double cosa, resultangle,dside,dtemp,etemp,eside;
 
  /* dtemp is temporary variable, i will use it to find the one of the median, i will call that median as a dside */
  /* etemp is temporary variable, i will use it to find the other median, i will call that median as a eside */
   
   triangle_exists(a,b,c); /* it will check if the triangle exists or not */
   
   cosa = ((b*b+c*c-a*a)/(2*b*c)); /* i found the angle, in front of the a side */
   
   c = c/2; /* i need the half of the c side for the cos theorem usage */
    
   dtemp = b*b + c*c -2*b*c*cosa;  /* dside equals = d * d */
   
   dside = sqrt(dtemp); /* i found the first median which is dside, by cos theorem */
   
   b = b /2; /* i need the half of the b side for the cos theorem usage */
   
   c = 2*c; /* i need the whole c side */
   
   etemp = c*c + b*b -2*b*c*cosa; /* eside equals = etemp * etemp */
   
   eside = sqrt(etemp);  /* i found the other median which is eside, by cos theorem */
   
   dside = (2*dside) / 3; /* i will only take the 2/3 part of the median */
   
   eside = (2*eside) / 3; /* i will only take the 2/3 part of the median */
 
   
   resultangle = (eside*eside + dside*dside -a*a)/(2*eside*dside); /* i will find the cos value of that angle */
  
   resultangle = acos(resultangle); /* i will find the angle with the help of arccosinus function which is acos */
  
   return resultangle; 
}


void print_tabulated(unsigned int r11, double r12, int r13, 
                     unsigned int r21, double r22, int r23, 
                     unsigned int r31, double r32, int r33, char border)
{
	
    int i; /* for loop */
   
   if(r11 < 0 || r11 >= 100000 ){ /* it will check the value of r11 */
   
   printf("Unsigned cant be negative or your input is more than 5 digits...\n");
   
   return;
   }
   
   if(r21 < 0 || r21 >= 100000){ /* it will check the value of r21 */
   
   printf("Unsigned cant be negative or your input is more than 5 digits...\n");
   
   return; 
   }
   
   if(r31 < 0 || r31 >= 100000 ){ /* it will check the value of r31 */
   
   printf("Unsigned cant be negative or your input is more than 5 digits...\n");
   
   return ;
   }
   
    if(r13 >= 100000 || r13 <= -100000){ /* it will check the value of r13 */
    
    printf("Unsigned cant be negative or your input is more than 5 digits...\n");
    
     return;
     }
   
   if(r23 >= 100000 || r23 <= -100000){ /* it will check the value of r23 */
   
   printf("Unsigned cant be negative or your input is more than 5 digits...\n");
   
   return;
   }
   
   if(r33 >= 100000 || r33 <= -100000){ /* it will check the value of r33 */
   
   printf("Unsigned cant be negative or your input is more than 5 digits...\n");
   
   return;
   }
   
   
	printf("┌"); /* left cornered character */
		
   
   
   for(i=0; i < 47;i++){  /*printing the  border */
   
   	printf("%c",border);
   	
   }
   
   printf("┐"); /* right cornered character */
   
   printf("\n");
   
   printf("|  Row 101     |  Row ABCDEFG   | Row XYZ123    | \n"); /* header */
   
 

   for(i=0; i < 49;i++){ /* printing the border */
   
   	printf("%c",border);
   	
   }
   
    printf("\n");
    
    print_left(r11); /* printing the number at the left side */
     
    print_middle(r12); /* printing the number in the middle */
    
    
    printf("|%-+6d         | \n",r13); /* printing the number at the right side */
    
     
   for(i=0; i < 49;i++){ /* printing the border */
   	
   	printf("%c",border);

   }
   
   printf("\n");
   
   print_left(r21); /* printing the number at the left side */
	
   print_middle(r22); /* printing the number in the middle */
    
    
    printf("|%-+6d         | \n",r23); /* printing the number at the right side */
   
     
    for(i=0; i < 49;i++){ /* printing the border */
    	
   	printf("%c",border);
   	
   }
   
    printf("\n");
      
    print_left(r31); /* printing the number at the left side */

    print_middle(r32); /* printing the number in the middle */
    
    printf("|%-+6d         | \n",r33); /* printing the number at the right side */
    
    printf("└"); /* cornered character */
   
       for(i=0; i < 47;i++){ /* printing the border */
       	
     	printf("%c",border);
   	
       }
   
     printf("┘"); /* cornered character */
     
     printf("\n");
    
}
void triangle_exists(double a, double b, double c){
	
   if(b > c){
   	
   	   if(a <= b-c || a >= b + c ){ /* Sides condition for triangle, a < b+c and a > |b - c|*/
   
   	      printf("there is no triangle with that sides...\n");
   	       return;
      }
   	
   }
   
   else if(c > b){
   	
   	   if(a <= c - b || a >= b + c ){ /* Sides condition for triangle, a < b+c and a > |b - c|*/
   
        	printf("there is no triangle with that sides...\n");
   	        return;
      }

   }
   else{
   	   if(a <= 0 || a >= b + c ){ /* Sides condition for triangle, a < b+c and a > |b - c|*/
   
   	         printf("there is no triangle with that sides...\n");
   	         return;
         } 
   	
   }
	
    if(a > c){
   	
   	   if(b <= a-c || b >= a + c ){ /* Sides condition for triangle, a < b+c and a > |b - c|*/
   
   	      printf("there is no triangle with that sides...\n");
   	       return;
      }
   	
   }
   
   else if(c > a){
   	
   	   if(b <= c - a || b >= a + c ){ /* Sides condition for triangle, a < b+c and a > |b - c|*/
   
        	printf("there is no triangle with that sides...\n");
   	        return;
      }

   }
   else{
   	   if(b <= 0 || b >= a + c ){ /* Sides condition for triangle, a < b+c and a > |b - c|*/
   
   	         printf("there is no triangle with that sides...\n");
   	         return;
         } 
   	
   }
   
      if(a > b){
   	
   	   if(c <= a-b || c >= b + a ){ /* Sides condition for triangle, a < b+c and a > |b - c|*/
   
   	      printf("there is no triangle with that sides...\n");
   	       return;
      }
   	
   }
   
   else if(b > a){
   	
   	   if(c <= b - a || c >= b + a ){ /* Sides condition for triangle, a < b+c and a > |b - c|*/
   
        	printf("there is no triangle with that sides...\n");
   	        return;
      }

   }
   else{
   	   if(c <= 0 || c >= b + a ){ /* Sides condition for triangle, a < b+c and a > |b - c|*/
   
   	         printf("there is no triangle with that sides...\n");
   	         return;
         } 
   	
   }
   
   
}

void print_left(unsigned int num){
	
 if(num<10){ /* it will print the number at the left side */
    
    printf("|     %-5d    ",num); 
    
	}
	else if(num<100){ /* it will try to print it into the center , 100 < num < 10 */
	
	printf("|     %-5d    ",num);
	
	}
	else if(num<1000){/* it will try to print it into the center, 1000 < num < 100 */
	
	printf("|    %-5d     ",num);	
	
	}
	else if(num<10000){/* it will try to print it into the center, 10000 < num < 1000 */
	
	printf("|    %-5d     ",num);	
	
	}
    else if(num<100000){/* it will try to print it into the center, 100000 < num < 10000 */
    
    printf("|   %-5d      ",num);	
    
	}

  
}

void print_middle(double sayi){

 if(sayi > 0 && sayi < 10){ /*if number is between 0 and 10 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f               ",sayi);
            
        }else{ 
        
         printf("|%.1f             ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f            ",sayi);
   
   }
   }
   
   if(sayi < 0 && sayi > -10){ /*if number is between 0 and -10 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f              ",sayi);
            
        }else{ 
        
         printf("|%.1f            ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f           ",sayi);
   
   }
   }
   
    if(sayi >= 10 && sayi < 100){ /*if number is between 0 and 100 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f              ",sayi);
            
        }else{ 
        
         printf("|%.1f            ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f           ",sayi);
   
   }
   }
   
   if(sayi <= -10 && sayi > -100){ /*if number is between -10 and -100 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f             ",sayi);
            
        }else{ 
        
         printf("|%.1f           ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f          ",sayi);
   
   }
   }
   
    if(sayi >= 100 && sayi < 1000){ /*if number is between 100 and 10000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f             ",sayi);
            
        }else{ 
        
         printf("|%.1f           ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f          ",sayi);
   
   }
   }
    
   if(sayi <= -100 && sayi > -1000){ /*if number is between -100 and -1000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f            ",sayi);
            
        }else{ 
        
         printf("|%.1f          ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f         ",sayi);
   
   }
   }
  
    if(sayi >= 1000 && sayi < 10000){ /*if number is between 1000 and 10000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f            ",sayi);
            
        }else{ 
        
         printf("|%.1f          ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f         ",sayi);
   
   }
   }
   
   if(sayi <= -1000 && sayi > -10000){ /*if number is between -1000 and -10000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f           ",sayi);
             
        }else{ 
        
         printf("|%.1f         ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f        ",sayi);
   
   }
   }
    
   if(sayi >= 10000 && sayi < 100000){ /*if number is between 10000 and 100000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f           ",sayi);
            
        }else{ 
        
         printf("|%.1f         ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f        ",sayi);
   
   }
   }
   
   if(sayi <= -10000 && sayi > -100000){ /*if number is between -10000 and -100000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f          ",sayi);
            
        }else{ 
        
         printf("|%.1f        ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f       ",sayi);
   
   }
   }
   
   if(sayi >= 100000 && sayi < 1000000){ /*if number is between 100000 and 1000000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f          ",sayi);
            
        }else{ 
        
         printf("|%.1f        ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f       ",sayi);
   
   }
   }
   
   if(sayi <= -100000 && sayi > -1000000){ /*if number is between -100000 and -10000000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f         ",sayi);
            
        }else{ 
        
         printf("|%.1f       ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f      ",sayi);
   
   }
   }
   
      if(sayi >= 1000000 && sayi < 10000000){ /*if number is between 1000000 and 10000000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f         ",sayi);
            
        }else{ 
        
         printf("|%.1f       ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f      ",sayi);
   
   }
   }
   
   if(sayi <= -1000000 && sayi > -10000000){ /*if number is between -1000000 and -10000000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f        ",sayi);
            
        }else{ 
        
         printf("|%.1f      ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f     ",sayi);
   
   }
   }
   
    if(sayi >= 10000000 && sayi < 100000000){ /*if number is between 10000000 and 100000000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f        ",sayi);
            
        }else{ 
        
         printf("|%.1f      ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f     ",sayi);
   
   }
   }
   
   if(sayi <= -10000000 && sayi > -100000000){ /*if number is between -10000000 and -100000000 it will go here */
   
   if((int)(sayi*100) % 10 ==0 ){ /* it will check if the second decimal number of floating point point is zero or not*/
   
        if((int)(sayi*10) % 10 ==0){ /* it will check if the number has leading zeros in the floating point of it */
        
            printf("|%.0f       ",sayi);
            
        }else{ 
        
         printf("|%.1f     ",sayi);
         
         }
     
   }else{
   	
   printf("|%.2f    ",sayi);
   
   }
   }
   
   
   
   
   
   }


