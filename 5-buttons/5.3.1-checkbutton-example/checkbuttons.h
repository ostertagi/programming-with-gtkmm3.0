#ifndef GTKMM_CHECKBUTTONS_H
#define GTKMM_CHECKBUTTONS_H

#include "gtkmm/window.h"
#include "gtkmm/checkbutton.h"

class CheckButtons : public Gtk::Window
{
  public:
    CheckButtons();
    virtual ~CheckButtons();
  
  protected:
    void on_button_clicked();
    Gtk::CheckButton m_check_button;
};

#endif