#include <stdlib.h>

typedef struct AdderOutput Result;

struct AdderOutput
{
  int sum;
  int carry;
};

Result halfAdder(int first, int second);
Result fullAdder(int first, int second, int third);

int *bitsum(int first, int second);
int pow(int num, int exp);
