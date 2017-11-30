#include "helloworld.h"
#include <iostream>

HelloWorld::HelloWorld() :
  btn1("Button 1"),
  btn2("Button 2")
{
  set_title("Improvised Hello World");
  set_border_width(10);

  add(box);

  btn1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &HelloWorld::on_button_clicked), "Button 1"));
  box.pack_start(btn1);
  btn1.show();

  btn2.signal_clicked().connect(sigc::bind<-1, Glib::ustring>(sigc::mem_fun(*this, &HelloWorld::on_button_clicked), "Button 2"));
  box.pack_start(btn2);
  btn2.show();

  box.show();
}

HelloWorld::~HelloWorld()
{}

void HelloWorld::on_button_clicked(Glib::ustring data)
{
  std::cout << "Hello world. " << data << " was pressed." << std::endl;
}