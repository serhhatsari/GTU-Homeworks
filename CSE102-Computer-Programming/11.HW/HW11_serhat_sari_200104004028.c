#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie_Budget{
 
 int budget, year;
 char *name;
 struct Movie_Budget *next;

}Movie_Budget;

typedef struct Movie_Name{

 char *genre;
 char *name;
 double score;
 struct Movie_Name *next;

}Movie_Name;

void my_program(char *txt); /* main part of my program */
Movie_Name* insert_movie_name(Movie_Name *head, char *name, char *genre, double score ); /* inserting */
Movie_Budget* insert_movie_budget(Movie_Budget *head, char *name, int budget, int year);  /* inserting */

Movie_Budget *check_budget(Movie_Budget *head, char *name); /*  check for overwrite possibility */
Movie_Name *check_name(Movie_Name *head, char *name);  /* check for overwrite possibility */

char **create_genre(Movie_Name *head, int *genre_count, int **tnn_genre); /* creating 2d dynamic genre */

void part_one(Movie_Name *name, Movie_Budget *budget); /* first part of menu */

int main(){ 

  char *txt = "Movies.txt"; /*Name of the file*/
  my_program(txt);
 
  return 0; 
 } 


void my_program(char *txt){

FILE *fp = fopen(txt,"r"); /* We opened the file with r (only read mode) */

Movie_Budget *budget = NULL; /* budget struct */
Movie_Name *name	= NULL; /* name struct */

int *tnn_genre = NULL; 
int genre_count = 0;

char *t_line, *line = NULL;
char letter; /* it will hold the letter which i got from txt file */
int letter_count = 0, i ,k = 0,j = 0 , num_of_movies = 0, operation;

double average = 0,score_t; /* its for print section */
int fl = 0,kontrol = 0,fourth = 0,yearval = 0,log,valu; /* i need them in print section */
char movie_name[50]; /* its for print part */

char **genre = NULL; /* 2d dynamic genre array  */

printf("Wait a second sir. File is being read.. \n\n");

while(( letter = fgetc(fp)) != EOF){ /* it will read the file until end of the file */


  if(letter != '\n'){ /* it will read the file until it sees /n */
	  
	   letter_count++;
	   t_line = (char *)malloc(letter_count * sizeof(char)); /* we allocate a memory to the t_line */
	   
	   for(i = 0; i < letter_count -1 ; i++){ /* we assign the old values */
	   t_line[i] = line[i];
	   }
	   
	   t_line[letter_count-1] = letter; /* we assign the new value */
	   if(line != NULL) free(line); /* we freed the old values */
	   line = t_line;
	   
	   }

  else{ 

	  if(fl == 0){ /* it wont add the first line to the struct */
	       
	      fl = 1; /* to not go into this again */
	      letter_count = 0;
              continue;
		  
	    }
           
	  char ALL[5][200];
	  for(i = 0, k = 0, j = 0; i < letter_count; i++){ /* we separete the word with this loop */
	   
	   if(line[i] == '\0'){ /* checking the end of the string */
	   
	   ALL[k][j] = '\0'; 
	   break;
	   }
	   else if(line[i] == ','){ /* checking commas */
		   
		   ALL[k][j] = '\0';
		   k++;
		   j = 0;
		   continue;
	   }
	   
	   ALL[k][j] = line[i];
	   j++;
	   
	  }
  
    if(strcmp(ALL[0],"unknown") == 0){
		  
	    strcpy(ALL[0],"-1"); 
		   	  
	 }
    
   budget = check_budget(budget, ALL[2]); /* checking for overwrite possibility */

   budget = insert_movie_budget(budget, ALL[2],atoi(ALL[0]), atoi(ALL[4])); /* inserting new data */
   
   name = check_name(name, ALL[2]); /* checking for overwrite possilibtiy */

   name = insert_movie_name(name, ALL[2], ALL[1], atof(ALL[3])); /* inserting new data */
   
	 letter_count = 0; 

   }

 }

 genre = create_genre(name,&genre_count, &tnn_genre); /* creating 2d genre */

while(1){ /* PRİNT PART */
   
   printf("1. List of the Sorted Data. \n");
   printf("2. List of the Genres. \n");
   printf("3. List of the Movie Through the Years. \n");
   printf("4. List of the Movie Through the Scores. \n");
   printf("5. All Informations of a Single Movie. \n");
   printf("6. Average of the IMDB Scores. \n");
   printf("7. Frequence of the Genres. \n");
   printf("8. EXİT. \n");
   
   printf("Please Select an operation: ");
   scanf("%d",&operation);
   
  if(operation == 1){ /* Part one */

   part_one(name,budget);

   }
  else if(operation == 2){ /* List of the Genres */
    
     for(i = 0; i < genre_count; i++){ /* printing the genres */
   
        printf("%s \n",genre[i]);
     
     }

   }
  else if(operation == 3){ /* List of the Movie through years */

       while(1){ /* loop */

    Movie_Budget *temp_budget = budget;

    printf("Enter a year: "); /* taking the year */
    scanf("%d",&yearval);
    
    printf("Until(0) or Since(1): "); /* taking since or until */ 
    scanf("%d",&valu);

	 if(valu == 0){ /* if user choose until it will go here */

	    while(temp_budget!= NULL){ /* printing loop */
		 
		 if(yearval > temp_budget->year){ /* checking */
		 
		 printf("%s %d \n",temp_budget->name,temp_budget->year);
	         fourth = 1;
	        }
       
        temp_budget = temp_budget->next;   

	     }

	   }  

	   else if(valu == 1){ /* if user choose since it will go here */

	     while(temp_budget!=NULL){
		 
		 if(yearval < temp_budget->year){
		 
		 printf("%s \n",temp_budget->name);
		 
	         fourth = 1;
	
	        }
	     
        temp_budget = temp_budget->next;

	     }

	    }
	    else{
	    
	    printf("TRY AGAİN \n");
	    
            } 
            if(fourth == 1){
            fourth = 0;
            break;
            }
        }  	

   }
  else if(operation == 4){

    while(1){
     
    Movie_Name *temp_name = name;

    printf("Enter a score: "); /* taking values */
    scanf("%lf",&score_t);
    
    printf("Less(0) or greater(1) than score?: "); /* taking values */
    scanf("%d",&log);
    printf("\n");
    
	 if(log == 0){ /* if less */

	    while(temp_name != NULL){ /* null check */
		 
		 if(score_t > temp_name->score){ /* comparison */
		 
		  printf("%s \n",temp_name->name);
	    
	         fourth = 1;
	         
	        }

	     temp_name = temp_name->next;

	     }

	   }  

	   else if(log == 1){ /* if greater */

       
	    while(temp_name != NULL){ /* null check */
		 
		 if(score_t < temp_name->score){ /* comparison */
		 
		  printf("%s \n",temp_name->name);
	         
	         fourth = 1;
	        
	        }
           
         temp_name = temp_name->next;
           
	     }
	    
	    }
	    else{
	    
	    printf("Less or greater is invalid value. TRY AGAİN \n");
         }

       if(fourth == 1){
          
           fourth = 0;

            printf("\n");

            break;
          
            }
        

        }  


   }
  else if(operation == 5){
   
   while(1){
    int po = 0;
    Movie_Name *n_temp	= name;
    Movie_Budget *b_temp = budget;

    printf("Please enter the name of the movie: ");
    scanf("%s",movie_name); /* taking the name of the movie */
    printf("\n");

	   while(n_temp != NULL){
	    
	    if(strcmp(n_temp->name,movie_name) == 0){ /* comparison */
         
         printf("\n"); /* printing */
         printf("Genre: %s\n",n_temp->genre); /* printing */
         printf("Name %s\n",n_temp->name); /* printing */
         printf("Score %f ",n_temp->score); /* printing */
         po = 1;
         break;

	    }  
         
	   	n_temp = n_temp->next;
	   }

	   while(b_temp != NULL){
	    
	    if(strcmp(b_temp->name,movie_name) == 0){
         
         printf("\n");
         printf("Year: %d\n",b_temp->year); /* printing */
         printf("Budget: %d\n \n",b_temp->budget); /* printing */
         
         break;

	    }  
         
	   	b_temp = b_temp->next;
	   
	   }

	   if(po == 1){

	    break;
     
     }else{
     	printf("There is no movie with that name \n \n");
     }

   }

   } 
  else if(operation == 6){
 
	  Movie_Name *temp	= name;
	   
		    while(temp != NULL){ /* Average calculation */
			   
		       average += temp->score;
		       num_of_movies++;
		       temp = temp->next;

		   	}
		    
	      printf("\n\nAverage is %f \n \n",average / (num_of_movies));	   
	      average = 0;
	      num_of_movies = 0;

   }
  else if(operation == 7){ /* Frequence of genres */

		   for(i = 0; i < genre_count; i++){
		   
		     printf("%s ---> ",genre[i]);
		     printf("%d \n",tnn_genre[i]);
		   
		   }

   }
  else if(operation == 8){ /* Terminating */
	   printf("Terminating...\n");
	   return;
   }
  else{
   
    printf("TRY AGAIN \n");
  
   }
      
} 

return;

}


