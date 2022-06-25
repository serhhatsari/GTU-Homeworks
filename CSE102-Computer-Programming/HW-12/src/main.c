#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct antonyms{ /* ANTONYMS STRUCT */

	char mainword[50];
	char antonym_words[30][50];
	struct antonyms *next;

}antonyms;

typedef struct synonyms{ /* SYNONYMS STRUCT */

	char mainword[50];
	char synonym_words[30][50]; 
	struct synonyms *next;

}synonyms;

typedef struct users{ /* USER RECORD */ 
  
  int true_answer_count; /* number of true entries */
  int wrong_answer_count; /* number of false entries */

}user;

antonyms* insert_antonyms(antonyms *head, char *line); 
/* this func will insert line to antonym struct */

synonyms* insert_synonyms(synonyms *head, char *line);
/* this func will insert line to synonym struct */

void main(){

FILE *anton = fopen("antonyms.txt","r"); /* we opened the file with reading mode */
FILE *synon = fopen("synonyms.txt","r"); /* we opened the file with reading mode */
FILE *users = fopen("users.txt","a+"); /* we opened the file with appending mode */
FILE *bin; /* we will open the binary file with this */

antonyms *antonymslist = NULL; /* list of antonyms */
synonyms *synonymslist = NULL; /* list of synonyms */

user currentuser; /* new user */
currentuser.true_answer_count = 0; 
currentuser.wrong_answer_count = 0;

char line[1024], linet[1024],answer[50]; /* we use those to take the line from the file */
char username[50],existing[50],wdfile[60]; /* we will use these in question part */

int i,k,j,a = 0,ch,let = 0,cek = 0; /* some flags */
int antonnum = 0,synonnum = 0; 
int randind = 0,ct = 0,val,usercount = 1;

printf("\tWELCOME..\n");
printf("Enter your username according to:\n");
printf("(if there is none, it will be created) \n");
printf("(İf there is one, it will upload the existing user's informations..)\n");
printf("Enter your username :::> ");
scanf("%s",username); /* taking the username */

while(fgets(existing,100,users)){ /* checking the username file */

 existing[strlen(existing) - 1] = '\0';  
 if(strcmp(existing,username) == 0){
  
  cek = 1;
  break;

 }

}

if(cek == 0){ /* if zero it means we created a user */
  
   strcpy(wdfile,username);
   strcat(wdfile,".worddat");
   
   bin = fopen(wdfile,"ab+");
   
   fprintf(users,"%s\n",username); 
	printf("USER İS CREATED :  %s \n",username);
 
 }
 else if(cek == 1){ /* if one it means existing user has entered */
 
  strcpy(wdfile,username);
  strcat(wdfile,".worddat");
 
  bin = fopen(wdfile,"ab+");
  fread(&currentuser,sizeof(user),1,bin);
  fclose(bin);

  printf("WELCOME BACK %s \n",username);

 }


	while(fgets(line,1010,anton))
	   { /* it will read the file until end of the file */
 
	        antonymslist = insert_antonyms(antonymslist,line);
	       /* inserting line to antonyms list */
 
	    }
  
	while(fgets(linet,1010,synon))
	   { /* it will read the file until end of the file */

	       synonymslist = insert_synonyms(synonymslist,linet);
	    /* inserting line to synonyms list */
	 
	    }
 
 fclose(anton); /* closing the file */
 fclose(synon); /* closing the file */


   while(1){

		    printf("\nWHİCH QUESTİON DO YOU WANT TO BE ASKED? \n");
		    printf("1- What is the synonym of X?\n");
		    printf("2- What is the antonym of X?\n");
		    printf("3- OR İF YOU WANT TO EXİT...\n");
		    printf("Choose 1 or 2, 3: ");
		    scanf("%d",&let);

		if(let == 1){ /* What is the synoym of the X question */

			   synonyms *head = NULL;
			   head = synonymslist; /* new list */
		  
		      srand(time(NULL));

		       randind = rand() % (1000); /* creating a new number */
	          
		        for(i = 0; i < randind; i++){
		        
		        head = head->next;  /* shifting the head */

		       } 
		   
		        printf("\nWhat is the synonym of \"%s\": ",head->mainword); /* question */
		        scanf("%s",answer);
		        printf("\n\n");

		         for(i = 0; i < 30; i++){
	             
	             if(head->synonym_words[i][0] == '5') break;	/* checking the last element */         	

		         if(strcmp(head->synonym_words[i],answer) == 0){ /* if exist */
	              
		           ct = 1;
		            break;
		         }

		        } 

		        if(ct == 1){

			        currentuser.true_answer_count++; /* incrementing the true answer count */

			        printf("YOUR ANSWER İS CORRECT!\n\n");
			        printf("Number of true answers: %d \n",currentuser.true_answer_count);
	              printf("Number of false answers: %d \n\n",currentuser.wrong_answer_count);

			        printf("DO YOU WANNA ADD A NEW SYNONYM TO THE WORD: %s \n",head->mainword);
			        printf("1: YES 2: NO\n");
			        printf("Enter your input (only 1,2) = ");
			        scanf("%d",&val);

				        if( val == 1){ /* new word adding */
				          
			             printf("ENTER THE WORD YOU WANT TO ADD: ");
			             scanf("%s",answer); 
			             
		                for(i = 0; i < 30;i++){
		                   
		                   if(head->synonym_words[i][0] == '5'){ /* finding the last element */
 
		                     strcpy(head->synonym_words[i],answer); /* adding the new word */
		                     head->synonym_words[i+1][0] = '5'; 
		                     head->synonym_words[i+1][1] = '\0';
		                     break;

		                   }

		               } 

			             printf("Your word is added...\n\n");

			       
				        }
			        
			        	ct = 0;
		       
		        }
		        
		        else if(ct == 0){
		           
			           currentuser.wrong_answer_count++; /* wrong answer count incremented */
				        
				        printf("YOUR ANSWER İS WRONG\n\n");
			           printf("Number of true answers: %d \n",currentuser.true_answer_count);
	                 printf("Number of false answers: %d \n",currentuser.wrong_answer_count);

				        printf("1: ADD YOUR WRONG ANSWER AS A NEW SYNONYM TO THE WORD: \n");  
				        printf("2: ADD A NEW SYNONYM TO THE WORD: \n");
				        printf("3: DONT DO ANYTHİNG..\n");
				        printf("Enter your input (only 1,2,3) = ");
				        scanf("%d",&val);
				              
				            if(val == 1){
				              
			                for(i = 0; i < 30;i++){
			                   
			                   if(head->synonym_words[i][0] == '5'){

			                     strcpy(head->synonym_words[i],answer); /* adding new word */
			                     head->synonym_words[i+1][0] = '5';
			                     head->synonym_words[i+1][1] = '\0';
			                     break;

			                   }

			               } 
			                 printf("Your answer is added..\n");
				              
				            
				            }  
				            else if(val == 2){
				               
				             printf("ENTER THE WORD YOU WANT TO ADD: ");
				             scanf("%s",answer); 

			                for(i = 0; i < 30;i++){
			                   
			                   if(head->synonym_words[i][0] == '5'){ /* checking the last element */

			                     strcpy(head->synonym_words[i],answer); /* adding new word */
			                     head->synonym_words[i+1][0] = '5';
			                     head->synonym_words[i+1][1] = '\0';
			                     break;

			                   }

			               } 

				             printf("Your word is added...\n\n");
				            
			                  
				            
				            }

		        } 
		    }
	   else if(let == 2){

			   antonyms *headds = NULL;
			   headds = antonymslist; /* new list */
		  
		      srand(time(NULL));

		       randind = rand() % (1000); /* generate a random element */
	          
		        for(i = 0; i < randind; i++){
		        
		        headds = headds->next;  

		       } 
		   
		        printf("\nWhat is the antonym of \"%s\": ",headds->mainword);
		        scanf("%s",answer);
		        printf("\n\n");

		         for(i = 0; i < 30; i++){
	             
	             if(headds->antonym_words[i][0] == '5') break; /* last element check */
	

		         if(strcmp(headds->antonym_words[i],answer) == 0){ /* if exist check */
	              
		           ct = 1;
		            break;
		         }

		        } 

		        if(ct == 1){

			      currentuser.true_answer_count++; /* incrementing true answer count */

			      printf("YOUR ANSWER İS CORRECT!\n\n");
			      printf("Number of true answers: %d \n",currentuser.true_answer_count);
	            printf("Number of false answers: %d \n \n",currentuser.wrong_answer_count);

		        printf("DO YOU WANNA ADD A NEW SYNONYM TO THE WORD: %s \n",headds->mainword);
		        printf("1: YES 2: NO\n");
		        printf("Enter your input (only 1,2) = ");
		        scanf("%d",&val);

			        if( val == 1){
			          
		             printf("ENTER THE WORD YOU WANT TO ADD: ");
		             scanf("%s",answer); 
		             
	                for(i = 0; i < 30;i++){
	                   
	                   if(headds->antonym_words[i][0] == '5'){ /* finding the last element */

	                     strcpy(headds->antonym_words[i],answer); /* adding the answer */
	                     headds->antonym_words[i+1][0] = '5';
	                     headds->antonym_words[i+1][1] = '\0';
	                     break;

	                   }

	               } 

		             printf("Your word is added...\n\n");

		       
			        }
		        
		        	ct = 0;
		       
		        }
		        
		        else if(ct == 0){
		        
			         currentuser.wrong_answer_count++; /* wrong answer count incremented */
				        
				  printf("YOUR ANSWER İS WRONG\n\n");
			     printf("Number of true answers: %d \n",currentuser.true_answer_count);
	           printf("Number of false answers: %d \n \n",currentuser.wrong_answer_count);

		        printf("1: ADD YOUR WRONG ANSWER AS A NEW SYNONYM TO THE WORD: \n");  
		        printf("2: ADD A NEW SYNONYM TO THE WORD: \n");
		        printf("3: DONT DO ANYTHİNG..\n");
		        printf("Enter your input (only 1,2,3) =  ");
		        scanf("%d",&val);
		              
		            if(val == 1){
		              
	                for(i = 0; i < 30;i++){
	                   
	                   if(headds->antonym_words[i][0] == '5'){ /* last element finding */

	                     strcpy(headds->antonym_words[i],answer); /* adding new anseer */
	                     headds->antonym_words[i+1][0] = '5';
	                     headds->antonym_words[i+1][1] = '\0';
	                     break;

	                   }

	               } 
	                 printf("Your answer is added..\n");
		              
		            
		            }  
		            else if(val == 2){
		               
		             printf("ENTER THE WORD YOU WANT TO ADD: ");
		             scanf("%s",answer); 

	                for(i = 0; i < 30;i++){ 
	                   
	                   if(headds->antonym_words[i][0] == '5'){ /* adding */

	                     strcpy(headds->antonym_words[i],answer);
	                     headds->antonym_words[i+1][0] = '5';
	                     headds->antonym_words[i+1][1] = '\0';
	                     break;

	                   }

	               } 

		             printf("Your word is added...\n\n");
		            
	                  
		            
		            }

		        } 

		   }
		else if(let == 3){

			 anton = fopen("antonyms.txt","w"); /* its for updating the file */
          synon = fopen("synonyms.txt","w"); /* its for updating the file */
          bin = fopen(wdfile,"w"); /* its for taking the records of the user */

            while(antonymslist != NULL){ /* updating antonymslist */
 
               fprintf(anton,"%s",antonymslist->mainword);
               fprintf(anton," <>");

               for(i = 0; i < 20; i++){

               if (antonymslist->antonym_words[i][0] == '5') 
               { 
               	break;
               }

               fprintf(anton," %s",antonymslist->antonym_words[i]); 
                

               }

               fprintf(anton,"\n");
 
               antonymslist = antonymslist->next;
            
            } 

            while(synonymslist != NULL){ /* updating synonyms list */
 
               fprintf(synon,"%s",synonymslist->mainword);
               fprintf(synon," =");

               for(i = 0; i < 20; i++){

               if (synonymslist->synonym_words[i][0] == '5') 
               { 
               	break;
               }

               fprintf(synon," %s",synonymslist->synonym_words[i]); 
                

               }

               fprintf(synon,"\n");
 
               synonymslist = synonymslist->next;
            
            } 
          

	         fwrite(&currentuser,sizeof(users),1,bin); /* storing the data of the user */
	         printf("Terminating...\n");
	         
	         fclose(anton); /* CLOSİNG THE FİLE */
	         fclose(synon);  /* CLOSİNG THE FİLE */
	         fclose(bin);   /* CLOSİNG THE FİLE */

	         return;

		    }

	   else{ /* WRONG İNPUT CHECK */
	        printf("Wrong input.. choose 1 or 2 or 3... \n\n");
	      }

 }



	return;
}



