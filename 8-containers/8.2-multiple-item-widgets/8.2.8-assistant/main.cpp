#include "examplewindow.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.assistant.example");

    ExampleWindow window;

    return app->run(window);
}