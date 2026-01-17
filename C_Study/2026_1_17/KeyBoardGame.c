#include "raylib.h"
#include<stdio.h>
#include<conio.h>

void main()
{
    InitWindow(720,600,"KeyBoardGame");
    SetTargetFPS(80);
    int dir_1=1;
    int dir_2=1;
    int speed=1;
    bool notstop=1;
    int x=50;
    int y=50;
    int fps=0;
    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_W)){dir_1=-1;}
        if(IsKeyPressed(KEY_A)){dir_2=-1;}
        if(IsKeyPressed(KEY_S)){dir_1=1;}
        if(IsKeyPressed(KEY_D)){dir_2=1;}
        if(IsKeyPressed(KEY_LEFT)){dir_1=0;dir_2=-1;}
        if(IsKeyPressed(KEY_RIGHT)){dir_1=0;dir_2=1;}
        if(IsKeyPressed(KEY_UP)){dir_1=-1;dir_2=0;}
        if(IsKeyPressed(KEY_DOWN)){dir_1=1;dir_2=0;}
        if(IsKeyPressed(KEY_O)&&(speed<50)){speed+=1;}
        if(IsKeyPressed(KEY_L)&&(speed>0)){speed-=1;}
        if((x>=700)||(x<=20)){dir_2=-dir_2;}
        if((y>=580)||(y<=40)){dir_1=-dir_1;}
        //it is not easy to read,yes?
        BeginDrawing();
        ClearBackground(YELLOW);
        x+=(speed*dir_2*notstop);
        y+=(speed*dir_1*notstop);
        DrawRectangle(0,0,720,16,DARKGREEN);
        DrawRectangle(4,16,712,4,DARKGREEN);
        fps=GetFPS();
        DrawText(TextFormat("FPS:%d",fps),0,0,15,YELLOW);
        DrawText("W:UP A:DOEN S:LEFT D:RIGHT | O:FAST L:SLOW",60,0,16,YELLOW);
        DrawCircle(4,16,4,DARKGREEN);
        DrawCircle(716,16,4,DARKGREEN);
        DrawCircle(x,y,20,DARKGRAY);
        if(IsKeyPressed(KEY_SPACE)){notstop=!(notstop);}
        if(!notstop)
        {DrawText("Paused",540,0,15,YELLOW);}
        if (dir_1==1){DrawText("DOWN",480,0,15,YELLOW);}
        if (dir_1==-1){DrawText("UP",480,0,15,YELLOW);}
        if (dir_2==1){DrawText("RIGHT",430,0,15,YELLOW);}
        if (dir_2==-1){DrawText("LEFT",430,0,15,YELLOW);}
        DrawText(TextFormat("SPEED:%d",speed),600,0,15,YELLOW);
        EndDrawing();
    }
    CloseWindow();
}//I am not good at writing the comment.
