#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void p1p2()
{
  FILE *fin = fopen("../inputs/day04", "r");

  char* line = NULL;
  size_t buff_size = 32;
  size_t line_len;
  int total_contained = 0;
  int total_overlap = 0;

  int r1low, r1high, r2low, r2high;
  
  while(fscanf(fin, "%d-%d,%d-%d", &r1low, &r1high, &r2low, &r2high) != EOF){
      // containment test
      if ((r1low <= r2low && r1high >= r2high) || (r1low >= r2low && r1high <= r2high))
	total_contained += 1;
      // overlap test
      if (r1high >= r2low && r1low <= r2high)
	total_overlap += 1;
  }
  
  printf("total contained: %d\n", total_contained);
  printf("total overlap: %d\n", total_overlap);
  fclose(fin);
}

int main(){
  p1p2();
}
