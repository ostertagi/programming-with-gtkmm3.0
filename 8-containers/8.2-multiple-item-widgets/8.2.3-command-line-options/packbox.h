#ifndef GTKMM_PACKBOX_H
#define GTKMM_PACKBOX_H

#include <gtkmm.h>

class PackBox : public Gtk::Box
{
  public:
    PackBox(bool homogeneous, int spacing, Gtk::PackOptions options, int padding = 0);
    virtual ~PackBox();

  protected:
    Gtk::Button btn1, btn2, btn3;
    Gtk::Button* pbtn4;
};

#endif