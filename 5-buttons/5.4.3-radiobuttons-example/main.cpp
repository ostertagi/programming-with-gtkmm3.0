#include "radiobuttons.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.radiobuttons.example");

  RadioButtons window;

  return app->run(window);
}