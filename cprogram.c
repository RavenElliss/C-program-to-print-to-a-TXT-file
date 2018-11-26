#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[30];
    int id;
	float mark;
	
};

void readfile(struct student array[], int size, FILE *fp)
{

	fp=fopen("grades.txt", "r");        //opens file to read it
	int i;
	
    for (i = 0; i < size+1; i++){
        fscanf(fp, "%s", &array[i].name);     //stores the values of the grades text files into the array 
		fscanf(fp, "%d", &array[i].id);
		fscanf(fp, "%f", &array[i].mark);
    }
	
	
}

int menu()
{    // menu bar to print out the options for the user to choose from
	int i;
	printf("Enter 1 to Display students details\n");
	printf("Enter 2 to Calculate average of all marks\n");
	printf("Enter 3 to add new student to the record\n");
	printf("Enter 4 to quit the program\n");
	
	scanf("%d", &i);
	
	return i;
	
}

int displaystudents(int size, struct student array[])
{
    int i;

		for(i=0; i < size; i++)            //each time the fuction loops will print the array containing the student information
	    {
	    	printf("%s\n", array[i].name);
		    printf("%d\n", array[i].id);
	    	printf("%.2f\n", array[i].mark);
	    }

	
}

int calculateaverage(struct student array[], int size)
{
	int i;
	float total=0;
	
	    for(i=0; i < size; i++)
	    {
		   total=total+array[i].mark;        //calculates the average by first adding all the marks together into one integer value 
		
	    }
	
	total=total/size;       //then divides this value by the size of the array
	
	return total;
	
}


int updatefile(struct student array[], int size, FILE *fp)
{
	fp=fopen("grades.txt", "a");   //used open for append means the data will be added at the end.
	 
	size+1; 
	int i;
	
	      for(i=size; i<size+1; i++)      //did not use dynamic memeory so need to add 1 to the size 
	      {	
	          printf("Please enter the new name:\n");
	          scanf("%s", &array[i].name);
	          printf("Please enter the new id:\n");
	          scanf("%d", &array[i].id);
	          printf("Please enter the new mark:\n");
	          scanf("%f", &array[i].mark);
	
	          fprintf(fp, "\n%s  ", array[i].name);
	          fprintf(fp, "%d   %.2f", array[i].id, array[i].mark);
	       }
	
	size=size+1;
	readfile(array,size,fp);

	return size;
	
}
int main()
{	//int main takes the answer returned from menu function to create a switch as to which functions are called next. 
    struct student array[100];
    int size=5;
	int answer;
	float average;
	FILE * fp;
	readfile(array,size,fp);
	
	printf("Welcome to Raven's Program! Please select from the following:\n");
	
	do
	{
	answer=menu();
	
	switch(answer)
	{
		case 1:
		{
			displaystudents(size, array);
			break;
		}
		
		case 2:
		{
			average=calculateaverage(array,size);
			printf("The average of all marks is %.2f\n", average);
			break;
		}
		
		case 3:
		{
			size=updatefile(array,size,fp);
			break;
		}
		
		case 4:
		{
			printf("Goodbye...");
			break;
		}
		
		default:
		{
			printf("You have entered an incorrect number please try again\n");
			break;
		}	
		
	}
	}while(answer != 4);
	
	
	
	return 0;
}