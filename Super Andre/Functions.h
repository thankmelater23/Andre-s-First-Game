void displayTiles(int map[][TILE_COLS], int rows)
	{ 

		int x = 10, y = 0;


		for(int r = 0; r < rows; r++)
		{
			x = 10;

			for(int c = 0; c < TILE_COLS; c++)
			{

				dbPasteImage(map[r][c], x, y);

				x += TILE_WIDTH;
			}

			y += TILE_HEIGHT;
		}
	}

void displayObstacles(int map[][TILE_COLS], int rows)
	{

		int x = 10, y = 0;

		for(int r = 0; r < rows; r++)
		{
			x = 10;

			for(int c = 0; c < TILE_COLS; c++)
			{

				if(map[r][c] != NONE)
				{
					dbSprite(map[r][c], x, y, map[r][c]);

					
				}
				x += TILE_WIDTH;
			}

			y += TILE_HEIGHT;
			
		}

		
	}

void loadGSM()
{
	dbSetDisplayMode(640, 480, 32);
	dbSetWindowTitle("SUPER ANDRE");
	dbSetImageColorKey(0, 255, 0);


	dbLoadImage("Grass.bmp",	GRASS);
	dbLoadImage("Top.bmp",		TOP);
	dbLoadImage("Sky.bmp",		SKY);
	dbLoadImage("Ground.bmp",	GROUND);
	dbLoadImage("Pipe.bmp",		PIPE); 
	dbLoadImage("Empty.bmp",	EMPTY);
	dbLoadImage("Pipe.bmp",		PIPE2);
	dbLoadImage("Enemy.bmp",	ENEMY);
	dbLoadImage("Brick.bmp",	BRICK2);
	dbLoadImage("Brick.bmp",	BRICK);
	dbLoadImage("Boarder.bmp",	BOARDER);
	dbLoadImage("Boarder.bmp",	BOARDER2);
	dbLoadImage("Ground_inv.bmp",	INV);
	dbLoadMusic("Grove Street.mp3", 1);
	dbLoadSound("thump.wav",		THUMP_SOUND); 


	dbCreateAnimatedSprite(HERO, "Andre.bmp", 1, 1, HERO);

	dbPlaySprite(HERO, 1, 1, DELAY);

	dbSprite(HERO, 100, 100, HERO);

	dbSyncOn();
	dbSyncRate(REFRESH_RATE);
	


	
	
}

void move()
{



	


	
	if(dbUpKey() == 1)
		{
			
			if(dbSpriteCollision(HERO, 1000) == 1 || dbSpriteCollision(HERO, 1001) == 1 || dbSpriteCollision(HERO, 1002) == 1 || dbSpriteCollision(HERO, 1003) == 1 || dbSpriteCollision(HERO, 1004) == 1 || dbSpriteCollision(HERO, 1005) == 1 || dbSpriteCollision(HERO, 1006) == 1 || dbSpriteCollision(HERO, 1007) == 1)

			{
				dbMoveSprite(HERO, UP_SPD);
			}

					
		}



		if(dbLeftKey() == 1)
		{
			dbPlaySprite(HERO, 1, 1, 50);

			dbRotateSprite(HERO,270);
			dbMoveSprite(HERO,RGT_LFT_SPD);
			dbRotateSprite(HERO, 0);

		}



		if(dbRightKey() == 1)
		{
			dbPlaySprite(HERO, 1, 1, 50);
			dbRotateSprite(HERO,90);
			dbMoveSprite(HERO,RGT_LFT_SPD);
			dbRotateSprite(HERO, 0);

		}



		if(dbDownKey() == 1 && dbSpriteCollision(HERO, 0) == 1)
			{
			
				dbPlaySprite(HERO, 1, 1, 100);
			}




}

void detectCollision()
{

	
	if(dbSpriteCollision(HERO, BOARDER))
		{

			dbRotateSprite(HERO,90);
			dbMoveSprite(HERO,RGT_LFT_SPD);
			dbRotateSprite(HERO, 0);
	}

		if(dbSpriteCollision(HERO, BOARDER2))
		{
			dbRotateSprite(HERO,270);
			dbMoveSprite(HERO,RGT_LFT_SPD);
			dbRotateSprite(HERO, 0);
		}
		
		
			if(dbSpriteCollision(HERO, 1000) == 1 || dbSpriteCollision(HERO, 1001) == 1 || dbSpriteCollision(HERO, 1002) == 1 || dbSpriteCollision(HERO, 1003) == 1 || dbSpriteCollision(HERO, 1004) == 1 || dbSpriteCollision(HERO, 1005) == 1  || dbSpriteCollision(HERO, 1006) == 1 || dbSpriteCollision(HERO, 1007) == 1) 
			{
				//Do Nothing
		
			}

			else
			{
			dbRotateSprite(HERO,180);
			dbMoveSprite(HERO,DWN_SPD);
			dbRotateSprite(HERO,0);
		}


return;

}

void andreText()
{
	dbSetCursor(dbScreenWidth() / 2 - 100, dbScreenHeight() / 2 - 40);
	dbSetTextSize(42);
	dbSetTextToBoldItalic();
	dbInk(RED, GREEN);
	dbPrint("SUPER ANDRE");
	dbWait(2000);
	
	return;
}

void playMusic()
{
	dbPlayMusic(1);
	dbSetMusicVolume(1, 30);

	return;
}

void memoryLeak()
{

	for(int i = 1; i > 10; i++)
	{
	dbDeleteImage(i);
	dbDeleteSprite(i);
	dbDeleteSound(i);
	dbDeleteMusic(i);
	}
}