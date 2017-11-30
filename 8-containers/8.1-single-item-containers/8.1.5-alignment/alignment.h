#ifndef GTKMM_ALIGNMENT_H
#define GTKMM_ALIGNMENT_H

#include <gtkmm.h>

class Alignment : public Gtk::Window
{
  public:
    Alignment();
    virtual ~Alignment();

  protected:
    void on_button_clicked();
    
    Gtk::Button btn;
};

#endif