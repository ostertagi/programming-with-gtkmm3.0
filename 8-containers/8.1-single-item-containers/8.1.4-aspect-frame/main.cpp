#include "aspectframe.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.aspectframe.example");

  AspectFrame window;

  return app->run(window);
}