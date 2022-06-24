#include <raylib.h>
#include "piece.h"

Piece piece;

namespace GFX
{
    static unsigned width = 800, height = 500;
    void Init()
    {
        SetTargetFPS(60);
        InitWindow(width, height, "Tetris");
    }
    void Update()
    {
        if (IsKeyPressed(KEY_UP))
            piece.Rotate();
        if (IsKeyPressed(KEY_LEFT))
        {
            piece.a.x--;
            piece.b.x--;
            piece.c.x--;
            piece.d.x--;
        }
        if (IsKeyPressed(KEY_RIGHT))
        {
            piece.a.x++;
            piece.b.x++;
            piece.c.x++;
            piece.d.x++;
        }
    }
    void Draw()
    {
        ClearBackground(RAYWHITE);
    }
    bool Open()
    {
        return !WindowShouldClose();
    }
    void Close()
    {
        CloseWindow();
    }
}

int main()
{
    GFX::Init();
    while (GFX::Open())
    {
        BeginDrawing();
        GFX::Update();
        GFX::Draw();
        EndDrawing();
    }
    GFX::Close();
    return 0;
}
