#include <stdio.h>
#include <assert.h>
#include "sum.h"

void testPow();
void testHalfAdder();
void testFullAdder();
void testBitSum();

int main() {
  testPow();
  testHalfAdder();
  testFullAdder();
  testBitSum();
  return 0;
}

void testPow() {
  int powersOf2[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };
  for (int i = 0; i < 10; ++i) {
    int output = pow(2, i);
    if (output != powersOf2[i]) {
      printf("%d %d\n", i, output);
      assert(0);
    }
  }
  printf("%s\n", "testPow is passed");
}

void testHalfAdder() {
  int inputs[4][2] = { {0,0}, {0,1}, {1,0}, {1,1} };
  int outputs[4][2] = { {0,0}, {0,1}, {0,1}, {1,0} };
  for (int i = 0; i < 4; ++i) {
    Result output = halfAdder(inputs[i][0], inputs[i][1]);
    int desiredSum = outputs[i][1];
    int desiredCarry = outputs[i][0];
    if (output.sum != desiredSum || output.carry != desiredCarry) {
      printf("WRONG: inputs %d %d\n", inputs[i][0], inputs[i][1]);
      assert(0);
    }
  }
  printf("%s\n", "testHalfAdder is passed");
}

void testFullAdder() {
  int inputs[8][3] = {
		      {0,0,0}, {0,0,1}, {0,1,0},
		      {0,1,1}, {1,0,0}, {1,0,1},
		      {1,1,0}, {1,1,1}
  };
  int outputs[8][2] = {
		       {0,0}, {0,1}, {0,1},
		       {1,0}, {0,1}, {1,0},
		       {1,0}, {1,1}
  };
  for (int i = 0; i < 8; ++i) {
    int *input = inputs[i];
    Result output = fullAdder(input[0], input[1], input[2]);
    int desiredSum = outputs[i][1];
    int desiredCarry = outputs[i][0];
    if (output.sum != desiredSum || output.carry != desiredCarry) {
      printf("WRONG: inputs %d %d\n", inputs[i][0], inputs[i][1]);
      assert(0);
    }
  }
  printf("%s\n", "testFullAdder is passed");
}

void testBitSum() {
  for (int i = 0; i < 30; ++i)
    for (int j = 0; j < 30; ++j) {
      int output = *bitsum(i, j);
      if (output != (i + j)) {
  	printf("WRONG: %d + %d != %d\n", i, j, output);
	assert(0);
      }
    }
  printf("%s\n", "testBitSum is passed");
}
