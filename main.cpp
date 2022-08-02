#include <raylib.h>
#include "piece.h"
#include <array>
#include <vector>

namespace GFX
{
    unsigned tile_size = 50;
    static unsigned w = tile_size * 12, h = tile_size * 12;
    std::vector<Piece> pieces;
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

            t_xs = { pieces.back().a.x, pieces.back().b.x, pieces.back().c.x, pieces.back().d.x };
            t_ys = { pieces.back().a.y, pieces.back().b.y, pieces.back().c.y, pieces.back().d.y };
            for (Piece piece : pieces)
            {
                /*
                p_xs = { piece.a.x, piece.b.x, piece.c.x, piece.d.x };
                p_ys = { piece.a.y, piece.b.y, piece.c.y, piece.d.y };
                for (int ip_xs : p_xs)
                    for (int ip_ys : p_ys)
                        for (int it_xs : t_xs)
                            for (int it_ys : t_ys)
                                if ((it_xs == ip_xs) && (it_ys + 1 == ip_ys))
                                {
                                    pieces.back().can_move = false;
                                    break;
                                }
                                FIXME NOT WORKING
                */
                // Not Right |v, all xs should iterate to equal the xs of the piece below, same for ys, but +1
                if (((pieces.back().a.x == piece.a.x) && (pieces.back().a.y + 1 == piece.a.y))
                    || ((pieces.back().b.x == piece.b.x) && (pieces.back().b.y + 1 == piece.b.y))
                    || ((pieces.back().c.x == piece.c.x) && (pieces.back().c.y + 1 == piece.c.y))
                    || ((pieces.back().d.x == piece.d.x) && (pieces.back().d.y + 1 == piece.d.y)))
                {
                    pieces.back().can_move = false;
                    break;
                }
            }
            if (pieces.back().a.y > 10 || pieces.back().b.y > 10 || pieces.back().c.y > 10 || pieces.back().d.y > 10)
                pieces.back().can_move = false;
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
