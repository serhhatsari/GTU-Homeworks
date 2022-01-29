#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank{
	
	char Name[30];
	int Age;
	int Label;	
	
}bnk[50];

void add_customer(struct bank *banking,int customer_number); 
void process_customer(struct bank *banking,int customer_number,int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]);
void order_customer(struct bank *banking,int customer_number,int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]);
void print_current_sequence(struct bank *banking,int customer_number,int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]);
void fill_array(int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]);
void order_struct(struct bank *banking,int customer_number,int input_num,int row,int column ,int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]);


int main() {

	int zero[12][5]; /* it will hold the number of employees */
	int one[17][3];  /* it will hold the number of retireds */
	int two[17][3];  /* it will hold the number of students */
	int three[25][2]; /* it will hold the number of unemployeds */
	int four[25][2];  /* it will hold the number of others */
    
	int input,customer_number = 0,j; /* input will hold the numb user entered */
	struct bank *banking; 
	banking = bnk; /* assigning structure array to pointer struct */

	fill_array(zero,one,two,three,four); /* it will fill the array with -5's */
	
	while(1){ 
		
	printf("***********Banking System*********** \n\n");
  
    printf("1-Add customer \n");
    printf("2-Process customer \n");	
    printf("3-Exit the program \n \n");
    printf("Please enter your input = ");
	scanf("%d",&input); 
	printf("\n");

	if(input == 1){ /* if user wants to add customer itll go here */
		
		if(customer_number == 50){ /* it will give error if we entered more than 50 customers */
			
			printf("Banking system keeps maximum 50 customer in same time. Please process customer... \n \n");
			continue;
			
		}
		
  	add_customer(banking,customer_number); /* this function will assign the customers info to the structure */
    
    order_customer(banking,customer_number,zero,one,two,three,four); /* this funct will order customer and structs */
    
    printf("Current Sequence: ");

    print_current_sequence(banking,customer_number,zero,one,two,three,four); /* printing the current sequence */
	

	customer_number++;

	}


	else if(input == 2){ /* if user wants to process costumer itll go here */
	
        	if(customer_number == 0){ /* if there is not any customer it will give error */
        		
		       printf("There is not any customer in bank system sequence. \n \n");
		       
	           printf("Current sequence : \n");
	           
		       continue;
         	}
	printf("Proceed customer is %s \n",bnk[0].Name);

	process_customer(banking,customer_number,zero,one,two,three,four);/* it will process the first customer */

	printf("Current Sequence: ");
  	
  	print_current_sequence(banking,customer_number,zero,one,two,three,four); /* it will print the current sequence */
  	
	customer_number--;	
    	
	}

    else if(input == 3){ /* if user enters 3 it will end the program */
	printf("Thank u for using my program. Have a nice day sir :) \n ");
		return 0;
	}
	
	else{ /* if user enter wrong input it will give error and ask again */
		
		printf("PLEASE ENTER 1 OR 2 \n \n");
	    continue;
	}	
		
		
	} /* End of the while */
	
	return 0;
}

void add_customer(struct bank *banking, int customer_number){
	
	char name[30]; /* it will hold the name */
	int age; /* it will hold the age */
	int label; /* it will hold the label */
	
	printf("Please enter the name of the customer: ");
	scanf("%s",name); /* taking the name */
	
	printf("Please enter the age of the customer: ");
	scanf("%d",&age); /* taking the age */
	
	while(age < 1 || age > 160){ /* i put 160 because longest human ever lived has lived 160 years who is Zaro Aga :)) */
	
	printf("\n There is no human with that age \n");
	printf("Please enter the age of the customer: ");
	scanf("%d",&age); /* taking the age */
	
    }
    
   	printf("Please enter the label of the customer: ");
	scanf("%d",&label); /*taking the label */
    
    while(label < 0 || label > 4){ /* conditions */
    printf("\n Label can be 0,1,2,3,4 \n"); 
	printf("Please enter the label of the customer: ");
	scanf("%d",&label); /* taking the label */
	
    }
	
	strcpy(banking[customer_number].Name,name); /* assigning to struct */
	banking[customer_number].Age = age; /* assigning to struct */
	banking[customer_number].Label = label; /* assigning to struct */

	printf("\n");
}

