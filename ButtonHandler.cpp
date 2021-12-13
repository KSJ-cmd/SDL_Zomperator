#include"ButtonHandler.h"

#include"Cmd_Info.h"
#include"Cmd_SupplyProcess.h"
#include"Cmd_ProductProcess.h"
#include"Cmd_SwatProductProcess.h"
#include"Cmd_InvestmentProcess_Swat.h"
#include"Cmd_Turn.h"


#include"Playroom.h"
ButtonHandler::ButtonHandler() {
    std::unique_ptr<LoaderParams*> button_Turn = std::make_unique<LoaderParams*>(new LoaderParams(1302, 676, "Turn_over_0", "button_Turn"));
    Button* Turn = new Button(button_Turn, Vector2D((float)0.9, (float)0.9));
    Turn->setCommand(new Cmd_Turn(Turn));

    std::unique_ptr<LoaderParams*> button_event = std::make_unique<LoaderParams*>(new LoaderParams(51, 10, "event_icon_spr_0", "button_event"));
    Button* event = new Button(button_event, Vector2D((float)0.8, (float)0.8));

    std::unique_ptr<LoaderParams*> button_swat_commit = std::make_unique<LoaderParams*>(new LoaderParams(228, 10, "swat_put_icon_spr_0", "button_swat_commit"));
    Button* swat_commit = new Button(button_swat_commit, Vector2D((float)0.8, (float)0.8));
    swat_commit->setCommand(new Cmd_InvestmentProcess_Swat(swat_commit));

    std::unique_ptr<LoaderParams*> button_res_inf = std::make_unique<LoaderParams*>(new LoaderParams(405, 10, "inf_icon_spr_0", "button_res_inf"));
    Button* res_inf = new Button(button_res_inf, Vector2D((float)0.8, (float)0.8));
    res_inf->setCommand(new Cmd_Info());

    std::unique_ptr<LoaderParams*> button_swat_manager = std::make_unique<LoaderParams*>(new LoaderParams(228, 668, "swat_management_spr_0", "button_swat_manager"));
    Button* swat_manager = new Button(button_swat_manager, Vector2D((float)0.8, (float)0.8));
    swat_manager->setCommand(new Cmd_SwatProductProcess(swat_manager));

    std::unique_ptr<LoaderParams*> button_res_manager = std::make_unique<LoaderParams*>(new LoaderParams(43, 668, "sup_manage_0", "button_res_manager"));
    Button* res_manager = new Button(button_res_manager, Vector2D((float)0.8, (float)0.8));
    res_manager->setCommand(new Cmd_ProductProcess(res_manager));


    std::unique_ptr<LoaderParams*> Sup_wp = std::make_unique<LoaderParams*>(new LoaderParams(396, 656, "sup_wp_spr_0", "Sup_wp"));
    Button* sup_wp = new Button(Sup_wp, Vector2D((float)0.77, (float)0.79));
    sup_wp->setCommand(new Cmd_SupplyProcess(sup_wp));
    sup_wp->setSupplyType(SUPPLYTYPE::WP);
    sup_wp->SetProcessingTexture("wp_progressing_0");

    std::unique_ptr<LoaderParams*> Sup_fd = std::make_unique<LoaderParams*>(new LoaderParams(670, 656, "sup_fd_spr_0", "Sup_fd"));
    Button* sup_fd = new Button(Sup_fd, Vector2D((float)0.78, (float)0.79));
    sup_fd->setCommand(new Cmd_SupplyProcess(sup_fd));
    sup_fd->setSupplyType(SUPPLYTYPE::FD);
    sup_fd->SetProcessingTexture("fd_progressing_0");

    std::unique_ptr<LoaderParams*> Sup_md = std::make_unique<LoaderParams*>(new LoaderParams(945, 656, "sup_md_spr_0", "Sup_md"));
    Button* sup_md = new Button(Sup_md, Vector2D((float)0.78, (float)0.79));
    sup_md->setCommand(new Cmd_SupplyProcess(sup_md));
    sup_md->setSupplyType(SUPPLYTYPE::MD);
    sup_md->SetProcessingTexture("md_progressing_0");


}