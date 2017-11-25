#ifndef GTKMM_ENTRYPROGRESS_H
#define GTKMM_ENTRYPROGRESS_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>

class EntryProgress : public Gtk::Window
{
  public:
    EntryProgress();
    virtual ~EntryProgress();

  protected:
    bool on_timeout();
    void on_button_close();

    Gtk::Box m_vbox;
    Gtk::Entry m_entry;
    Gtk::Button m_button_close;
};

#endif