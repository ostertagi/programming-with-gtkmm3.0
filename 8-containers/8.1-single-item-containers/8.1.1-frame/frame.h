#ifndef GTKM_FRAME_H
#define GTKM_FRAME_H

#include <gtkmm/window.h>
#include <gtkmm/frame.h>

class Frame : public Gtk::Window
{
  public:
    Frame();
    virtual ~Frame();

  protected:
    Gtk::Frame frame;
};

#endif