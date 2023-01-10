#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate(double x1);

int main()
{
    char group[4],name[10],surname[10];
    double x1,x2,y,delta,bin,**A;
    int number,N;

    FILE* file=fopen("A:\\Учёба\\Предметы\\Информатика\\Лаб 5\\Lab_5\\file.txt", "r");
    FILE* file_out=fopen("A:\\Учёба\\Предметы\\Информатика\\Лаб 5\\Lab_5\\file_output.txt", "w");
    FILE* file_bin=fopen("A:\\Учёба\\Предметы\\Информатика\\Лаб 5\\Lab_5\\file_binary.txt", "w");
    fscanf(file,"%lf %lf %d %lf %s %s %s", &x1, &x2, &number, &delta, group, surname, name);

    if (number==0)
    {
        number=((x2-x1)/delta)+1;
    }
    else if (delta==0)
    {
        delta=(x2-x1)/(number-1);
    }
    fclose(file);

    fprintf(file_out, "\t|N|X\t|Y\t\t|");
    fwrite(&number, sizeof(int), 1, file_bin);
    for(int i=0; i<number; i++)

    {
        y=calculate(x1);
        fprintf(file_out, "\n\t|%d|%.2lf\t|%.2lf\t|",i,x1,y);
        fwrite(&x1, sizeof(double), 1, file_out);
        fwrite(&y, sizeof(double), 1, file_bin);
        x1+=delta;
    }
    fclose(file_out);
    fclose(file_bin);

    file_bin = fopen("file_binary.txt", "r+b");
    printf("%s\n%s %s", group, surname,name);
    printf("\n|N|\t|X\t|\t|Y\t\t|");
    fread(&N, sizeof(int), 1, file_bin);

    A=(double**)malloc(3*sizeof(double*));
    for(int i=0; i<3; i++)
    {
        A[i]=(double*)malloc(N*sizeof(double));
    }

    for(int i=0; i<N; i++)
    {
        printf("\n|%d|", i);
        for(int j=1; j<3; j++)
        {
            fread(&bin, sizeof(double), 1, file_bin);
            A[j][i] = bin;
            printf("\t|%.2lf\t| ", A[j][i]);
        }
    }
    getch();
    return 0;
}

double calculate(double x1){
return 0.25*pow(x1,5)+4*pow(x1+20,4)-2*x1;
}
