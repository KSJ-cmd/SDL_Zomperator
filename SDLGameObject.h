#ifndef __SDLGAMEOBJECT_H__
#define __SDLGAMEOBJECT_H__
#include"GameObject.h"
#include"Vector2D.h"
class SDLGameObject : public GameObject{
public:
  SDLGameObject(const std::unique_ptr<LoaderParams*>& pParams);
  SDLGameObject(const std::unique_ptr<LoaderParams*>& pParams,Vector2D scale);
  SDLGameObject(const SDLGameObject& src);
  virtual void draw();
  virtual void update();
  virtual void clean(){};
  virtual ~SDLGameObject(){}

  virtual void collision(SDLGameObject* collision) {};
  virtual bool check_collision(const SDLGameObject& A, const SDLGameObject& B);
  virtual bool check_collision_X(const SDLGameObject& A, const SDLGameObject& B);
  virtual bool check_collision_Y(const SDLGameObject& A, const SDLGameObject& B);
  virtual bool check_collision_camera();
  virtual bool check_collision_mouse(const Vector2D& mousePosition);
  virtual void move(SDLGameObject& wall);

  void setScale(Vector2D vector);

  std::string getTag() const;
  bool getActive() const;
  void Active();
  void InActive();

  bool getDestroy() const;
  void Destroy();
  
protected:
  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;
  Vector2D m_Scale;

  int m_width = 0;
  int m_height = 0;
  int m_currentRow = 0;
  int m_currentFrame = 0;

  std::string m_textureID = "";
  std::string m_tag = "";

  bool isActive = false;
  bool isDestroy = false;
};

#endif
