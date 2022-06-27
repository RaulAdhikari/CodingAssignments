#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void PrintArray(int ArrayToPrint[], int SizeAP)  
{  
 int i;  
  
 for (i = 0; i < SizeAP; i++)  
  {
  printf("\n%d\n", ArrayToPrint[i]);  
  }
  printf("\n\n\n");
}

void InsertionSort(int Array[], int Size)
{
  int i, key, j;
  
  for(j = 1; j < Size; j++)
  {
    key = Array[j];
    i = j - 1;
    while(i >= 0 && Array[i] > key)
    {
      Array[i + 1] = Array[i];
      i = i - 1;
            

    }
    Array[i + 1] = key;

  }
 
}

int ReadFileIntoArray(int argc,  char *argv[], int **AP)
{
  FILE *file = fopen(argv[1],"r");
    
  if(file == NULL)
  {
    printf("File Must be  provided on command line...exiting\n");
    exit(0);
  }

  int counter = 0;
  char c;
  char size[10];
  
  while(fgets(size,sizeof(size),file) != NULL)
  {
    counter++;
  }
  
  fseek(file,0,0);
  *AP = malloc(counter * sizeof(int));

  int i  = 0;
  while(fgets(size,sizeof(size),file) != NULL)
  {
    (*AP)[i] = atoi(size);
    i++;
  }
  
  return counter;
  free(AP);

}

int main(int argc, char *argv[])
{
  int* AP;
  clock_t start, end;
  int elements =  ReadFileIntoArray(argc, argv, &AP);
  
  #ifdef PRINT
  PrintArray(AP, elements); 
  #endif
  
  start = clock();
  InsertionSort(AP, elements);
  end = clock();

  printf("Insertion Sort Tics = %ld\n",end-start);
  #ifdef PRINT
  PrintArray(AP, elements);
  printf("Processed %d records\n",elements);
  #endif
  
  
  

  

    return 0;
}