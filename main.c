#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  int i;
  SHA_CTX c;
  unsigned char md[SHA_DIGEST_LENGTH];

  if (argc != 2) {
    return 0;
  }

  SHA1_Init(&c);
  SHA1_Update(&c, argv[1], (unsigned long)strlen(argv[1]));
  SHA1_Final(&(md[0]), &c);

  for (i = 0; i < SHA_DIGEST_LENGTH; i++) {
    printf("%02x", md[i]);
  }
  printf("\n");

  return 0;
}
