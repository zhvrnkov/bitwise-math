#include "sum.h"

Result halfAdder(int first, int second) {
  struct AdderOutput output;
  output.sum = first ^ second;
  output.carry = first & second;
  return output;
}

Result fullAdder(int first, int second, int third) {
  Result output;
  Result op1 = halfAdder(first, second);
  Result op2 = halfAdder(op1.sum, third);
  
  output.sum = op2.sum;
  output.carry = op1.carry || op2.carry;
  return output;
}

int pow(int num, int exp) {
  int base = num;
  if (exp == 0) return 1;
  for (int i = 2; i <= exp; ++i)
    num *= base;
  return num;
}

int numberOfBits(int num) {
  int output = 0;
  while(num) {
    num = num >> (++output);
  }
  return output;
}

int *bitsum(int first, int second) {
  int *output = (int *)malloc(sizeof(int));
  *output = 0;
  int carry = 0;
  
  for (int i = 0; i < sizeof(int) * 8; ++i) {
    int firstShifted = first >> i;
    int secondShifted = second >> i;    
    int bitOfFirst = firstShifted & 1;
    int bitOfSecond = secondShifted & 1;
    Result
      result = fullAdder(bitOfFirst, bitOfSecond, carry);
    carry = result.carry;

    *output |= result.sum << i;
  }

  return output;
}
