#include <vector>

#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

#ifndef ENIGMA_HPP
#define ENIGMA_HPP

using namespace std;

class Enigma
{
private:
  vector<Rotor*>* rotors;
  Plugboard* plugboard;
  Reflector* reflector;

public:
  Enigma();
  ~Enigma();
  void setPlugboard(Plugboard* p);
  void setReflector();
  Plugboard* getPlugboard();
  vector<Rotor*>* getRotors();
  Reflector* getReflector();
  void addRotor(Rotor* r);
  void encryptLetter(int& letter);
};


#endif
