#include "scrolledwindow.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.scrolledwindow.example");

  ScrolledWindow window;

  return app->run(window);
}