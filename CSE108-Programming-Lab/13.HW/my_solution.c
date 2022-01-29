#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct program{

char *country;
char *capital; /* MY MAİN STRUCT */
int population;
bool driving_side; 

}program;

typedef struct linked{
 /* MY LİNKED LİST */
char *country;
char *capital;
int population;
bool driving_side; 
struct linked *next;

}linked;


int main(){
  
FILE *fp; /* file pointer */
 
linked *list = NULL;  /* creating list */


program *my_program;
int num_of_str = 0; /* numb of entries */
int inp = 0,i;
int drv_side;
char *drv;

 my_program = malloc((num_of_str + 2) * sizeof(program)); /* memory allocation */


while(1){
              /* MENU PART */
 printf("1: Enter new record\n");
 printf("2: Write to the file\n");
 printf("3: Read from the file\n");
 printf("4: Print the linked list\n");
 printf("5: Exit\n");

 printf("Enter your input: \n");;
 scanf("%d",&inp); /* taking the input */

 if(inp == 1){

		 num_of_str++;
		 my_program = realloc(my_program,(num_of_str + 1) * sizeof(program)); /* reallocating the mem */

		 printf("Country name: "); 
		 my_program[num_of_str-1].country = malloc(21*sizeof(char));  /* allocating strings */
		 scanf("%s",my_program[num_of_str-1].country);
		 
		 printf("Capital: ");
		 my_program[num_of_str-1].capital = malloc(21*sizeof(char));  /* allocating strings */
		 scanf("%s",my_program[num_of_str-1].capital);
		 
		 printf("Population of %s: ",my_program[num_of_str-1].country); /* taking population */
		 scanf("%d",&my_program[num_of_str-1].population);

		 printf("Do people in %s drive on the right side? (Yes:1, No:0): ",my_program[num_of_str-1].country);
		 scanf("%d",&drv_side);

	     my_program[num_of_str-1].driving_side = drv_side;

		 /* taking driving sşde */

 }
 
 else if(inp == 2){
  
	  fp = fopen("struct.txt","w+"); /* opening the file */

		  for(i = 0; i < num_of_str; i++){ /* loop */
		  
		  fprintf(fp,"%s ",my_program[i].country); /* writing the values */
		  fprintf(fp,"%s ",my_program[i].capital); /* writing the values */
		  fprintf(fp,"%d ",my_program[i].population); /* writing the values */

		  if(my_program[i].driving_side == 1){ /* if true */
		  
		  fprintf(fp,"Right \n"); 
		  
		  }else{
		 
		  fprintf(fp, "Left \n");

		  }
		  
		  }

		 fclose(fp);

 }
 else if( inp == 3){

 }
 else if(inp == 4){
  
	  while(list != NULL){ /* NULL CHECK */
	 
	 	  printf("%s ",list->country); /* printing */
		  printf("%s ",list->capital); /* printing */
		  printf("%d ",list->population); /* printing */

		  if(list->driving_side == 1){ /* driving check */
		  
		  printf("Right \n");
		  
		  }else{
		 
		  printf("Left \n");

		  } 

	   list = list->next;
	  
	   }
  
 }

 else if(inp == 5){ /* EXİTİNG THE PROGRAM */
 	printf("Terminating... \n"); 
 	return 0;
 }


}

}
