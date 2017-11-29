#include <iostream>
#include <conio.h> // Þarf fyrir getch
using namespace std;

int pos_x;
int pos_y;
int map_width;
int map_height;

// Ýtir gömlu myndinni í burtu svo tvær sjást ekki í einu.
void clear_screen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

// Teiknar . allstaðar nema þar sem leikmaðurinn er, þar er @ notað.
void render()
{
    clear_screen();
    for (int i = 0; i < map_height; i++)
    {
        for (int j = 0; j < map_width; j++)
        {
            if (pos_x == j && pos_y == i)
            {
                cout << "@";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}

// Tekur við bókstaf og færir stöðu leikmanns í átt aftir henni. Notað er ASDW-kerfi.
void update()
{
    char c = getch();
    switch (c)
    {
        case 'a':
            pos_x--;
            break;
        case 'd':
            pos_x++;
            break;
        case 'w':
            pos_y--;
            break;
        case 's':
            pos_y++;
            break;
    }
}

// Stillir upphafsstöðu leiksins, stærð korts og teiknar hana.
void setup()
{
    pos_x = 2;
    pos_y = 2;
    map_width = 40;
    map_height = 10;
    render();
}

int main()
{
        // Keyrt einu sinni í upphafi
        setup();

        // Single frame er ein keyrsla á þessari lykkju
        while(1)
        {
            // Uppfæra staðsetningar
            update();
            // Teikna
            render();
        }
}
