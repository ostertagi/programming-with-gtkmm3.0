#include "entryprogress.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.entryprogress.example");

  EntryProgress window;

  return app->run(window);
}