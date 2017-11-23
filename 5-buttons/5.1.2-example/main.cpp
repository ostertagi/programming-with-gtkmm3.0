#include "buttons.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.buttons.example");

  Buttons buttons;

  return app->run(buttons);
}