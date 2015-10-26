#include <fstream>

#include "Mapper.hpp"

#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

class Plugboard : public Mapper
{
public:
  Plugboard(ifstream &file);
  ~Plugboard();
  void encode(int &letter);
};

#endif
