#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int check_equal(char* front, int sub_len)
{
  for (int i = 0 ; i < sub_len - 1 ; ++i){
    for (int j = i + 1 ; j < sub_len ; ++j){
      if (*(front - i) == *(front - j)){
	return 1;
      }
    }
  }
  return 0;
}

void p1p2()
{

  FILE* fin = fopen("../inputs/day06", "r");
  char* pack;
  
  fseek (fin, 0, SEEK_END);
  long length = ftell (fin);
  fseek (fin, 0, SEEK_SET);

  pack = (char*) malloc(sizeof(char) * length);
  fread(pack, sizeof(char), length, fin);

  int sub_len0 = 4;
  int sub_len1 = 14;
  int eq0 = 1;
  int eq1 = 1;
  int first0 = 0;
  int first1 = 0;
  char* front0 = pack + sub_len0 - 1;
  char* front1 = pack + sub_len1 - 1;
  
  for (int i = 0 ; i < length - sub_len0; ++i){
    eq0 = check_equal(front0, sub_len0);
    eq1 = check_equal(front1, sub_len1);
    if (eq0 == 0 && first0 == 0){
      printf("len 4 first no repeats: %d\n", i + sub_len0);
      first0 = 1;
    }
    if (eq1 == 0 && first1 == 0){
      printf("len 14 first no repeats: %d\n", i + sub_len1);
      first1 = 1;
    }
    front0++;
    front1++;
  }
  fclose(fin);
}

int main(){

  p1p2();

}
