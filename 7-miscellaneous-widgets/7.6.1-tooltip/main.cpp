#include "tooltip.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "foo.bar");

  Tooltip window;

  return app->run(window);
}