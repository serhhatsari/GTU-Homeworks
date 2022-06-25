/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.22.19.55
** 
*/


#include <stdio.h>
#include "hw8_lib.h"


void test_clean_file () 
{ 
    
     char *infile = "infile.txt";
     char *outfile = "outfile.txt";
    
     char *words_to_delete[]={"serhat"};
     int number_of_words = 1;  
     /* I USED NUMBER OF WORDS AS THE NUMBER OF WORDS TO DELETE */
     clean_file(infile,outfile,words_to_delete,number_of_words);
	
}


void test_maze_move ()

{

    cell_type maze[8][8] = 

    {   {cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall},
        {cell_wall, cell_p1, cell_free, cell_free, cell_wall, cell_free, cell_target, cell_wall},
        {cell_wall, cell_p2, cell_wall, cell_free, cell_wall, cell_free, cell_wall, cell_wall},
        {cell_wall, cell_free, cell_wall, cell_free, cell_free, cell_free, cell_free, cell_wall},
        {cell_wall, cell_free, cell_wall, cell_wall, cell_free, cell_wall, cell_free, cell_wall},
        {cell_wall, cell_free, cell_wall, cell_wall, cell_free, cell_wall, cell_free, cell_wall},
        {cell_wall, cell_free, cell_free, cell_free, cell_free, cell_free, cell_free, cell_wall},
        {cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall}
        
        };
    
    cell_type player = cell_p1;
    
    maze_move(maze,player,0);

}


void test_towers_of_hanoi ()
{
	printf("İ COULDNT DO THİS PART SİR \n");
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_clean_file ();
	test_maze_move ();
	test_towers_of_hanoi ();
	return (0);
} /* end main */