antonyms* insert_antonyms(antonyms *head, char *line){

	antonyms *first,*second;
    antonyms *temp;
    int i,k,j = 0,a = 1;

		if(head == NULL) /* if list is empty it will go here */
	{
      
		temp = (antonyms*)malloc(sizeof(antonyms)); /* memory alloc */
       
       	  	for(i = 0,k = 0; line[i] != '\n';i++){ /* separating the line */
		        
                if(line[i] == ' '){

                   if(a == 1){

                    temp->mainword[j] = '\0';
                    j = 0;
                    a++;

                   }
                   else if(a == 2){
 
                    a++;
                    continue;

                   }

                   else if(a > 2){

                    temp->antonym_words[k][j] = '\0';
                    
                    j = 0;
                    k++;
                    
                   }
                  continue;

                }

                if(a == 1){
                      
                 temp->mainword[j] = line[i];
                 j++;

                }

                else if(a > 2){

                temp->antonym_words[k][j] = line[i];
                j++;
                  
                }

          }
         
          temp->antonym_words[k][j] = '\0';
          temp->antonym_words[k+1][0] = '5';
 

		temp->next = NULL;
	
		head = temp;	
	
	} 

	else{

			first = head;
			second = first->next;
  
			
			while(first != NULL && second != NULL){  /* null check */

				first = second; 
				second = first->next;

			}
	    

			temp = (antonyms*)malloc(sizeof(antonyms));  /* memory alloc */
			
			temp->next = second;
			first->next = temp;

			 for(i = 0,k = 0; line[i] != '\n';i++){ /* separating the line */
		        
                if(line[i] == ' '){

                   if(a == 1){

                    temp->mainword[j] = '\0';
                    j = 0;
                    a++;

                   }
                   else if(a == 2){
                   	a++;
                   	continue;

                   }

                   else if(a > 2){

                    temp->antonym_words[k][j] = '\0';
                    
                    j = 0;
                    k++;
                    
                   }
                   continue;

                }

                if(a == 1){
                      
                 temp->mainword[j] = line[i];
                 j++;

                }

                else if(a > 2){

                temp->antonym_words[k][j] = line[i];
                j++;
                  
                }

          }
           
         temp->antonym_words[k][j] = '\0';
         temp->antonym_words[k+1][0] = '5';


		}

		return head;

 }



