/* 
First Homework
*/

#include <stdio.h>
#include <math.h>

void standart_calculator(){
	
	int num_type,calc_type;
	int first_num, second_num;
	int real_first, imag_first;
	int real_second, imag_second;
	int real_result , imag_result;
	
	printf("Enter the number type \n"); 
	
	printf("1. Integer \n");
	printf("2. Complex \n");
	
	scanf("%d",&num_type); /* We choose what kind of numbers we are gonna deal with */
	
	printf("\n Please enter the calculation type \n");
	printf("1. Addition \n");
	printf("2. Multiplication \n");
	
	scanf("%d",&calc_type); /* We choose the calculation type */ 
	
	if(num_type == 1){ /*Ýf we are gonna deal with integers it will go here */
		
	     if(calc_type == 1){ /* Ýf we are gonna do addition it will go here  */
	   	    printf("Please enter the first number \n");
	   	    scanf("%d",&first_num);
	   	
	   	    printf("Please enter the second number \n");
	   	    scanf("%d",&second_num);
	   	
	   	    printf("Addition of the numbers  = %d", first_num+second_num);
	   	
	       }
	   
	      else if(calc_type == 2 ){ /* Multiplication */
	   	
	   	    printf("Please enter the first number \n");
	   	    scanf("%d",&first_num);
	     	
	     	printf("Please enter the second number \n");
	   	    scanf("%d",&second_num);
	    	
			printf("Multiplication of the numbers  = %d", first_num * second_num); /* Result */
			
	        }
	   
	      else{ /*WARNÝNG  */
	   	
	   	    printf("You should have entered 1 or 2, nothing else...\n");
	     	return ;
	   	
	       }
		
	}
	
	else if(num_type == 2){ /* if we are gonna deal with complex numbers, it will go here */
		
		
		  if(calc_type == 1){  /* Addition */
		  	
		   printf("Please enter the first complex number (real part first) \n");
		   
		   scanf("%d %d",&real_first, &imag_first);
		   
		   printf("Please enter the second complex number (real part first) \n");
		   
		   scanf("%d %d",&real_second, &imag_second);
		   
		   printf("Addition of the numbers = %d %+di",(real_first + real_second),(imag_first+imag_second)); /* Result */
	      }
	   
	   
	      else if(calc_type == 2 ){ /* Multiplication */
	      	
	      	printf("Please enter the first complex number (real part first) \n");
		   
		   scanf("%d %d",&real_first, &imag_first);
		   
		   printf("Please enter the second complex number (real part first) \n");
		   
		   scanf("%d %d",&real_second, &imag_second);
		   
		   real_result = real_first * real_second  - ( imag_first * imag_second);
	   	   imag_result = real_first * imag_second + imag_first * real_second;
	   	   
	   	   printf("Multiplication of the numbers = %d %+di \n",real_result,imag_result); /* Result */
		   
	   	
	     }
	   
	      else{ /* WAARNÝNG */
	      	
	   	  printf("You should have entered 1 or 2, nothing else...\n");
	   	  return ;
	      }
		
		
	}
	else{ /* WARNÝNG */
		printf("You should enter 1 or 2... \n");
		return ;
	}
}

void area_perimeter_calculator(){
	
	int shape_type;
	double first_side,second_side, third_side;
	double s,area,perimeter,radius;
	printf("Enter the shape type...\n"); 
	
	printf("1. Rectangle \n");
	printf("2. Triangle \n");
	printf("3. Circle \n");
	
	scanf("%d",&shape_type); /* we choose which geometric shape we are gonna deal with */
	
	if(shape_type==1){
		
	 printf("please enter the short side of rectangle...\n");
	 scanf("%lf",&first_side);
	 
	 printf("please enter the long side of rectangle...\n");
	 scanf("%lf",&second_side);
	 
	 area = first_side * second_side; /* Calculating the are  of rectangle */
	 printf("Area of recantgle = %f",area);
	 
	 perimeter = 2*(first_side + second_side); /* Calculating the perimeter */
	 printf("perimeter of rectangle = %f",perimeter);
	 
	}
	
	else if(shape_type == 2){ /*Ýf triangle  */
	   printf("please enter the sides of triangle...\n");
	   
	   scanf("%lf",&first_side);
	   
	   scanf("%lf",&second_side);
	  
	   scanf("%lf",&third_side);
	   
	   s = (first_side + second_side + third_side) / 2; /* We need s to use heron formula */
	   
	   area = sqrt(s*(s-first_side)*(s-second_side)*(s-third_side));  /*Calculating the are of triangle using heron formula  */
	   
	   printf("Area of triangle = %f \n",area);
	   
	   perimeter = first_side + second_side + third_side; /* calculating the perimeter */
	   
	   printf("\n Perimeter of triangle = %f ",perimeter);
	}
	
	else if(shape_type == 3){ /* Ýf circle */
		printf("please enter the radius of the circle...\n");
		scanf("%lf",&radius);
	   	
	    area = 3.14 * radius * radius; /* area of circle */
	    printf("Area of the circle = %f \n", area); 
	    
	    perimeter = 2*3.14*radius; /* perimeter of circle */
	    printf("Perimeter of the circle = %f ",perimeter); 
	}
	
	else{
		printf("You should have entered 1,2 or 3...");
		return;
	}
}

void temperature_calculator(){
	int temp_type;
	double temp;
	double result_temp;
	
	printf("Enter the calculation type...\n"); 
	printf("1. Fahrenheit to Kelvin...\n");
	printf("2. Kelvin to Fahrenheit...\n");
	
	scanf("%d",&temp_type); /* We choose the type of conversion */
	
	if(temp_type == 1){ /* Fahrenheit to kelvin */
		
		printf("Please enter the temperature in Fahrenheit...\n");
		scanf("%lf",&temp);
		
		result_temp =  ((5.0 / 9.0) * (temp - 32)) + 273.15; /* fahrenheit to kelvin formula */
   	    printf("Result = %.5f ",result_temp);
	}
	
	else if(temp_type == 2){ /* kelvin to fahrenheit */
		
		printf("Please enter the temperature in Kelvin...\n");
		scanf("%lf",&temp);
		
		result_temp =  (9.0 / 5.0) * ( temp - 273.15)  + 32; /* kelvin to fahrenheit formula */
		printf("Result = %f ",result_temp);
	}
	
	else{
	  printf("you should have entered 1 or 2...\n");
	  return;
	}
	
}

int multi_calculator(){
	
	int calctype;
	
	printf("Enter the calculator type: \n");
	printf("1. Standart Calculator \n");
	printf("2. Area&Perimeter Calculator \n");
	printf("3. Temperature Calculator \n");
    
    
    printf("Please enter a num : ");
	scanf("%d",&calctype); /* We choose which calculator we are gonna use in here */
	
	while(calctype > 3 || calctype < 1){
		
	printf("WARNING ! Please enter {1,2,3} only: ");
	scanf("%d",&calctype);
	
	}
	
	if(calctype == 1){ /* Standart calculator */
		
	 standart_calculator();
	 
     }
     
    else if(calctype == 2){ /* Area perimeter calculator */
    	
	area_perimeter_calculator();
	
    }
    
	else if(calctype == 3) { /* Temperature calculator */
		
	temperature_calculator();
	
	}
	
}

int main() {
	
	multi_calculator();
	
	return 0;
}
