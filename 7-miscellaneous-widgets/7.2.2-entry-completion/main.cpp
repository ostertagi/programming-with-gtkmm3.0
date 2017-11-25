#include "entrycompletion.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.entrycompletion.example");

  EntryCompletion window;

  return app->run(window);
}