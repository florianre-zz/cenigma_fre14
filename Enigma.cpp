#include <iostream>

#include "Enigma.hpp"
#include "Utils.hpp"

Enigma::Enigma()
{
  rotors = new vector<Rotor*>;
}

Enigma::~Enigma()
{
  rotors->clear();
  delete rotors;
  delete plugboard;
  delete reflector;
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

void Enigma::setPlugboard(Plugboard* p)
{
  plugboard = p;
}

void Enigma::setReflector()
{
  reflector = new Reflector();
}

void Enigma::addRotor(Rotor* r)
{
  rotors->push_back(r);

}

void Enigma::rotate()
{
  for (vector<Rotor*>::iterator it = rotors->begin(); it != rotors->end(); ++it)
  {
    (*it)->getNumberOfRotations() = ((*it)->getNumberOfRotations() + 1)%26;
    if ((*it)->getNumberOfRotations() != 26)
    {
      break;
    }
  }
}

void Enigma::encryptLetter(int &letter)
{
  rotate();
  plugboard->encode(letter);
  for (vector<Rotor*>::iterator it = rotors->begin(); it != rotors->end(); ++it)
  {
    (*it)->encode(letter);
  }
  reflector->encode(letter);
  for (vector<Rotor*>::reverse_iterator rit = rotors->rbegin(); rit != rotors->rend(); ++rit)
  {
    (*rit)->inverseEncode(letter);
  }
  plugboard->encode(letter);
}


void Enigma::encryptMessage(string &message)
{
  for (int i = 0; i < message.size(); i++) {
    if (message.at(i) != ' ')
    {
      int indexInAlp = toInt(message.at(i));
      encryptLetter(indexInAlp);
      message.at(i) = toChar(indexInAlp);
    }
  }
}
