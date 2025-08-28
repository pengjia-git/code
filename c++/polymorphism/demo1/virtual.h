#ifndef __VIRTUAL_H__
#define __VIRTUAL_H__

#include <string>

class CAnimal {
public:
  CAnimal(std::string);
  std::string getName();
  // virtual void sound();
  void sound();

private:
  std::string mName;
};

class CDog : public CAnimal {
public:
  CDog(std::string);
  void sound();
};

class CCat : public CAnimal {
public:
  CCat(std::string);
  void sound();
};
#endif
