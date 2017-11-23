#ifndef GTKMM_APP_H
#define GTKMM_APP_H

#include <gtkmm.h>

class AppWindow;

class App : public Gtk::Application
{
  protected:
    App();

  public:
    static Glib::RefPtr<App> create();

  protected:
    void on_activate() override;
    void on_open(const Gio::Application::type_vec_files& files,
      const Glib::ustring& hint) override;

  private:
    AppWindow* create_appwindow();
    void on_hide_window(Gtk::Window* window);
};

#endif