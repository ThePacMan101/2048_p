#define bool int
#define true 1
#define false 0

//game-states definition:
typedef int tState;
#define menu_main       0
#define menu_options    1
#define menu_scores     2
#define menu_ranking    3
#define game_playing    4
#define game_defeat     5
#define game_victory    6
// [...] 
// Each state defines a screen that a user may interact with



typedef struct {
    int id;
    char name[20];
    //[...] TODO

}tUser;

typedef struct {
    int board[4][4];
    tUser user;
    int score;
} tGame;

void tick(int key,bool*running,tGame *game,tState *state);
/*
The tick function calls other functions depending on the current state
it also updates all global variables based on user's last input key
*/

void render(tState state,tGame game);
/*
The render function calls other functions to show the screen based on the
current state and the game variable
*/