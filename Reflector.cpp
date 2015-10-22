#include "Reflector.hpp"

const int lengthOfAlphabet = 26;

Reflector::Reflector() {
  setUp();
}

void Reflector::setUp()
{
  for (int i = 0; i < lengthOfAlphabet; ++i)
  {
    insertInMapper(i, (i+lengthOfAlphabet/2)%lengthOfAlphabet);
  }
}

void Reflector::swapWithEncryption(int &letter)
{
  letter = p_mapper->at(letter).second;
}
