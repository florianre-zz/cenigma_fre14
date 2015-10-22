#include <vector>
#include <iostream>

#ifndef MAPPER_HPP
#define MAPPER_HPP

using namespace std;

class Mapper
{
protected:
  vector<pair<int, int> >* p_mapper;
public:
  Mapper();
  ~Mapper();
  void insertInMapper(int letter, int encryptedLetter);
  virtual void encode(int& letter) =0;
};

#endif
