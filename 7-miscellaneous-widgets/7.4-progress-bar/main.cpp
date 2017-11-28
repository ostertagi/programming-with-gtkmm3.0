#include "progressbar.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.progressbar.example");

  ProgressBar window;

  return app->run(window);
}