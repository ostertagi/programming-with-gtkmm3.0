#include "paned.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.paned.example");

  Paned window;

  return app->run(window);
}