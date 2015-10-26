#include "Mapper.hpp"

#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

class Reflector: public Mapper
{
public:
  Reflector();
  ~Reflector();
  void encode(int &letter);
};

#endif