Movie_Name* insert_movie_name(Movie_Name *head, char *name, char *genre,  double score){

	Movie_Name *first,*second;
	Movie_Name *temp;

	if(head == NULL) /* İf list is empty it will go here */
	{

		temp = (Movie_Name*)malloc(sizeof(Movie_Name)); /* memory allocation */

		temp->score = score; /* assigning */
      
      temp->genre = (char *)malloc(sizeof(char) * strlen(genre) + 1 ); /* memory allocation */
      strcpy(temp->genre, genre); /* assigning */ 
      

      temp->name = (char *)malloc(sizeof(char) * strlen(name) + 1); /* memory allocation */
      strcpy(temp->name,name);		 /* assigning */
      

		temp->next = head;
	
		head = temp;	
	
	}

	else
   {

		first = head; 
		second = first->next;
		
		while(first != NULL && second != NULL){ /* null check */
			first = second;
			second = first->next;
		}

		temp = malloc(sizeof(Movie_Name)); /* memory allocation */

		temp->next = second; 
		first->next = temp;

		temp->score = score;
      
      temp->genre = (char *)malloc(sizeof(char) * strlen(genre) + 1 ); /* memory allocation */
      strcpy(temp->genre, genre);

      temp->name = (char *)malloc(sizeof(char) * strlen(name) + 1); /* memory allocation */
      strcpy(temp->name,name);	

	}


	return head;

 }


