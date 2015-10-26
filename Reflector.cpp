#include "Reflector.hpp"

const int lengthOfAlphabet = 26;

Reflector::Reflector()
{
  // Creates a mapping from letters to there reflected letter
  for (int i = 0; i < lengthOfAlphabet; ++i)
  {
    insertInMapper(i, (i+lengthOfAlphabet/2)%lengthOfAlphabet);
  }
}

Reflector::~Reflector() {}

void Reflector::encode(int &letter)
{
  letter = p_mapper->at(letter).second;
}
