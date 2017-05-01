#include "DarkGDK.h"
#include "time.h"


// Variables
static const int BACKGROUND = 1;
static const int BAR = 2;
static const int HAMMER = 3;
static const int GOAT = 4;
// Standing Goats
static const int GOAT_1 = 101;
static const int GOAT_2 = 102;
static const int GOAT_3 = 103;
static const int GOAT_4 = 104;
static const int GOAT_5 = 105;
static const int GOAT_6 = 106;
static const int GOAT_7 = 107;
static const int GOAT_8 = 108;
static const int GOAT_9 = 109;
static const int GOAT_10 = 110;
// Hit Goat
static const int GOAT_1_1 = 10;
static const int GOAT_2_2 = 20;
static const int GOAT_3_3 = 30;
static const int GOAT_4_4 = 40;
static const int GOAT_5_5 = 50;
static const int GOAT_6_6 = 60;
static const int GOAT_7_7 = 70;
static const int GOAT_8_8 = 80;
static const int GOAT_9_9 = 90;
static const int GOAT_10_10 = 100;

bool MouseClick = 0;
int hit = 0;
int goatCounter = 0;


void StartGame()
{

	dbSyncOn();
	dbSyncRate(60);
	dbDisableEscapeKey();
	dbRandomize(dbTimer());
	dbSetImageColorKey ( 255, 0, 255 );
	dbLoadMusic("Harvest_Moon_-_Meet_Love.mid", 6);
	dbPlayMusic(6);

	// Load Background
	dbLoadImage("background.bmp", BACKGROUND);
	dbSprite(BACKGROUND, 0, 25, BACKGROUND);
	dbSizeSprite(BACKGROUND, dbScreenWidth(), dbScreenHeight());
	dbSetSpritePriority(BACKGROUND, 0);
	dbLoadImage("bar.bmp", BAR);
	dbSprite(BAR, 0, 0, BAR);
	dbSetSpritePriority(BAR, 6);

	// GOAT
	dbCreateAnimatedSprite(GOAT_1, "goat.bmp", 8, 1, GOAT_1);
	dbCreateAnimatedSprite(GOAT_2, "goat.bmp", 8, 1, GOAT_2);
	dbCreateAnimatedSprite(GOAT_3, "goat.bmp", 8, 1, GOAT_3);
	dbCreateAnimatedSprite(GOAT_4, "goat.bmp", 8, 1, GOAT_4);
	dbCreateAnimatedSprite(GOAT_5, "goat.bmp", 8, 1, GOAT_5);
	dbCreateAnimatedSprite(GOAT_6, "goat.bmp", 8, 1, GOAT_6);
	dbCreateAnimatedSprite(GOAT_7, "goat.bmp", 8, 1, GOAT_7);
	dbCreateAnimatedSprite(GOAT_8, "goat.bmp", 8, 1, GOAT_8);
	dbCreateAnimatedSprite(GOAT_9, "goat.bmp", 8, 1, GOAT_9);
	dbCreateAnimatedSprite(GOAT_10, "goat.bmp", 8, 1, GOAT_10);
	dbSetSpritePriority(GOAT_1, 2);
	dbSetSpritePriority(GOAT_2, 2);
	dbSetSpritePriority(GOAT_3, 2);
	dbSetSpritePriority(GOAT_4, 2);
	dbSetSpritePriority(GOAT_5, 2);
	dbSetSpritePriority(GOAT_6, 2);
	dbSetSpritePriority(GOAT_7, 2);
	dbSetSpritePriority(GOAT_8, 2);
	dbSetSpritePriority(GOAT_9, 2);
	dbSetSpritePriority(GOAT_10, 2);

	// Hit Goat
	dbCreateAnimatedSprite(GOAT_1_1, "goat_hit.bmp", 4, 1, GOAT_1_1);
	dbCreateAnimatedSprite(GOAT_2_2, "goat_hit.bmp", 4, 1, GOAT_2_2);
	dbCreateAnimatedSprite(GOAT_3_3, "goat_hit.bmp", 4, 1, GOAT_3_3);
	dbCreateAnimatedSprite(GOAT_4_4, "goat_hit.bmp", 4, 1, GOAT_4_4);
	dbCreateAnimatedSprite(GOAT_5_5, "goat_hit.bmp", 4, 1, GOAT_5_5);
	dbCreateAnimatedSprite(GOAT_6_6, "goat_hit.bmp", 4, 1, GOAT_6_6);
	dbCreateAnimatedSprite(GOAT_7_7, "goat_hit.bmp", 4, 1, GOAT_7_7);
	dbCreateAnimatedSprite(GOAT_8_8, "goat_hit.bmp", 4, 1, GOAT_8_8);
	dbCreateAnimatedSprite(GOAT_9_9, "goat_hit.bmp", 4, 1, GOAT_9_9);
	dbCreateAnimatedSprite(GOAT_10_10, "goat_hit.bmp", 4, 1, GOAT_10_10);
	dbSetSpritePriority(GOAT_1_1, 4);
	dbSetSpritePriority(GOAT_2_2, 4);
	dbSetSpritePriority(GOAT_3_3, 4);
	dbSetSpritePriority(GOAT_4_4, 4);
	dbSetSpritePriority(GOAT_5_5, 4);
	dbSetSpritePriority(GOAT_6_6, 4);
	dbSetSpritePriority(GOAT_7_7, 4);
	dbSetSpritePriority(GOAT_8_8, 4);
	dbSetSpritePriority(GOAT_9_9, 4);
	dbSetSpritePriority(GOAT_10_10, 4);


	// Cursor
	dbCreateAnimatedSprite(HAMMER, "hammer.bmp", 2, 1, HAMMER);
	dbSprite(HAMMER, dbMouseX(), dbMouseY(), HAMMER);
	dbHideMouse();
	dbSetSpritePriority(3, 6);

	// Hit Sound
	dbLoadSound("scream.wav", 5);
}



