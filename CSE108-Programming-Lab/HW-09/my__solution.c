#include <stdio.h>


typedef struct line{

float x1,y1,x2,y2,x3,y3,slope;

}line_t;


typedef struct grades{
   
 float midterm, final,homework;
 float average;

}grades_t;


typedef struct students{
	
char name[30];
char surname[30];
int id_num;
grades_t std_grade;

}students_t;

typedef struct games{
	
  char name[30];
  char platforms[50][20];
  float score;

}games_t;

void first();
void second();
void third();



int main(){

/* First Part */

first();

/* Second Part */

second();
 
/* Third Part */

  
third();


} 

void first(){

	line_t our_line;   

	double first,second;

	printf("Enter x1: ");
	scanf("%f",&our_line.x1);

	printf("Enter y1: ");
	scanf("%f",&our_line.y1);

	printf("Enter x2: ");
	scanf("%f",&our_line.x2);

	printf("Enter y2: ");
	scanf("%f",&our_line.y2);

	printf("Enter x3: ");
	scanf("%f",&our_line.x3);


	first = our_line.y2 - our_line.y1;
	second = our_line.x2 - our_line.x1;

	our_line.slope = first / second;

	our_line.y3 = (our_line.slope * (our_line.x3 - our_line.x2)) + our_line.y2;


	printf("Slope is : %.3lf \n ",our_line.slope);
	printf("Y3 is : %.3lf \n",our_line.y3);

}

void second(){
   
   int i,number;

   float mid,fin,hom;
   int id,check =0;

   printf("Enter the number of games: ");
   scanf("%d",&number);
   
   students_t our_std[number];

   for(i = 0 ; i < number; i++){

    printf("Enter the %d. students name: ",i+1);
    scanf("%s",our_std[i].name);

    printf("Enter the %d. students surname: ",i+1);
    scanf("%s",our_std[i].surname);

    printf("Enter the %d. student's İD: ",i+1);
    scanf("%d",&our_std[i].id_num);

    printf("Enter the %d.student's midterm: ",i+1);
    scanf("%f",&mid);
    our_std[i].std_grade.midterm = mid;

    printf("Enter the %d. student's final: ",i+1);
    scanf("%f",&fin);
    our_std[i].std_grade.final = fin;

    printf("Enter the %d. student's homework: ",i+1);
    scanf("%f",&hom);
    our_std[i].std_grade.homework = hom;

    our_std[i].std_grade.average = (mid + fin + hom) / 3.0;

   }

   for(i = 0;i < number; i++){

    printf("%d.students average = %.3f \n",i+1,our_std[i].std_grade.average);

   }

    printf("Enter an id :");
    scanf("%d",&id);
    
    for(i = 0; i< number;i++){
     
       if(our_std[i].id_num == id){
        
        printf("Name: %s\nSurname:%s ",our_std[i].name,our_std[i].surname);
        printf("İD %d \n",our_std[i].id_num);
        printf("Midterm: %f\nFinal %f\n",our_std[i].std_grade.midterm,our_std[i].std_grade.final);
        printf("homework: %f \n",our_std[i].std_grade.homework);
        printf("average : %f\n",our_std[i].std_grade.average);
        return;
       }

    }

      printf("THERE İS NO STUDENT WİTH THAT İD NUMBER :\n");


 

}

void third(){

int number,i,k,j,platform;
float average = 0;
char plat_n[30];


printf("Enter the number of games: \n");
scanf("%d",&number);

games_t our_games[number];

for(i = 0; i < number;i++){
   
   printf("Enter the name of the game: ");
   scanf("%[^\n]%*c",our_games[i].name);
   
   printf("How many platform ?\n");
   scanf("%d",&platform);

   for(k = 0; k < platform;k++){

   	printf("Enter the %d platform: ",k + 1);
   	scanf("%s",our_games[i].platforms[k]);

   }

}

for(i = 0; i < number; i++){
  
  average += our_games[i].score;

}
printf("Average of the scores of the game %f \n",average);



}