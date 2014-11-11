#include "MyController.hpp"
#include "MyView.hpp"
#include <tygra/Window.hpp>
#include <iostream>

MyController::
MyController()
{
	view_ = std::make_shared<MyView>();
}

MyController::
~MyController()
{
}

void MyController::
windowControlWillStart(std::shared_ptr<tygra::Window> window)
{
    window->setView(view_);
    window->setTitle("Real-Time Graphics :: Relight My Gbuffer");
}

void MyController::
windowControlDidStop(std::shared_ptr<tygra::Window> window)
{
    window->setView(nullptr);
}

void MyController::
windowControlMouseMoved(std::shared_ptr<tygra::Window> window,
                        int x,
                        int y)
{
}

void MyController::
windowControlMouseButtonChanged(std::shared_ptr<tygra::Window> window,
                                int button_index,
                                bool down)
{
}


void MyController::
windowControlMouseWheelMoved(std::shared_ptr<tygra::Window> window,
                             int position)
{
}

void MyController::
windowControlKeyboardChanged(std::shared_ptr<tygra::Window> window,
                             int key_index,
                             bool down)
{
}

void MyController::
windowControlGamepadAxisMoved(std::shared_ptr<tygra::Window> window,
                              int gamepad_index,
                              int axis_index,
                              float pos)
{
}

void MyController::
windowControlGamepadButtonChanged(std::shared_ptr<tygra::Window> window,
                                  int gamepad_index,
                                  int button_index,
                                  bool down)
{
}
