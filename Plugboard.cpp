#include "Plugboard.hpp"

Plugboard::Plugboard(ifstream& file)
{
  // Reads indices from file in pairs (pair consists of letters to be swapped) and inserts the pair in the mapper
  int from, to;
  while (file >> from >> to)
  {
    insertInMapper(from, to);
  }
}

Plugboard::~Plugboard() {}

void Plugboard::encode(int &letter)
{
  for (vector<pair<int, int> >::iterator it = p_mapper->begin(); it != p_mapper->end(); ++it)
  {
    if ((*it).first == letter)
    {
      letter = (*it).second;
      return;
    } else if ((*it).second == letter)
    {
      letter = (*it).first;
      return;
    }
  }
}
