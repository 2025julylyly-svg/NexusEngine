/*********************
 * Nexus Game Engine *
 *********************/
#include <thread>

#include "Engine/MainEngine/Engine.h"
#include "Engine/Systems/Input/InputSystemFiles/InputManager/inputManager.h"
#define NE() std::cout << R"(
 /$$   /$$|
| $$$ | $$|
| $$$$| $$|   /$$$$$$   /$$   /$$|  /$$   /$$   /$$$$$$$
| $$ $$ $$|  /$$__  $$ |  $$ /$$/  | $$  | $$  /$$_____/
| $$  $$$$| | $$$$$$$$  \  $$$$/   | $$  | $$ |  $$$$$$
| $$\  $$$| | $$_____/   >$$  $$\  | $$  | $$  \____  $$
| $$ \  $$| |  $$$$$$$  /$$/\  $$| |  $$$$$$/  /$$$$$$$/
|__/  \__/   \_______/ |__/  \__/   \______/  |_______/
)" << std::endl;


namespace {
    class Logic final : public GameLogic
    {
    public:
        void Main() const override {
            // write the logic of your game in this function
        }
    };
}


int main() {
    NE();
    /*auto* rt = new Rectangle();
    rt->setSize( { 50, 50 } );
    rt->setFillColor( VecCol { 255, 0, 0 }.GetColor() );
    rt->setPosition( { 400, 200 } );
    Logic logic;
    Engine engine;
    engine.CreateShape( rt );
    engine.CreateWindow( { 900, 900 }, 60 );
    engine.Run( &logic );*/
    ReadInputMouse MInput;
    std::cout << "Hello World" << std::endl;
    while (true) {
        MInput.GetMouseInputEvent();
        if (MInput.IsRightButtonPressed()) {
            break;
        }
        if (MInput.IsLeftButtonPressed()) {
            std::cout << "Left Button Pressed" << std::endl;
        }
        if (MInput.IsLeftButtonHeld()) {
            std::cout << "Left Button Held" << std::endl;
        }
        if (MInput.IsLeftButtonReleased()) {
            std::cout << "Left Button Released" << std::endl;
        }
        MInput.Update();
        std::this_thread::sleep_for( std::chrono::milliseconds(100) );
    }

    return 0;
}
