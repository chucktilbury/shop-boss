/***************************************************************
 * Name:      shop_bossApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Chuck Tilbury (chucktilbury@gmail.com)
 * Created:   2025-11-09
 * Copyright: Chuck Tilbury (https://charlestilbury.net)
 * License:
 **************************************************************/

#include "shop_bossApp.h"

//(*AppHeaders
#include "shop_bossMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(shop_bossApp);

bool shop_bossApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        shop_bossDialog Dlg(0);
        SetTopWindow(&Dlg);
        Dlg.ShowModal();
        wxsOK = false;
    }
    //*)
    return wxsOK;

}
