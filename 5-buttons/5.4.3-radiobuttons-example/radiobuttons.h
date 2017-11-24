#ifndef GTKMM_RADIOBUTTONS_H
#define GTKMM_RADIOBUTTONS_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/separator.h>

class RadioButtons : public Gtk::Window
{
  public:
    RadioButtons();
    virtual ~RadioButtons();

  protected:
    void on_button_clicked();

    Gtk::Box m_box_top, m_box1, m_box2;
    Gtk::RadioButton m_rb1, m_rb2, m_rb3;
    Gtk::Separator m_separator;
    Gtk::Button m_button_close;
};

#endif