Movie_Budget* insert_movie_budget(Movie_Budget *head, char *name, int budget, int year){

	Movie_Budget *first,*second;
  Movie_Budget *temp;

		if(head == NULL) /* if list is empty it will go here */
	{

		temp = (Movie_Budget*)malloc(sizeof(Movie_Budget)); /* memory alloc */

		temp->budget = budget; /* assigning */
      
    temp->year = year; /* assigning */
      
      temp->name = (char *)malloc(sizeof(char) * strlen(name) + 1);  /* memory alloc */
      strcpy(temp->name,name);		 /* assigning */

		temp->next = NULL;
	
		head = temp;	
	
	} 

	else{

			first = head;
			second = first->next;

     if(first->year <= year){

 			temp = (Movie_Budget*)malloc(sizeof(Movie_Budget));  /* memory alloc */
		
			temp->budget = budget; /* assigning */
			temp->year = year;   /* assigning */

	    temp->name = (char *)malloc(sizeof(char) * strlen(name) + 1);  /* memory alloc */
	    strcpy(temp->name,name);	 /* assigning */
    
     temp->next = head;
     head = temp;

     return head;

     } 
     
			
			while(first != NULL && second != NULL && !(first->year > year && second->year <= year)  ){ /* checking year */

				first = second; 
				second = first->next;

			}
	    

			temp = (Movie_Budget*)malloc(sizeof(Movie_Budget));  /* memory alloc */
			
			temp->next = second;
			first->next = temp;

			temp->budget = budget; /* assigning */
			temp->year = year; /* assigning */

	      temp->name = (char *)malloc(sizeof(char) * strlen(name) + 1);  /* memory alloc */
	      strcpy(temp->name,name);	 /* assigning */
		}

		return head;

 }


Movie_Budget *check_budget(Movie_Budget *head, char *name){ /* removing node */

	Movie_Budget *first,*second;
	
	first = second = head; /* assigning */

	while(first != NULL && strcmp(first->name,name) != 0){ /* null check and name check */
		second = first;
		first = first->next;	
	}

	if(first != NULL){ /* null check */
	
		if(first == second) head = first->next;
		else second->next = first->next;	
		free(first);
	
	}
	
	return head;
 }


Movie_Name *check_name(Movie_Name *head, char *name){ /* removing node */

	Movie_Name *first,*second; 
	
	first = second = head; /* assigning */

	while(first != NULL && strcmp(first->name,name) != 0){ /* checking names and null check */
		second = first;
		first = first->next;	
	}


	if(first != NULL){ /* null check */

		if(first == second) head = first->next; 
		else second->next = first->next;	
		
		free(first);
	}

	return head;
 }


