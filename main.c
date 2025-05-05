#include <raylib.h>
#include <raymath.h>
#include "main.h"

double inEyeFactor(Vector2 eye, Vector2 size);
Vector2 clampElipse(Vector2 eye, Vector2 size);
Vector2 customLerp(Vector2 V, double t);

int main()
{
//  --- Transparency need to be set beefore window initialization
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);

//  --- Window size is set to default value (screen size)
    InitWindow(0, 0, "weyes");

//  --- Keep above other
    SetWindowState(FLAG_WINDOW_TOPMOST);
    //SetWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);
    SetWindowState(FLAG_WINDOW_UNDECORATED);

//  --- Set eyes size to 4/5 of the screen size
    int windowWidth = GetMonitorWidth(0);
    int windowHeight = GetMonitorHeight(0);

    int eyesWidth = windowWidth / 5;
    int eyesHeight = windowHeight / 4;

//      If the screen is too small set specific values
    if (windowWidth <= 1280 || windowHeight <= 720){
        eyesWidth = 256;
        eyesHeight = 180;
    }

//  --- Eyes sizes and positions and pupils radius
    Vector2 eyeSize = {eyesWidth/4, eyesHeight/2};
    Vector2 eyeL = {windowWidth - eyesWidth/4, windowHeight - eyesHeight/2};
    Vector2 eyeR = {windowWidth - (eyesWidth - eyesWidth/4), windowHeight - eyesHeight/2};

    Vector2 pupilL;
    Vector2 pupilR;
    float pupilRadius = eyeSize.y / 5;

//  --- I think it's clear what this loop is for
    while (!WindowShouldClose()) {

        pupilL = clampElipse(eyeL, eyeSize);
        pupilR = clampElipse(eyeR, eyeSize);

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
