/*
 *
 *
 * ██╗    ██╗ ██████╗ ██╗████████╗███████╗██╗  ██╗
 * ██║    ██║██╔═══██╗██║╚══██╔══╝██╔════╝██║ ██╔╝
 * ██║ █╗ ██║██║   ██║██║   ██║   █████╗  █████╔╝
 * ██║███╗██║██║   ██║██║   ██║   ██╔══╝  ██╔═██╗
 * ╚███╔███╔╝╚██████╔╝██║   ██║   ███████╗██║  ██╗
 *  ╚══╝╚══╝  ╚═════╝ ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
 *
 *
 *
 *  ______
 * /\  ___\
 * \ \ \____
 *  \ \_____\
 *   \/_____/
 *
 *
 *
 * This program reads a text file containing a list of integer numbers. The
 * first integer (K) specifies how many of the remaining numbers are to be
 * read. These K numbers are used to fill a K-dimensional integer array "data".
 * Then the program determines the largest integer stored in "data", and
 * computes the average of the values in this array. The corresponding results
 * are printed to the standard output and to a file named "answer-hw3.txt".
 *
 *
 */

#include <stdio.h>
#include <string.h>

#define OUTPUT_FILE "answer-hw3.txt"
/* Size of the string that stores the name of the input text file. */
#define SIZE_FILE_NAME 256

/* This function reads the text file, and returns the number of integers in the
   file. We use this information to avoid, e.g., trying to read 15 integers
   when there are only 10. */
int determine_num_ints(char file_name[])
{
    unsigned int num;
    FILE* txt_file;

    txt_file = fopen(file_name, "r");
    if (txt_file == NULL) {
        return -1;
    } else {
        num = 0;
        /* We're assuming that every integer is in a separate line of the
           input file. */
        while (fscanf(txt_file, "%*d\n") != EOF) {
            num += 1;
        }
        fclose(txt_file);
        return (int) num;
    }
}

/* This function reads the input text file, and returns the first integer
   stored in that file. */
int read_1st(char file_name[])
{
    int first;
    FILE* txt_file;

    /* The following command will always work, since this function won't be
       called if the input file cannot be opened. */
    txt_file = fopen(file_name, "r");
    /* We're assuming that every integer is in a separate line of the
       input file. */
    fscanf(txt_file, "%d\n", &first);
    fclose(txt_file);
    return first;
}

/* This function reads the input text file, and loads the integer array "data". */
void load_data(int data[], unsigned int length_data, char file_name[])
{
    unsigned int i;
    FILE* txt_file;

    /* The following command will always work, since this function won't be
       called if the input file cannot be opened. */
    txt_file = fopen(file_name, "r");
    fscanf(txt_file, "%*d\n");
    for (i = 0; i < length_data; i++) {
        /* We're assuming that every integer is in a separate line of the
           input file. */
        fscanf(txt_file, "%d\n", &data[i]);
    }
    fclose(txt_file);
    return;
}

/* This function receives an integer array and its length. Then the function
   returns the average of the values in the array. */
double average(int data[], unsigned int length_data)
{
    unsigned int i;
    long int sum = 0;

    for (i = 0; i < length_data; i++) {
        sum += (long int) data[i];
    }
    return sum / ((double) length_data);
}

/* This function receives an integer array and its length. Then the function
   returns the largest integer stored in the array. */
int max(int data[], unsigned int length_data)
{
    unsigned int i;
    int max_val = data[0];
    int temp;

    for (i = 1; i < length_data; i++) {
        temp = data[i];
        if (temp > max_val) {
            max_val = temp;
        }
    }
    return max_val;
}

/* This function receives the number of integers that must be read from the
   input text file. Then the function reads these integers into the array
   "data", and determines the corresponding average and maximum. */
void avg_max_ints(unsigned int length_data,\
                  double* avgdata,\
                  int* maxdata,\
                  char file_name[])
{
    int data[length_data];

    load_data(data, length_data, file_name);
    *avgdata = average(data, length_data);
    *maxdata = max(data, length_data);
    return;
}

/* This function prints all the results to a file. */
void print_to_file(double avg_ints,\
                   int first_int,\
                   unsigned int length_data,\
                   int max_ints,\
                   unsigned int num_ints)
{
    FILE* out_file;

    out_file = fopen(OUTPUT_FILE, "w");
    fprintf(out_file, "Number of integers in the input file: %hu\n", num_ints);
    fprintf(out_file, "1st integer: %d\n", first_int);
    fprintf(out_file, "Number of integers read into the array \"data\": %hu\n",\
            length_data);
    fprintf(out_file, "Largest integer in \"data\": %d\n", max_ints);
    fprintf(out_file, "Average of the integers in \"data\": %lf\n", avg_ints);
    fclose(out_file);
    return;
}

/* This function prints all the results to the standard output. */
void print_to_stdout(double avg_ints,\
                     int first_int,\
                     unsigned int length_data,\
                     int max_ints,\
                     unsigned int num_ints)
{
    printf("\nNumber of integers in the input file: %hu\n", num_ints);
    printf("1st integer: %d\n", first_int);
    printf("Number of integers read into the array \"data\": %hu\n",\
           length_data);
    printf("Largest integer in \"data\": %d\n", max_ints);
    printf("Average of the integers in \"data\": %lf\n\n", avg_ints);
    return;
}

int main()
{

    double avg_ints;
    char file_name[SIZE_FILE_NAME];
    int first_int;
    unsigned int length_data;
    int max_ints;
    unsigned int num_ints;
    int temp;

    printf("Enter the name of the file containing the integers: ");
    fgets(file_name, SIZE_FILE_NAME, stdin);
    temp = strlen(file_name);
    if ((temp > 0) && (file_name[temp - 1] == '\n')) {
        file_name[temp - 1] = '\0';
    }

    /* Determines the number of integers in the input text file. */
    temp = determine_num_ints(file_name);
    if (temp == -1) {
        printf("\nThe file %s doesn't exist!\n\n", file_name);
        return -1;
    } else if (temp == 0) {
        printf("\nThere are no integers in the file %s!\n\n", file_name);
        return -1;
    } else {
        num_ints = (unsigned int) temp;
    }

    /* Reads the first integer stored in the input file. Then determines the
       length of the array "data". */
    first_int = read_1st(file_name);
    if (first_int < 1) {
        printf("\nThe 1st integer is less than 1. Nothing can be done.\n\n");
        return -1;
    } else {
        temp = ((int) num_ints) - 1;
        if (first_int <= temp) {
            length_data = (unsigned int) first_int;
        } else if (temp > 0) {
            /* Cannot read the specified number of integers. Reads as many
               integers as possible. */
            length_data = (unsigned int) temp;
        } else {
            printf("\nAfter the 1st integer, there's nothing to read.\n\n");
            return -1;
        }
    }

    /* Loads the array "data", and determines the corresponding average and
       maximum. */
    avg_max_ints(length_data, &avg_ints, &max_ints, file_name);

    /* Prints all the results. */
    print_to_file(avg_ints, first_int, length_data, max_ints, num_ints);
    print_to_stdout(avg_ints, first_int, length_data, max_ints, num_ints);

    return 0;

}
