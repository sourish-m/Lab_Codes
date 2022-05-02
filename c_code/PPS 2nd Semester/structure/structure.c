//W.A.P in C to store and access “id, name and marks1 and marks2 ” for 'n' students using Structure array. Calculate the average marks obtained by //each student and store it in the records for all n students.


#include <stdio.h>
#include <stdlib.h> //for system("cls")
struct student
{
    int id, marks1, marks2; float avg;
    char name[20];
};
int main()
{
    printf("Enter number of students\n");
    int n;
    scanf("%d", &n);
    struct student st[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter details of student %d ---\nEnter id: ", i + 1);
        scanf("%d", &st[i].id);
        printf("Enter name: ");
        fflush(stdin);
        fgets(st[i].name, 20, stdin);
        printf("Enter marks1 and marks2\n");
        scanf("%d\t%d", &st[i].marks1, &st[i].marks2);
        st[i].avg = (float)(st[i].marks1 + st[i].marks2) / 2;
    }

    //enter Details of each student and calculate average for each student
    system("cls");

    for ( int j = 0; j < n; j++)
    {
        printf ("\nThe details of student %d are---\n", j + 1);
        printf("id:\t%d\nname:\t%s\nmarks1:\t%d\nmarks2:\t%d\naverage marks:\t%f\n",
               st[j].id, st[j].name, st[j].marks1, st[j].marks2, st[j].avg);
    }

    return 0;
}

