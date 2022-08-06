#include <raylib.h>
#include "piece.h"
#include <array>
#include <vector>

namespace GFX
{
    unsigned tile_size = 50;
    static unsigned w = tile_size * 12, h = tile_size * 12;
    std::vector<Piece> pieces;
    std::vector<Vec2> occupied;
    std::array<int, 4> t_xs, t_ys, p_xs, p_ys;
    int i = 0;
    void Init()
    {
        SetTargetFPS(60);
        InitWindow(w, h, "Tetris");
        pieces.push_back(Piece());
    }
    void Update()
    {
        if (IsKeyDown(KEY_SPACE))
            i += 5;
        else i++;
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

            for (Vec2 place : occupied)
            {
                if (Vec2(place.x, place.y - 1) == pieces.back().a || Vec2(place.x, place.y - 1) == pieces.back().b
                    || Vec2(place.x, place.y - 1) == pieces.back().c || Vec2(place.x, place.y - 1) == pieces.back().d)
                    pieces.back().can_move = false;
            }
        }
        else
        {
            occupied.push_back(Vec2(pieces.back().a));
            occupied.push_back(Vec2(pieces.back().b));
            occupied.push_back(Vec2(pieces.back().c));
            occupied.push_back(Vec2(pieces.back().d));
            pieces.push_back(Piece());
        }
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
