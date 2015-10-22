#include <iostream>

#include "Mapper.hpp"

Mapper::Mapper() {
  p_mapper = new vector<pair <int, int> >;
}

Mapper::~Mapper()
{
  p_mapper->clear();
}

void Mapper::insertInMapper(int letter, int encryptedLetter)
{
  p_mapper->push_back(pair<int, int> (letter, encryptedLetter));
}
