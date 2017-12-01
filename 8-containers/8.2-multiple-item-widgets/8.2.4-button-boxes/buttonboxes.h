#ifndef GTKMM_BUTTONBOXES_H
#define GTKMM_BUTTONBOXES_H

#include <gtkmm.h>

class ButtonBoxes : public Gtk::Window
{
  public:
    ButtonBoxes();
    virtual ~ButtonBoxes();

  protected:
    void on_button_clicked();

    Gtk::Box vbox_main, vbox, hbox;
    Gtk::Frame frame_h, frame_v;
};

#endif