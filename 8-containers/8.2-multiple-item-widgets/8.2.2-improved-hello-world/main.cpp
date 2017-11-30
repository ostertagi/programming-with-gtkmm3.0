#include "helloworld.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.improvedhelloworld.example");

  HelloWorld window;

  return app->run(window);
}