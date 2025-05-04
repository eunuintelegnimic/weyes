#include <raylib.h>
#include <raymath.h>

int main()
{
//  --- Transparency need to be set beefore window initialization
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
//  --- Window size is set to default value (screen size)
    InitWindow(0, 0, "weyes");
//  --- Keep above other
    SetWindowState(FLAG_WINDOW_TOPMOST);

//  --- Set window size to 3/4 of the screen size
    int windowWidth = GetMonitorWidth(0) / 4;
    int windowHeight = GetMonitorHeight(0) / 3;
//      If the screen is too small set specific values
    if (GetScreenWidth() <= 1280 || GetScreenHeight() <= 720){
        windowWidth = 320;
        windowHeight = 260;
    } SetWindowSize(windowWidth, windowHeight);

//  --- I think it's clear what this loop is for
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLANK);
        EndDrawing();
    }

//  --- Close the window afterwards
    CloseWindow();

    return 0;
}
