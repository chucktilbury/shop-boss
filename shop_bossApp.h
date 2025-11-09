/***************************************************************
 * Name:      shop_bossApp.h
 * Purpose:   Defines Application Class
 * Author:    Chuck Tilbury (chucktilbury@gmail.com)
 * Created:   2025-11-09
 * Copyright: Chuck Tilbury (https://charlestilbury.net)
 * License:
 **************************************************************/

#ifndef SHOP_BOSSAPP_H
#define SHOP_BOSSAPP_H

#include <wx/app.h>

class shop_bossApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // SHOP_BOSSAPP_H
