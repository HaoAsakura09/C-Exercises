#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996);

int main(void)
{
    // I initialized subject. Assigned 0 to it
    int subject, mark, total = 0, student,n, maxMark = 0, topStudent;
    double average;
    double highestAverage = 0; // To track the highest average


    printf("\n======================================================\n");
    printf("              MARKS PROCESSING SYSTEM                   \n");
    printf("======================================================\n");

    printf("Enter how many students? ");
    scanf("%d", &n);

    for(student = 1; student <= n; student++)
    {
        printf("Student No. %d\n", student);
        for(subject = 1; subject <= 3; subject++)
        {
            printf("       Marks for Subject %d: ", subject);
            scanf("%d", &mark);

            total += mark;
        }

        average = (double)total / 3.0;
        printf("       TOTAL MARK -----------> %d\n", total);
        printf("       AVERAGE MARK ---------> %.2f\n", average);


        if(total > maxMark)             // Gets the highest mark
            maxMark = total;

        if(average > highestAverage)
        {   // Gets the highest average
            highestAverage = average;
            //The number of highest average student
            topStudent = student;
        }

        total = 0;   // set it back to zero for the next calculation
        average = 0; // We don't want to add the total and average of previous student.
                     // so we clear the previously stored values
    }

    printf("THE HIGHEST TOTAL MARK IS -------------> %d\n", maxMark);
    printf("THE TOP STUDENT IS STUDENT NO. --------> %d", topStudent);
    printf("\n======================================================\n");
    printf("            THANK YOU FOR USING THIS SYSTEM!            \n");
    printf("            FOR SUGGESTION PLEASE CONTACT               \n");
    printf("            <your name> AT <your phone no.>               ");
    printf("\n======================================================\n");
    return 0;
}