char **create_genre(Movie_Name *head, int *genree_count, int **tnn_genre){

	char **t_genre = NULL; /* MY GENRE ARRAY */
	char **genre_arr; /* İTS FOR OLD VALUES */
	int genre_count = 0;
  
  int *tn_genre = NULL;
	int *n_genre; /* İTS FOR THE NUMBER OF GENRES */
	int i;
  int fl = 0;

	 while(head != NULL){
	 
	 for(i = 0; i < genre_count; i++) { /* checking the genres */
	 
	   if(strcmp(head->genre,t_genre[i]) == 0){

	    tn_genre[i]++;
	    fl = 1;
      break;
	   }

	 }
  
  if(fl == 1){

   fl = 0; 
   head = head ->next;
   continue;
  }
  

	genre_count++;

	genre_arr = (char**)calloc(sizeof(char*), genre_count); /* genre allocation */

	n_genre = (int*)malloc(sizeof(int) * genre_count); /* genre number allocation */


	for(i = 0; i < genre_count - 1; i++){

	n_genre[i] = tn_genre[i];

	}


	n_genre[genre_count - 1] = 0;
	n_genre[genre_count -1]++;

	if(tn_genre != NULL) free(tn_genre);

	tn_genre = n_genre;


	 
	for(i = 0; i < genre_count -1;i++){ /* assigning old values */

	genre_arr[i] = t_genre[i];

	}

	genre_arr[genre_count -1] = (char*)malloc(sizeof(char) * strlen(head->genre) + 1); /* genre allocation */

	strcpy(genre_arr[genre_count-1],head->genre);

	if(t_genre != NULL) free(t_genre);

	t_genre = genre_arr;
	 
	head = head->next;
	  }
    
   *genree_count = genre_count; 
   
   *tnn_genre = tn_genre;

	  return t_genre;

 }


