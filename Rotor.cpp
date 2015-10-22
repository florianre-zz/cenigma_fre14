#include "Rotor.hpp"

const int lengthOfAlphabet = 26;

Rotor::Rotor(ifstream &file)
{
  setUp(file);
}

Rotor::~Rotor() {}

int &Rotor::getNumberOfRotations()
{
  return numberOfRotations;
}

void Rotor::setUp(ifstream &file)
{
  numberOfRotations = 0;
  int index = 0, encryptedIndex;
  while (file >> encryptedIndex)
  {
    insertInMapper(index++, encryptedIndex);
  }
}

void Rotor::encode(int &letter)
{
  letter = (letter + numberOfRotations) % 26;
  for (vector<pair<int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it) {
    if ((*it).first == letter)
    {
      letter = (*it).second;
      return;
    }
  }
}

void Rotor::inverseEncode(int &letter)
{
  cout << letter << " ";
  letter = (((letter - numberOfRotations) % 26) + 26) % 26;
  cout << letter << endl;
  for (vector<pair<int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it)
  {
    if ((*it).second == letter)
    {
      letter = (*it).first;
      return;
    }
  }
}