synonyms* insert_synonyms(synonyms *head, char *line){

	synonyms *first,*second;
    synonyms *temp;
    int i,k,j = 0,a = 1;

		if(head == NULL) /* if list is empty it will go here */
	{
      
		temp = (synonyms*)malloc(sizeof(synonyms)); /* memory alloc */
       
       	  	for(i = 0,k = 0; line[i] != '\n';i++){ /* separating the line */
		        
                if(line[i] == ' '){

                   if(a == 1){

                    temp->mainword[j] = '\0';
                    j = 0;
                    a++;

                   }
                   else if(a == 2){
 
                    a++;
                    continue;

                   }

                   else if(a > 2){

                    temp->synonym_words[k][j] = '\0';
                    
                    j = 0;
                    k++;
                    
                   }
                  continue;

                }

                if(a == 1){
                      
                 temp->mainword[j] = line[i];
                 j++;

                }

                else if(a > 2){

                temp->synonym_words[k][j] = line[i];
                j++;
                  
                }

          }

         temp->synonym_words[k][j] = '\0';
         temp->synonym_words[k+1][0] = '5';

         

		temp->next = NULL;
	
		head = temp;	
	
	} 

	else{

			first = head;
			second = first->next;
  
			
			while(first != NULL && second != NULL){ /* null check */

				first = second; 
				second = first->next;

			}
	    

			temp = (synonyms*)malloc(sizeof(synonyms));  /* memory alloc */
			
			temp->next = second;
			first->next = temp;

			 for(i = 0,k = 0; line[i] != '\n';i++){ /* separating the line */
		        
                if(line[i] == ' '){

                   if(a == 1){

                    temp->mainword[j] = '\0';
                    j = 0;
                    a++;

                   }
                   else if(a == 2){
                   	a++;
                   	continue;

                   }

                   else if(a > 2){

                    temp->synonym_words[k][j] = '\0';
                    
                    j = 0;
                    k++;
                    
                   }
                   continue;

                }

                if(a == 1){
                      
                 temp->mainword[j] = line[i];
                 j++;

                }

                else if(a > 2){

                temp->synonym_words[k][j] = line[i];
                j++;
                  
                }

          }

         temp->synonym_words[k][j] = '\0';
         temp->synonym_words[k+1][0] = '5';

		}

		return head;

 }
