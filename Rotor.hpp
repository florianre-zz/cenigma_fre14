#include <fstream>

#include "Mapper.hpp"

#ifndef ROTOR_HPP
#define ROTOR_HPP

class Rotor : public Mapper
{
private:
  int numberOfRotations, numRevolutions;
public:
  Rotor(ifstream &file);
  ~Rotor();
  int &getNumberOfRevolutions();
  void setUp(ifstream &file);
  void rotate();
  void adjustAfterRotation();
  void encode(int &letter);
  void inverseEncode(int &letter);
};

#endif
