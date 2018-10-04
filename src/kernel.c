
#define COLOR_BLACK				(0x0)
#define COLOR_BLUE				(0x1)
#define COLOR_GREEN				(0x2)
#define COLOR_CYAN				(0x3)
#define COLOR_RED				(0x4)
#define COLOR_MAGENTA			(0x5)
#define COLOR_BROWN				(0x6)
#define COLOR_GRAY				(0x7)
#define COLOR_DARK_GRAY			(0x8)
#define COLOR_LIGHT_BLUE		(0x9)
#define COLOR_LIGHT_GREEN		(0xa)
#define COLOR_LIGHT_CYAN		(0xb)
#define COLOR_LIGHT_RED			(0xc)
#define COLOR_LIGHT_MAGENTA		(0xd)
#define COLOR_YELLOW			(0xe)
#define COLOR_WHITE				(0xf)

#define WIDTH 80
#define HEIGHT 25

typedef struct cell {
    char character;
    unsigned char fg : 4;
    unsigned char bg : 4;
} cell_t;

static cell_t* cell = (cell_t*)0xB8000;
static int cursor_x = 0, cursor_y = 0;

void clear() {
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        cell[i].character = ' ';
    }
}

void scroll() {
    for(int i = 0; i < (HEIGHT - 1) * WIDTH; i++) {
        cell[i] = cell[i + WIDTH];
    }

    for(int i = 0; i < WIDTH; i++) {
        cell[(HEIGHT - 1) * WIDTH + i].character = ' ';
        cell[(HEIGHT - 1) * WIDTH + i].fg = COLOR_WHITE;
        cell[(HEIGHT - 1) * WIDTH + i].bg = COLOR_BLACK;
    }
}

void print_colored(const char* message, char bg, char fg) {
    while(*message != 0) {
        char c = *message;
        message++;

        switch(c) {
            case '\n': {
                cursor_x = 0;
                cursor_y++;
            } break;
            default: {
                cell[cursor_x + cursor_y * WIDTH].character = c;
                cell[cursor_x + cursor_y * WIDTH].bg = bg;
                cell[cursor_x + cursor_y * WIDTH].fg = fg;
                cursor_x++;
            } break;
        }
        
        if(cursor_y == HEIGHT) {
            scroll();
            cursor_y--;
            cursor_x = 0;
        }

        if(cursor_x == WIDTH) {
            return;
        }
    }
}

void print(const char* message) {
    print_colored(message, COLOR_BLACK, COLOR_WHITE);
}

void kmain() {
    clear();
    for(int i = 0; i < 25; i++) {
        print("test\n");
    }
    print_colored("colored\n", COLOR_BLUE, COLOR_YELLOW);
}
