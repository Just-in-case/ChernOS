#define COLOR_BLACK                     (0x0)
#define COLOR_BLUE                      (0x1)
#define COLOR_GREEN                     (0x2)
#define COLOR_CYAN                      (0x3)
#define COLOR_RED                       (0x4)
#define COLOR_MAGENTA                   (0x5)
#define COLOR_BROWN                     (0x6)
#define COLOR_GRAY                      (0x7)
#define COLOR_DARK_GRAY                 (0x8)
#define COLOR_LIGHT_BLUE                (0x9)
#define COLOR_LIGHT_GREEN               (0xa)
#define COLOR_LIGHT_CYAN                (0xb)
#define COLOR_LIGHT_RED                 (0xc)
#define COLOR_LIGHT_MAGENTA             (0xd)
#define COLOR_YELLOW                    (0xe)
#define COLOR_WHITE                     (0xf)

#define WIDTH 80
#define HEIGHT 25

typedef struct cell {
    char character;
    unsigned char fg : 4;
    unsigned char bg : 4;
} cell_t;

static cell_t* cell = (cell_t*)0xB8000; 
static int cursor_x = 0, cursor_y = 0;

struct cell scr_buff_up[WIDTH * HEIGHT] = {{' ', COLOR_WHITE, COLOR_BLACK}};
static unsigned int scr_buff_up_index = 0;

struct cell scr_buff_down[WIDTH * HEIGHT] = {{' ', COLOR_WHITE, COLOR_BLACK}}; 
static unsigned int scr_buff_down_index = 0;

void print_up_buff(){
    for(unsigned int i = 0; i < WIDTH; i++){
        cell[i].character = scr_buff_up[scr_buff_up_index - WIDTH + i].character;
        cell[i].fg = COLOR_WHITE;
        cell[i].bg = COLOR_BLACK;

    }
    scr_buff_up_index -= WIDTH;
}

void print_down_buff(){
    int counter = 0;
    for(unsigned int i = (HEIGHT - 1) * WIDTH; i < HEIGHT * WIDTH; i++){
        cell[i].character = scr_buff_down[scr_buff_down_index - WIDTH + counter].character;
        cell[i].fg = COLOR_WHITE;
        cell[i].bg = COLOR_BLACK;
        counter++;
    }
    scr_buff_down_index -= WIDTH;
}

void store_in_up_buff(){
    for(int i = 0; i < WIDTH; i++){
        scr_buff_up[scr_buff_up_index].character = cell[i].character;
        scr_buff_up[scr_buff_up_index].fg = cell[i].fg;
        scr_buff_up[scr_buff_up_index].bg = cell[i].bg;
        scr_buff_up_index++;
    }
}

void store_in_down_buff(){
    for(int i = (HEIGHT - 1) * WIDTH; i < HEIGHT * WIDTH; i++){
        scr_buff_down[scr_buff_down_index].character = cell[i].character;
        scr_buff_down[scr_buff_down_index].fg = cell[i].fg;
        scr_buff_down[scr_buff_down_index].bg = cell[i].bg;
        scr_buff_down_index++;
    }
}

void scroll_up(){
    store_in_down_buff();
    for(unsigned int i = WIDTH * HEIGHT; i >  WIDTH; i--){
        cell[i] = cell[i - WIDTH];
    }
    print_up_buff();
    cursor_x = 0;
    cursor_y = HEIGHT;
}

void scroll_down(){
    store_in_up_buff();
    for(int i = 0; i < (HEIGHT - 1) * WIDTH; i++){
        cell[i] = cell[i + WIDTH];
    }
    for(int i = 0; i < WIDTH; i++){
        cell[(HEIGHT - 1) * WIDTH + i].character = ' ';
        cell[(HEIGHT - 1) * WIDTH + i].fg = COLOR_WHITE;
        cell[(HEIGHT - 1) * WIDTH + i].bg = COLOR_BLACK;
    }
    print_down_buff();
    cursor_x = 0;
    cursor_y--;

}

void clear(){
    for(unsigned int i = 0; i < WIDTH * HEIGHT; i++){
        cell[i].character = ' ';
        cell[i].fg = COLOR_WHITE;
        cell[i].bg = COLOR_BLACK;
    }
}

void print_colored(const char* msg, int fg, int bg){
    while(*msg){
        char c = *msg;
        msg++;

        switch(c){
            case '\n': {
                cursor_x = 0;
                cursor_y++;
            } break;
            default:{
                cell[cursor_x + cursor_y * WIDTH].character = c;
                cell[cursor_x + cursor_y * WIDTH].fg = fg;
                cell[cursor_x + cursor_y * WIDTH].bg = bg;
                cursor_x++;
            }break;
        }
        if(cursor_y == HEIGHT){
            scroll_down();
        }
		
        if(cursor_x == WIDTH){
            return;			
        }
    }
}
void print(const char* msg){
    print_colored(msg, COLOR_WHITE, COLOR_BLACK);
}

void kmain(){
      
}
