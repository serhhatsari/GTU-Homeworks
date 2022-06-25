/*
** hw8_lib.cn:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (cn) 2018-2021
**
** Revision: 2021.04.22.19.55
** 
*/

#include <stdio.h>
#include "hw8_lib.h"

#define WORDSIZE 30

/* first part helper functions */
void make_string_array(char our_text[], char words[200][30],int ind,int indnum,int sec,int *word_num);

void check_words(char words[][30],int word_num, char *words_to_delete[WORDSIZE] , int number_of_words,int word_index,int delete_index);

int string_equality(char *word,char *delete_word,int index);

int find_size(char *word,int size);

void print_words(FILE* outfid, char words[][30],int word_num,int index);

/* second part helper functions */

int maze_move(cell_type maze[][8], cell_type player, move_type move);

void maze_printing(cell_type maze[][8],int row,int column);
void current(cell_type maze[][8], cell_type player, int *row, int *column);

void move_to_left(cell_type maze[][8], cell_type player, int row, int column,int *return_val);
void move_to_right(cell_type maze[][8], cell_type player, int row, int column,int *return_val);
void move_to_up(cell_type maze[][8], cell_type player, int row, int column,int *return_val);
void move_to_down(cell_type maze[][8], cell_type player, int row, int column,int *return_val);

/* FİRST PART */

void delete_words (FILE* infid, FILE* outfid, char* words_to_delete[WORDSIZE],  int number_of_words)
{ 
     int i,j,word_num = 0; /* these are for loops */
     char our_text[1024];  /* it will gold my aray */
     char words[200][30]; /* it will hold the words in array */

    if(fgets(our_text,1024,infid)){ /* it will take the line */
    
     make_string_array(our_text,words,0,0,0,&word_num); /* it will separete the line to words */
     
     check_words(words,word_num, words_to_delete, number_of_words,0,0); /* it will check the words */
    
     print_words(outfid,words,word_num,0); /* it will print the words to the outfid file */
    
     delete_words (infid, outfid, words_to_delete, number_of_words); /* recursive part */
    
    }
    
}


void clean_file(char* infile, char * outfile, char* words_to_delete[WORDSIZE], int number_of_words)
{


	FILE* infid = fopen(infile,"row"); /* we opened the file */
	FILE* outfid = fopen(outfile,"a"); /* we opened the file */
	
	if(infid == NULL){ /* file check */
	printf("İnput File didnt open \n");
	return;
	}
	
	if(outfid == NULL){ /* file check */
	printf("Output File didnt open  \n");
	return;
	}
	
	delete_words (infid, outfid, words_to_delete, number_of_words);
	
	fclose(infid);
	fclose(outfid);
}


void make_string_array(char our_text[], char words[200][30],int ind,int indnum,int sec,int *word_num){


int index = ind; 
int seco = sec;
int wordcount = indnum;

if(our_text[index] == '\n'){ /* it will check if it has reached end of the line */

*word_num = wordcount +1; 

words[wordcount][seco] = '\0'; 

return;

}

else{


    if(our_text[index] != ' '){ /* it will check the spaces */
    
     words[wordcount][seco] = our_text[index]; /* it will assign the elments */
     seco++;
     index++;   
     make_string_array(our_text,words,index,wordcount,seco,word_num);  /* recursive part */
    
    }else{
    
    words[wordcount][seco] = '\0'; /* it will make the word a stirng */
    wordcount++;
    index++;
    seco = 0;
    make_string_array(our_text,words,index,wordcount,seco,word_num); /* recursive part */
    
   }
   
}

}

void check_words(char words[][30],int word_num, char* words_to_delete[WORDSIZE], int number_of_words,int word_index,int delete_index){

if(word_index == word_num){ /* it will check the end of the string */
return;
}

      
if(delete_index != number_of_words){ /* it will check if delete index is equal or not to numb or words */


 if(string_equality(words[word_index],words_to_delete[delete_index],0) == 1){ /* it will compare the string */
        
        words[word_index][0] ='\0';
        
      }
      
 delete_index++;     
 check_words(words,word_num,words_to_delete,number_of_words,word_index,delete_index); /* recursive part */
}      


word_index++;
delete_index = 0;
check_words(words,word_num,words_to_delete,number_of_words,word_index,delete_index); /* recursive part */

}

int string_equality(char *word,char *delete_word,int index){ /* it will compare the strings */

int size = find_size(word,0); /* it will find the size of string */

if(word[size-1] == '.'){ /* it will check if the last element equals dot or not */

size--;
word[size-1] = '\0';

}


if(index == size){ /* it will check the size of the string */

return 1;

}

if(word[index] != delete_word[index]){

return 0;

}

index++;

string_equality(word,delete_word,index);
 
}

int find_size(char *word,int size){ /* it will find the size of the string */

int siz = size;

if(word[siz] == '\0'){

return siz;

}

siz++;
find_size(word,siz);


}

void print_words(FILE* outfid, char words[][30],int word_num,int index){ /* it will print the words to the output file */

if(index == word_num){
fprintf(outfid,"\n");
return;
}

if(words[index][0] != '\0'){
fprintf(outfid,"%s ",words[index]);
}


index++;

print_words(outfid,words,word_num,index); /* recursive part */

}


/* SEcOND PART */

