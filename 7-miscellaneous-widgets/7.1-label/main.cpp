#include "labels.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.labels.example");

  Labels window;

  return app->run(window);
}