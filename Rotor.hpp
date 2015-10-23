#include <fstream>

#include "Mapper.hpp"

#ifndef ROTOR_HPP
#define ROTOR_HPP

class Rotor : public Mapper
{
private:
  int numberOfRotations, numRevolutions;
  bool revolutionCompleted;
public:
  Rotor(ifstream &file);
  ~Rotor();
  void setUp(ifstream &file);
  void rotate();
  bool hasCompletedARevolution();
  void adjustAfterRotation();
  void encode(int &letter);
  void inverseEncode(int &letter);
};

#endif
