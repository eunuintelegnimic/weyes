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

//  --- Set window size to 4/5 of the screen size
    int windowWidth = GetMonitorWidth(0) / 5;
    int windowHeight = GetMonitorHeight(0) / 4;
//      If the screen is too small set specific values
    if (GetScreenWidth() <= 1280 || GetScreenHeight() <= 720){
        windowWidth = 256;
        windowHeight = 180;
    } SetWindowSize(windowWidth, windowHeight);
//  --- Place it in bottom-right corner
    SetWindowPosition(GetMonitorWidth(0) - windowWidth,
                      GetMonitorHeight(0) - windowHeight);

//  --- Eyes sizes and positions and pupils radius
    Vector2 eyeSize = {windowWidth/4, windowHeight/2};
    Vector2 eyeL = {windowWidth/4, windowHeight/2};
    Vector2 eyeR = {windowWidth - windowWidth/4, windowHeight/2};

    Vector2 pupilL = eyeL;
    Vector2 pupilR = eyeR;
    float pupilRadius = eyeSize.y / 5;

//  --- I think it's clear what this loop is for
    while (!WindowShouldClose()) {
    BeginDrawing();
        ClearBackground(BLANK);
        DrawEllipse(eyeL.x, eyeL.y, eyeSize.x, eyeSize.y, WHITE);
        DrawEllipse(eyeR.x, eyeR.y, eyeSize.x, eyeSize.y, WHITE);
        DrawEllipseLines(eyeL.x, eyeL.y, eyeSize.x, eyeSize.y, BLACK);
        DrawEllipseLines(eyeR.x, eyeR.y, eyeSize.x, eyeSize.y, BLACK);

        DrawCircleV(pupilL, pupilRadius, BLACK);
        DrawCircleV(pupilR, pupilRadius, BLACK);
    EndDrawing();
    }

//  --- Close the window afterwards
    CloseWindow();

    return 0;
}
