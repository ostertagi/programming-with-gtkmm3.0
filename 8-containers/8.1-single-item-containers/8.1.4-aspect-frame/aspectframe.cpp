#include "aspectframe.h"

AspectFrame::AspectFrame() :
  /* label, center x, center y, x/y = 2, ignore child's aspect */
  aframe("2x1", Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER, 2.0, false)
{
  set_title("Gtk::AspectFrame");
  set_border_width(10);

  /* Adds a child to the frame of size 200 x 200, but 200 x 100 will be shown */
  area.set_size_request(200, 200);
  aframe.add(area);

  add(aframe);

  show_all_children();
}

AspectFrame::~AspectFrame()
{}