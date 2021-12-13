#include"Cmd_SwatProductProcess.h"
#include"Cmd_Xbutton.h"
#include"Cmd_Investment_ReSource.h"

#include"SwatProductView.h"
#include"SwatProductViewModel.h"
#include"SwatProductData.h"
#include"SwatDataView.h"
#include"SwatRateView.h"

#include<memory>
Cmd_SwatProductProcess::Cmd_SwatProductProcess(Button* _button)
	:m_Button(_button)
{
}

Cmd_SwatProductProcess::~Cmd_SwatProductProcess()
{
}

void Cmd_SwatProductProcess::execute()
{
	std::unique_ptr<LoaderParams*> p_loader_bg = std::make_unique<LoaderParams*>(new LoaderParams(0, 0, 1600, 900, "", ""));
	std::unique_ptr<Button*> p_swatproduct_bg_button = std::make_unique<Button*>(new Button(p_loader_bg));

	std::unique_ptr<LoaderParams*> p_loader = std::make_unique<LoaderParams*>(new LoaderParams(446, 168, "swat_manage_bg_spr_0", "swat_manage_bg_spr_0"));
	std::unique_ptr<Button*> p_swatproduct_bg = std::make_unique<Button*>(new Button(p_loader));
	(*p_swatproduct_bg.get())->setScale(Vector2D(0.8, 0.8));

	SwatProductData* SwatData1 = new SwatProductData(INVESTMENT::WP);
	SwatProductData* SwatData2 = new SwatProductData(INVESTMENT::FD);
	SwatProductData* SwatData3 = new SwatProductData(INVESTMENT::MD);

	std::shared_ptr<SwatProductViewModel*> SwatViewModel = std::make_shared<SwatProductViewModel*>(new SwatProductViewModel());
	(*SwatViewModel)->DataInsert(SwatData1);
	(*SwatViewModel)->DataInsert(SwatData2);
	(*SwatViewModel)->DataInsert(SwatData3);

	std::unique_ptr<LoaderParams*> p_loader_swat_view1 = std::make_unique<LoaderParams*>(new LoaderParams(737, 339, "", ""));
	std::unique_ptr<SwatProductView*> p_swatProductView1 = std::make_unique<SwatProductView*>(new SwatProductView(p_loader_swat_view1, *SwatViewModel, INVESTMENT::WP));

	std::unique_ptr<LoaderParams*> p_loader_swat_view2 = std::make_unique<LoaderParams*>(new LoaderParams(737, 443, "", ""));
	std::unique_ptr<SwatProductView*> p_swatProductView2 = std::make_unique<SwatProductView*>(new SwatProductView(p_loader_swat_view2, *SwatViewModel, INVESTMENT::FD));

	std::unique_ptr<LoaderParams*> p_loader_swat_view3 = std::make_unique<LoaderParams*>(new LoaderParams(737, 549, "", ""));
	std::unique_ptr<SwatProductView*> p_swatProductView3 = std::make_unique<SwatProductView*>(new SwatProductView(p_loader_swat_view3, *SwatViewModel, INVESTMENT::MD));

	std::unique_ptr<LoaderParams*> p_loader_swatInvestment1 = std::make_unique<LoaderParams*>(new LoaderParams(964, 312, "swat_funding_spr_0", "swat_funding_spr_0"));
	std::unique_ptr<Button*> p_swatInvestment_button1 = std::make_unique<Button*>(new Button(p_loader_swatInvestment1));
	(*p_swatInvestment_button1.get())->setScale(Vector2D(0.8, 0.8));
	(*p_swatInvestment_button1.get())->setCommand(new Cmd_Investment_ReSource((*p_swatproduct_bg.get()), SwatData1));

	std::unique_ptr<LoaderParams*> p_loader_swatInvestment2 = std::make_unique<LoaderParams*>(new LoaderParams(964, 417, "swat_funding_spr_0", "swat_funding_spr_0"));
	std::unique_ptr<Button*> p_swatInvestment_button2 = std::make_unique<Button*>(new Button(p_loader_swatInvestment2));
	(*p_swatInvestment_button2.get())->setScale(Vector2D(0.8, 0.8));
	(*p_swatInvestment_button2.get())->setCommand(new Cmd_Investment_ReSource((*p_swatproduct_bg.get()), SwatData2));

	std::unique_ptr<LoaderParams*> p_loader_swatInvestment3 = std::make_unique<LoaderParams*>(new LoaderParams(964, 523, "swat_funding_spr_0", "swat_funding_spr_0"));
	std::unique_ptr<Button*> p_swatInvestment_button3 = std::make_unique<Button*>(new Button(p_loader_swatInvestment3));
	(*p_swatInvestment_button3.get())->setScale(Vector2D(0.8, 0.8));
	(*p_swatInvestment_button3.get())->setCommand(new Cmd_Investment_ReSource((*p_swatproduct_bg.get()), SwatData3));

	std::unique_ptr<LoaderParams*> p_loader_swatDataview = std::make_unique<LoaderParams*>(new LoaderParams(0, 0, "", ""));
	std::unique_ptr<SwatDataView*> p_swatDataview = std::make_unique<SwatDataView*>(new SwatDataView(p_loader_swatDataview));
	
	std::unique_ptr<LoaderParams*> p_loader_swatRateview = std::make_unique<LoaderParams*>(new LoaderParams(0, 0, "", ""));
	std::unique_ptr<SwatRateView*> p_swatRateview = std::make_unique<SwatRateView*>(new SwatRateView(p_loader_swatRateview));



	std::unique_ptr<LoaderParams*> p_loader_button_X = std::make_unique<LoaderParams*>(new LoaderParams(1113, 178, "X_but_0", "X_button"));
	std::unique_ptr<Button*> X_button = std::make_unique<Button*>(new Button(p_loader_button_X));
	Cmd_Xbutton* cmd_X = new Cmd_Xbutton(std::move(*X_button.get()));

	cmd_X->insertTarget(std::move(*p_swatproduct_bg_button.get()));
	cmd_X->insertTarget(std::move(*p_swatproduct_bg.get()));
	cmd_X->insertTarget(std::move(*p_swatProductView1.get()));
	cmd_X->insertTarget(std::move(*p_swatProductView2.get()));
	cmd_X->insertTarget(std::move(*p_swatProductView3.get()));
	cmd_X->insertTarget(std::move(*p_swatInvestment_button1.get()));
	cmd_X->insertTarget(std::move(*p_swatInvestment_button2.get()));
	cmd_X->insertTarget(std::move(*p_swatInvestment_button3.get()));
	cmd_X->insertTarget(std::move(*p_swatDataview.get()));
	cmd_X->insertTarget(std::move(*p_swatRateview.get()));

	(*X_button.get())->setCommand(cmd_X);

	std::cout << "SwatProduct create" << std::endl;
}
