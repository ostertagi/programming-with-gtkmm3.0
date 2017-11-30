#ifndef GTKMM_HELLOWORLD_H
#define GTKMM_HELLOWORLD_H

#include <gtkmm.h>

class HelloWorld : public Gtk::Window
{
  public:
    HelloWorld();
    virtual ~HelloWorld();

  protected:
    void on_button_clicked(Glib::ustring data);

    Gtk::Box box;
    Gtk::Button btn1, btn2;
};

#endif