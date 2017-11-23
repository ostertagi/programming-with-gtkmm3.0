#include "app.h"
#include "appwindow.h"

App::App() : Gtk::Application("org.gtkmm.examples.application", Gio::APPLICATION_HANDLES_OPEN)
{
}

Glib::RefPtr<App> App::create()
{
  return Glib::RefPtr<App>(new App());
}

AppWindow* App::create_appwindow()
{
  auto appwindow = new AppWindow();

  add_window(*appwindow);

  appwindow->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this, &App::on_hide_window), appwindow));

  return appwindow;
}

void App::on_activate()
{
  try 
  {
    auto appwindow = create_appwindow();
    appwindow->present();
  }
  catch (const Glib::Error& ex) 
  {
    std::cerr < "App::on_open(): " << ex.what() << std::endl;
  } 
  catch (const std::exception& ex) 
  {
    std::cerr < "App::on_open(): " << ex.what() << std::endl;
  }
}

void App::on_open(const Gio::Application::type_vec_files& files, const Glib::ustring& hint)
{
  AppWindow* appwindow = nullptr;

  auto windows = get_windows();
  
  if (windows.size() > 0)
    appwindow = dynamic_cast<AppWindow*>(windows[0]);

  try 
  {
    if (!appwindow)
      appwindow = create_appwindow();

    for (const auto& file : files)
      appwindow->open_file_view(file);

    appwindow->present();
  }
  catch (const Glib::Error& ex) 
  {
    std::cerr < "App::on_open(): " << ex.what() << std::endl;
  } 
  catch (const std::exception& ex) 
  {
    std::cerr < "App::on_open(): " << ex.what() << std::endl;
  }
}

void App::on_hide_window(Gtk::Window* window)
{
  delete window;
}