#include "Rotor.hpp"

const int lengthOfAlphabet = 26;

Rotor::Rotor(ifstream &file)
{
  setUp(file);
}

Rotor::~Rotor() {}

int &Rotor::getNumberOfRevolutions()
{
  return numRevolutions;
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


void Rotor::rotate()
{
  ++numberOfRotations;
  if (numberOfRotations == 26) {
    ++numRevolutions;
    numberOfRotations = 0;
  }
}

void Rotor::adjustAfterRotation()
{
  for (vector<pair <int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it)
  {
    int &firstElemInPair = (*it).first;
    firstElemInPair = (firstElemInPair + 1)%26;
  }
}

void Rotor::encode(int &letter)
{
//  cout << "rotations: " << numberOfRotations << endl;
//  cout << "f: " << letter << " ";
  letter = (letter + numberOfRotations) % 26;
  //cout << letter << " ";
  for (vector<pair<int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it) {
    if ((*it).first == letter)
    {
      letter = (*it).second;
      //cout << letter << endl;
      return;
    }
  }
  //cout << letter << endl;
}

void Rotor::inverseEncode(int &letter)
{
  //cout << "f(-1): " << letter << " ";
  for (vector<pair<int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it)
  {
    if ((*it).second == letter)
    {
      letter = (*it).first;
      goto end;
    }
  }
  end:
  letter = (((letter - numberOfRotations) % 26) + 26) % 26;
  //cout << letter << endl;
  return;
}


