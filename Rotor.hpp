#include <fstream>

#include "Mapper.hpp"

#ifndef ROTOR_HPP
#define ROTOR_HPP

class Rotor : public Mapper
{
private:
  int numberOfRotations;
public:
  Rotor(ifstream &file);
  ~Rotor();
  int &getNumberOfRotations();
  void setUp(ifstream &file);
  void encode(int &letter);
  void inverseEncode(int &letter);
};

#endif
