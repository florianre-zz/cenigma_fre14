#include <fstream>

#include "Mapper.hpp"

#ifndef ROTOR_HPP
#define ROTOR_HPP

class Rotor : public Mapper
{
private:
  int numberOfRotations;
  bool revolutionCompleted;
public:
  Rotor(ifstream &file);
  ~Rotor();
  // Turns rotor by one and checks if a full revolution has been completed
  void rotate();
  // Return true if revolution completed
  bool hasCompletedARevolution();
  // Shifts original indices (i.e. first element of the pairs in the mapper) by 1
  void adjustAfterRotation();
  void encode(int &letter);
  // Encodes the input letter when going through rotors for the second time
  void inverseEncode(int &letter);
};

#endif
