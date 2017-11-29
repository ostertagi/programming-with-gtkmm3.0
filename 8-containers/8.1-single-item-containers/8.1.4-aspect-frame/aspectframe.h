#ifndef GTKMM_ASPECT_FRAME_H
#define GTKMM_ASPECT_FRAME_H

#include <gtkmm.h>

class AspectFrame : public Gtk::Window
{
  public:
    AspectFrame();
    virtual ~AspectFrame();

  protected:
    Gtk::AspectFrame aframe;
    Gtk::DrawingArea area;
};

#endif