#include "entryicons.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.entryicons.example");

  EntryIcons window;

  return app->run(window);
}