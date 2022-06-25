#include <stdio.h>
#include <math.h>

void part_one(); /* first function */ 
void part_two(); /* second function */
void part_three(); /* third function */

void armstrong(int numb); /* this function will check if the numb is armstrong number or not */
void palindrom(int if_arm, int numb); /* this function will check if the number is palindrom or not */

void print_coef(float coef,int degree,int pow); /* it will print the coefficient in the first function */


int main() { /* my main function */

    part_one();
    part_two();
    part_three();
	
	return 0;
}



void part_one(){
	
    float coef; /* coef will hold my coefficients */
    
    int degree,pow; /* degree will hold the degree of polynomial and pow will hold the pow of the x variable */
    
    printf("\t\t\t PRETTY POLYNOMIAL \n");
    
    printf("Enter the degree of your polynomial:[n a_n a_n-1 a_n-2 ... a_0]:"); /* taking the degree */
    
	scanf("%d",&degree);
    
    printf("p(x) = ");
    
    for (pow = degree; pow >= 0 ; pow--) /* it will print the coefficients */
     {  
     scanf("%f", &coef); /* taking the coefficients */    
        
      print_coef(coef,degree,pow); /* printing the coefficient in a pretty format */ 
        
      } /* end of for loop */ 
     
	  printf("\n");

}


void part_two(){
	int num;
	
	printf("\n \t \t \t ARMSTRONG AND PALINDROME CHECKER \n");
	printf("Please enter an integer number: "); /* asking the num */
	scanf("%d",&num);
	
	while(num < 0){ /*checking if num is positive or not */
		
	printf("Please enter an non negative number: ");
	scanf("%d",&num);

    }
    
	armstrong(num); /* sending num to armstrong functioýn */
	
}


void part_three(){
	
	int i,sum = 0,num_one,num_two; /* i is for loop, nums are gonna represent my numbers */
	int first_int,second_int; /* it will hold my first values */
	
	printf("\n\n \t\t\t SUM OF PRIME NUMBERS FUNCTION\n");
	
	printf("Please enter first integer number : ");
	scanf("%d",&num_one); /* taking the first value */
	printf("Please enter second integer number : ");
	scanf("%d",&num_two); /* taking the second value */
	
	while(num_one < 0 || num_two < 0){ /* if one of the numbers is negative it will go here */
		
		if(num_one < 0 && num_two<0){
				printf("Please enter first POSITIVE integer number : ");
	            scanf("%d",&num_one); /* taking the first value */
	            printf("Please enter second POSITIVE integer number : ");
	            scanf("%d",&num_two); /* taking the second value */
		}
		else if(num_one < 0){
			
			printf("Please enter first POSITIVE integer number : ");
	        scanf("%d",&num_one); /* taking the first value */
				
		}
		else if(num_two < 0 ){
				printf("Please enter second POSITIVE integer number : ");
	            scanf("%d",&num_two); /* taking the second value */
			
		}
		

	
	}
	
	
	first_int = num_one; /* we need the first value of num one so we assign it to first int */
	second_int = num_two; /* we need the first value of num two so we assign it to second int */
	
	if(num_one > num_two){ /* if the first value is bigger than second, it will go here */
		
		for(num_two++; num_two < num_one ;num_two++){ /* it will go until the first number */
			
			for(i = 2;i < num_two;i++){ /* it will check if the num two is prime number or not */
			 
				if(num_two % i == 0){ 
					
				  break;
				  
				}
				
				if(i == num_two - 1){ /* if the code came here that means that number is prime numb*/
					sum += num_two; /* it will sum the prime numbers */
				}
			}
			
		} 
		
		if(second_int < 2 && first_int > 2){ /* if the smaller number is smaller than 2 it will add 2 */
		 
		 sum = sum + 2; /* it will add 2 into the sum */
		 
		 printf("Sum of prime numbers between %d and %d is %d ",first_int,second_int,sum);
		
		 return;	
		}
		
		printf("Sum of prime numbers between %d and %d is %d ",first_int,second_int,sum);
	}
	
	else if(num_two > num_one){ /* if the second value is bigger than first, it will go here */
	
		for(num_one++; num_one < num_two ;num_one++){ /* it will go until num one equals num two */
			
			for(i = 2;i < num_one;i++){ /* it will check if the number is prime or not */
				
				if(num_one % i == 0){
					
				  break;
				  
				}
				
				if(i == num_one - 1){ /* if this is true , that means that number is prime */
					sum += num_one;
				}
			}
			
		}
		
		if(first_int < 2 && second_int > 2){ /* if the smallest number is smaller than 2 it will go here */
		 
		 sum += 2; /* it will add the first prime number which is 2 */
		 
		 printf("Sum of prime numbers between %d and %d is %d",first_int,second_int,sum);
		 return;	
		 
		}
		
		printf("Sum of prime numbers between %d and %d is %d",first_int,second_int,sum);
		
	}
	
	else{ /* if they are equal it will go here */
		
		printf("Sum of prime numbers between %d and %d is 0",num_one,num_two);
	}
}


