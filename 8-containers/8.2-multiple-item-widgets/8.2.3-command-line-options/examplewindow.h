#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
  public:
    ExampleWindow(int which);
    virtual ~ExampleWindow();

  protected:
    // Signal handlers
    void on_button_quit_clicked();

    // Child widgets
    Gtk::Button btn, btn_quit;
    Gtk::Box box, box_quit;
    Gtk::Label lbl1, lbl2;
    Gtk::Separator sep;
};

#endif