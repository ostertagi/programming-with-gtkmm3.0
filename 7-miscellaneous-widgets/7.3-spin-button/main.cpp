#include "spinbuttons.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.spinbutton.example");

  SpinButtons window;

  return app->run(window);
}