#ifndef GTKMM_APPWINDOW_H_
#define GTKMM_APPWINDOW_H_

#include <gtkmm.h>

class AppWindow : public Gtk::ApplicationWindow
{
public:
  AppWindow();

  void open_file_view(const Glib::RefPtr<Gio::File>& file);
};

#endif