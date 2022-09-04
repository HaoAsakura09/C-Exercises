#include <stdio.h>
#define MAX 100 // Maximum students

void print_result(int student[MAX][3]);

int size(void);

int main(void)
{
    int student_mark[MAX][3];

    print_result(student_mark);
    return 0;
}

int size(void)
{
    int n;
    printf("Please enter the number of students: ");
    scanf("%d", &n);
    return n;
}

void print_result(int student[MAX][3])
{
    int total_mark = 0, highest_mark = 0, highest_student = 0, i, j;
    double average = 0, highest_average;
    printf("\n==========================================\n");
    printf("          MARKS PROCESSING SYSTEM          \n");
    printf("==========================================\n");
    int length = size();
    
    // Terminate the program if the length exceeds 100
    if(length > 100)
      return; 
  
    for( i = 0; i < length; i++)
    {
        printf("Student No. %d:\n", i + 1);
        for( j = 0; j < 3; j++)
        {
            printf("        Marks for Subject %d: ", j + 1);
            scanf("%d", &student[i][j]);

            total_mark += student[i][j];
        }

        average = (double)total_mark / 3.0;
        printf("        TOTAL MARK ---------> %d\n", total_mark);
        printf("        AVERAGE MARK -------> %.2f\n", average);


        if(total_mark > highest_mark)
            highest_mark = total_mark;

        if(average > highest_average)
        {
            highest_average = average;
            highest_student = i + 1;
        }

        total_mark = 0;
        average = 0;
    }

    printf("THE HIGHEST TOTAL MARK IS ---------> %d\n", highest_mark);
    printf("THE TOP STUDENT IS STUDENT NO -----> %d", highest_student);

    printf("\n===============================================\n");
    printf("       THANK YOU FOR USING THIS SYSTEM!!\n");
    printf("       FOR SUGGESTION PLEASE CONTACT\n");
    printf("       <your name> AT Myour phone no.>");
    printf("\n===============================================\n");
}
