#pragma once
#include<string>
#include<vector>
#include"SDLGameObject.h"
#include"Command.h"
enum class SUPPLYTYPE : int
{
	DEFAULT = 0, WP, FD, MD
};

enum class BUTTONSTATE : int
{
	IDLE = 0, PROCESS = 1
};
class Button : public SDLGameObject {
public:
	
	Button(const std::unique_ptr<LoaderParams*>& pParams);
	Button(const std::unique_ptr<LoaderParams*>& pParams, Vector2D scale);
	Button(const Button& src);
	virtual ~Button();
	virtual void update();
	virtual void draw();

	virtual void TransTexture(BUTTONSTATE _state);

	virtual void OnClick();

	//Ŀ�ǵ� ����, Ŀ�ǵ�� ��� ��ü�� �и��� set���� Ŀ�ǵ弳���� ������ ��ü���� �������ش�.
	void setCommand(ICommand* _command);

	void SetProcessingTexture(std::string id);
	void setSupplyType(SUPPLYTYPE _Ty);
	SUPPLYTYPE getSupplyType() const;
private:
	ICommand* m_Command;
	std::string m_TextureIDs[2];
	BUTTONSTATE enum_state;
	SUPPLYTYPE enum_SupplyType;
};