void  goatSpawn()
{
	// Goat Spawn
	
	dbSprite(GOAT_1, 102, 62, GOAT_1);
	dbSprite(GOAT_2, 272, 62, GOAT_2);
	dbSprite(GOAT_3, 432, 62, GOAT_3);
	dbSprite(GOAT_4, 68, 173, GOAT_4);
	dbSprite(GOAT_5, 205, 173, GOAT_5);
	dbSprite(GOAT_6, 335, 173, GOAT_6);
	dbSprite(GOAT_7, 478, 173, GOAT_7);
	dbSprite(GOAT_8, 100, 295, GOAT_8);
	dbSprite(GOAT_9, 272, 295, GOAT_9);
	dbSprite(GOAT_10, 445, 295, GOAT_10);
}

void goatHitRespawn()
{
	dbCreateAnimatedSprite(GOAT_1_1, "goat_hit.bmp", 4, 1, GOAT_1_1);
	dbCreateAnimatedSprite(GOAT_2_2, "goat_hit.bmp", 4, 1, GOAT_2_2);
	dbCreateAnimatedSprite(GOAT_3_3, "goat_hit.bmp", 4, 1, GOAT_3_3);
	dbCreateAnimatedSprite(GOAT_4_4, "goat_hit.bmp", 4, 1, GOAT_4_4);
	dbCreateAnimatedSprite(GOAT_5_5, "goat_hit.bmp", 4, 1, GOAT_5_5);
	dbCreateAnimatedSprite(GOAT_6_6, "goat_hit.bmp", 4, 1, GOAT_6_6);
	dbCreateAnimatedSprite(GOAT_7_7, "goat_hit.bmp", 4, 1, GOAT_7_7);
	dbCreateAnimatedSprite(GOAT_8_8, "goat_hit.bmp", 4, 1, GOAT_8_8);
	dbCreateAnimatedSprite(GOAT_9_9, "goat_hit.bmp", 4, 1, GOAT_9_9);
	dbCreateAnimatedSprite(GOAT_10_10, "goat_hit.bmp", 4, 1, GOAT_10_10);
	dbSetSpritePriority(GOAT_1_1, 5);
	dbSetSpritePriority(GOAT_2_2, 5);
	dbSetSpritePriority(GOAT_3_3, 5);
	dbSetSpritePriority(GOAT_4_4, 5);
	dbSetSpritePriority(GOAT_5_5, 5);
	dbSetSpritePriority(GOAT_6_6, 5);
	dbSetSpritePriority(GOAT_7_7, 5);
	dbSetSpritePriority(GOAT_8_8, 5);
	dbSetSpritePriority(GOAT_9_9, 5);
	dbSetSpritePriority(GOAT_10_10, 5);
}


