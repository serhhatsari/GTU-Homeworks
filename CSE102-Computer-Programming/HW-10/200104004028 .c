#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie{ /* İTS MY STRUCT */

 double budget;
 int genre;
 char *name;
 double score;
 int year;

};

struct Movie *t_movie; /* MY STRUCT ARRAY */
struct Movie *movie = NULL; /* İ NEED THİS TO STORE OLD VALUE OF T MOVİE */
struct Movie temp;

char **t_genre = NULL; /* MY GENRE ARRAY */
char **genre_arr; /* İTS FOR OLD VALUES */
int genre_count = 0;

int *n_genre; /* İTS FOR THE NUMBER OF GENRES */
int *tn_genre = NULL;

void my_program(char *txt); /* MY MAİN PROGRAM */
int find_genre(char *genre,int chk,int gen); /* WE FİND THE CORRECT GENRE WİTH THİS FUNC */
void part_one(); /* İTS FOR NUMBER 1 SELECTİON */

int main(){

char *txt = "Movies.txt"; /*Name of the file*/
my_program(txt);

return 0;
}

void my_program(char *txt){

FILE *fp = fopen(txt,"r"); /* We opened the file with r (only read mode) */
char *t_line, *line = NULL;
char letter; /* it will hold the letter which i got from txt file */
int letter_count = 0,struct_count = 0,i,k = 0,j = 0; /* some flags */
int operation,check = 0; /* more flags */
double average = 0,score_t; /* its for print section */
int fl = 0,kontrol = 0,fourth = 0,yearval = 0,log,valu; /* i need them in print section */
char *movie_name;

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
           
	  char ALL[5][200]; /* i stored the component of the line in this */
	  /* yakup hoca said something about this as i remember. we can use static arrays in local things like 
	  this. i didnt use any static array except this */
	  
	  for(i = 0, k = 0, j = 0; i < letter_count; i++){ /* we separete the word with this functiın */
	   
	   if(line[i] == '\0'){
	   
	   ALL[k][j] = '\0';
	   break;
	   }
	   else if(line[i] == ','){
		   
		   ALL[k][j] = '\0';
		   k++;
		   j = 0;
		   continue;
	   }
	   
	   ALL[k][j] = line[i];
	   j++;
	   
	  }
	  check = 0;
	 
      for(i = 0; i < struct_count ; i++){
	   
	   if(strcmp(ALL[2],movie[i].name) == 0){ /* checking if the names are same or not */
	   
		  if(strcmp(ALL[0],"unknown") == 0){
		  
		   movie[i].budget = -1; /* overwrite the struct */
		   	  
		  }else{
		  
		   movie[i].budget = atof(ALL[0]);  /* overwrite the struct */
		  }
		   movie[i].score = atof(ALL[3]);  /* overwrite the struct */
		   movie[i].year = atoi(ALL[4]);  /* overwrite the struct */
		   movie[i].genre = find_genre(ALL[1],1,movie[i].genre);  /* overwrite the struct */
		   check = 1; 
	   }
	  } 
	  if(check == 1){
	  letter_count = 0;
	  continue;
          }
	  struct_count++;
	 
	  t_movie = (struct Movie*)calloc(struct_count , sizeof(struct Movie)); /* we allocate a memory to t_movie struct */

	 for(i = 0; i < struct_count - 1; i++){
	  
	    t_movie[i].budget = movie[i].budget; /* assigning the old values */
	    t_movie[i].year = movie[i].year; /* assigning the old values */
	    t_movie[i].score = movie[i].score; /* assigning the old values */
	    t_movie[i].genre = movie[i].genre; /* assigning the old values */
	     
	   t_movie[i].name = (char*)malloc(strlen(movie[i].name) * sizeof(char) + 1);
	   strcpy(t_movie[i].name,movie[i].name); /* assigning the old values */
	    
	  } 
	  if(strcmp(ALL[0],"unknown") == 0){
	  t_movie[struct_count-1].budget = -1; /* assigning the newest value */
	    
	  }else{
	  
	  t_movie[struct_count-1].budget = atof(ALL[0]); /* assigning the newest value */
	  }
 
	  t_movie[struct_count-1].score = atof(ALL[3]); /* assigning the newest value */
	  t_movie[struct_count-1].year = atoi(ALL[4]); /* assigning the newest value */
	  t_movie[struct_count-1].genre = find_genre(ALL[1],0,0); /* assigning the newest value */
	  
          t_movie[struct_count-1].name = (char*)malloc(strlen(ALL[2]) * sizeof(char) + 1);
	  
          strcpy(t_movie[struct_count -1].name, ALL[2]); /* assigning the newest value */
	   
	  if(movie != NULL) free(movie); /* we freed the movie struct */
	  
	  movie = t_movie; /* assign the struct array to the movie */
	   
	  letter_count = 0; 
    }
}   

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
   
   if(operation == 1){ /* if user choose 1 it will open part one function */
   part_one();
   }
   else if(operation == 2){ /* . List of the Genres */
   
   for(i = 0; i < genre_count; i++){ /* printing the genres */
   
     printf("%s \n",t_genre[i]);
   }
   }
   else if(operation == 3){/* List of the Movie Through the Years. */
 
       while(1){
    
    printf("Enter a year: "); /* taking the year */
    scanf("%d",&yearval);
    
    printf("Until(0) or Since(1): "); /* taking since or until */ 
    scanf("%d",&valu);

	 if(valu == 0){ /* if user choose until it will go here */
	    for(i = 0; i < struct_count - 1; i++){ /* printing loop */
		 
		 if(yearval > movie[i].year){
		 
		 printf("%s %d \n",movie[i].name,movie[i].year);
	         fourth = 1;
	        }
	     }
	   }  
	   else if(valu == 1){ /* if user choose since it will go here */
	     for(i= 0; i < struct_count - 1; i++){
		 
		 if(yearval < movie[i].year){
		 
		 printf("%s \n",movie[i].name);
	         fourth = 1;
	        }
	     }
	    }else{
	    
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
    
    printf("Enter a score: ");
    scanf("%lf",&score_t);
    
    printf("Less(0) or greater(1) than score?: ");
    scanf("%d",&log);
    
	 if(log == 0){
	    for(i= 0; i < struct_count-1; i++){ /* it will check if its less or not */
		 
		 if(score_t > movie[i].score){
		 printf("%s \n",movie[i].name);
	         fourth = 1;
	         
	        }
	     }
	   }  
	   else if(log == 1){
	     for(i= 0; i < struct_count-1; i++){ /* it will check if its greater or not */
		 
		 if(score_t < movie[i].score){
		 
		 printf("%s \n",movie[i].name);
	         fourth = 1;
	        }
	     }
	    
	    }else{
	    
	    printf("Less or greater is invalid value. TRY AGAİN \n");
            }
            if(fourth == 1){
            fourth = 0;
            break;
            }
        }
   }
  
   else if(operation == 5){/* All Informations of a Single Movie */
   
	while(1){
	   
		printf("Please enter the name of the movie: ");   
		scanf("%s",movie_name);
		
		for(i = 0; i < struct_count-1; i++){
		   
		 if(strcmp(movie_name,movie[i].name)==0){ /* check if they are same or not */
			 printf("\n\n");
			 if(movie[i].budget == -1){
			 printf("Budget: Unknown \n");
			 }else{
			 printf("Budget: %.0f \n",movie[i].budget);
			 }  
			 printf("Genre: %s \n",genre_arr[movie[i].genre - 1]);
			 printf("Name: %s \n",movie_name);
			 printf("Year: %d \n",movie[i].year);
			 printf("Score: %f \n\n",movie[i].score);
			 printf("\n");
			 kontrol = 1;
			 break;
		 }
		}
		if(kontrol == 1){
		 kontrol = 0;
		 break;
		 
		}
		else{
		
		printf("TRY AGAİN \n");
		
		}
      }   
   }
   
   else if(operation == 6){  /* Average of the IMDB Scores. */
   
	for(i = 0; i < struct_count ; i++){
	   
           average += movie[i].score;
	}
	   
      printf("\n\nAverage is %f \n \n",average / (struct_count-1));	   
      average = 0;
      
   }
   else if(operation == 7){ /* Frequence of genres */

   for(i = 0; i < genre_count; i++){
   
     printf("%s ---> ",t_genre[i]);
     printf("%d \n",tn_genre[i]);
   
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

int find_genre(char *genre,int chk,int gen){
 int i;
 
 for(i = 0; i < genre_count; i++) { /* checking the genres */
 
   if(strcmp(genre,t_genre[i]) == 0){
    if(chk == 1){
    tn_genre[gen-1]--;
    tn_genre[i]++;
    return i+1;
    }
    tn_genre[i]++;
    return i+1;
   
   }
 }
genre_count++;

genre_arr = (char**)calloc(sizeof(char*),genre_count); /* genre allocation */

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

genre_arr[genre_count -1] = (char*)malloc(sizeof(char) * strlen(genre) + 1); /* genre allocation */

strcpy(genre_arr[genre_count-1],genre);

if(t_genre != NULL) free(t_genre);

t_genre = genre_arr;

return genre_count;

}


void part_one(){
int oper,select,val,flag = 0,start_val,end_val,i;
int j, min;

while(1){ /* print part */
  
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
	  printf("2. Multiple Selection\n\n");
	  printf("Please select an operation:");
	  scanf("%d",&select);
	  
	  if(select == 1){ /* SİNGLE SELECTİON */
	    
	    printf("Enter a value: ");
	    scanf("%d",&val); /* taking the input */
	    printf("%d. Movie\n\n",val);
	    printf("%.0lf  %s  %s",movie[val-1].budget,t_genre[movie[val-1].genre -1],movie[val-1].name);
	    printf("  %lf  %d \n\n",movie[val-1].score,movie[val-1].year);
	    flag = 1; 
	    return;
	  }
	  else if(select == 2){ /* MULTİPLE SELECTİON */
	  
           printf("Enter start value: ");
           scanf("%d",&start_val); /* taking the input */
           printf("Enter end value: ");
           scanf("%d",&end_val); /* taking the input */
           end_val++; 
           
              for (i = start_val; i < end_val - 1; i++) { /* SORTİNG */
              
		    min = i;
		        
		    for (j = i + 1; j < end_val; j++){
		        
	         	    if (movie[j].budget < movie[min].budget){
		           
	                    min = j;
		                
		           } 
                     }
		         
                  temp = movie[min];
	          movie[min] = movie[i];
	          movie[i] = temp;
		 
                }	
                
              for(i = start_val; i < end_val; i++){ /* PRİNTİNG THE ORDER */
 
 		 printf("\n");
         	 if(movie[i].budget == -1){
         	 
         	 printf("Unknown ");
	         }else{
	         
		 printf("%.0f ",movie[i].budget);
	         }  
			 printf("%s ",genre_arr[movie[i].genre - 1]);
			 printf("%s ",movie[i].name);
			 printf("%d ",movie[i].year);
			 printf("%f ",movie[i].score);
			 printf("\n");              
             
              }  
	     
	     printf("\n");
	     return;
	  }
	  else{
	  
	  printf("TRY AGAİN \n");
	  
	  }
	   
         }
         if(flag == 1) return;
         
  }
  
  else if(oper == 2){
    
     while(1){
     
	  printf("1. Single Selection\n");
	  printf("2. Multiple Selection\n\n");
	  printf("Please select an operation:");
	  scanf("%d",&select); /* taking the input */
	  
	  if(select == 1){
	    
	    printf("Enter a value: ");
	    scanf("%d",&val); /* taking the input */
	    printf("%d. Movie\n\n",val);
	    printf("%.0lf  %s  %s",movie[val-1].budget,t_genre[movie[val-1].genre -1],movie[val-1].name);
	    printf("  %lf  %d \n\n",movie[val-1].score,movie[val-1].year);
	    flag = 1; 
	    return;
	  }
	  else if(select == 2){
	  
           printf("Enter start value: ");
           scanf("%d",&start_val); /* taking the input */
           printf("Enter end value: ");
           scanf("%d",&end_val); /* taking the input */
           end_val++;
           
           
           
              for (i = start_val; i < end_val - 1; i++) { /* SORTİNG */
              
		    min = i;
		        
		    for (j = i + 1; j < end_val; j++){
		        
	         	    if (strcmp(t_genre[movie[j].genre-1],t_genre[movie[min].genre-1]) < 0){
		           
	                    min = j;
		                
		             }
		            
                     }
		         
                  temp = movie[min];
	          movie[min] = movie[i];
	          movie[i] = temp;
		 
                }	
                
              for(i = start_val; i < end_val; i++){ /* PRİNTİNG THE ORDER */
 
 		 printf("\n");
         	 if(movie[i].budget == -1){
         	 
         	 printf("Unknown ");
	         }else{
	         
		 printf("%.0f ",movie[i].budget);
	         }  
			 printf("%s ",genre_arr[movie[i].genre - 1]);
			 printf("%s ",movie[i].name);
			 printf("%d ",movie[i].year);
			 printf("%f ",movie[i].score);
			 printf("\n");              
             
              }  
	     
	     printf("\n");
	  	  
	    return;
	  }
	  else{
	  
	  printf("TRY AGAİN \n");
	  
	  }
	   
         }
         if(flag == 1) return;
 }
  
  else if(oper == 3){ /* NAME PART */
    
     while(1){
     
	  printf("1. Single Selection\n");
	  printf("2. Multiple Selection\n\n");
	  printf("Please select an operation:");
	  scanf("%d",&select); /* taking the input */
	  
	  if(select == 1){ /* SİNGLE SELECTİON */
	    
	    printf("Enter a value: ");
	    scanf("%d",&val); /* taking the input */
	    printf("%d. Movie\n\n",val+1);
	    printf("%.0lf  %s  %s",movie[val-1].budget,t_genre[movie[val-1].genre -1],movie[val-1].name);
	    printf("  %lf  %d \n\n",movie[val-1].score,movie[val-1].year);
	    flag = 1; 
	    return;
	  }
	  else if(select == 2){ /* MULTİPLE SELECTİON */

	  
           printf("Enter start value: ");
           scanf("%d",&start_val);
           printf("Enter end value: ");
           scanf("%d",&end_val); /* taking the input */
           end_val++;
           
           
           
              for (i = start_val; i < end_val - 1; i++) { /* SORTİNG */
              
		    min = i;
		        
		    for (j = i + 1; j < end_val; j++){
		        
	         	    if (strcmp(movie[j].name,movie[min].name) < 0){
		           
	                    min = j;
		                
		             }
		            
                     }
		         
                  temp = movie[min];
	          movie[min] = movie[i];
	          movie[i] = temp;
		 
                }	
                
              for(i = start_val; i < end_val; i++){ /* PRİNTİNG THE ORDER */
 
 		 printf("\n");
         	 if(movie[i].budget == -1){
         	 
         	 printf("Unknown ");
	         }else{
	         
		 printf("%.0f ",movie[i].budget);
	         }  
			 printf("%s ",genre_arr[movie[i].genre - 1]);
			 printf("%s ",movie[i].name);
			 printf("%d ",movie[i].year);
			 printf("%f ",movie[i].score);
			 printf("\n");              
             
              }  
	     
	     printf("\n");
	  	  
	  return;
	  }
	  else{
	  
	  printf("TRY AGAİN \n");
	  
	  }
	   
         }
         if(flag == 1) return;
         
 }
  
  else if(oper == 4){ /* SCORE PART */
  
     while(1){ 
     
	  printf("1. Single Selection\n");
	  printf("2. Multiple Selection\n\n");
	  printf("Please select an operation:");
	  scanf("%d",&select); /* taking the input */
	  
	  if(select == 1){ /* SİNGLE SELECTİON */
	    
	    printf("Enter a value: ");
	    scanf("%d",&val); /* taking the input */
	    printf("%d. Movie\n\n",val);
	    printf("%.0lf  %s  %s",movie[val-1].budget,t_genre[movie[val-1].genre -1],movie[val-1].name);
	    printf("  %lf  %d \n\n",movie[val-1].score,movie[val-1].year);
	    flag = 1; 
	    return;
	  }
	  else if(select == 2){ /* MULTİPLE SELECTİON */

	  
           printf("Enter start value: ");
           scanf("%d",&start_val); /* taking the input */
           printf("Enter end value: ");
           scanf("%d",&end_val); /* taking the input */
           end_val++;
           
           
           
              for (i = start_val; i < end_val - 1; i++) { /* SORTİNG */
              
		    min = i;
		        
		    for (j = i + 1; j < end_val; j++){
		        
	         	    if (movie[j].score < movie[min].score){
		           
	                    min = j;
		                
		             }
		            
                     }
		         
                  temp = movie[min];
	          movie[min] = movie[i];
	          movie[i] = temp;
		 
                }	
                
              for(i = start_val; i < end_val; i++){ /* PRİNTİNG THE ORDER */
 
 		 printf("\n");
         	 if(movie[i].budget == -1){
         	 
         	 printf("Unknown ");
	         }else{
	         
		 printf("%.0f ",movie[i].budget);
	         }  
			 printf("%s ",genre_arr[movie[i].genre - 1]);
			 printf("%s ",movie[i].name);
			 printf("%d ",movie[i].year);
			 printf("%f ",movie[i].score);
			 printf("\n");              
              }  
	     
	     printf("\n");
	    return;
	  }
	  else{
	  
	  printf("TRY AGAİN \n");
	  
	  }
	   
         }
         if(flag == 1) return;
         
 }
  
  else if(oper == 5){ /* YEAR SELECTİON PART */
  
     while(1){
     
	  printf("1. Single Selection\n");
	  printf("2. Multiple Selection\n\n");
	  printf("Please select an operation:");
	  scanf("%d",&select); /* taking the input */
	  
	  if(select == 1){ /* SİNGLE SELECTİON */
	    
	    printf("Enter a value: ");
	    scanf("%d",&val); /* taking the input */
	    printf("%d. Movie\n\n",val+1);
	    printf("%.0lf  %s  %s",movie[val-1].budget,t_genre[movie[val-1].genre -1],movie[val-1].name);
	    printf("  %lf  %d \n\n",movie[val-1].score,movie[val-1].year);
	    flag = 1; 
	    break;
	  }
	  else if(select == 2){ /* MULTİPLE SELECTİON */
	  
           printf("Enter start value: ");
           scanf("%d",&start_val); /* taking the input */
           printf("Enter end value: ");
           scanf("%d",&end_val); /* taking the input */
           end_val++;
           
           
           
              for (i = start_val; i < end_val - 1; i++) { /* SORTİNG */
              
		    min = i;
		        
		    for (j = i + 1; j < end_val; j++){
		        
	         	    if (movie[j].year < movie[min].year){
		           
	                    min = j;
		                
		             }
		            
                     }
		         
                  temp = movie[min];
	          movie[min] = movie[i];
	          movie[i] = temp;
		 
                }	
                
              for(i = start_val; i < end_val; i++){ /* PRİNTİNG THE ORDER */
 
 		 printf("\n");
         	 if(movie[i].budget == -1){
         	 
         	 printf("Unknown ");
	         }else{
	         
		 printf("%.0f ",movie[i].budget);
	         }  
			 printf("%s ",genre_arr[movie[i].genre - 1]);
			 printf("%s ",movie[i].name);
			 printf("%d ",movie[i].year);
			 printf("%f ",movie[i].score);
			 printf("\n");              
             
              }  
	     
	     printf("\n");
	     return;
	  }
	  else{
	  
	  printf("TRY AGAİN \n");
	  
	  }
	   
         }
         if(flag == 1) return;
         
   }
  
  else{
  
  printf("TRY AGAİN \n\n");
  
  }


  }
  
}

