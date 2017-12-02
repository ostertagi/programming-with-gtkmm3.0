#include "grid.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.grid.example");

    Grid window;

    return app->run(window);
}