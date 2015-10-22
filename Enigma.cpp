#include <iostream>

#include "Enigma.hpp"

Enigma::Enigma()
{
  rotors = new vector<Rotor*>;
}


Enigma::~Enigma()
{
  rotors->clear();
  delete plugboard;
  delete reflector;
}

void Enigma::setPlugboard(Plugboard* p)
{
  plugboard = p;
}

void Enigma::addRotor(Rotor* r)
{
  rotors->push_back(r);

}

void Enigma::setReflector()
{
  reflector = new Reflector();
}

Plugboard* Enigma::getPlugboard()
{
  return plugboard;
}

Reflector* Enigma::getReflector()
{
  return reflector;
}

vector<Rotor*>* Enigma::getRotors()
{
  return rotors;
}


void Enigma::encryptLetter(int &letter)
{
  plugboard->swapWithEncryption(letter);

  for (vector<Rotor*>::iterator it = rotors->begin(); it != rotors->end(); ++it)
  {
    (*it)->swapWithEncryption(letter);
  }

  reflector->swapWithEncryption(letter);

  for (vector<Rotor*>::reverse_iterator rit = rotors->rbegin(); rit != rotors->rend(); ++rit)
  {
    (*rit)->inverseSwapWithEncryption(letter);
  }

  plugboard->swapWithEncryption(letter);


}
