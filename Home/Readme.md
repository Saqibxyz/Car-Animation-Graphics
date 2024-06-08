Car Animation Graphics Project
Description
This project demonstrates a simple car animation using the graphics library in C. The animation includes moving buildings, trees, and a car driving along a road. The project is developed by Saqib, Umer, and Murtaza.

Features
Animated car moving across the screen
Dynamic buildings with grid patterns
Trees moving alongside the car
Road animation
Prerequisites
C compiler (e.g., GCC)
Graphics library (e.g., BGI for Turbo C)
How to Run
Ensure you have a C compiler and graphics library installed.
Copy the code into a file named main.c.
Compile the code using your C compiler.
Run the executable.
Compilation Example (GCC)
sh
Copy code
gcc main.c -o CarAnimation -lgraph
Running the Executable
sh
Copy code
./CarAnimation
Code Explanation
Header Files
c
Copy code
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
These header files include the necessary functions for graphics, console input/output, and standard libraries.

Function Prototypes
c
Copy code
void car();
void drawBuilding(int x, int y1, int y2, int width, int height, int gap);
void road(int xmax);
void drawTrees(int i, int xmax);
These are the function prototypes for the various parts of the animation.

Main Function
c
Copy code
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xmax = getmaxx();
    int ymin = 50, ymax = 250;
    int buildingWidth = 250;
    int buildingHeight = 200;
    int gap = 20;
    char Names[] = "Project By Saqib,Umer and Murtaza";

    for (int i = 0; i < 100000 && !kbhit(); i++)
    {
        drawBuilding((xmax - buildingWidth - i - 100) % xmax, ymin + 50, ymax, 100, 200, gap);
        drawBuilding((xmax - i) % xmax, ymin - 4, ymax, 300, 50, gap);
        drawTrees(i, xmax);
        setcolor(GREEN);
        car();
        setcolor(WHITE);
        road(xmax);
        outtextxy(xmax / 2 - 100, 400, Names);

        delay(5);
        cleardevice();
        i = i % xmax;
    }

    getch();
    closegraph();
    return 0;
}
The main function initializes the graphics mode, sets up the animation loop, and calls the drawing functions.

Car Function
c
Copy code
void car()
{
    int nearMid = getmaxx() / 2;
    int left = 10 + nearMid / 2;
    int right = 200 + nearMid / 2;
    int top = 200;
    int bottom = 250;
    int wheel1_x = 45 + nearMid / 2;
    int wheel2_x = 155 + nearMid / 2;
    int wheel_y = 250;
    int roof_top = 170;

    rectangle(left, top, right, bottom);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill((left + right) / 2, (top + bottom) / 2, GREEN);

    circle(wheel1_x, wheel_y, 15);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(wheel1_x, wheel_y, GREEN);

    circle(wheel2_x, wheel_y, 15);
    floodfill(wheel2_x, wheel_y, GREEN);

    line(left, top, wheel1_x, roof_top);
    line(wheel2_x, roof_top, right, top);
    line(wheel1_x, roof_top, wheel2_x, roof_top);
    setfillstyle(SOLID_FILL, RED);
    floodfill((left + right) / 2, (top + roof_top) / 2, GREEN);
}
This function draws a car at a fixed position on the screen.

Building Function
c
Copy code
void drawBuilding(int x, int y1, int y2, int width, int height, int gap)
{
    int x1 = x;
    int x2 = x + width;

    rectangle(x1, y1, x2, y2);

    for (int y = y1 + gap; y < y2; y += gap)
    {
        line(x1, y, x2, y);
    }

    for (int x = x1 + gap; x < x2; x += gap)
    {
        line(x, y1, x, y2);
    }
}
This function draws a building with grid lines.

Trees Function
c
Copy code
void drawTrees(int i, int xmax)
{
    for (int k = 0; k <= 90; k += 30)
    {
        line((xmax - (3 * i) % xmax - k), 150, (xmax - (3 * i) % xmax), 265);
    }

    for (int k = 0; k <= 90; k += 30)
    {
        line((xmax - 150 - (3 * i) % xmax - k), 150, (xmax - 150 - (3 * i) % xmax), 265);
    }

    for (int k = 0; k <= 90; k += 30)
    {
        line((xmax - 300 - (3 * i) % xmax - k), 150, (xmax - 300 - (3 * i) % xmax), 265);
    }

    for (int k = 0; k <= 90; k += 30)
    {
        line((xmax - 450 - (3 * i) % xmax - k), 150, (xmax - 450 - (3 * i) % xmax), 265);
    }
}
This function draws multiple trees at different positions.

Road Function
c
Copy code
void road(int xmax)
{
    line(0, 265, xmax, 265);
}
This function draws a road across the screen.

Contributors
Saqib
Umer
Murtaza