void process_customer(struct bank *banking,int customer_number,int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]){
	
	int i,k,number;
	number = banking[0].Label;
	
	for(i =0 ;i < 49;i++){ /* it will process the first customer, i mean it will delete the first struct. */
		banking[i] = banking[i+1]; 
	}

	if(number==0){ /* it will delete the first customers label in the zero array  if its zero  */
      for(k = 0; k < 12; k++){
        
        if(zero[k][0] != -5){

           for(i = 0;i <4;i++){
            zero[k][i] = zero[k][i+1];       
           }
           zero[k][4] = -5;
           return;
         }    
	   }
      }
	else if(number ==1){ /* it will delete the first customers label in the one array  if its one  */
        for(k = 0; k < 17; k++){
        
           if(one[k][0] != -5){

              for(i = 0;i <2;i++){
              one[k][i] = one[k][i+1];
           }
           one[k][2] = -5;
           return;
         }
      } 
	}
	else if(number==2){ /* it will delete the first customers label in the two array  if its two  */
      for(k = 0; k < 17; k++){
        
        if(two[k][0] != -5){
          for(i = 0 ; i < 2; i++){
          	two[k][i] = two[k][i+1];
          }	
           two[k][2] = -5;
           return;
         }
      }
	}
	else if(number ==3){ /* it will delete the first customers label in the three array  if its three  */
      for(k = 0; k < 25; k++){
        
        if(three[k][0] != -5){
           three[k][0] = three[k][1];
           three[k][1] = -5;
           return;
         }    
      } 
	}
	else if(number == 4){ /* it will delete the first customers label in the four array  if its four  */
      for(k = 0; k < 25; k++){
        if(four[k][0] != -5){
           four[k][0] = four[k][1];
           four[k][1] = -5;
           return;
         }
      } 
	}
}

void print_current_sequence(struct bank *banking,int customer_number,int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]){

	  int i=0,j;
	    for(i = 0; i < 25; i++){ /* it will print the numbers in array */

	         if(i < 12){       
	           for(j = 0; j < 5; j++){ 		/* it will print the numbers in zero array */
	             if(zero[i][j] != -5){
	                 printf("%d ",zero[i][j]);
		             }
		           }
		        }
                if(i < 17){ 
		          
		           for(j = 0; j < 3; j++){ /* it will print the numbers in one array */
		             if(one[i][j] != -5){
		                 printf("%d ",one[i][j]);
		             }
		           }
		         }
		         if(i<17){
		           for(j = 0; j < 3; j++){ /* it will print the numbers in two array */
		             if(two[i][j] != -5){
		                 printf("%d ",two[i][j]);
		             }
		          }
                }

		           for(j = 0; j < 2; j++){ /* it will print the numbers in three array */
		             if(three[i][j] != -5){
		                 printf("%d ",three[i][j]);
		             }
		           }
		           for(j = 0; j < 2; j++){ /* it will print the numbers in four array */
		             if(four[i][j] != -5){
		                 printf("%d ",four[i][j]);
		             }
		           }
		     }
		   printf("\n \n");
		 }
		
