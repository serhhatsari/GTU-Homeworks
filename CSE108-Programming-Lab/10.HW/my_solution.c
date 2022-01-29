#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book{

char title[50];
char author[50];
char subject[50];
int id;
int pub_year;

}book_t;

book_t *my_books,*t_books = NULL;
book_t temp;

int main(){
	int choose,counter = 0,i,k;
	char tit[50],aut[50],sub[50];
	int idd,publ;
	int max;

  
 while(1){
	 

	  printf("MENU \n \n"); /* our menu */

	  printf("\t\t1- Add new books \n"); /* SHOWİNG THE MENU */
	  printf("\t\t2- List books \n");
	  printf("\t\t3- Exit \n");
	  printf("Choose: "); /* TAKİNG THE VALUES */
	  scanf("%d",&choose);
      
	  if(choose == 1)
		  {
			  counter++;	
	          my_books = (struct Book*)calloc(counter,sizeof(struct Book*)); /* giving memory */

	          printf("\n");

	          for(i = 0; i < counter - 1; i++){
	               
	               my_books[i] = t_books[i]; /* getting old values */

	          }

	          printf("Enter the book title: \n"); ;/* TAKİNG THE VALUES */
	          scanf("%s",tit);

	          printf("Enter the book author: \n");
	          scanf("%s",aut); /* TAKİNG THE VALUES */

	          printf("Enter the book subject: \n");
	          scanf("%s",sub);

	          printf("ENter book year\n");
	          scanf("%d",&publ);/* TAKİNG THE VALUES */

	          my_books[counter-1].id = counter;
              strcpy(my_books[counter-1].title,tit);
              strcpy(my_books[counter-1].author,aut);
              strcpy(my_books[counter-1].subject,sub);
            
	          if(t_books != NULL){

	          	free(t_books); /* freeing old memory */
	          } 
	           
	          t_books = my_books;/* assigning to t_books; */
            tit[0] = '\0';
            aut[0] = '\0';
            sub[0] = '\0';
		  }

	  else if(choose == 2)
		  {

		  while(1){	 /* WHİĞLE LOOP */
		  	printf("SUBMENU\n"); /* PRİNTİNG THE SUB MENU */
		  	printf("\t\t1 GET BY TİTLE\n");
		  	printf("\t\t2 GET BY AUTHOR\n");
		  	printf("\t\t3 GET BY SUBJECT\n");
		  	printf("\t\t4 SORTED LİST BY YEAR\n");
		  	printf("\t\t5 LİST ALL books\n");
		  	printf("\t\t6 EXİT MENU:\n\n"); 

		  	printf("CHOOSE = \n");
		  	scanf("%d",&choose); /* we take the input */

		  	if(choose == 1){ /* TİTLE PART */

            printf("Enter a title: ");
            scanf("%s",tit);
            for(i = 0; i < counter;i++){

            	 if(strcmp(t_books[i].title,tit) == 0){
                  
                  printf("\n\n");
            	  printf("%s ",t_books[i].title);
		  		  printf("%s ",t_books[i].author);
		  		  printf("%s ",t_books[i].subject);
		  		  printf("%d\n\n",t_books[i].pub_year);


            	 }
            }
  
		  	}
		  	else if(choose == 2){ /* AUTHOR PART */

		    printf("Enter a author: "); /* TAKİNG THE VALUES */
            scanf("%s",aut);

            for(i = 0; i < counter;i++){

            	 if(strcmp(t_books[i].author,aut) == 0){
                  
                  printf("\n\n");
            	  printf("%s ",t_books[i].title);
		  		  printf("%s ",t_books[i].author);
		  		  printf("%s ",t_books[i].subject);
		  		  printf("%d\n\n",t_books[i].pub_year);

		  		  break;


            	 }
               }

               printf(" No book found...\n");
  
		  	}

		  	else if(choose == 3){ /* subject part */

		  	printf("Enter a subject: ");
            scanf("%s",sub); /* TAKİNG THE VALUES */

            for(i = 0; i < counter;i++){
           
            	 if(strcmp(t_books[i].subject,sub) == 0){ /* checking the titles*/
                  printf("\n \n");
            	  printf("%s ",t_books[i].title);
		  		  printf("%s ",t_books[i].author);
		  		  printf("%s ",t_books[i].subject);
		  		  printf("%d\n\n",t_books[i].pub_year);
		  		  break;


            	 }
             }

             printf("No book found...\n");
  
		  	}
		  	else if(choose == 4){
         
         for(i = 0; i < counter-1;i++){


		    max = i;

            for (k = k + 1; k < counter; k++)
           {


	            if (t_books[k].pub_year > t_books[max].pub_year)
	            {

	                max = k;
	            }

           }


            temp = t_books[max];

            t_books[max] = t_books[i];

            t_books[i] = temp;
           }
                     
		  		for(i = 0;i < counter;i++){
  
		  		  printf("%d.book : \n",i+ 1);
                  printf("******************\n");
		  		  printf("%s ",t_books[i].title);
		  		  printf("%s ",t_books[i].author);
		  		  printf("%s ",t_books[i].subject);
		  		  printf("%d\n",t_books[i].pub_year);
		  		  printf("*******************\n");

		  		}

		  	  }
		  	
		  	else if(choose == 5){

		  		for(i = 0;i < counter;i++){
  
		  		  printf("%d.book : \n",i+ 1);
                  printf("******************\n");
		  		  printf("%s ",t_books[i].title);
		  		  printf("%s ",t_books[i].author);
		  		  printf("%s ",t_books[i].subject);
		  		  printf("%d\n",t_books[i].pub_year);
		  		  printf("*******************\n");

		  		}

		  	}

		  	else if(choose == 6)
		  	{
		  	break;
		  	} /* return the menu */

          }   
      	}

	  else if(choose == 3) /* Terminating the program */
		  {
		   printf("Terminating... \n");	
		   return 0;
		  }
	  
	  else
		  { /* İNVALİD VALUE CHECK */
		   printf("TRY AGAİN\n");
		  } 


  }




}