int maze_move(cell_type maze[][8], cell_type player, move_type move)
{

	int return_val, road_type;

	int row = 0, column = 0;
	
	maze_printing(maze, 0, 0); /* we will print the maze */
    
    if(player+1 == 1){ /* to see which player is playimg */
    
    printf("FİRST PLAYER PLEASE PLAY! İTS YOUR TURN! \n");

    }
    else if(player +1 == 2){ /* to see which player is playing */
    
    printf("SECOND PLAYER PLEASE PLAY! İTS YOUR TURN \n");

    }

	printf("WHERE DO YOU WANNA GO?\n");

	printf("UP = 1  DOWN = 2, LEFT = 3, RİGHT = 4 \n");

	printf("if you want to exit enter (0) \n");

	printf("Please enter your input: ");

	scanf("%d", &road_type);

	printf("\n");

	current(maze, player, &row, &column); /* finding the current place */

	move = road_type; 
    
    if(move == 0){ /* if move equals 0 program is gonna end */
    	
    printf("GAME İS OVER!! \n");

    return 0;

    }

    else if(move == move_up){ /* it will go up */

     move_to_up(maze, player, row, column,&return_val);

    }

    else  if(move == move_down){ /* it will go down */
    	
    move_to_down(maze, player, row, column,&return_val);

    }

    else  if(move == move_left){ /* it will go left */
    	
    move_to_left(maze, player, row, column,&return_val);

    }

    else  if(move == move_right){ /* it will go right */
    	
    move_to_right(maze, player, row, column,&return_val);

    }

    else{ 
    
    printf("Your input is wrong \n");

    return_val = 0;

    }
 


    if(return_val == 0){ /* it will display an error */


		printf("YOU COULDNT MOVE !! \n \n");

	}

	else if (return_val == 100) /* it means someone reached the target */
	{

	printf("GAME OVER SOMEONE REACHED THE TARGET! \n");

		return 1;

	}


	else if(return_val == 10){ /* it means move is succesfull */

     
        if (player == 0)
     	    {

     	    player++;

            }
	    else if(player == 1){
            
            player--;

	    }

	}

		return  maze_move(maze, player, move); /* recursive part*/

}


void maze_printing(cell_type maze[][8], int row, int column)
{
    switch(maze[row][column]) /* we print the elements of the maze */
    {
           case cell_target:
            
              printf("X ");

           break;

           case cell_wall:
              
              printf("0 ");

           break;

           case cell_free:

               printf("  ");

           break;

           case cell_p1:

               printf("1 ");

           break;

           case cell_p2:

               printf("2 ");

           break;

    };
      
    if(row == 7 && column == 7){ /* checking the indexes */
   
    printf("\n");

     return;

    }

	if (column != 7) /* checking the columns */

	{

		column = column + 1;

	}

	else if (row != 7 && column == 7)
	{
		printf("\n");

		column = 0;

		row++;
	}


	maze_printing(maze, row, column); /*recursive part */


}




void current(cell_type maze[][8], cell_type player, int *row, int* column)
{
	/* this function will find the current place */
    

	if (maze[*row][*column] == player) /* if we found it we will return */
	{
		return;

	}
	else if (*row != 7 && *column == 7) /* if not we will increment */
	{
		(*row)++;

		*column = 0;
        

	}

	else if(*column != 7){

     (*column)++;


	}


	current(maze, player, row, column); /* recursive part */
}



void move_to_down(cell_type maze[][8], cell_type player, int row, int column,int *return_val) 
{

	/* it will move to down */

    if(maze[row+1][column] == cell_free){ /* it will check if its free */
     
            maze[row+1][column] = player;

			maze[row][column] = cell_free;

			*return_val = 10;

			return;

    }

    else if(maze[row+1][column] == cell_target){ /* it will check if its target */
    
            maze[row+1][column] = player;

			maze[row][column] = cell_free;

			*return_val =  100;

			return;
    
    }

    else{ /* it will check if its safe or not if not it will return 0 with return val*/
      
            *return_val = 0;

			return;

    }
      
}

void move_to_left(cell_type maze[][8], cell_type player, int row, int column,int *return_val) 
{
	/* it will move to left */

	    if(maze[row][column-1] == cell_free){ /* it will check if its free */
     
            maze[row][column-1] = player;

			maze[row][column] = cell_free;

			*return_val = 10;

			return;

    }

    else if(maze[row][column-1] == cell_target){ /* it will check if its target */
    
            maze[row][column-1] = player;

			maze[row][column] = cell_free;

			*return_val =  100;

			return;
    
    }

    else { /* it will check if its safe or not if not it will return 0 with return val*/      
            *return_val = 0;

			return;

    }

}

void move_to_right(cell_type maze[][8], cell_type player, int row, int column,int *return_val) 
{
   /* it will move to right */

    if(maze[row][column+1] == cell_free){ /* it will check if its free */
     
            maze[row][column+1] = player;

			maze[row][column] = cell_free;

			*return_val = 10;

			return;

    }

    else if(maze[row][column+1] == cell_target){ /* it will check if its target */
    
            maze[row][column+1] = player;

			maze[row][column] = cell_free;

			*return_val =  100;

			return;
    
    }

    else{ /* it will check if its safe or not if not it will return 0 with return val*/
      
            *return_val = 0;

			return;

    }	

}

void move_to_up(cell_type maze[][8], cell_type player, int row, int column,int *return_val) 
{

    /* it will move to up */

    if(maze[row-1][column] == cell_free){ /* it will check if its free */
     
            maze[row-1][column] = player;

			maze[row][column] = cell_free;

			*return_val = 10;

			return;

    }

    else if(maze[row-1][column] == cell_target){ /* it will check if its target */
    
            maze[row-1][column] = player;

			maze[row][column] = cell_free;

			*return_val =  100;

			return;
    
    }

    else{  /* it will check if its safe or not if not it will return 0 with return val*/
      
            *return_val = 0;

			return;

    }

}


/*THİRD PART */


void towers_of_hanoi(char start_peg, char end_peg, char aux_peg, int n)
{
    printf("İ cOULDNT DO THE TOWERS OF HANOİ PART SİR...\n");
}

