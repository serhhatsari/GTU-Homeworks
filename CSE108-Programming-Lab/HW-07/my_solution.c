#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int check_palindrome(int a[],int n);
int search_element(int arr[],int input_number);
float cosine(int n, float x);

int main(){

/*first part is*/
  int array[50]; /* my array */
   int i; /* its for loop */
   int n = 0;
   
	   for(i = 0 ;i < 50; i ++){ /* it will go until user enters -1 */
	   
	   printf("please enter the %d. element ( if you want to exit enter (-1) \n",i);
	   scanf("%d",&array[i]); /* taking the values */
	   n++; /* incrementing the size */
	   if(array[i] == -1){ /* if the user enters -1 it will break the loop */
	   n--;
	   break;
	    }
	  }
	  
	  if(check_palindrome(array,n-1) == 1){ /* sending array to the function */
	  printf("Your input is a palindrome \n");
	  }else{ /* if the return value isnt 1 it will go here */
	  printf("Your input is not a palindrome \n");
	  }
	  
 /* second part */
 
 int my_ar[20]; /* my array */
 int k; /* for loop */
 int rand_num; /* its gonna hold my rand numbers */
 int input; /* its gonna hold the input */
 
	 for(k = 0; k < 20; k ++){ /* it will generate the numbers */
	 rand_num = rand() % 101; /* it will generate a random number */
	 my_ar[k] = rand_num; /* it will assign it to my r */
	}
	
	
	 for(k = 0; k < 20; k ++){ /* to see the numbers i added this part hocam */
	printf("=%d \n",my_ar[k]);
	}
	
	
	printf("Please enter the input number \n");
	scanf("%d",&input); /* we took the input from the user */
	
	if(search_element(my_ar,input) == 1){ /* if its gonna return 1 itll go here */
	
	printf("your number is in the given array \n");
	
	}else{ /* if not itll go here */
	
	printf("your number is not in the given array \n");
	
	}

/* third part */

	int first;
	float second;
	
	printf("Please enter the n value of the theorem \n");
	scanf("%d",&first); /* taking the first value */
	
	printf("Please enter the x value of the theorem \n");
	scanf("%f",&second); /* taking the second value */
	printf("our result = %f \n",cosine(first,second));

}


int check_palindrome(int a[],int n){

if(n <= 0){
 /* when n is smaller than zero it will return 1 */
return 1;

}

if(a[n] == a[0]){ /* it will check the elements */

return check_palindrome(a+1,n-2); /* recursive part */

}else{

return 0; /* if they are not equal it will retyrn 0 */

}


}

int search_element(int arr[],int input_number){

static int a = 0;

while(arr[a] != input_number){ /* it will check if the number equals or not to the input */

if(a == 20){ /* if its not equal to the all of them it will return 0 */
return 0;
}

a++; /* incrementing the static value for the next use */
search_element(arr,input_number); /* recursive part */

}

return 1; /* if the input is in the array its gonna return 1 */

}





float cosine(int n, float x){


if(n < MAX){ /* if n is smaller than MAX it will go here */

return (1- ( (x*x) / ((2*n-1) * (2*n)) ) ) * cosine(n+1,x);

}

else{ /* if not it will return 1 to print the result */

return 1;

}

}
