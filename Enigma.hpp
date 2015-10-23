#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

#ifndef ENIGMA_HPP
#define ENIGMA_HPP

class Enigma
{
private:
  vector<Rotor *> *rotors;
  Plugboard *plugboard;
  Reflector *reflector;

public:
  Enigma();
  ~Enigma();
  void setPlugboard(Plugboard *p);
  void setReflector();
  void addRotor(Rotor *r);
  void rotateRotors();
  void encrypt(int &letter);
};

#endif
