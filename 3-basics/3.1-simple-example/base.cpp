#include <gtkmm.h>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  Gtk::Window window;

  window.set_default_size(500, 500);

  return app->run(window);
}