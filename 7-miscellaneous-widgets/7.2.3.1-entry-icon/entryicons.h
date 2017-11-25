#ifndef GTKMM_ENTRYICONS_H
#define GTKMM_ENTRYICONS_H

#include <gtkmm.h>

class EntryIcons : public Gtk::Window
{
  public:
    EntryIcons();
    virtual ~EntryIcons();

  protected:
    void on_icon_pressed(Gtk::EntryIconPosition icon_pos, const GdkEventButton* event);
    void on_button_close();

    Gtk::Box m_vbox;
    Gtk::Entry m_entry;
    Gtk::Button m_button_close;
};

#endif