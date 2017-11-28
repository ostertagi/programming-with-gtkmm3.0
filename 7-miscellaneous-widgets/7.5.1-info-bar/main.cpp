#include "infobar.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.infobar.example");

  InfoBar window;

  return app->run(window);
}