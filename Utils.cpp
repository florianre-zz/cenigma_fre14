#include <assert.h>

#include "Utils.hpp"

int toInt(char c)
{
  assert(c >= 'A' && c <= 'Z' && "Error: need an upper case letter");
  return c - 'A';
}

char toChar(int c)
{
  assert(c >= 0 && c <= 25 && "Error: need an index between 0 and 25");
  return c + 'A';
}