void armstrong(int numb){
	
	
	int i,j; /* these are loop counters */
	int sum = 0, counter = 1; /* sum is the result of our pows and etc, counter is for loop */ 
   
   	for(i =10; i < numb ; i *=10 ){ /* it will go until i is bigger than our number */
   		
   		for(j = 1; j < 10;j++ ){ /* it will go until j is 10 */
   			
   			if(counter*j > (numb % i)){ /* it will find the all digits of the number except the left one*/
   				
   				sum += pow(j-1,3); /* it will take the cube of the digit and add it to sum variable */
   				break; 
   				
			   }
   			
		   }
   		
   		counter *=10; /* counter will be multiplied with 10 for the algorithm */
	   }
	  
	   if(i > numb ){ /* when i is bigger than numb, it will go in for loop last time */
	   	
	   	for(j = 1; j < 10;j++ ){ /* it will go until j is 10 */
   			
   			if(counter*j > (numb % i)){ /* it will find the left digit of the number */
   				
   				sum += pow(j-1,3); /* it will take the cube of the digit and add it to sum variable */
   				
   				break;
   				
			   }
		   }
        i *=10;
	   }
	   
   
   if(sum == numb){ /* if number is armstrong number, it will send 1 to is_palindrom function */ 
   
   	palindrom(1,numb);
   	
   
   }else{ /* if number is not an armstrong number, it will send 2 to is_palindrom function */
   	
   	palindrom(2,numb);
   
   }
	
}


void palindrom(int if_arm, int numb){
	
	int last_digit,fake_num = 0,real_num,number; /*last digit is the last digit of the number */
	int length_of_number; /* it will hold the length of my number */
	int i,k; /* im gonna use these in for loop */
	
    number = numb; /* i need the first value of numb to calculate the length */
	real_num = numb; /* i need the first value of numb to check if its equal fake num or not */
	
	while (number != 0) { /* it will calculate the length of my number */
		
        number = number / 10;     
        
        length_of_number++; /* length of number increase */
        
    }
	
	k = pow(10,length_of_number-1); /* its for multiplication in loop */
	
	if(if_arm == 1){ /* it is the value came from armstrong funcion */
	
	  for(i = length_of_number ;i >= 1;  i--, k /= 10){ /* it will calculate the reverse number of our real mnumber */
	  	
	  	last_digit = numb % 10; /* it will find the last digit of my number */
	  	
	  	fake_num += last_digit * k; /* it will multiply the last digit with k and add it to fake num */
	  	
	  	numb = numb / 10; /* it will increase the length of my number to calculation */
	  	
	  	if(numb == 0){ /* if numb equals zero that means everything is done and we found the answer */
	  		break;
		  }
	  	
	  }
	
	if(fake_num == real_num){ /* if this is true, that means our number is also palindrome num */
		
		printf("This number is both Palindrome and Armstrong number.");
		
	}else{
		
		printf("This number is only Armstrong number.");
		
  }
}
	else if(if_arm == 2){ /* it is the value came from armstrong func */
	
		  for(i = length_of_number ;i >= 1;  i--, k /= 10){ /* it will calculate the reverse number of our real mnumber */
	  	
	  	last_digit = numb % 10; /* it will find the last digit of my number */
	  	
	  	fake_num += last_digit * k; /* it will multiply the last digit with k and add it to fake num */
	  	
	  	numb = numb / 10; /* it will increase the length of my number to calculation */
	  	
	  	if(numb == 0){ /* if numb equals zero that means everything is done and we found the answer */
	  		break;
	  		
		  }
	  	
	  }
	
	if(fake_num == real_num){ /* if this is true, that means our number is only palindrome number */
		
		printf("This number is only Palindrome");
		
	}else{
		
		printf("This number does not satisfy any special cases");
		
	  }
	}
	printf("\n");
	
}


