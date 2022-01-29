#include <stdio.h>

void calculate_fibonacci_sequence();
void decide_perfect_harmonic_number();
void difference_max_min();
void bmi_calculation();

void calculate_fibonacci_sequence(){
	printf("\t\tFIBONACCI PROGRAM \n");
while(1){ /* program will repeat until the return value which can only happen by passing to second part, when user inputs * */

 int num_one, num_two , num_last ,i; /* num one and num two are the first 2 values of fibonacci sequence, i is for loop */
  
  num_one = 1; /* first value of fibonacci sequence */
  num_two = 1; /* second value of fibonacci sequence */
  
    int num; /* it will hold the input */
    char star; /* it will hold my star * value */


    printf("Please enter term(s) number : \n"); /* enter the number */
    
    while(1){ /* it will check if the value is valid, if its not it is gonna ask again and again */
    	
        scanf("%d", &num); /* taking the value */
    
         star = getchar(); /* if the user types * it will hold that */
    
          if(star == '*'){ /* it will go to part 2 if the user enters * (star) */
	
	       decide_perfect_harmonic_number(); /* second function i mean part 2 */
	       
	       return; /* it will end the program if the user enters * in the part 2 */
	       
           }
           
          else if(star != '\n'){ /* if the value of star isnt new line that means user entered some invalid values */
           	
           	printf("Please enter \"numeric\" term(s) number: \n"); 
		   }
	
	      else if(num <=0   ){ /* it will check if the user entered negative number or zero */
	    		
	     	printf("Please enter \"positive\" term(s) number: \n");
	    
	     	
	        }
	        
	      else if(num > 0 ){ /* if the value is positive it will end the loop, then will go to calculation part */
	        	
	        	break;
	        	
			} 
}
	   printf("\n");
	   
	      printf("Fibonacci Sequence: \n \n");
	   
	   
	        if(num == 1){ /*if the value is 1 it will print only the first value of fibonacci sequence */
	        	
	        	printf(" %d \n",num_one);
	        	
			}
			
			else if(num ==2){ /* if the value is 2 it will print first and second value of fibonacci sequence */
				
				printf(" %d \n %d \n",num_one,num_two);
				
			}
			
	        else{ /* it will print the fibonacci sequence for the given number */
	        	
	        	
	        	
	        	printf(" %d \n\n",num_one); /* it will print the first num */
           
                printf(" %d \n\n",num_two); /* it will print the second num */
				  
	   	        for(i=2; i< num ;i++){ 
			    
                   num_last = num_one + num_two;   /* it will assign the last 2 numbers addition to the last number */
                
                   printf(" %d \n\n",num_last);    /* it will print the last number */
                 
                   num_one = num_two;    /* first number will be second, and second number will be third and so on */
                
                   num_two = num_last;    /* first number will be second, and second number will be third and so on */
            
	 	         }
	        	
			}
	        
		
		
	} 
	
}

void decide_perfect_harmonic_number(){
	
	int sayi,perfect_sum = 0,i; /*sayi will be our number, perfect sum is for perfect number checking, i is for loop */
	
	double upper=0,bottom= 0; /* fractional number parts for harmonic check, a/b  a = upper b = bottom*/
	
	char star; /* it will hold the * and other invalid values if the user entered */
	
	double number_of_divisors =0; /* number of divisors */
	
	printf("\n \t\t HARMONIC AND PERFECT NUMBER CHECKING...\n");
	
	while(1){ /* it will continue until the user enter * i mean star */
		
	  printf("Please enter input number : ");
	  
	  scanf("%d",&sayi);
	  star = getchar();
	  
	  if(star == '*'){ /* if the user enters * it will end the function */
	  	return;
	  }
	  
	  else if(star != '\n'){ /* if the user enters difference then enter key and star it will give an error */
	  	printf("Please enter a number...\n");
	  }
	  
	  else if(sayi <= 0){ /* it will check if the number positive or not */
	 	
	 	printf("Please enter a positive number...\n");
	 	
	 } else{ /* if the number is positive and user didnt input star it will start to calculate */
	 	
	 	printf("Natural Number Divisors: ");
	 	
	   	for(i = 1;i <sayi;i++){ /* it will go until i variable became our value which is sayi*/
	   		
	   		if(sayi%i == 0){ /* it will check if the i is the divisor of our number */
	   		
	   			upper += (sayi / i); /* the sum of numerators.. i found this method to find the sum of numerators for multiple floating number */
	   			
	   			perfect_sum +=i; /* it will add the divisors into the perfect_sum for the perfect sum checking */
	   			
	   			printf("%d ",i); /* it will print the divisors */
	   			
	   			number_of_divisors++;
	   			
			   }
	   		
	   		
		   }
		   
		   printf("%d ",sayi); /* it will print the last divisor which is itself */
		   
		   printf("\n");
		  
		   if(perfect_sum == sayi){ /*if the number is equals our perfect_sum value that means our number is perfect number */
		   	
		   printf("Is Perfect Number? : Yes \n");
		   
		   }else{ /* *if the number is not equals our perfect_sum value that means our number is not perfect number */
		   	
		   printf("Is Perfect Number? : No \n");
		   	
		   }
		   
		   number_of_divisors++; /* our number is also a divisor so i add it */
		   
		   upper++;
		   
		   bottom = sayi;
	
		 if( number_of_divisors * bottom / upper == (int)(number_of_divisors * bottom / upper)){
		   	
		   	/* it will check if our number is harmonic divisor number or not */
		   	
		   	printf("Is Harmonic Divisor Number? : Yes \n"); 
		   	
		   }else{
		   	
		   	printf("Is Harmonic Divisor Number? : No \n");
		   	
		   }
		   
		   
	       	 	
     } /* end of else part */
	 
	 upper = 0, bottom = 0; /* we will reset the nominator and denominator because we are gonna use it again with other numbers*/
	 
	 number_of_divisors = 0; /* we will reset the value of number of divisors because we are gonna use it again with other numbers */
	 
	 perfect_sum = 0; /* we will reset the value of perfect_sum because we are gonna use it again with other numbers */
	 
	  printf("\n");
	  
	} /* end of while loop */
	
} /* end of function */