void fill_array(int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]){

		int i,j;

	  	for(i = 0; i < 12; i++){ /* fill the array with -5's */
	       for(j = 0; j < 5; j++){
	        zero[i][j] = -5;
	           }
		}
			for(i = 0; i < 17; i++){   /* fill the array with -5's */      
	           for(j = 0; j < 3; j++){
	             one[i][j] = -5;
	           }
		}
			for(i = 0; i < 17; i++){   /* fill the array with -5's */   
	           for(j = 0; j < 3; j++){
	             two[i][j] = -5;
	           }
		}
			for(i = 0; i < 25; i++){    /* fill the array with -5's */  
	           for(j = 0; j < 2; j++){
	             three[i][j] = -5;
	           }
		}
			for(i = 0; i < 25; i++){  /* fill the array with -5's */    
	           for(j = 0; j < 5; j++){
	             four[i][j] = -5;
	           }
		}
}
void order_customer(struct bank *banking,int customer_number,int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]){

	int i,j;    	 
	if(banking[customer_number].Label == 0){ /* if the label of new coming customer is zero it will go here */
 	for(i = 0; i < 12; i++){    /*it will check the customer with label zero */      
           for(j = 0; j < 5; j++){
             if(zero[i][j] == -5){
                 zero[i][j] = 0;
                 order_struct(banking,customer_number,0,i,j,zero,one,two,three,four); /* it will order the struct then return */
                 return;
             }
           }
	}      
    }	
	else if(banking[customer_number].Label == 1){   /* if the label of new coming customer is one it will go here */    
      	for(i = 0; i < 17; i++){  /*it will check the customer with label one */      
           
           for(j = 0; j < 3; j++){

             if(one[i][j] == -5){
                one[i][j] = 1;
                order_struct(banking,customer_number,1,i,j,zero,one,two,three,four); /* it will order the struct then return */
                 return;
             }
           }
	  }		
	}  
	else if(banking[customer_number].Label == 2){   /* if the label of new coming customer is two it will go here */
		 for(i = 0; i < 17; i++){  /*it will check the customer with label two */      
           
           for(j = 0; j < 3; j++){

             if(two[i][j] == -5){                 
                 two[i][j] = 2;
                 order_struct(banking,customer_number,2,i,j,zero,one,two,three,four); /* it will order the struct then return */
                 return;
             }
           }
	  }
	}  
	
	else if(banking[customer_number].Label == 3){  /* if the label of new coming customer is three it will go here */
		for(i = 0; i < 25; i++){  /*it will check the customer with label three */      
           
           for(j = 0; j < 2; j++){

             if(three[i][j] == -5){                 
                 three[i][j] = 3;
                 order_struct(banking,customer_number,3,i,j,zero,one,two,three,four); /* it will order the struct then return */
                 return;
             }
           }
	   }				
	}  
	
	else if(banking[customer_number].Label == 4){  /* if the label of new coming customer is four it will go here */

	  	for(i = 0; i < 25; i++){            /*it will check the customer with label four */      
           for(j = 0; j < 2; j++){
             if(four[i][j] == -5){                 
                 four[i][j] = 4;
                 order_struct(banking,customer_number,4,i,j,zero,one,two,three,four); /* it will order the struct then return */
                 return;
             }
           }
	  }		
	}   
 	
  }