void goatDespawn()
{

	if(dbSpriteHit(HAMMER, GOAT_1) == 1)
	{
		dbDeleteSprite(GOAT_1);
		hit++;
		goatCounter++;
		dbPlaySound(5);
		dbSprite(GOAT_1_1, 102, 62, GOAT_1_1);
		dbPlaySprite(GOAT_1_1, 1, 4, 1);
	}
	else if(dbSpriteHit(HAMMER, GOAT_2) == 1)
	{
		dbDeleteSprite(GOAT_2);
		hit++;
		goatCounter++;
		dbPlaySound(5);
		dbSprite(GOAT_2_2, 272, 62, GOAT_2_2);
		dbPlaySprite(GOAT_2_2, 1, 4, 60);
	}
	else if(dbSpriteHit(HAMMER, GOAT_3) == 1)
	{
		dbDeleteSprite(GOAT_3);
		hit++;
		goatCounter++;
		dbPlaySound(5);
		dbSprite(GOAT_3_3, 432, 62, GOAT_3_3);
		dbPlaySprite(GOAT_3_3, 1, 4, 60);
	}
	else if(dbSpriteHit(HAMMER, GOAT_4) == 1)
	{
		dbDeleteSprite(GOAT_4);
		hit++;
		goatCounter++;
		dbPlaySound(5);
		dbSprite(GOAT_4_4, 68, 153, GOAT_4_4);
		dbPlaySprite(GOAT_4_4, 1, 4, 60);
	}
	else if(dbSpriteHit(HAMMER, GOAT_5) == 1)
	{
		dbDeleteSprite(GOAT_5);
		hit++;
		goatCounter++;
		dbPlaySound(5);
		dbSprite(GOAT_5_5, 205, 153, GOAT_5_5);
		dbPlaySprite(GOAT_5_5, 1, 4, 60);
	}
	else if(dbSpriteHit(HAMMER, GOAT_6) == 1)
	{
		dbDeleteSprite(GOAT_6);
		hit++;
		goatCounter++;
		dbPlaySound(5);
		dbSprite(GOAT_6_6, 335, 153, GOAT_6_6);
		dbPlaySprite(GOAT_6_6, 1, 4, 60);
	}
	else if(dbSpriteHit(HAMMER, GOAT_7) == 1)
	{
		dbDeleteSprite(GOAT_7);
		hit++;
		goatCounter++;
		dbSprite(GOAT_7_7, 478, 153, GOAT_7_7);
		dbPlaySprite(GOAT_7_7, 1, 4, 60);
	}
	else if(dbSpriteHit(HAMMER, GOAT_8) == 1)
	{
		dbDeleteSprite(GOAT_8);
		hit++;
		goatCounter++;
		dbPlaySound(5);
		dbSprite(GOAT_8_8, 100, 295, GOAT_8_8);
		dbPlaySprite(GOAT_8_8, 1, 4, 60);
	}
	else if(dbSpriteHit(HAMMER, GOAT_9) == 1)
	{
		dbDeleteSprite(GOAT_9);
		hit++;
		goatCounter++;
		dbPlaySound(5);
		dbSprite(GOAT_9_9, 272, 295, GOAT_9_9);
		dbPlaySprite(GOAT_9_9, 1, 4, 60);
	}
	else if(dbSpriteHit(HAMMER, GOAT_10) == 1)
	{
		dbDeleteSprite(GOAT_10);
		hit++;
		goatCounter++;
		dbPlaySound(5);
		dbSprite(GOAT_10_10, 445, 295, GOAT_10_10);
		dbPlaySprite(GOAT_10_10, 1, 4, 60);
	}
}

