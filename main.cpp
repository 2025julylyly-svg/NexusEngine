/*********************
 * Nexus Game Engine *
 *********************/
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
    auto* rt = new Rectangle();
    rt->setSize( { 50, 50 } );
    rt->setFillColor( VecCol { 255, 0, 0 }.GetColor() );
    rt->setPosition( { 400, 200 } );
    Logic logic;
    Engine engine;
    engine.CreateShape( rt );
    engine.CreateWindow( { 900, 900 }, 60 );
    engine.Run( &logic );

    return 0;
}