void print_coef(float coef,int degree, int pow){
	        
	         if(degree == 0){ /* it will check if the degree is zero or not */
	         	if((int)coef == coef){ /* it will check if number is integer or float */
	         		printf(" %.0f ",coef);
	         		return;
				 }
	         	printf(" %.1f ",coef);
	         	return;
			 }
	
	        if(coef < 0.051 && coef > -0.051 && coef != 0){ /* it will check if number is between 0.051 and -0.051 */
	        	
	          return;
	        	
			}
			
		    if(coef <= 0.099 && coef >= -0.099 && coef != 0){ /* it will check if number is at this range */
	        	
	        	if(coef > 0 ){ /* it will check if the num is positive */
	        		if(pow == 1){ /* it will check if the pow is 1 or not */
	        			if(degree == 1){ /* it will check if the degree is 1 or not */
	        				printf(" 0.1x ");
	        				return;
						}
						printf(" +0.1x ");
						return;
					}
					else if(pow == 0){ /* it will check if the pow is zero or not */
						if(degree == 0){
							printf(" 0.1 ");
							return;
						}
						printf(" +0.1x ");
						return;
					}
					else{ /* if none of them true it will go here */
						if(pow == degree){ /* it will check if pow equals degree */
							printf(" 0.1x^%d ",pow);
							return;
						}
						printf(" +0.1x^%d ",pow);
						return;
					}
	        		
	        		 
				}else{ /* if numb is negative it will go here */
				        		if(pow == 1){ /* if pow is 1 it will go here */
	        			if(degree == 1){ /* if degree is one it will go here */
	        				printf(" -0.1x ");
	        				return;
						}
						printf(" -0.1x ");
						return;
					}
					else if(pow == 0){ /* if pow is zero it will go here */
						if(degree == 0){
							printf(" -0.1 ");
							return;
						}
						printf(" -0.1x ");
						return;
					}
					else{ /* if none of them true it will go here */
						if(pow == degree){ /* if pow equals degree it will go here */
							printf(" -0.1x^%d ",pow);
							return;
						}
						printf(" -0.1x^%d ",pow);
						return;
					}
	        		
					}
	    
					
				}
				
	        if(pow == 1 && degree == 1){ /* it will check if the pow is 1 and degree is one at the same time */
                   
                   if(coef > 0){ /* if coef is positive it will go here */
				   
		    	  	if(((int)(coef * 10)) % 10 == 0 ){ /* it will check the first digit */
    	  		
    	  		         if(((int)(coef*100)) % 10 <= 5 ){ /* it will check the second digit */
    	  		         	
    	  		         	if((int)coef == 1){ 
    	  				
    	  				printf(" x ");
    	  				return;
					  
					  }
    	  		         	
    	  		    	printf("%dx ",(int)coef);
    	  		        return;
				  
				       } else{
				  	
				  	printf("%d.1x ",(int)coef);
				  	return;
				  	
				  }
			 
	     	   }else{
	     	   	
	     	   	 if(((int)(coef*100)) % 10 <= 5 ){ /* it will check the second digit */
	     	   	 	
	     	   	 			if((((int)(coef*100) % 10) == 5) && ((int)(coef*100) -(coef *100) == 0 ) ){ 
			  	   	 		
			  	   	 		coef -= 0.01;
			  	   	 	    printf(" %+.1fx ",coef);
    	  		            return;
							  }
    	  		         	
    	  		    	printf("%+.1fx ",coef);
    	  		        return;
				  
				       } else{
				       	
				  	coef += 0.05;
				  	if(((int)(coef * 10)) % 10 == 0 ){
				  		printf("  %+.0fx  ",coef);
				  		return;
					  }
				  	printf("%+.1fx ",coef);
				  	return;
				  	
				  }	     	   	
	     	   	
				}
			}
			else if(coef < 0){ /* if coef is negative it will gho here */
				if(((int)(coef * 10)) % 10 == 0 ){
    	  		
    	  		         if(((int)(coef*100)) % 10 >= -5 ){
    	  		         if((int)coef == -1){
    	  				
    	  				printf(" -x ");
    	  				return;
					  
					  }	
    	  		         	
    	  		    	printf("%+dx ",(int)coef);
    	  		        return;
				  
				       } else{
				  	
				  	printf("%+d.1x ",(int)coef);
				  	return;
				  	
				  }
			 
	     	   }else{
	     	   	
	     	   	 if(((int)(coef*100)) % 10 >= -5 ){ /* if the second digit is smaller than -5 it will go here */
    	  		         
						  	if((((int)(coef*100) % 10) == -5) && ((int)(coef*100) -(coef *100) == 0 ) ){
			  	   	 		
			  	   	 	    	 coef += 0.01;
			  	   	 	         printf(" %+.1fx ",coef);
    	  		               return;
							  }	
    	  		         	
    	  		    	printf("%+.1fx ",coef);
    	  		        return;
				  
				       } else{
				       	
				  	coef -= 0.05;
				  		if(((int)(coef * 10)) % 10 == 0 ){
				  		printf("  %+.0fx  ",coef);
				  		return;
					  }
				  	printf("%+.1fx ",coef);
				  	return;
				  	
				  }	     	   	
	     	   	
				}
				
				
			}
	    
		}
	   
	    	if(pow == degree){ /* it will check if its the biggest degree of the polynomial */ 
    		
    	  if(coef > 0){ /* it will check if the number is positive number */ 
    	    
    	    if(coef==1){ /* if the number equals 1 it wont print it */
    	    	
    	     printf("x^%d ",pow);
    	     return;
			}
    	  	
    	  	if( ((int)(coef * 10)) % 10 == 0 ){
    	  		
    	  		if((int)(((int)(coef*100)) % 10) <= 5 ){
    	  			
    	  			 	if((((int)(coef*100) % 10) == 5) && ((int)(coef*100) -(coef *100) != 0 ) ){
			  	   	 		
			  	   	    	coef += 0.01;
			  	   	 
					        printf(" %.1fx^%d ",coef,pow);
					    
    	  		            return;
					  } 
    	  			
    	  			if((int)coef == 1){
    	  				
    	  				printf(" x^%d ",pow);
    	  				return;
					  
					  }  
					  
    	  			printf("%dx^%d ",(int)coef,pow);
    	  			return;
    	  	
				  
				  }else{
	
				  	
				  	printf("%d.1x^%d ",(int)coef,pow);
				  	return;
				  	
				  }
    	  	
			  }else{
			  	
			  	   	 if(((int)(coef*100) % 10) <= 5 ){ /* if the second digit is bigger than 5 it will go here */
			  	   	 	
			  	   	 	if((((int)(coef*100) % 10) == 5) && ((int)(coef*100) -(coef *100) == 0 ) ){
			  	   	 		
			  	   	 	coef -= 0.01;
			  	   	 
					    printf(" %.1fx^%d ",coef,pow);
					    
    	  		            return;
							  }
    	  		    	printf(" %.1fx^%d ",coef,pow);
    	  		        return;
				  
				       } else{
				       	
				  	coef += 0.05;
				  	
				  	if(((int)(coef * 10)) % 10 == 0 ){
				  		printf(" %.0fx^%d  ",coef,pow);
				  		return;
					  }
				  
				  	printf(" %.1fx^%d ",coef,pow);
				  	return;
				  	
				  }	   
	
			  }
    	
		  } else if(coef < 0){
		  	
		if(coef==-1){ /* if the number equals 1 it wont print it */
    	    	
    	     printf("-x^%d ",pow);
    	     return;
			}
    	  	
    	  	if( ((int)(coef * 10)) % 10 == 0 ){
    	  		
    	  		if(((int)(coef*100)) % 10 >= -5 ){
    	  			
    	  			if((int)coef == -1){
    	  				
    	  				printf("-x^%d ",pow);
    	  				return;
					  
					  }
    	  			
    	  			printf("%+dx^%d ",(int)coef,pow);
    	  	        return;
				  
				  }else{
	
				  	
				  	printf("%+d.1x^%d ",(int)coef,pow);
				  	return;
				  	
				  }
    	  	
			  }else{
			  	
			  	   	 if(((int)(coef*100)) % 10 >= -5 ){ /* if the second digit is bigger than -5 it will go here */
			  	   	 	
			  	   	 		if((((int)(coef*100) % 10) == -5) && ((int)(coef*100) -(coef *100) == 0 ) ){
			  	   	 
			  	   	 		coef += 0.01;
			  	   	 	    printf(" %.1fx^%d ",coef,pow);
    	  		            return;
							  }
    	  		         	
    	  		    	printf(" %+.1fx^%d ",coef,pow);
    	  		        return;
				  
				       } else{
				       	
				  	coef -= 0.05;
				  		if(((int)(coef * 10)) % 10 == 0 ){ /* if the first digit equals zero it will go here */
				  		printf("  %+.0fx^%d  ",coef,pow);
				  		return;
					  }
				  	printf("%+.1fx^%d ",coef,pow);
				  	return;
				  	
				  }	   
	
			  }
    	
			
		  } else{
		  	
		  	if(pow!=0){
		  	printf("Leading number is zero! rest of the func = ");
		  	return;
		  	
		   }else{
		   	
		   	printf("0");
		   	return;
		   	
		   }
		  }
		  
		}		
		
            if(coef == 0){ /* if the number is zero it will not print it */        
		     return;
		     }
		 
	    	if(coef == 1){ /* if number equals 1 it wont print it */
    	    	
    	    if(pow == 1){ /* it will check if the pow is 1 or not */
              
	            	printf(" +x ");
                 	return;
                 	
		    }
		    
    	    if(pow == 0){ 
    	    
			printf("%+.0f",coef);
			return;	
    	    	
			}	
			
   	       printf("+x^%d ",pow); 
   	     
   	     return;
   	     
		}
		
	     	if(coef == -1){ /* it will check if the coef equals -1 */
			
	       if(pow == 1){ /* it will check if the pow is 1 or not */
        
	    	    printf(" -x "); 
               	return;
               	
		    }
		    
    	   if(pow == 0){ /* it will check if the pow equals zero */
    	    
			printf("%+.0f",coef);
			return;	
    	    	
			}	
			
   	       printf("-x^%d ",pow); 
   	       return;
			
		}
            
            if(pow == 1){ /* it will check if the pow is 1 or not */
                   
                   if(coef > 0){
				   
		    	  	if(((int)(coef * 10)) % 10 == 0 ){
    	  		
    	  		         if(((int)(coef*100)) % 10 <= 5 ){
    	  		         	
    	  		         	if((int)coef == 1){
    	  				
    	  				printf(" +x ");
    	  				return;
					  
					  }
    	  		         	
    	  		    	printf("%+dx ",(int)coef);
    	  		        return;
				  
				       } else{
				  	
				  	printf("%+d.1x ",(int)coef);
				  	return;
				  	
				  }
			 
	     	   }else{
	     	   	
	     	   	 if(((int)(coef*100)) % 10 <= 5 ){ /* if the second digit is smaller than 5 it will go here */
	     	   	 	
	     	   	 			if((((int)(coef*100) % 10) == 5) && ((int)(coef*100) -(coef *100) == 0 ) ){
			  	   	 		
			  	   	 		coef -= 0.01;
			  	   	 	    printf(" %+.1fx ",coef);
    	  		            return;
							  }
    	  		         	
    	  		    	printf("%+.1fx ",coef);
    	  		        return;
				  
				       } else{
				       	
				  	coef += 0.05;
				  	if(((int)(coef * 10)) % 10 == 0 ){
				  		printf("  %+.0fx  ",coef);
				  		return;
					  }
				  	printf("%+.1fx ",coef);
				  	return;
				  	
				  }	     	   	
	     	   	
				}
			}
			else if(coef < 0){
				if(((int)(coef * 10)) % 10 == 0 ){ /* it will check the first digit */
    	  		
    	  		         if(((int)(coef*100)) % 10 >= -5 ){
    	  		         if((int)coef == -1){
    	  				
    	  				printf(" -x ");
    	  				return;
					  
					  }	
    	  		         	
    	  		    	printf("%+dx ",(int)coef);
    	  		        return;
				  
				       } else{
				  	
				  	printf("%+d.1x ",(int)coef);
				  	return;
				  	
				  }
			 
	     	   }else{
	     	   	
	     	   	 if(((int)(coef*100)) % 10 >= -5 ){
    	  		         
						  	if((((int)(coef*100) % 10) == -5) && ((int)(coef*100) -(coef *100) == 0 ) ){
			  	   	 		
			  	   	 	    	 coef += 0.01;
			  	   	 	         printf(" %+.1fx ",coef);
    	  		               return;
							  }	
    	  		         	
    	  		    	printf("%+.1fx ",coef);
    	  		        return;
				  
				       } else{
				       	
				  	coef -= 0.05;
				  		if(((int)(coef * 10)) % 10 == 0 ){ /* it will check the first digit */
				  		printf("  %+.0fx  ",coef);
				  		return;
					  }
				  	printf("%+.1fx ",coef);
				  	return;
				  	
				  }	     	   	
	     	   	
				}
				
				
			}
	    
		}
		
	        if(pow == 0){ /* if the pow is zero it will go here and just print the coefficient without x variable */
	        
                               if(coef > 0){
				   
		    	  	if(((int)(coef * 10)) % 10 == 0 ){ /* it will check the first digit */ 
    	  		
    	  		         if(((int)(coef*100)) % 10 <= 5 ){
    	  		         	if((int)coef == 1){
    	  				
    	  				printf(" +1 ");
    	  				return;
					  
					  }
    	  		         	
    	  		    	printf("+%d ",(int)coef);
    	  		        return;
				  
				       } else{
				  	
				  	printf("%+d.1 ",(int)coef);
				  	return;
				  	
				  }
			 
	     	   }else{
	     	   	
	     	   	 if(((int)(coef*100)) % 10 <= 5 ){ /* it will check the first digit */
    	  		        	if((((int)(coef*100) % 10) == 5) && ((int)(coef*100) -(coef *100) == 0 ) ){
			  	   	 		
			  	   	 		coef -= 0.01;
			  	   	 	    printf(" %+.1f ",coef);
    	  		            return;
							  }
    	  		         	
    	  		    	printf("%+.1f ",coef);
    	  		        return;
				  
				       } else{
				       	
				  	coef += 0.05;
				  			if(((int)(coef * 10)) % 10 == 0 ){ /* it will check the first digit */
				  		printf("  %+.0f  ",coef);
				  		return;
					  }
				  	printf("%+.1f ",coef);
				  	return;
				  	
				  }	     	   	
	     	   	
				}
			}
			else if(coef < 0){
				if(((int)(coef * 10)) % 10 == 0 ){ /* if the first digit equals zero it wil lgo here */
    	  		
    	  		         if(((int)(coef*100)) % 10 >= -5 ){
    	  		         	
    	  		         if((int)coef == -1){
    	  				
    	  				printf(" -1 ");
    	  				return;
					  
					  }	
    	  		         	
    	  		    	printf("%+d ",(int)coef);
    	  		        return;
				  
				       } else{
				  	
				  	printf("%+d.1 ",(int)coef);
				  	return;
				  	
				  }
			 
	     	   }else{
	     	   	
	     	   	 if(((int)(coef*100)) % 10 >= -5 ){ /* if the second digit is bigger than -5 it will go here */
    	  		       		if((((int)(coef*100) % 10) == -5) && ((int)(coef*100) -(coef *100) == 0 ) ){
			  	   	 		
			  	   	 		coef += 0.01;
			  	   	 	    printf(" %+.1f ",coef);
    	  		            return;
							  }  	
    	  		         	
    	  		    	printf("%+.1f ",coef);
    	  		        return;
				  
				       } else{
				       	
				  	coef -= 0.05;
				  		if(((int)(coef * 10)) % 10 == 0 ){ /* it will check the first digit */
				  		printf("  %+.0f  ",coef);
				  		return;
					  }
				  	printf("%+.1f ",coef);
				  	return;
				  	
				  }	     	   	
	     	   	
				}
				
				
			}
		
        
		}
		
	    	if(coef > 0){  /* if coef is positive it will go here */
		
			if(((int)(coef * 10)) % 10 == 0 ){ /* it will check the first digit */
    	  		
    	  		         if(((int)(coef*100)) % 10 <= 5 ){
    	  		         	
    	  		        if((int)coef == 1){
    	  				
    	  				printf(" +x^%d ",pow);
    	  				return;
					  
					  } 	
                       printf("  %+dx^%d  ",(int)coef,pow);				  
				       return;
				       } else{
				  	  
						  
				  	  printf("  %+d.1x^%d  ",(int)coef,pow);
				  	  return;
				  	
				  }
			 
               
	     	   }else{
	     	   	
	     	   	 if(((int)(coef*100)) % 10 <= 5 ){ /* it will check the first digit */
	     	   	 	
    	  		     if((((int)(coef*100) % 10) == 5) && ((int)(coef*100) -(coef *100) == 0 ) ){
			  	   	 		
			  	   	 		coef -= 0.01;
			  	   	 		
			  	   	 	    printf(" %+.1fx^%d ",coef,pow);
			  	   	 	    
    	  		            return;
							} 	
    	  		         	
    	  		    	printf("  %+.1fx^%d  ",coef,pow);
    	  		        return;
				  
				       } else{
				       	
				  	coef += 0.05;
				  	
				     if(((int)(coef * 10)) % 10 == 0 ){ /* it will check the first digit */
				  		printf("  %+.0fx^%d  ",coef,pow);
				  		return;
					  }
					  
				  	printf("  %+.1fx^%d  ",coef,pow);
				  	return;
				  	
				  }	     	   	
	     	   	
	      }
	        }
	
	        else if(coef < 0){ /* if coef is negative it will go here */
	  				if(((int)(coef * 10)) % 10 == 0 ){ /* it will check the first digit */
    	  		
    	  		         if(((int)(coef*100)) % 10 >= -5 ){
    	  		         	
    	  		         if((int)coef == -1){
    	  				
    	  				printf(" -x^%d ",pow);
    	  				return;
					  
					  }	
    	  		         	
                       printf("  %+dx^%d  ",(int)coef,pow);				  
				       return;
				       } else{
				  	  
						  
				  	  printf("  %+d.1x^%d  ",(int)coef,pow);
				  	  return;
				  	
				  }
			 
               
	     	   }else{
	     	   	
	     	   	 if(((int)(coef*100)) % 10 >= -5 ){ /* it will check the first digit */
	     	   	 	
    	  		       	if((((int)(coef*100) % 10) == -5) && ((int)(coef*100) -(coef *100) == 0 ) ){
			  	   	 		
			  	   	 		coef += 0.01;
			  	   	 	    printf(" %.1fx^%d ",coef,pow);
    	  		            return;
							  }  	
    	  		         	
    	  		    	printf("  %+.1fx^%d  ",coef,pow);
    	  		        return;
				  
				       } else{
				       	
				  	coef -= 0.05;
				  	  	if(((int)(coef * 10)) % 10 == 0 ){
				  		printf("  %+.0fx^%d  ",coef,pow);
				  		return;
					  }
				  	
				  	printf("  %+.1fx^%d  ",coef,pow);
				  	return;
				  	
				  }	     	   	
	     	   	
	         }
	  	
	  	
	      }
		


	}



