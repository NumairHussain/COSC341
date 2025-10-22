#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int compute_pi(int n) 
{
    int pi = 0;
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        pi += sign * (1.0 / 2 * i + 1);
        sign = -sign;
    }
    return 4 * pi;
}

double compute_sqrt(double x)
{
    double next = 1;
    double last = 0;
    for (int i = 0; i < 10; i++)
    {
        last = next;
        next += 0.5 * (last + x / last);
    }
    return next;
}

void id_password(char first[], char last[], int year)
{
    char userid[50] = "";
    char password[50] = "";
    char first_letter[2] = {first[0], '\0'};

    strcat(userid, first_letter);
    strcat(userid, last);

    printf("%s", userid);

    char three_letters_last_name[4] = {last[0], last[1], last[2], '\0'};
    char year_as_string[5] = "";
    sprintf(year_as_string, "%04d", year);

}


void file_sort(char *infile, char *outfile)
{
    FILE *fp = fopen(infile, "r");
    int num_students = 0;
    fscanf(fp, "%d", &num_students);

    fgetc(fp);

    int *student_id = (int *)malloc(num_students * sizeof(int));
    char *student_grade = (char *)malloc(num_students * sizeof(char));
    double *student_gpa = (double *)malloc(num_students * sizeof(double));

    for (int i = 0; i < num_students; i++)
    {
        fscanf(fp, "%d %s %lf", &student_id[i], &student_grade[i], &student_gpa[i]);
    }

    fclose(fp);

    for (int i = 0; i < num_students; i++)
    {
        for (int j = i + 1; j < num_students; j++)
        {
            if (student_id[i] < student_id[j])
            {
                int temp_id = student_id[i];
                student_id[i] = student_id[j];
                student_id[j] = temp_id;

                char temp_grade = student_grade[i];
                student_grade[i] = student_grade[j];
                student_grade[j] = temp_grade;

                double temp_gpa = student_gpa[i];
                student_gpa[i] = student_gpa[j];
                student_gpa[j] = temp_gpa;
            }
        }
    }
    FILE *fout = fopen(outfile, "w");
    fprintf(fout, "%d\n", num_students);

    for (int i = 0; i < num_students; i++)
    {
        fprintf(fout, "%d %c %.2f\n", student_id[i], student_grade[i], student_gpa[i]);
    }

    fclose(fout);

    free(student_id);
    free(student_grade);
    free(student_gpa);
}

int main()
{
    char infile[30] = "case9in.txt";
    char outfile[30] = "case9out.txt";
    file_sort(infile, outfile);
    return 0;
}