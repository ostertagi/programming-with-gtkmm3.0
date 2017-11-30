#include "alignment.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.alignment.example");

  Alignment window;

  return app->run(window);
}