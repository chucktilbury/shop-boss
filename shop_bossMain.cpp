/***************************************************************
 * Name:      shop_bossMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Chuck Tilbury (chucktilbury@gmail.com)
 * Created:   2025-11-09
 * Copyright: Chuck Tilbury (https://charlestilbury.net)
 * License:
 **************************************************************/

#include "shop_bossMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(shop_bossDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(shop_bossDialog)
const long shop_bossDialog::ID_STATICTEXT1 = wxNewId();
const long shop_bossDialog::ID_BUTTON3 = wxNewId();
const long shop_bossDialog::ID_BUTTON1 = wxNewId();
const long shop_bossDialog::ID_STATICLINE1 = wxNewId();
const long shop_bossDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(shop_bossDialog,wxDialog)
    //(*EventTable(shop_bossDialog)
    //*)
END_EVENT_TABLE()

shop_bossDialog::shop_bossDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(shop_bossDialog)
    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxSize(289,142));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to\nwxWidgets"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(20);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StatusButton = new wxButton(this, ID_BUTTON3, _("Status"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StatusButton->SetHelpText(_("Display the system status"));
    BoxSizer2->Add(StatusButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AboutButton = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(AboutButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND, 4);
    QuitButton = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(QuitButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&shop_bossDialog::OnStatusButtonClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&shop_bossDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&shop_bossDialog::OnQuit);
    //*)
}

shop_bossDialog::~shop_bossDialog()
{
    //(*Destroy(shop_bossDialog)
    //*)
}

void shop_bossDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void shop_bossDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void shop_bossDialog::OnStatusButtonClick(wxCommandEvent& event)
{
    wxString msg = wxString("This is the system status button");
    wxMessageBox(msg, _("Status Button"));
}

