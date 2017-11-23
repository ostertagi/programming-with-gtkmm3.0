#include "appwindow.h"

AppWindow::AppWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) : Gtk::ApplicationWindow()
{
}

AppWindow* AppWindow::create()
{
  auto refBuilder = Gtk::Builder::create_from_resource("/org/gtkmm/exampleapp/window.ui");

  AppWindow* window = nullptr;

  refBuilder->get_widget_derived("app_window", window);

  if (!window)
  {
    throw std::runtime_error("No \"app_window\" object in window.ui");
  }

  return window;
}

void AppWindow::open_file_view(const Glib::RefPtr<Gio::File>& file)
{
}