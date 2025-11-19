#include "tgaimage.h"
#include <cmath>

constexpr TGAColor white = { 255, 255, 255, 255 }; // attention, BGRA order
constexpr TGAColor green = { 0, 255,   0, 255 };
constexpr TGAColor red = { 0,   0, 255, 255 };
constexpr TGAColor blue = { 255, 128,  64, 255 };
constexpr TGAColor yellow = { 0, 200, 255, 255 };

// Given coordinates and a color, places pixels to form a line from a to b.
void line(int ax, int ay, int bx, int by, TGAImage &framebuffer, TGAColor color) {
    for (double t = 0.0; t <= 1.0; t+=0.02) {
        int x = round(ax + t * (bx - ax));
        int y = round(ay + t * (by - ay));
        framebuffer.set(x, y, color);
    }
}

int main(int argc, char** argv) {
    constexpr int width = 64;
    constexpr int height = 64;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    int ax = 7, ay = 3;
    int bx = 12, by = 37;
    int cx = 62, cy = 53;

    framebuffer.set(ax, ay, white);
    framebuffer.set(bx, by, white);
    framebuffer.set(cx, cy, white);

    // Making the lines from point to point.
    line(ax, ay, bx, by, framebuffer, blue);
    line(cx, cy, bx, by, framebuffer, green);
    line(cx, cy, bx, by, framebuffer, yellow);
    line(ax, ay, cx, cy, framebuffer, red);

    framebuffer.write_tga_file("framebuffer.tga");
    return 0;
}