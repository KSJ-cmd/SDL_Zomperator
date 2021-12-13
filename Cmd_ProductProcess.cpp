#include<memory>
#include "Cmd_ProductProcess.h"
#include"Cmd_ProduceResource.h"
#include"Cmd_Xbutton.h"
#include"ProductView.h"
Cmd_ProductProcess::Cmd_ProductProcess(Button* _button)
	:m_Button(_button)
{
}

Cmd_ProductProcess::~Cmd_ProductProcess()
{
}

void Cmd_ProductProcess::execute()
{
	std::unique_ptr<LoaderParams*> p_loader_bg = std::make_unique<LoaderParams*>(new LoaderParams(0, 0,1600,900, "", ""));
	std::unique_ptr<Button*> p_product_bg_button= std::make_unique<Button*>(new Button(p_loader_bg));

	std::unique_ptr<LoaderParams*> p_loader = std::make_unique<LoaderParams*>(new LoaderParams(443, 194, "sup_product_BG_0", "sup_product_BG_0"));
	std::unique_ptr<Button*> p_product_bg = std::make_unique<Button*>(new Button(p_loader));
	(*p_product_bg.get())->setScale(Vector2D(0.8, 0.8));

	std::unique_ptr<LoaderParams*> p_loader1 = std::make_unique<LoaderParams*>(new LoaderParams(960, 280, "sup_production_0", "sup_production_0"));
	ProductData* productdata1 = new ProductData(100, PRODUCT_PRICE::WP);
	std::unique_ptr<ProductView*> p_product_wp = std::make_unique<ProductView*>(new ProductView(productdata1, p_loader1, Vector2D(900, 315), Vector2D(735, 315)));
	(*p_product_wp.get())->setScale(Vector2D(0.8, 0.8));
	(*p_product_wp.get())->setCommand(new Cmd_ProduceResource((*p_product_wp.get()), productdata1));

	std::unique_ptr<LoaderParams*> p_loader2 = std::make_unique<LoaderParams*>(new LoaderParams(960, 410, "sup_production_0", "sup_production_0"));
	ProductData* productdata2 = new ProductData(100, PRODUCT_PRICE::FD);
	std::unique_ptr<ProductView*> p_product_fd = std::make_unique<ProductView*>(new ProductView(productdata2, p_loader2, Vector2D(900, 444), Vector2D(735, 444)));
	(*p_product_fd.get())->setScale(Vector2D(0.8, 0.8));
	(*p_product_fd.get())->setCommand(new Cmd_ProduceResource((*p_product_fd.get()), productdata2));

	std::unique_ptr<LoaderParams*> p_loader3 = std::make_unique<LoaderParams*>(new LoaderParams(960, 540, "sup_production_0", "sup_production_0"));
	ProductData* productdata3 = new ProductData(100, PRODUCT_PRICE::MD);
	std::unique_ptr<ProductView*> p_product_md = std::make_unique<ProductView*>(new ProductView(productdata3, p_loader3, Vector2D(900, 573), Vector2D(735, 573)));
	(*p_product_md.get())->setScale(Vector2D(0.8, 0.8));
	(*p_product_md.get())->setCommand(new Cmd_ProduceResource((*p_product_md.get()), productdata3));

	std::unique_ptr<LoaderParams*> p_loader4 = std::make_unique<LoaderParams*>(new LoaderParams(494, 280, "sup_wp_spr_0", "sup_wp_spr_0"));
	std::unique_ptr<Button*> p_product_icon_wp = std::make_unique<Button*>(new Button(p_loader4));
	(*p_product_icon_wp.get())->setScale(Vector2D(0.8, 0.8));

	std::unique_ptr<LoaderParams*> p_loader5 = std::make_unique<LoaderParams*>(new LoaderParams(494, 410, "sup_fd_spr_0", "sup_fd_spr_0"));
	std::unique_ptr<Button*> p_product_icon_fd = std::make_unique<Button*>(new Button(p_loader5));
	(*p_product_icon_fd.get())->setScale(Vector2D(0.8, 0.8));

	std::unique_ptr<LoaderParams*> p_loader6 = std::make_unique<LoaderParams*>(new LoaderParams(494, 540, "sup_md_spr_0", "sup_md_spr_0"));
	std::unique_ptr<Button*> p_product_icon_md = std::make_unique<Button*>(new Button(p_loader6));
	(*p_product_icon_md.get())->setScale(Vector2D(0.8, 0.8));

	std::unique_ptr<LoaderParams*> p_loader_button_X = std::make_unique<LoaderParams*>(new LoaderParams(1106, 178, "X_but_0", "X_button"));
	std::unique_ptr<Button*> X_button = std::make_unique<Button*>(new Button(p_loader_button_X));
	Cmd_Xbutton* cmd_X = new Cmd_Xbutton(std::move(*X_button.get()));

	cmd_X->insertTarget(std::move(*p_product_bg_button.get()));
	cmd_X->insertTarget(std::move(*p_product_bg.get()));
	cmd_X->insertTarget(std::move(*p_product_wp.get()));
	cmd_X->insertTarget(std::move(*p_product_fd.get()));
	cmd_X->insertTarget(std::move(*p_product_md.get()));
	cmd_X->insertTarget(std::move(*p_product_icon_wp.get()));
	cmd_X->insertTarget(std::move(*p_product_icon_fd.get()));
	cmd_X->insertTarget(std::move(*p_product_icon_md.get()));
	(*X_button.get())->setCommand(cmd_X);
	
	std::cout << "ProductView create" << std::endl;
}
