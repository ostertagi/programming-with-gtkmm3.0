#include "frame.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.frame.example");

  Frame window;

  return app->run(window);
}