void difference_max_min(){
	
	double number_one, number_two, number_three,number_four,number_five; /* number which user gonna enter */
	
	double max,min; /* these variables will hold max and min numbers */
	
	
	printf("\n \t \t DIFFERENCE MAX AND MIN PROGRAM... \n");
	
	printf("Please enter the first number...\n"); /* asking user the first number */
	
    scanf("%lf",&number_one); 
     
    printf("Please enter the second number...\n");  /* asking user the second number */
	
    scanf("%lf",&number_two);

	printf("Please enter the third number...\n");  /* asking user the third number */
	
    scanf("%lf",&number_three);

	printf("Please enter the fourth number...\n");  /* asking user the fourth number */
	
    scanf("%lf",&number_four);

	printf("Please enter the fifth number...\n");  /* asking user the fifth number */
	
    scanf("%lf",&number_five);

   
	max = number_one; /* we will assign the first number to the max value */
	
	if(number_two > max){ /* if the second value is bigger than the max, then our new max value will be number two*/
		
	  max = number_two;   
		  	
	}
	if(number_three > max){ /* if the third value is bigger than the max, then our new max value will be number three*/
		
		max = number_three;
		
	}if(number_four > max){ /* if the fourth value is bigger than the max, then our new max value will be number four*/
		
		max = number_four;
		
	}if(number_five > max){ /* if the fifth value is bigger than the max, then our new max value will be number five*/
		
		max = number_five;
		
	}
	
	min = number_one; /* we will assign the first number to the min value */
	
	if(number_two < min){ /* if the second value is smaller than the min, then our new min value will be number two*/
		
	  min = number_two;   
		  	
	}
	if(number_three < min){ /* if the third value is smaller than the min, then our new min value will be number three*/
		
		min = number_three;
		
	}if(number_four < min){ /* if the fourth value is smaller than the max, then our new min value will be number four*/
		
		min = number_four;
		
	}if(number_five < min){ /* if the fifth value is smaller than the max, then our new min value will be number five*/
		
		min = number_five;
		
	}
	

	printf("Maximum number is: %f \n",max);
	printf("Minimum number is: %f \n",min);
	printf("Difference between maximum and minimum is %.4f ",max - min); /* it will return the difference */
	
}

void bmi_calculation(){
	
	double weight,height,bmi; /* they will hold users weight heýght and bmi */
	
	printf("\n \t \t BMI CALCULATION \n");
	
	printf("What is your weight?..\n");
	
	scanf("%lf",&weight);
	
	printf("What is your height?..\n");
	
	scanf("%lf",&height);
	
	if(height > 3){ /* if the height is written like 173 or 178 i mean in centimeter format, it will convert it to meter format for formula */
		height = height / 100.0;
	}
	/* i wrote height > 3 because world longest human is 2 meter 51 centimeter who is Sultan Kösen :))) */
	
	bmi = weight / (height * height); /* calculating the bmi */
	
	if(bmi < 16){ /* if the bmi is under 16 it will go here */
		printf("Your Category: Severely Underweight...\n");
	}
	
	else if(bmi <= 18.49){ /* if the bmi is under 18.49 it will go here */
		printf("Your Category: Underweight...\n");
	}
	
	else if(bmi <= 24.99){ /* if the bmi is under 24.99 it will go here */
		printf("Your Category: Normal...\n");
	}
	
	else if(bmi <= 29.99){ /* if the bmi is under 29.99 it will go here */
		printf("Your Category: Owerweight...\n");
	}
	
	else{   /* if the bigger and equals to 30 it will go here */
		printf("Your Category: Obese...\n");
	}
	
	
}

int main() {
  
  	calculate_fibonacci_sequence();
	
    difference_max_min();
	
   	bmi_calculation();

	
	return 0;
}



