#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fix_spelling_error(char *text,char *dictionary); /* it will check the words */

void fix_spelling_error2(int dif_num,char dif_array[][40],int dif_size,char array[],int array_size,int punc,char last[],int tor[],int *howman); /* it will correct the 2 difference words */

void find_best_correction(int dif_num,char dif_array[][40],int dif_size,char array[],int array_size,int punc,char last[],int tor[],int *howman); /* it will correct the 1 difference words */

void check_punc(char array[],int size,int *punc,char last[]); /* it will check the puncs */

void add_punc(char array[],int punc,char last[]); /* it will add the after the word corrected */

void lower_maker(char array[],int size, int tor[],int *howman); /* it will make the word lower */

void upper_maker(char array[],int size, int tor[],int *howman); /* it will make the word upper */

/* this program can correct the words with one different letter or two different letter */

/* i did the bonus part too */

int main(){

        char *text = "text.txt";
        char *dictionary = "dictionary.txt";
        
        fix_spelling_error(text,dictionary);
        
	return 0;
}

void fix_spelling_error(char *text,char *dictionary){

    int size; /* it will hold the size of my word */
    char array[40]; /* it will hold my number */
    int tor[40];
    int howman = 0;
    FILE *txt = fopen(text,"r+");  /* we opened the text file with r+ */
    
       if(txt == NULL)
    {
        printf("Could not open the file \n");
        exit(1);
    }
    
	while(fscanf(txt, "%s", array) != EOF) /* it will go until the end of the file */
  {
  	
      size = strlen(array); /* we took the size of word */
      int first_size = size; /* we need the first value of size so we assign it */
      
     char one_dif[100][40]; /* its gonna hold the one dif words */
     char two_dif[100][40];  /* its gonna hold the two dif words */
     char arr[40]; /* its gonna hold the word when we took from dictionary */
   
     int i=0,let_dif = 0; /* i is for loop, let dif is the difference */
     int a=0, b=0; /* they are for loop */
     int punc = 0; /* its gonna hold which condition our word has been */
     int no_dif; /* its for true words */
   
    char last_ch[2]; /* its gonna hold the punc */
    
    check_punc(array,size,&punc,last_ch); /* this function will check puncs */
    
    size = strlen(array);  
    howman = 0;
    lower_maker(array,size,tor,&howman);
    
    
   FILE *dict = fopen(dictionary,"r"); /* we opened the dictionary file with r */
   
    if(dict == NULL)
    {
        printf("Could not open the file \n");
        exit(1);
    }
     
     while(fscanf(dict,"%s",arr) != EOF ) /* it will go until the end of the file */
   	{
   		
	   if(size == strlen(arr)){ /* if size of the word equals our size itll go here */
			
			
			for(i=0; i < size; i++){ /* it will check the elements of the words*/
				
				if(arr[i] != array[i]){
				
					let_dif++; /* it will increment if one of them not equal */
				
        	                     }
					
				}
				
		
		 if(let_dif==0){ /* if difference is zero it will go here */
		         upper_maker(array,size,tor,&howman);
		         add_punc(array,punc,last_ch); /* if it has a punc it will go here */
		         no_dif = 1; 
                          break;
	               
                  }
                  
		
		else if(let_dif==1){ /* if difference is one it will go here */
		
			strcpy(one_dif[a],arr); /* it will hold the dif words */
			a++;
			
		    	}
		    	
		 else if(let_dif==2){ /* if difference is two it will go here */
		
			
			strcpy(two_dif[b],arr); /* it will hold the two dif words */
		        b++;
			
		    	}   	
				
                let_dif = 0; /* it is the difference */
                
                
		}
		
		strcpy(arr,"\0");
	  		
	} 
	
	if(no_dif != 1){ /* if word is correct it wont go here */
	
	
	   if(a != 0){
	   
	   find_best_correction(1,one_dif,a,array,size,punc,last_ch,tor,&howman); /* it will correct the word  with one dif*/
	   
           }
        
          else if(b != 0){ 
          
          find_best_correction(2,two_dif,b,array,size,punc,last_ch,tor,&howman); /* it will correct the word with two dif */
          
          }
        
       }
       
        
        no_dif = 0;
        
        
        fclose(dict); /* we closed the file */

  
       fseek(txt,-(first_size), SEEK_CUR); /* it will change the cursor */
       
        fprintf(txt,"%s ", array); /* it will print the correct word to the file */
        
        strcpy(array,"\0");
    }	
       
  fclose(txt); /* we closed the second file */
  
}



void find_best_correction(int dif_num,char dif_array[][40],int dif_size,char array[],int array_size,int punc,char last[],int tor[],int *howman){

int a,b,z;

if(dif_num == 1){ /* it will correct the one difference words */

   for(z=0; z < dif_size; z++){ /* it will go until the size of array */


          for(a=0; a < array_size; a++){ /* it will find the wrong element */
        
               if(dif_array[z][a] != array[a]){ /* it will check the elements */
               b = a; /* it will assign the number of element to b */
               break;
               }
       
           }
       

           if(dif_array[z][b] == 'a' || dif_array[z][b] == 'e' ||dif_array[z][b] == 'i' ||dif_array[z][b] == 'o' || dif_array[z][b] == 'u'){ /* it will check if the different character is vowel or not */
           
            array[b] = dif_array[z][b];
            upper_maker(array,array_size,tor,howman); /* it will make the word upper */
            add_punc(array,punc,last); /* it will add needed punct to the word */
            
            return;
            }
     
        else  if(z == dif_size -1 ){ /* it will check if there is no vowel or not */
          
            array[b] = dif_array[z][b]; 
            upper_maker(array,array_size,tor,howman); /* it will make the word upper */
            add_punc(array,punc,last); /* it will add punct to the word */ 
      
         return;
          }
      
        }
  }




  else if(dif_num == 2){ /* if there is no one letter difference word to our original word it will check the 2 letter difference words */
    
   fix_spelling_error2(dif_num,dif_array,dif_size,array,array_size,punc,last,tor,howman); /* it will correct the 2 letter difference words */
   
  }

}



