#include"Button.h"
#include"Playroom.h"



Button::Button(const std::unique_ptr<LoaderParams*>& pParams)
	:SDLGameObject(pParams)
	, m_Command(nullptr)
	, m_TextureIDs()
	, enum_state(BUTTONSTATE::IDLE)
	, enum_SupplyType(SUPPLYTYPE::DEFAULT)
{
	m_TextureIDs[(int)BUTTONSTATE::IDLE] = m_textureID;
	Playroom::getButtons().push_back(this);
}

Button::Button(const std::unique_ptr<LoaderParams*>& pParams, Vector2D scale)
	: SDLGameObject(pParams, scale)
	, m_Command(nullptr)
	, m_TextureIDs()
	, enum_state(BUTTONSTATE::IDLE)
	, enum_SupplyType(SUPPLYTYPE::DEFAULT)
{
	m_TextureIDs[(int)BUTTONSTATE::IDLE] = m_textureID;
	Playroom::getButtons().push_back(this);
}

Button::Button(const Button& src)
	:SDLGameObject(src)
	, m_Command(nullptr)
	, m_TextureIDs()
	, enum_state(BUTTONSTATE::IDLE)
	, enum_SupplyType(SUPPLYTYPE::DEFAULT)
{
	m_TextureIDs[(int)BUTTONSTATE::IDLE] = m_textureID;
	Playroom::getButtons().push_back(this);
}
Button::~Button()
{
	delete m_Command;
	std::cout << "Button delete" << std::endl;
	Playroom::getButtons().remove(this);
}



void Button::update(){
}
void Button::draw() {
	SDLGameObject::draw();
}

void Button::TransTexture(BUTTONSTATE _state)
{
	m_textureID = m_TextureIDs[(int)_state];
}


void Button::OnClick()
{
	if (m_Command != nullptr) {
		m_Command->execute();
	}
}

void Button::setCommand(ICommand* _command)
{
	if (m_Command != nullptr) {
		delete m_Command;
		m_Command = nullptr;
	}
	m_Command = _command;
}



void Button::SetProcessingTexture(std::string id)
{
	m_TextureIDs[(int)BUTTONSTATE::PROCESS] = id;
}

void Button::setSupplyType(SUPPLYTYPE _Ty)
{
	enum_SupplyType = _Ty;
}

SUPPLYTYPE Button::getSupplyType() const
{
	return enum_SupplyType;
}

