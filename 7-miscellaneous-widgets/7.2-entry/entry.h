#ifndef GTKMM_ENTRY_H
#define GTKMM_ENTRY_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>

class Entry : public Gtk::Window
{
  public:
    Entry();
    virtual ~Entry();

  protected:
    void on_checkbox_editable_toggled();
    void on_checkbox_visible_toggled();
    void on_button_close();

    Gtk::Box m_hbox, m_vbox;
    Gtk::Entry m_entry;
    Gtk::Button m_button_close;
    Gtk::CheckButton m_checkbutton_editable, m_checkbutton_visible;
};

#endif