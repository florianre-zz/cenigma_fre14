#include "fstream"
#include "Mapper.hpp"

#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

class Plugboard : public Mapper
{
public:
  Plugboard(ifstream& file);
  void setUp(ifstream& file);
  void swapWithEncryption(int &letter);
};

#endif
