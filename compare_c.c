#include <stdio.h>

void file_sort(char *infile, char *outfile)
{
    FILE *fp;
    fp = fopen(infile, "r");
    int num_students = 0;
    fscanf(fp, "%d", &num_students);

    fgetc(fp);  // Consume newline after number

    // Allocate memory for student data arrays
    int *ids = (int *)malloc(num_students * sizeof(int));
    char *grades = (char *)malloc(num_students * sizeof(char));
    double *gpas = (double *)malloc(num_students * sizeof(double));

    // Read student data from file
    for (int i = 0; i < num_students; i++)
    {
        fscanf(fp, "%d %s %lf", &ids[i], &grades[i], &gpas[i]);
    }

    fclose(fp);

    // Sort students by ID using selection sort
    for (int i = 0; i < num_students - 1; i++) 
    {
        for (int j = i + 1; j < num_students; j++) 
        {
            if (ids[j] < ids[i]) 
            {
                // Swap ids
                int tempId = ids[i];
                ids[i] = ids[j];
                ids[j] = tempId;

                // Swap grades
                char tempGrade = grades[i];
                grades[i] = grades[j];
                grades[j] = tempGrade;

                // Swap gpas
                double tempGpa = gpas[i];
                gpas[i] = gpas[j];
                gpas[j] = tempGpa;
            }
        }
    }

    // Write sorted data to output file
    FILE *fout = fopen(outfile, "w");
    fprintf(fout, "%d \n", num_students);
    for (int i = 0; i < num_students; i++)
    {
        fprintf(fout, "%d %c %.2f\n", ids[i], grades[i], gpas[i]);
    }
    fclose(fout);

    // Free allocated memory
    free(ids);
    free(grades);
    free(gpas);
    
}