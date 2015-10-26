#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

#ifndef ENIGMA_HPP
#define ENIGMA_HPP

class Enigma
{
private:
  // Stores rotors of Enigma machine
  vector<Rotor *> *p_rotors;
  // Enigma machine's plugboard
  Plugboard *p_plugboard;
  // Enigma machine's reflector
  Reflector *p_reflector;

public:
  Enigma();
  ~Enigma();
  // Set up already initialised plugboard
  void setPlugboard(Plugboard *p);
  // Set up initialised reflector
  void setReflector();
  // Add already initialised rotor to p_rotors
  void addRotor(Rotor *r);
  // Rotate the rotors in p_rotors when needed
  void rotateRotors();
  // Encrypts a letter
  void encrypt(int &letter);
};

#endif
