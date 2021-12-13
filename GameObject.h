#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include"LoaderParams.h"
#include<memory>
class GameObject{
public:
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void clean() = 0;
  virtual ~GameObject(){}
protected:
  GameObject(const std::unique_ptr<LoaderParams*>& pParams){}
};
#endif