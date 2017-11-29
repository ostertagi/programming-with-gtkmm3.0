#ifndef GTKMM_SCROLLEDWINDOW_H
#define GTKMM_SCROLLEDWINDOW_H

#include <gtkmm.h>

class ScrolledWindow : public Gtk::Dialog
{
  public:
    ScrolledWindow();
    virtual ~ScrolledWindow();

  protected:
    void on_dialog_response(int id);

    Gtk::ScrolledWindow window;
    Gtk::Grid grid;
};

#endif