#include "rangewidgets.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.rangewidgets.example");

  RangeWidgets window;

  return app->run(window);
}