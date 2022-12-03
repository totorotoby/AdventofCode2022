#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(){

  FILE *fin = fopen("../inputs/day01", "r");
  char* cur_string = NULL;
  int cur_int;
  size_t buf_size = 8;
  int sum = 0;
  int max0 = 0;
  int max1 = 0;
  int max2 = 0;
  int err;
  
  while ((err = getline(&cur_string, &buf_size, fin)) != EOF)
    {
      if (isspace(*cur_string)){
	if (sum >= max0){
	  max2 = max1;
	  max1 = max0;
	  max0 = sum;
	}
	else if (sum >= max1){
	  max2 = max1;
	  max1 = sum;
	}
	else if(sum >= max2){
	  max2 = sum;
	}
	sum = 0;
      }
      else{
	sum += atoi(cur_string);
      }
    }
  
  printf("max0: %d max1: %d max2: %d\n", max0, max1, max2);
  printf("sum: %d\n", max0 + max1 + max2);
}
