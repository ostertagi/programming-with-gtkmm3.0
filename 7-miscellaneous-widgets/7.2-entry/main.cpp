#include "entry.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.entry.example");

  Entry window;

  return app->run(window);
}