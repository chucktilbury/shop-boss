/***************************************************************
 * Name:      shop_bossMain.h
 * Purpose:   Defines Application Frame
 * Author:    Chuck Tilbury (chucktilbury@gmail.com)
 * Created:   2025-11-09
 * Copyright: Chuck Tilbury (https://charlestilbury.net)
 * License:
 **************************************************************/

#ifndef SHOP_BOSSMAIN_H
#define SHOP_BOSSMAIN_H

//(*Headers(shop_bossDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class shop_bossDialog: public wxDialog
{
    public:

        shop_bossDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~shop_bossDialog();

    private:

        //(*Handlers(shop_bossDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnStatusButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(shop_bossDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON3;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(shop_bossDialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* AboutButton;
        wxButton* QuitButton;
        wxButton* StatusButton;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SHOP_BOSSMAIN_H