void order_struct(struct bank *banking,int customer_number,int input_num,int row,int column ,int zero[][5],int one[][3], int two[][3], int three[][2], int four[][2]){

	int counter = -1,out =0; 
	int i,j;  
	char temp_name[30]; /* it will hold the first name */
	int temp_age,temp_label; /* they will hold the first value of age and lable */

	if(input_num == 0){ /* if the new customers label is zero it will go here and order the struct */
	         for(i = 0; i < 25; i++){  /*it will check the customer with label zero */      

	         if(i < 12){	               
	           for(j = 0; j < 5; j++){
	             if(zero[i][j] != -5){	  
	        
	                 counter++;	    
	                 if(i == row && j == column){
	          
	                    out = 1;
	                   break;
	                 }
	             }
	           }
	           if(out == 1){
	           	break;
	           }
	        }
	        if(i < 17){	           /*it will check the customer with label one */      
	           for(j = 0; j < 3; j++){	         
	             if(one[i][j] != -5){	                 
	                 counter++;	                
	             }
	           }
	         }
	         if(i < 17){  /*it will check the customer with label two */      
	           for(j = 0; j < 3; j++){
	             if(two[i][j] != -5){	                 
	                counter++;
	             }
	           }
	          }

	           for(j = 0; j < 2; j++){  /*it will check the customer with label three */      
	             if(three[i][j] != -5){
	                 counter++;
	             }
	           }	           
	           for(j = 0; j < 2; j++){  /*it will check the customer with label four */      
	             if(four[i][j] != -5){	  
        
	                 counter++;
	  
	             }
	           } 
	     }
	}

	if(input_num == 1){  /* if the new customers label is one it will go here and order the struct */
	         for(i = 0; i < 25; i++){  /*it will check the customer with label zero */      
	         if(i < 12){
	           for(j = 0; j < 5; j++){
	             if(zero[i][j] != -5){
	                 counter++;
	             }
	           }
	        }
	        if(i < 17){  /*it will check the customer with label one */      
	           for(j = 0; j < 3; j++){
	             if(one[i][j] != -5){
	             	
	                 counter++;
	               
	                 if(i == row && j == column){	 
	     
	                   out = 1;
	                   break;
	                 }
	             }
	           }
	           	   if(out == 1){
	             	break;
	             }
	         } 
	         if(i < 17){  /*it will check the customer with label two */      
	           for(j = 0; j < 3; j++){

	             if(two[i][j] != -5){
	                 
	                counter++;
	             }
	           }

	        }
	           for(j = 0; j < 2; j++){  /*it will check the customer with label three */      
	             if(three[i][j] != -5){	                 
	                 counter++;
	             }
	           }	           
	           for(j = 0; j < 2; j++){  /*it will check the customer with label four */      
	             if(four[i][j] != -5){
	                counter++;
	             }
	           } 	   
	     }
	}
	if(input_num == 2){  /* if the new customers label is two it will go here and order the struct */
	         for(i = 0; i < 25; i++){  /*it will check the customer with label zero */      
	         if(i < 12){	               
	           for(j = 0; j < 5; j++){	           		
	             if(zero[i][j] != -5){	                 
	                 counter++;
	             }	    	           
	           }		    
	        }
	        if(i < 17){	    /*it will check the customer with label one */      
	           for(j = 0; j < 3; j++){	         
	             if(one[i][j] != -5){	                 
	                 counter++;
	             }	           
	           }		
	         }
	         if(i < 17){	 /*it will check the customer with label two */      	 		            
	           for(j = 0; j < 3; j++){
	             if(two[i][j] != -5){	                 
	                counter++;
	                if(i == row && j == column){	
	                                
	                   out = 1;
	                   break;	                   
	                 }
	             }
	            }
	            	if(out == 1){
	             	break;
	             }
	           }			           
	           for(j = 0; j < 2; j++){  /*it will check the customer with label three */      
	             if(three[i][j] != -5){	                 
	                 counter++;
	             }
	           }			           
	           for(j = 0; j < 2; j++){  /*it will check the customer with label four */      
	             if(four[i][j] != -5){	                 
	                 counter++;
	             }
	          } 
	     }
	}
	if(input_num == 3){  /* if the new customers label is three it will go here and order the struct */
	         for(i = 0; i < 25; i++){  /*it will check the customer with label zero */      
	         if(i < 12){	               
	           for(j = 0; j < 5; j++){	           		
	             if(zero[i][j] != -5){	                 
	                 counter++;
	             }	    	           
	           }		    
	        }
	        if(i < 17){	  /*it will check the customer with label one */               
	           for(j = 0; j < 3; j++){	         
	             if(one[i][j] != -5){	                 
	                 counter++;
	             }	            
	           }		
	         }
	         if( i < 17){	 /*it will check the customer with label two */                 
	           for(j = 0; j < 3; j++){
	             if(two[i][j] != -5){	                 
	                counter++;
	             }
	           }
	           }	           
	           for(j = 0; j < 2; j++){  /*it will check the customer with label three */      
	             if(three[i][j] != -5){	                 
	                 counter++;
	                  if(i == row && j == column){	   
	                                  
	                   out = 1;
	                   break;	                   
	                 }
	             }

	           }

	           	    if(out == 1){
	             	break;
	                 }	           
	           for(j = 0; j < 2; j++){  /*it will check the customer with label four */      
	             if(four[i][j] != -5){	                 
	                 counter++;
	             }
	           } 
	     }
	}
	if(input_num == 4){  /* if the new customers label is four it will go here and order the struct */
	         for(i = 0; i < 25; i++){  /*it will check the customer with label zero */      
	         if(i < 12){	               
	           for(j = 0; j < 5; j++){	           		
	             if(zero[i][j] != -5){	                 
	                 counter++;
	             }	           
	           }		  
	        }
	        if(i < 17){	     /*it will check the customer with label one */            
	           for(j = 0; j < 3; j++){	         
	             if(one[i][j] != -5){	                 
	                 counter++;
	             }	           
	           }		
	         }
	         if( i <  17){	 /*it will check the customer with label two */      	 		           
	           for(j = 0; j < 3; j++){
	             if(two[i][j] != -5){	                 
	                counter++;
	             }
	           }
	           }			           
	           for(j = 0; j < 2; j++){  /*it will check the customer with label three */      
	             if(three[i][j] != -5){	                 
	                 counter++;
	             }
	           }			           
	           for(j = 0; j < 2; j++){  /*it will check the customer with label four */      
	             if(four[i][j] != -5){
	             	counter++;
	                 if(i == row && j == column){	       

	                   out = 1;
	                   break;	                   
	                 }	                 
	             }

	           }
	           	             if(out == 1){
	             	break;
	             } 	   
	     }
	}

	strcpy(temp_name,banking[customer_number].Name);
	temp_age = banking[customer_number].Age;
	temp_label = banking[customer_number].Label;

	for(i = customer_number; i > counter; i--){ /* it will order the structs */
	   
	   banking[i] = banking[i-1];

	}

	strcpy(banking[counter].Name, temp_name);
	banking[counter].Age = temp_age;
	banking[counter].Label = temp_label;

}

