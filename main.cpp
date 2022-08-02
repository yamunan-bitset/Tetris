#include <raylib.h>
#include "piece.h"
#include <iostream>

Piece piece;

namespace GFX
{
    unsigned tile_size = 50;
    static unsigned w = tile_size * 12, h = tile_size * 12;
    int i = 0;
    void Init()
    {
        SetTargetFPS(60);
        InitWindow(w, h, "Tetris");
    }
    void Update()
    {
        i++;
        if (piece.can_move)
        {
            if (IsKeyPressed(KEY_UP))
                piece.Rotate();
            if (IsKeyPressed(KEY_LEFT))
                piece - 'x';
            if (IsKeyPressed(KEY_RIGHT))
                piece + 'x';
            if (i % 20 == 0)
                piece + 'y';
            if (piece.a.y > 10 || piece.b.y > 10 || piece.c.y > 10 || piece.d.y > 10)
                piece.can_move = false;
            piece.CheckCollision();
        }
    }
    void Draw()
    {
        ClearBackground(BLACK);
        
        DrawRectangle(piece.a.x * tile_size, piece.a.y * tile_size, tile_size, tile_size, RED);
        DrawRectangle(piece.b.x * tile_size, piece.b.y * tile_size, tile_size, tile_size, RED);
        DrawRectangle(piece.c.x * tile_size, piece.c.y * tile_size, tile_size, tile_size, RED);
        DrawRectangle(piece.d.x * tile_size, piece.d.y * tile_size, tile_size, tile_size, RED);

        for (unsigned i = 1; i < 12; i++)
            DrawLine(tile_size * i, 0, tile_size * i, h, GRAY);
        for (unsigned i = 1; i < 12; i++)
            DrawLine(0, tile_size * i, w, tile_size * i, GRAY);

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
