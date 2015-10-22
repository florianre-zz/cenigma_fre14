#include "Mapper.hpp"

#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

class Reflector: public Mapper
{
public:
  Reflector();
  void setUp();
  void swapWithEncryption(int &letter);
};


#endif
