#include "Enigma.hpp"

Enigma::Enigma()
{
  rotors = new vector<Rotor *>;
}

Enigma::~Enigma()
{
  rotors->clear();
  delete rotors;
  delete plugboard;
  delete reflector;
}

void Enigma::setPlugboard(Plugboard *p)
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

void Enigma::rotateRotors()
{
  for (vector<Rotor *>::iterator it = rotors->begin(); it != rotors->end(); ++it)
  {
    (*it)->rotate();
    if ((it + 1) != rotors->end())
    {
      (*(it + 1))->adjustAfterRotation();
    }
    if (!(*it)->hasCompletedARevolution())
    {
      break;
    }
  }
}

void Enigma::encrypt(int &letter)
{
  plugboard->encode(letter);
  for (vector<Rotor *>::iterator it = rotors->begin(); it != rotors->end(); ++it)
  {
    (*it)->encode(letter);
  }
  reflector->encode(letter);
  for (vector<Rotor *>::reverse_iterator rit = rotors->rbegin(); rit != rotors->rend(); ++rit)
  {
    (*rit)->inverseEncode(letter);
  }
  plugboard->encode(letter);
  rotateRotors();
}
