#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

void drawPixel(int x, int y, int t, int color) {
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            putpixel(x + i, y + j, color);
        }
    }
}

void DDA(int x1, int y1, int x2, int y2, int t, int color, int dash, int gap) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float dx = x2 - x1;
    float dy = y2 - y1;
	int steps = max(abs(dx), abs(dy));
	float xi = dx / (float) steps;
    float yi = dy / (float) steps;
	float x = x1, y = y1;
	int count = 0;
	
    for (int i = 0; i <= steps; i++) {
    
    	if (count < dash) {
            drawPixel(round(x), round(y), t, color);
        }
      
        count++;

        if (count >= dash + gap) {
            count = 0;
        }
        
		x += xi;
        y += yi;
        
    }

    getch();
    closegraph();
}

int main() {
    int x1, y1, x2, y2, t, color, dash, gap;
   
    cout << "Enter the first coordinate (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the second coordinate (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Enter the thickness: ";
    cin >> t;
    cout << "Enter the color (0-15): ";
    cin >> color;
    cout << "Enter the length of the dash: ";
    cin >> dash;
    cout << "Enter the length of the gap: ";
    cin >> gap;

    DDA(x1, y1, x2, y2, t, color, dash, gap);

    return 0;
}

/* Horizontal Line: (100, 150) and (200, 150)
Vertical Line: (150, 100) and (150, 200)
Positive Slope Line: (100, 100) and (200, 200)
Negative Slope Line: (100, 200) and (200, 100)
Steep Slope Line: (100, 100) and (100, 200)
Shallow Slope Line: (100, 100) and (200, 120)
Diagonal Line: (120, 120) and (220, 220)
Endpoint Reversal: (200, 120) and (120, 220)
Horizontal Line Reversed: (200, 150) and (100, 150)
Vertical Line Reversed: (150, 200) and (150, 100) */
