#include <raylib.h>
#include "piece.h"
#include <vector>

std::vector<Piece> pieces = { Piece() };

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
        if (pieces.back().can_move)
        {
            if (IsKeyPressed(KEY_UP))
                pieces.back().Rotate();
            if (IsKeyPressed(KEY_LEFT))
                pieces.back() - 'x';
            if (IsKeyPressed(KEY_RIGHT))
                pieces.back() + 'x';
            if (i % 20 == 0)
                pieces.back() + 'y';
            if (pieces.back().a.y > 10 || pieces.back().b.y > 10 || pieces.back().c.y > 10 || pieces.back().d.y > 10)
                pieces.back().can_move = false;
            pieces.back().CheckCollision();
        }
        else pieces.push_back(Piece());
    }
    void Draw()
    {
        ClearBackground(BLACK);
        
        for (Piece piece : pieces)
        {
            DrawRectangle(piece.a.x * tile_size, piece.a.y * tile_size, tile_size, tile_size, RED);
            DrawRectangle(piece.b.x * tile_size, piece.b.y * tile_size, tile_size, tile_size, RED);
            DrawRectangle(piece.c.x * tile_size, piece.c.y * tile_size, tile_size, tile_size, RED);
            DrawRectangle(piece.d.x * tile_size, piece.d.y * tile_size, tile_size, tile_size, RED);
        }

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
