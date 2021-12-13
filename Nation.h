#pragma once
#include"SDLGameObject.h"
#include"Button.h"
#include"HpBar.h"
#include"HP.h"
#include"WP.h"
#include"MD.h"
#include"FD.h"
#include"Command.h"
#include"Observer.h"


enum class NATION
{
	GL = 1,
	NA,
	MA,
	SA,
	UR,
	AF,
	OS,
	AS
};

class Nation :public SDLGameObject,public IObserver {
public:
	Nation(const std::unique_ptr<LoaderParams*>& pParams, const Vector2D& position, const Vector2D& area);
	virtual ~Nation();
	virtual void update();
	virtual void draw();

	Hp* getHp() const;
	Weapon* getWp() const;
	Medicine* getMd() const;
	Food* getFd() const;
	Button* getButton() const;
	bool getAlive() const;

	void Recovery();
	void Alive();
	void Dead();

	virtual void Ability();

	virtual void setCommand(ICommand* _command);

	virtual void Observer_update();
	virtual void Observer_update(int _val);
private:
	Hp* m_Hp;
	Weapon* m_Wp;
	Medicine* m_Md;
	Food* m_Fd;

	Button* m_supButton;
	HpBar* m_Hpbar;
	Vector2D m_iconPosition;
	bool isAlive;
};



