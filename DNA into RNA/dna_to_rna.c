#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *RNA_Transcription(char *alphabet) {

  int i;

  for(i = 0; *(alphabet + i) != 0; ++i) {
  

    if(alphabet[i] == 'T') {
      alphabet[i] = 'U';
    }
  
  }
  return alphabet;
}


int main() {
  int i;

  char m[] = {"GATGGAACTTGACTACGTAAATT"};  

  printf("%s \n", RNA_Transcription(m));
  
  FILE *fp;
  size_t count;
  
  char const *str = RNA_Transcription(m);
  

  fp = fopen("1.txt", "wb");
  if(fp == NULL) {
      perror("ошибка открытия файла");
      return 0;
  }
  count = fwrite(str, strlen(str), 1, fp);
  fclose(fp);

 return 0;
}