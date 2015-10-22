#include "Plugboard.hpp"

Plugboard::Plugboard(ifstream& file)
{
  setUp(file);
}

Plugboard::~Plugboard() {}

void Plugboard::setUp(ifstream &file)
{
  int from, to;
  while (file >> from >> to) {
    insertInMapper(from, to);
  }
}

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
