typedef pair<int,int> tile;
#define color first
#define number second

typedef vector<tile> tiles;
typedef vector<tile>::iterator vit;

#define WAN    0
#define SUO    1
#define TONG   2
#define DONG   3
#define NAN    4
#define XI     5
#define BEI    6
#define ZHONG  7
#define FA     8
#define BAI    9


bool Singles[10][10]={false};


int abs(int x){
	if (x>0) return x;
	return -x;
}

// util.cpp

bool IsNumber(int color);
bool IsHonor(int color);
tile MakeTile(int color, int value);
tile MakeTile(string str);
tile MakeTile(const char* str);
string Tile2Str(tile T);


// global.cpp

void Initialize(); 
void AppearTile(tile T);
int RestTile(tile T);

// role.cpp

void Starting();
void Gaming();
int CountTile(tile T);
void AddTile(tile T);
void MoveTile(tile T);
void Out(tile T);
void Chi(tile T);
void Peng();
void Gang();
void JiaGang(tile T);
void AnGang(tile T);
void Pass();
void QiangGang();
void Hu();


// algo.cpp

void Algo_Initialize();
void PushTile(tile T);
bool TestHu(tile T);
void ActionAfterPick(tile T);
void ActionAfterMOut(tile T);



