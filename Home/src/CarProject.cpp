#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void car();
void drawBuilding(int x, int y1, int y2, int width, int height, int gap);
void road(int xmax);
void drawTrees(int i, int xmax);
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
        // Draw buildings with wrap-around
        drawBuilding((xmax - buildingWidth - i - 100) % xmax, ymin + 50, ymax, 100, 200, gap);

        drawBuilding((xmax - i) % xmax, ymin - 4, ymax, 300, 50, gap);
        // first four lines
        drawTrees(i, xmax);
        // Draw car and road
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

// Function to draw a car
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

    // Draw car body
    rectangle(left, top, right, bottom);
    setfillstyle(SOLID_FILL, BLUE);                           // Set fill style and color
    floodfill((left + right) / 2, (top + bottom) / 2, GREEN); // Fill the car body

    // Draw wheels
    circle(wheel1_x, wheel_y, 15);
    setfillstyle(SOLID_FILL, BLACK);     // Set fill style and color for wheels
    floodfill(wheel1_x, wheel_y, GREEN); // Fill the first wheel

    circle(wheel2_x, wheel_y, 15);
    floodfill(wheel2_x, wheel_y, GREEN); // Fill the second wheel

    // Draw roof
    line(left, top, wheel1_x, roof_top);
    line(wheel2_x, roof_top, right, top);
    line(wheel1_x, roof_top, wheel2_x, roof_top);
    setfillstyle(SOLID_FILL, RED);                              // Set fill style and color for roof
    floodfill((left + right) / 2, (top + roof_top) / 2, GREEN); // Fill the roof
}

// Function to draw a building with grid lines
void drawBuilding(int x, int y1, int y2, int width, int height, int gap)
{
    int x1 = x;
    int x2 = x + width;

    // Draw the outer rectangle (the building)

    rectangle(x1, y1, x2, y2);

    // Draw horizontal lines with equal gaps inside the rectangle
    for (int y = y1 + gap; y < y2; y += gap)
    {
        line(x1, y, x2, y);
    }

    // Draw vertical lines with equal gaps inside the rectangle
    for (int x = x1 + gap; x < x2; x += gap)
    {
        line(x, y1, x, y2);
    }
}
void drawTrees(int i, int xmax)
{
    for (int k = 0; k <= 90; k += 30)
    {
        line((xmax - (3 * i) % xmax - k), 150, (xmax - (3 * i) % xmax), 265);
    }

    // next four linesG
    for (int k = 0; k <= 90; k += 30)
    {
        line((xmax - 150 - (3 * i) % xmax - k), 150, (xmax - 150 - (3 * i) % xmax), 265);
    }
    // next four lines
    for (int k = 0; k <= 90; k += 30)
    {
        line((xmax - 300 - (3 * i) % xmax - k), 150, (xmax - 300 - (3 * i) % xmax), 265);
    }
    // next four lines
    for (int k = 0; k <= 90; k += 30)
    {
        line((xmax - 450 - (3 * i) % xmax - k), 150, (xmax - 450 - (3 * i) % xmax), 265);
    }
}
// Function to draw a road
void road(int xmax)
{
    line(0, 265, xmax, 265);
}
