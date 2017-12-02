#include "buttonboxes.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.buttonboxes.example");

    ButtonBoxes window;

    return app->run(window);
}