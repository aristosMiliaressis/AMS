#include "misc.h"

#include <string.h>
#include <ctype.h>


static long partition(int arr[], int lo, int hi);
static void swap(int *first, int *second);


void quicksort(int arr[], int lo, int hi)
{
  int p;
  if (lo < hi)
  {
    p = partition(&arr[0], lo, hi);
    quicksort(&arr[0], lo, p - 1);
    quicksort(&arr[0], p + 1, hi);
  }
}


static long partition(int arr[], int lo, int hi)
{
  int i, pivotIndex, pivotValue;

  pivotValue = arr[hi];
  pivotIndex = lo;

  for (i = lo; i <= hi - 1; i++)
  {
    if (arr[i] <= pivotValue)
    {
      swap(&arr[pivotIndex], &arr[i]);
      pivotIndex++;
    }
  }

  swap(&arr[pivotIndex], &arr[hi]);
  return pivotIndex;
}


static void swap(int *first, int *second)
{
  int tmp = *first;
  *first = *second;
  *second = tmp;
}


size_t removeDuplicate(char *arr[], size_t nmemb)
{
  char **current, **end = arr + nmemb - 1;
  size_t count = 0;

  for (current = arr + 1; arr < end; arr++, current = arr + 1)
  {
    while (current <= end)
    {
      if (!strcmp(*current, *arr))
      {
        strcpy(*current, *end);
        end--;
      }
      else
      {
        current++;
      }
    }
    count++;
  }

  return count;
}


bool csvReadNextVal(FILE* fp, char* dest)
{
  size_t i = 0;
  char ch;

  while (!feof(fp))
  {
    ch = fgetc(fp);
    if (ch == ',')
    {
      dest[i] = '\0';
      return true;
    }
    dest[i] = ch;
    i++;
  }

  return false;
}


size_t getString(char* dest, size_t size)
{
  size_t len;
	
  fflush(stdin);
  fgets(dest, size, stdin);
  len = strlen(dest);
	
  if (len == size - 1)
    getchar();
    
  /* Remove Line Feed Character */
  if (dest[strlen(dest)-1] == '\n')
  {
    dest[strlen(dest)-1] = '\0';
    len--;
  }
	
  return len;
}


bool isIntBetween(char* src, int min, int max)
{
  size_t i;	
	
  /* Test if all characters are digits */
  for(i = 0; i < strlen(src); i++)
    if (!isdigit(*(src + i)))
      return false;

  /* Test if value is within min/max range */
  if (atoi(src) < min || atoi(src) > max)
    return false;
	
  return true;
}


void parseWhiteSpace(char* str)
{
  size_t i = 0;
  char ch;
  
  do {
    ch = str[i];
    if (ch == ' ' || ch == '\t' || ch == '\n') 
    {
      size_t j;
      for (j = i; j < strlen(str); j++)
        str[j] = str[j+1];
    }
    else i++;
  } while (ch != '\0');
}


void fatal(char* errMsg)
{
  fprintf(stderr, "\n\n\t\tFailed while %s!", errMsg);
  perror("\n\t\tERROR");
  printf("\n\t\tPress [Enter] to Exit..");
  getchar();

  clearScreen();
  exit(EXIT_FAILURE);
}


void clearScreen(void)
{
  printf("\033[H\033[2J");
}


void strToUpper(char* str)
{
  size_t i;
  for (i = 0; i < strlen(str); i++)
    str[i] = toupper(str[i]);
}