#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int contain_check(long* ranges)
{
  // second is contained in first
  if (ranges[0] <= ranges[2] && ranges[1] >= ranges[3])
    return 1;

  // first is contained in second
  if (ranges[0] >= ranges[2] && ranges[1] <= ranges[3])
    return 1;

  return 0;
}

int overlap_check(long* ranges)
{
  // first upper needs to be greater than second lower, but cannot pass all the way through so
  // that second upper is less than first lower
  if (ranges[1] >= ranges[2] && ranges[0] <= ranges[3]){
    return 1;
  return 0;
}

void parse_line(char* line, size_t line_len, long* ranges)
{
  
  char* p = line;
  int count = 0;
  
  while(*p){
    if (isdigit(*p))
      ranges[count] = strtol(p, &p, 10);
    else{
    ++p;
    ++count;
    }
  }
}

void p1p2()
{

  FILE *fin = fopen("../inputs/day04", "r");

  char* line = NULL;
  size_t buff_size = 32;
  size_t line_len;
  int total_contained = 0;
  int total_overlap = 0;

  long ranges[4];
  
  while((line_len = getline(&line, &buff_size, fin)) != EOF){
      parse_line(line, line_len, ranges);
      total_contained += contain_check(ranges);
      total_overlap += overlap_check(ranges);
  }
  
  printf("total contained: %d\n", total_contained);
  printf("total overlap: %d\n", total_overlap);
  
  fclose(fin);
}

int main(){
  p1p2();
}
