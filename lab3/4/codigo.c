#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *fn = "/tmp/output";
  char conteudo[201];
  FILE *fp;
  scanf("%200s", conteudo);
  if (!access(fn, W_OK)) {
    fp = fopen(fn, "a+");
    fwrite(conteudo, sizeof(char), strlen(conteudo), fp);
    fclose(fp);
  } else {
    printf("Sem permiss˜ao de escrita no arquivo.\n");
  }
  return 0;
}