void goatHitDespawn()
{
	dbDeleteSprite(GOAT_1_1);
	dbDeleteSprite(GOAT_2_2);
	dbDeleteSprite(GOAT_3_3);
	dbDeleteSprite(GOAT_4_4);
	dbDeleteSprite(GOAT_5_5);
	dbDeleteSprite(GOAT_6_6);
	dbDeleteSprite(GOAT_7_7);
	dbDeleteSprite(GOAT_8_8);
	dbDeleteSprite(GOAT_9_9);
	dbDeleteSprite(GOAT_10_10);

}
void goatRespawn()
{
	dbCreateAnimatedSprite(GOAT_1, "goat.bmp", 8, 1, GOAT_1);
	dbCreateAnimatedSprite(GOAT_2, "goat.bmp", 8, 1, GOAT_2);
	dbCreateAnimatedSprite(GOAT_3, "goat.bmp", 8, 1, GOAT_3);
	dbCreateAnimatedSprite(GOAT_4, "goat.bmp", 8, 1, GOAT_4);
	dbCreateAnimatedSprite(GOAT_5, "goat.bmp", 8, 1, GOAT_5);
	dbCreateAnimatedSprite(GOAT_6, "goat.bmp", 8, 1, GOAT_6);
	dbCreateAnimatedSprite(GOAT_7, "goat.bmp", 8, 1, GOAT_7);
	dbCreateAnimatedSprite(GOAT_8, "goat.bmp", 8, 1, GOAT_8);
	dbCreateAnimatedSprite(GOAT_9, "goat.bmp", 8, 1, GOAT_9);
	dbCreateAnimatedSprite(GOAT_10, "goat.bmp", 8, 1, GOAT_10);
	dbSetSpritePriority(GOAT_1, 2);
	dbSetSpritePriority(GOAT_2, 2);
	dbSetSpritePriority(GOAT_3, 2);
	dbSetSpritePriority(GOAT_4, 2);
	dbSetSpritePriority(GOAT_5, 2);
	dbSetSpritePriority(GOAT_6, 2);
	dbSetSpritePriority(GOAT_7, 2);
	dbSetSpritePriority(GOAT_8, 2);
	dbSetSpritePriority(GOAT_9, 2);
	dbSetSpritePriority(GOAT_10, 2);
	dbSprite(GOAT_1, 102, 62, GOAT_1);
	dbSprite(GOAT_2, 272, 62, GOAT_2);
	dbSprite(GOAT_3, 432, 62, GOAT_3);
	dbSprite(GOAT_4, 68, 153, GOAT_4);
	dbSprite(GOAT_5, 205, 153, GOAT_5);
	dbSprite(GOAT_6, 335, 153, GOAT_6);
	dbSprite(GOAT_7, 478, 153, GOAT_7);
	dbSprite(GOAT_8, 100, 295, GOAT_8);
	dbSprite(GOAT_9, 272, 295, GOAT_9);
	dbSprite(GOAT_10, 445, 295, GOAT_10);
}

void deleteImages()
{
	dbDeleteImage(1);
	dbDeleteImage(2);
	dbDeleteImage(3);
	dbDeleteImage(4);
	dbDeleteImage(100);
	dbDeleteImage(102);
	dbDeleteImage(103);
	dbDeleteImage(104);
	dbDeleteImage(105);
	dbDeleteImage(106);
	dbDeleteImage(107);
	dbDeleteImage(108);
	dbDeleteImage(109);
	dbDeleteImage(10);
	dbDeleteImage(20);
	dbDeleteImage(30);
	dbDeleteImage(40);
	dbDeleteImage(50);
	dbDeleteImage(60);
	dbDeleteImage(70);
	dbDeleteImage(80);
	dbDeleteImage(90);
	dbDeleteImage(100);
}
// MAIN CODE
void DarkGDK ( void )
{
	dbMaximiseWindow();
	dbDrawSpritesFirst();
	StartGame();
	dbRandomize(dbTimer());
	goatSpawn();
	while(LoopGDK())
	{
		
		// updates hammer when mouse position is changed
		if(dbMouseX() != 0 && dbMouseY() != 0)
			dbSprite(3, dbMouseX(), dbMouseY(), 3);


		// animate hammer when clicked
		if(dbMouseClick() == 1)
		{
			while(dbMouseClick() == 1)
			{
				MouseClick = 1;
			}
			dbSetSpriteFrame(3, 2);
			goatDespawn();

		}
		else if(dbMouseClick() == 0)
		{
			dbSetSpriteFrame(3, 1);
		}



		if(goatCounter == 7)
		{
			goatHitDespawn();
			goatRespawn();
			goatHitRespawn();
			goatCounter = 0;
		}
		
		/*while(clock() % 7)
		{
			
		}*/


	

		// Text
		dbText(0, 0, "Hit: ");
		dbText(50, 0, dbStr(hit));
		dbText(100, 0, "Timer:");
		dbText(175, 0, dbStr(clock()/1000));

		// EXIT
		if (dbEscapeKey())
			break;
		dbSync();
	}


	// Delete Images
	deleteImages();

	return;
}