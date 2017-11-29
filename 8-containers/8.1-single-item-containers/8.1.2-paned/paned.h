#ifndef GTKMM_PANED_H
#define GTKMM_PANED_H

#include "messageslist.h"
#include "messagetext.h"

#include <gtkmm.h>

class Paned : public Gtk::Window
{
  public:
    Paned();
    virtual ~Paned();

  protected:
    Gtk::Paned vpaned;
    MessagesList list;
    MessageText text;
};

#endif