void fix_spelling_error2(int dif_num,char dif_array[][40],int dif_size,char array[],int array_size,int punc,char last[],int tor[],int *howman){

  int c[3]; /* it will hold the number of elements which are different from original arrays elements */
  int k = 0; /* its for loop */
  int a,z; /* they are for loop */
  
     for(z=0; z < dif_size; z++){ /* it will go until the size of array */

          for(a=0; a < array_size; a++){ /* it will find the wrong elements */
        
               if(dif_array[z][a] != array[a]){ /* it will check the elements if they are same or not */
               c[k] = a; /* it will hold the number of element in the c array */
               k++;
               if(k==2){ /* when it become 2 it will break the loop */
               break;
               }
               }
       
           }
       
     for(k = 0; k < 2;k++){ /* it will correct the 2 elements */
     
           if(dif_array[z][c[k]] == 'a' || dif_array[z][c[k]] == 'e' ||dif_array[z][c[k]] == 'i' ||dif_array[z][c[k]] == 'o' || dif_array[z][c[k]] == 'u'){ /* it will check if the different letter is vowel or nıt */
           
            array[c[k]] = dif_array[z][c[k]];
            
            }
     
          else if(z == dif_size -1 ){ /* if none of the letters are vowel it will just take the last letter */
          
          array[c[k]] = dif_array[z][c[k]]; 
          
          }
          
          }
          
         
            
           
          
        }
         add_punc(array,punc,last); /* it will add the punct to the word */ 
         return;
}



void check_punc(char array[],int size,int *punc,char last[]){
  
  char lastch[2]; 
  
    if(array[size-1] == '.'){ /* it will check the punction */
    
    array[size-1] = '\0';
    *punc = 1;
    
    }
     
    else if(array[size-1] == ','){ /* it will check the punction */
    
    array[size-1] = '\0';
    *punc = 2;
    
    }
    
        else if(array[size-1] == '\''){ /* it will check the punction */
    
    array[size-1] = '\0';
    *punc = 3;
    
    }
    
        else if(array[size-1] == '\"'){ /* it will check the punction */
    
    array[size-1] = '\0';
    *punc = 4;
    
    }
    
        else if(array[size-1] == '?'){ /* it will check the punction */
    
    array[size-1] = '\0';
    *punc = 5;
    
    }
    
     else if(array[size-2] == '\''){ /* it will check the punction */
     
    lastch[0] = array[size-1];
    lastch[1] = '\0';
     strcpy(last,lastch);
    array[size-2] = array[size-1];
    array[size-1] = '\0';
    *punc = 6;
  
    }
    
     else if(array[0] == '\"'){ /* it will check the punction */
     
    int i;
    for(i = 0; i <= strlen(array) -2  ;i++){ /* it will change the array */
    
    array[i] = array[i+1];
    
    }
    array[strlen(array) -1] = '\0';
    
    *punc = 7;
   
    } 


}

void add_punc(char array[],int punc,char last_ch[]){

    char nokta[2] = "."; 
    char vir[2] = ",";
    char tek_tir[2] = "\'";
    char cift_tir[2] = "\"";
    char soru[2] = "?";
    char carr[40]; /* it will hold the original array then we change this */
    
    char last_of[2];
    int a,boyut;

             if(punc == 1){ /* adding punctions to the word */
                            strcat(array,nokta);
                             }
                   else if(punc == 2){ /* adding punctions to the word */
                             strcat(array,vir);
                              }
                    else if(punc == 3){ /* adding punctions to the word */
                             strcat(array,tek_tir);
                              }
                    else  if(punc == 4){ /* adding punctions to the word */
                             strcat(array,cift_tir);
                              }
                    else if(punc == 5){ /* adding punctions to the word */
                             strcat(array,soru);
                             }
                     else if(punc == 6){ /* adding punctions to the word */
                       
                           strcpy(carr,array);
                         boyut = strlen(carr);
                         carr[boyut+1] = '\0';
                         carr[boyut] = last_ch[0];
                         carr[boyut-1] = tek_tir[0];
                         strcpy(array,carr);
                       
                       
                              }
                              
                    else if(punc == 7){ /* adding punctions to the word */
                     
                        carr[0] ='\0';
                         
                        strcat(carr,cift_tir);
                        
                        strcat(carr,array);
                        
                        strcpy(array,carr);
                      
                   
                    } 
                              
}

void lower_maker(char array[],int size, int tor[],int *howman){ /* make needed letters lower */
int i,k=0; /* they are for loop */

for(i = 0;i < size; i++){ /* it will change the elements of the array like A => a */

     if(array[i] >= 'A' && array[i] <= 'Z'){ /* check the elements */

     array[i] += 32; /* make it upper */
     tor[k] = i;
     k++;

     }

}

*howman = k; /* it will hold the number of changes */

}


void upper_maker(char array[],int size, int tor[],int *howman){ /* make needed letters upper */

int i,k;

for(i = 0;i < *howman; i++){ /* it will change the elements of the array like a => A */

k = tor[i];
array[k] -= 32;

} 

}

