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
            if (i % 20 == 0)
            {
                piece.a.y++;
                piece.b.y++;
                piece.c.y++;
                piece.d.y++;
            }
            if (piece.a.y > 10 || piece.b.y > 10 || piece.c.y > 10
                || piece.d.y > 10)
                piece.can_move = false;
        }
    }
    void Draw()
    {
        ClearBackground(RAYWHITE);
        DrawRectangle(piece.a.x * tile_size, piece.a.y * tile_size, tile_size, tile_size, RED);
        DrawRectangle(piece.b.x * tile_size, piece.b.y * tile_size, tile_size, tile_size, YELLOW);
        DrawRectangle(piece.c.x * tile_size, piece.c.y * tile_size, tile_size, tile_size, BLUE);
        DrawRectangle(piece.d.x * tile_size, piece.d.y * tile_size, tile_size, tile_size, GREEN);
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
