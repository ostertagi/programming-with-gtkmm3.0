#ifndef GTKMM_MESSAGETEXT_H
#define GTKMM_MESSAGETEXT_H

#include <gtkmm.h>

class MessageText : public Gtk::ScrolledWindow
{
  public:
    MessageText();
    virtual ~MessageText();

    void insert_text();

  protected:
    Gtk::TextView text_view;
};

#endif