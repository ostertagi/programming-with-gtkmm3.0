#ifndef GTKMM_APPWINDOW_H_
#define GTKMM_APPWINDOW_H_

#include <gtkmm.h>

class AppWindow : public Gtk::ApplicationWindow
{
  public:
    AppWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

    static AppWindow* create();
    
    void open_file_view(const Glib::RefPtr<Gio::File>& file);
  
  protected:
    Glib:RefPtr<Gtk::Builder> m_refBuilder;
};

#endif