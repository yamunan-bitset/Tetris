#include <raylib.h>
#include "piece.h"
#include <array>
#include <vector>
#include <ctime>

namespace GFX
{
    unsigned tile_size = 50;
    static unsigned w = tile_size * 12, h = tile_size * 12;
    std::vector<Piece> pieces;
    std::vector<Vec2> occupied;
    std::array<int, 4> t_xs, t_ys, p_xs, p_ys;
    int i = 0;
    Color colour[17] = {BEIGE, BLUE, GREEN, DARKGREEN, YELLOW, DARKBLUE, DARKPURPLE, BROWN, MAGENTA, PINK, ORANGE, RED, VIOLET, WHITE, MAROON, LIME};
    void Init()
    {
        std::srand(std::time(0));
        SetTargetFPS(60);
        InitWindow(w, h, "Tetris");
        pieces.push_back(Piece(colour[std::rand() % 18]));
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
            if (IsKeyPressed(KEY_LEFT) && pieces.back().move_left)
                pieces.back() - 'x';
            if (IsKeyPressed(KEY_RIGHT) && pieces.back().move_right)
                pieces.back() + 'x';
            if (i % 20 == 0)
                pieces.back() + 'y';

            if (pieces.back().a.y > 10 || pieces.back().b.y > 10 || pieces.back().c.y > 10 || pieces.back().d.y > 10)
                pieces.back().can_move = false;

            for (Vec2 place : occupied)
            {
                if (place == pieces.back().a || place == pieces.back().b || place == pieces.back().c
                    || place == pieces.back().d) printf("Error!!\n");
                if (Vec2(place.x, place.y - 1) == pieces.back().a || Vec2(place.x, place.y - 1) == pieces.back().b
                    || Vec2(place.x, place.y - 1) == pieces.back().c || Vec2(place.x, place.y - 1) == pieces.back().d)
                    pieces.back().can_move = false;
                if (Vec2(place.x - 1, place.y) == pieces.back().a || Vec2(place.x - 1, place.y) == pieces.back().b
                    || Vec2(place.x - 1, place.y) == pieces.back().c || Vec2(place.x - 1, place.y) == pieces.back().d)
                    pieces.back().move_right = false;
                else pieces.back().move_right = true;
                if (Vec2(place.x + 1, place.y) == pieces.back().a || Vec2(place.x + 1, place.y) == pieces.back().b
                    || Vec2(place.x + 1, place.y) == pieces.back().c || Vec2(place.x + 1, place.y) == pieces.back().d)
                    pieces.back().move_left = false;
                else pieces.back().move_left = true;
            }
        }
        else
        {
            occupied.push_back(Vec2(pieces.back().a));
            occupied.push_back(Vec2(pieces.back().b));
            occupied.push_back(Vec2(pieces.back().c));
            occupied.push_back(Vec2(pieces.back().d));
            if (pieces.back().a.y == 11 || pieces.back().b.y == 11
                || pieces.back().c.y == 11 || pieces.back().d.y == 11)
                printf("Debug: Game Over\n");
            pieces.push_back(Piece(colour[std::rand() % 18]));
        }
    }
    void Draw()
    {
        ClearBackground(BLACK);
        for (Piece piece : pieces)
        {
            DrawRectangle(piece.a.x * tile_size, piece.a.y * tile_size, tile_size, tile_size, piece.colour);
            DrawRectangle(piece.b.x * tile_size, piece.b.y * tile_size, tile_size, tile_size, piece.colour);
            DrawRectangle(piece.c.x * tile_size, piece.c.y * tile_size, tile_size, tile_size, piece.colour);
            DrawRectangle(piece.d.x * tile_size, piece.d.y * tile_size, tile_size, tile_size, piece.colour);
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
