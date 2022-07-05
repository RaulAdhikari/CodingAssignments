/* 
1001691078
rxa1078
*/
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
  

}
void merge(int arr[], int left, int middle, int right) 
{ 
    //part 1
    int i, j, k; 
    int n1 = middle - left + 1; 
    int n2 = right - middle; 
    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    
    for (j = 0; j < n2; j++) 
        R[j] = arr[middle + 1 + j];

    //part 2
    i = 0;
    j = 0; 
    k = left;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
    
        k++; 

    } 
    //part 3
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
} 

void mergeSort(int arr[], int L, int R) 
{ 
    if (L < R) 
    { 
        int M = (L+R)/2; 
        mergeSort(arr, L, M); 
        mergeSort(arr, M+1, R); 
        merge(arr, L, M, R); 
    } 
} 

int main(int argc, char *argv[])
{
    int* AP;
    clock_t start, end, start1, end1;
    int elements =  ReadFileIntoArray(argc, argv, &AP);
  
    //PrintArray(AP, elements); 
    #ifdef PRINTARRAY
    PrintArray(AP, elements); 
    #endif
 
    start1 = clock();
    mergeSort(AP, 0, elements-1);  
    end1 = clock();  
  
    #ifdef PRINTARRAY
    PrintArray(AP, elements); 
    #endif  

    free(AP); //freeing array
    
    AP = NULL; //pointing it to null
    elements =  ReadFileIntoArray(argc, argv, &AP); //finding the count of array.

    #ifdef PRINTARRAY
    PrintArray(AP, elements); // printing the unsorted array.
    #endif  
    
    start = clock();  
    InsertionSort(AP, elements);
    end = clock();

    #ifdef PRINTARRAY
    PrintArray(AP, elements);
    #endif
  
    free(AP);
    printf("Processed %d records\n",elements);
    printf("Merge Sort     = %ld\n",end1-start1);
    printf("Insertion Sort = %ld\n",end-start);

    return 0;
    

}