#include "iostream"
#include "Rotor.hpp"

const int lengthOfAlphabet = 26;

Rotor::Rotor(ifstream& file) {
  setUp(file);
}

void Rotor::setUp(ifstream& file)
{
  int index = 0, encryptedIndex;
  while (file >> encryptedIndex)
  {
    insertInMapper(index++, encryptedIndex);
  }
}

void Rotor::swapWithEncryption(int &letter)
{
  for (vector<pair<int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it) {
    if ((*it).first == letter)
    {
      letter = (*it).second;
      return;
    }
  }
}

void Rotor::inverseSwapWithEncryption(int &letter)
{
  for (vector<pair<int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it)
  {
    if ((*it).second == letter)
    {
      letter = (*it).first;
      return;
    }
  }
}


