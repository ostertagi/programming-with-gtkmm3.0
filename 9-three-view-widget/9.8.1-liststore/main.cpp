#include "liststore.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.liststore.example");

    ListStore window;

    return app->run(window);
}