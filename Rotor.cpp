#include "Rotor.hpp"

const int lengthOfAlphabet = 26;

Rotor::Rotor(ifstream &file)
{
  // Initialises rotor rotation and connects the original letter to its encryption
  numberOfRotations = 0;
  revolutionCompleted = false;
  int index = 0, encryptedIndex;
  while (file >> encryptedIndex)
  {
    insertInMapper(index++, encryptedIndex);
  }
}

Rotor::~Rotor() {}

void Rotor::rotate()
{
  if (++numberOfRotations == lengthOfAlphabet)
  {
    revolutionCompleted = true;
    numberOfRotations = 0;
  } else {
    revolutionCompleted = false;
  }
}

bool Rotor::hasCompletedARevolution()
{
  return revolutionCompleted;
}

void Rotor::adjustAfterRotation()
{
  for (vector<pair <int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it)
  {
    (*it).first = ((*it).first + 1)%lengthOfAlphabet;
  }
}

void Rotor::encode(int &letter)
{
  letter = (letter + numberOfRotations) % lengthOfAlphabet;
  for (vector<pair<int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it)
  {
    if ((*it).first == letter)
    {
      letter = (*it).second;
      return;
    }
  }
}

void Rotor::inverseEncode(int &letter)
{
  for (vector<pair<int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it)
  {
    if ((*it).second == letter)
    {
      letter = (*it).first;
      goto end;
    }
  }
  end:
  letter = ((letter - numberOfRotations) % lengthOfAlphabet + lengthOfAlphabet) % lengthOfAlphabet;
  return;
}