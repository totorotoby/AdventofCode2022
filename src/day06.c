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

void p1()
{

  FILE* fin = fopen("../inputs/day06", "r");
  char* pack;
  
  fseek (fin, 0, SEEK_END);
  long length = ftell (fin);
  fseek (fin, 0, SEEK_SET);

  pack = (char*) malloc(sizeof(char) * length);
  fread(pack, sizeof(char), length, fin);

  int sub_len = 14;
  int idx = 0;
  int eq = 1;
  char* front = pack + sub_len - 1;
  
  for (int i = 0 ; i < length - sub_len; ++i){
    eq = check_equal(front, sub_len);
    if (eq == 0){
      idx = i + sub_len;
      break;
    }
    front++;
  }
  
  fclose(fin);
  
  printf("%d\n", idx);
  
}

void p2()
{

  FILE *fin = fopen("../inputs/day<>", "r");

  
  fclose(fin);

}

int main(){

  p1();
  p2();

}
