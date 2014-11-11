#pragma once
#include <tygra/WindowControlDelegate.hpp>

class MyView;

class MyController : public tygra::WindowControlDelegate
{
public:
	
    MyController();

    ~MyController();

private:

    void
    windowControlWillStart(std::shared_ptr<tygra::Window> window);

    void
    windowControlDidStop(std::shared_ptr<tygra::Window> window);

    void
    windowControlMouseMoved(std::shared_ptr<tygra::Window> window,
                            int x,
                            int y);	

    void
    windowControlMouseButtonChanged(std::shared_ptr<tygra::Window> window,
                                    int button_index,
                                    bool down);


    void
    windowControlMouseWheelMoved(std::shared_ptr<tygra::Window> window,
                                 int position);

    void
    windowControlKeyboardChanged(std::shared_ptr<tygra::Window> window,
                                 int key_index,
                                 bool down);

    void
    windowControlGamepadAxisMoved(std::shared_ptr<tygra::Window> window,
                                  int gamepad_index,
                                  int axis_index,
                                  float pos);

    void
    windowControlGamepadButtonChanged(std::shared_ptr<tygra::Window> window,
                                      int gamepad_index,
                                      int button_index,
                                      bool down);

private:
	std::shared_ptr<MyView> view_;

};