void part_one(Movie_Name *name, Movie_Budget *budget){

 while(1){ /* print part */

  int oper,select,val,flag = 0,start_val,end_val,i;
  int j, min,count = 0;
 
  Movie_Name *t_name = name;
  Movie_Budget *t_budget = budget;

  printf("1. Budget \n");
  printf("2. Genre \n");
  printf("3. Name \n");
  printf("4. Score \n");
  printf("5. Year \n\n");
  
  printf("Please select an operation: ");
  scanf("%d",&oper);
  
  if(oper == 1){ /* BUDGET */
  
     while(1){
     
	    printf("1. Single Selection\n");
	    printf("2. İ COULDNT DO THE MULTİPLE PART...\n\n");
	    printf("Please select an operation:");
	    scanf("%d",&select);

        struct Movie_Budget *current = budget, *index = NULL;  
        int temp;  
	  
	      if(select == 1){ /* SİNGLE SELECTİON */
	    
	       printf("Enter a value: ");
	       scanf("%d",&val); /* taking the input */
	       printf("%d. Movie\n\n",val);
          
         while(t_name != NULL){
         count++;  
          
          if(count == val){
                
                printf("%s  ",t_name->name);
                printf("%s  ",t_name->genre);
                printf("%f  ",t_name->score);

                	   while(t_budget != NULL){
	    
										    if(strcmp(t_budget->name,t_name->name) == 0){
									          
									         printf("%d  ",t_budget->year);
									         printf("%d\n \n",t_budget->budget);
									         return;
										    }  
									         
										   	t_budget = t_budget->next;
										   
										   } 		   

            }

            t_name = t_name->next; 
          
           }

	       }
	   
		   else if(select == 2){ 
          
          printf("I COULDNT DO THİS PART :( \n");
  
	       return;		  
           
		       }

		     else{
		  
		          printf("TRY AGAİN \n");
		  
	  	     }
		   
	    } 

    } 

  else if(oper == 2){ /* GENRE */
  
     while(1){
     
	    printf("1. Single Selection\n");
	    printf("2. İ COULDNT DO THE MULTİPLE PART...\n\n");
	    printf("Please select an operation:");
	    scanf("%d",&select);
	  
	      if(select == 1){ /* SİNGLE SELECTİON */
	    
	       printf("Enter a value: ");
	       scanf("%d",&val); /* taking the input */
	       printf("%d. Movie\n\n",val);
          
         while(t_name != NULL){
         count++;  
          
          if(count == val){
                
                printf("%s  ",t_name->name);
                printf("%s  ",t_name->genre);
                printf("%f  ",t_name->score);

                	   while(t_budget != NULL){
	    
										    if(strcmp(t_budget->name,t_name->name) == 0){
									          
									         printf("%d  ",t_budget->year);
									         printf("%d\n \n",t_budget->budget);
									         return;
										    }  
									         
										   	t_budget = t_budget->next;
										   
										   } 		   

            }

            t_name = t_name->next; 
          
           }

	       }
	   
	    else if(select == 2){ 
          
          printf("I COULDNT DO THİS PART :( \n");
  
	       return;		  
           
        
		       }

		     else{
		  
		          printf("TRY AGAİN \n");
		  
	  	     }
		   
	    } 

    }

  else  if(oper == 3){ /* NAME */
  
     while(1){
     
	    printf("1. Single Selection\n");
	    printf("2. İ COULDNT DO THE MULTİPLE PART...\n\n");
	    printf("Please select an operation:");
	    scanf("%d",&select);
	  
	      if(select == 1){ /* SİNGLE SELECTİON */
	    
	       printf("Enter a value: ");
	       scanf("%d",&val); /* taking the input */
	       printf("%d. Movie\n\n",val);
          
         while(t_name != NULL){
         count++;  
          
          if(count == val){
                
                printf("%s  ",t_name->name);
                printf("%s  ",t_name->genre);
                printf("%f  ",t_name->score);

                	   while(t_budget != NULL){
	    
										    if(strcmp(t_budget->name,t_name->name) == 0){
									          
									         printf("%d  ",t_budget->year);
									         printf("%d\n \n",t_budget->budget);
									         return;
										    }  
									         
										   	t_budget = t_budget->next;
										   
										   } 		   

            }

            t_name = t_name->next; 
          
           }

	       }
	   
		   else if(select == 2){ 
          
          printf("I COULDNT DO THİS PART :( \n");
  
	       return;		  
           
        
		       }

		     else{
		  
		          printf("TRY AGAİN \n");
		  
	  	     }
		   
	    } 

    }  

  else if(oper == 4){ /* SCORE */
  
     while(1){
     
	    printf("1. Single Selection\n");
	    printf("2. İ COULDNT DO THE MULTİPLE PART...\n\n");
	    printf("Please select an operation:");
	    scanf("%d",&select);
	  
	      if(select == 1){ /* SİNGLE SELECTİON */
	    
	       printf("Enter a value: ");
	       scanf("%d",&val); /* taking the input */
	       printf("%d. Movie\n\n",val);
          
         while(t_name != NULL){
         count++;  
          
          if(count == val){
                
                printf("%s  ",t_name->name);
                printf("%s  ",t_name->genre);
                printf("%f  ",t_name->score);

                	   while(t_budget != NULL){
	    
										    if(strcmp(t_budget->name,t_name->name) == 0){
									          
									         printf("%d  ",t_budget->year);
									         printf("%d\n \n",t_budget->budget);
									         return;
										    }  
									         
										   	t_budget = t_budget->next;
										   
										   } 		   

            }

            t_name = t_name->next; 
          
           }

	       }
	   
		   else if(select == 2){ 
          
          printf("I COULDNT DO THİS PART :( \n");
  
	       return;		  
           
        
		       }

		     else{
		  
		          printf("TRY AGAİN \n");
		  
	  	     }
		   
	    } 

    } 

  else if(oper == 5){ /* YEAR */
  
     while(1){
     
	    printf("1. Single Selection\n");
	    printf("2. İ COULDNT DO THE MULTİPLE PART...\n\n");
	    printf("Please select an operation:");
	    scanf("%d",&select);
	  
	      if(select == 1){ /* SİNGLE SELECTİON */
	    
	       printf("Enter a value: ");
	       scanf("%d",&val); /* taking the input */
	       printf("%d. Movie\n\n",val);
          
         while(t_name != NULL){
         count++;  
          
          if(count == val){
                
                printf("%s  ",t_name->name);
                printf("%s  ",t_name->genre);
                printf("%f  ",t_name->score);

                	   while(t_budget != NULL){
	    
										    if(strcmp(t_budget->name,t_name->name) == 0){
									          
									         printf("%d  ",t_budget->year);
									         printf("%d\n \n",t_budget->budget);
									         return;
										    }  
									         
										   	t_budget = t_budget->next;
										   
										   } 		   

            }

            t_name = t_name->next; 
          
           }

	       }
	   
		   else if(select == 2){ 
          
          printf("I COULDNT DO THİS PART :( \n");
  
	       return;		  
           
        
		       }

  else{
		  
		     printf("TRY AGAİN \n");
		  
	  	 }
		   
	 } 

  } 
 
  }

}

