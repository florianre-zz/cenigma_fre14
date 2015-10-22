#include <fstream>

#include "Mapper.hpp"

#ifndef ROTOR_HPP
#define ROTOR_HPP

class Rotor : public Mapper

{
public:
  Rotor(ifstream& file);
  void setUp(ifstream& file);
  void swapWithEncryption(int &letter);
  void inverseSwapWithEncryption(int &letter);
};

#endif
