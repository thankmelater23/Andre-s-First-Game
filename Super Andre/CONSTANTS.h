const int	GRASS					=10;
const int	TOP						=2;
const int	SKY						=3;
const int	GROUND					=4;
const int	EMPTY					=5;
const int	ROCK					=6;
const int	NONE					=0;

const int	PIPE					=1000;
const int	PIPE2					=1001;
const int	BRICK					=1002;
const int	BRICK2					=1003;
const int	BOARDER					=1004;
const int	BOARDER2				=1005;
const int	ENEMY					=1006;
const int	INV						=1007;


const int	TILE_WIDTH				=32;
const int	TILE_HEIGHT				=24;
const int	TILE_ROWS				=20;
const int	TILE_COLS				=20;
const int	FIRST_OBSTACLE_SPRITE	=100;				



const int	HERO					=1;
const int	ALEC_ROWS				=1;
const int	ALEC_COLS				=1;

const int	STANDING				=1;
const int	JUMP_START				=1;
const int	JUMP_END 				=1;
const int	EAST_START_WALK			=1;
const int	EAST_END_WALK			=1;
const int	WEST_START_WALK			=1;
const int	WEST_END_WALK			=1;
const int	NORTH_START_WALK		=1;
const int	NORTH_END_WALK			=1;
const int	SOUTH_START_WALK		=1;
const int	SOUTH_END_WALK			=1;



const int	DELAY					=200;
const int	THUMP_SOUND				=1;
const int	REFRESH_RATE			=15;






int const RGT_LFT_SPD =			10;
int const DWN_SPD =				10;
int const UP_SPD =				100;




	
DWORD const GREEN = dbRGB(0, 255, 0);
DWORD const RED = dbRGB(255, 0, 0);
DWORD const BLUE = dbRGB(0, 0, 255);


bool falling = false;