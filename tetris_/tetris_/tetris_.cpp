#include <raylib.h>

namespace PC
{
    static unsigned width = 800, height = 500;
    void Init()
    {
        SetTargetFPS(60);
        InitWindow(width, height, "Tetris");
    }
    void Update()
    {
        
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
    PC::Init();
    while (PC::Open())
    {
        BeginDrawing();
        PC::Update();
        PC::Draw();
        EndDrawing();
    }
    PC::Close();
    return 0;
}
