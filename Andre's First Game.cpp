#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include <stdafx.h>

using namespace std;

//	Random Number Genoratorn
int rand_0toN1(int n);


//	Start Game
char Start_Game;
int Start_Screen;

//	Potion
int pot;
int pot2;
int Player_Potion();
int Enemy_Potion();

//	Players Attack Input
int AE, AP;

// Player Achievments
int pi3, pi5, p2i3, p2i5, dbx3, db2x3, ki2, k2i2, nl, n2l, p3k, e3k, pt, et;
int LS = 0;
//	Name Strings
string Player, Enemy;
void to_upper(string *cpt);

//	Player Attacks
int Player_Punch();
int Player_Kick();
int Player_Death_Blow();
int Plife_Swap();
int Ptackle();

//  Enemy Attacks
int Enemy_Punch();
int Enemy_Kick();
int Enemy_Death_Blow();
int Elife_Swap();
int Etackle();



// Players Attack Scheme
int Enemy_Select_Attack();
int Player_Select_Attack();

//	Players Health
int Enemy_Health = 40;
int Player_Health = 40;

int r(int n);
void swap(int *a, int *b);

int main() {
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t WELCOME TO \"FIGHT\"\n\n\n\n\n\n\n\n\n\n\t\t Developed by: Andre Villanueva";
	cout << "\n\n\t\t  Created on: October 5th, 2010\n\n\t\t\t\tGame #1\n\n\n\n";
	system("PAUSE");
	system("CLS");
	 while(1)	{
	Start_Screen;

	while(1) {
		cout << "Press \"s\" to Start, \"g\" for game instructions: ";
		cin >> Start_Game;
		 
		if(Start_Game == 's')
			break;
		if(Start_Game == 'g')	{
			system("CLS");
			cout <<  "WELCOME TO FIGHT\n\n\nThere's 3 Attacks to choose from, one potion option, one magice spell, and a\nHealth check option. \n\n";
			cout << "1)Punch has an 8 out of 10 chance of success, which deals -3 damage\n\n2)Kick has a 1 out of 2 chance of success,which deals -5 damage\n\n";
			cout << "3)Death Blow has an 5 out of 12 chance of success, which deals -10 damage\nand if missed it gives the next player a counter \nattack,"; 
			cout << " and his following attack\n\n4)Potion, gives the player 15 life points, but only has 1 out of 2 chance of it working, and players only ";
			cout << "gets 3 potions a game\n\n5)Health Swap has an 2 out of 3 chance of success and swaps the life points of \nthe players.This spell can ";
			cout << "only be attempted once a game between the two players\n\n6)Health Check allows the player to check his/her health with the option to \nstill";
			cout << " select an attack after";
			cout << "\n\nThe game consists of *Player Achievments* which consists of extra life, \nstronger attacks, extra attacks, and ect...\n\n";
			cout << "GAME PLAYER ACHIEVMENTS LIST\n\n1)DOUBLE PUNCH\n2)BLOOD FLOW\n3)DOUBLE KICK\n4)STUNNED\n5)LIFE DESPERATION\n6)TRIPPLE KICK\n\nGood Luck on achieving and figuring ";
			cout << "out what these achivments do...\n\n";
			system("PAUSE");
			system("CLS");		}
	}

//  Player Identifier

	system ("CLS");
	cout << "Player 1 Enter Your Name: ";
	getline(cin,Player);
	getline(cin, Player);
	
	cout << "\nPlayer 2 Enter Your name: ";
	getline(cin, Enemy);
	Player[0] = toupper(Player[0]);
	Enemy[0] = toupper(Enemy[0]);


	// Game Resets
	pt = 0;
	et = 0;
	pi3 = 0;
	pi5 = 0; 
	p2i3 = 0; 
	p2i5 = 0;
	dbx3 = 0; 
	db2x3 = 0; 
	ki2 = 0; 
	k2i2 = 0; 
	nl = 0; 
	n2l = 0;
	LS = 0;
	p3k = 0;
	e3k = 0;
	pot = 0;
	pot2 = 0;
	Enemy_Health = 50;
	Player_Health = 50;

	while(1) {

		srand(time(NULL));

// Enemy select an attack
		Player_Select_Attack();

// Player chooses an attack
		Enemy_Select_Attack();
		

		// Enemy and Player Health

		if(Enemy_Health <= 0 && Player_Health <= 0) {
			system("CLS");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "\nTie Game...\n";
				cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl << "\n\n";
				break; }
			if(Enemy_Health < 1) {
				system("CLS");
				cout << endl << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << Player << " Wins!!!\n";
				cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
				cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl << "\n\n";
				break;	}
			
				if(Player_Health < 1) {
					system("CLS");
					cout << endl << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy <<" Wins!!!\n";
					cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
					cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl << "\n\n";
					system("PAUSE");
					system("CLS");
					break;	}
}
	system("PAUSE");
	system("CLS");

			
	}

}


//	Player Select Attack
	int Player_Select_Attack() {
		system("PAUSE");
		system ("CLS");
			cout << "1)Punch\n2)Kick\n3)Death Blow\n4)Use Potion\n5)Check Health Statues\n6)Life Swap\n" << Player << " Select An Attack 1-6: ";
		cin >> AE;
		if (AE == 1)	{
			cout << "\n" << Player << " Threw A Punch At " << Enemy << endl;
		Player_Punch();
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;
			 }
		if (AE == 2)	{
			cout <<"\n" << Player <<" Attemped To Kick " << Enemy << "\n";
		Player_Kick();
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;}
		if (AE == 5)	{
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;
		Player_Select_Attack();	}
		if (AE == 3)	{
			cout <<"\n" << Player <<" Attemped Death Blow On " << Enemy << "\n";
		Player_Death_Blow();
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;}
		if (AE == 4)	{
		Player_Potion();
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;}
		if (AE == 6)	{
			Plife_Swap();	}
		
		
	return 0;	}	
	int Enemy_Select_Attack() {
			system("PAUSE");
			system ("CLS");
			cout << "1)Punch\n2)Kick\n3)Death Blow\n4)Use Potion\n5)Check Health Statues\n6)Life Swap\n" << Enemy << " Select An Attack 1-6: ";
		cin >> AP;
		if (AP == 1)	{
			cout << "\n" << Enemy << " Threw A Punch At " << Player << endl;
		Enemy_Punch();
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;}
		if (AP == 2)	{
			cout <<"\n" << Enemy <<" Attemped To Kick " << Player<< "\n";
		Enemy_Kick();
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;}
		if (AP == 5) {
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;
		Enemy_Select_Attack();	}
		if (AP == 3)	{
			cout <<"\n" << Enemy <<" Attemped Death Blow On " << Player<< "\n";
		Enemy_Death_Blow();
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;}
		if (AP == 4)	{
		Enemy_Potion();
			cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;}
		if (AP == 6)	{
			Elife_Swap();	}
		
		
return 0;	}



// Player Attack Fucntions
	int Player_Punch() {
	    srand(time(NULL));
		int *EH = &Enemy_Health;
		int *PH = &Player_Health;
		int s = r(5);
		s;
		if (s != 4)	{
			++pi3;
			++pi5;
			if(pi5 == 5)	{
				cout << "Hit Succesful\n";
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(BLOOD FLOW)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Player << " Landed 5 consecutive succesful punches.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Player;
				cout << " got BLOOD FLOW\n\t\t\t\t\t\t\t\t\t\t\t\t" << Player << " gained 10 life points";
				*PH = *PH + 10;	
				pi5 = 0;
				pi3 = 0;
				return *PH;	}
			if(pi3 == 3) {
				cout << "Hit Succesful\n";
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(Double Punch Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Player << " Landed 3 consecutive succesful punches.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Player;
				cout << " landed a DOUBLE PUNCH\n\t\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy << " lost 5 life points";
				*EH = *EH -5;
				pi3 = 0;
			return *EH;			}
			cout << "Hit Succesful\n ";
			*EH = *EH - 3;
				return *EH;	}

		else	{
			pi3 = 0;
			pi5 = 0;
			cout << "Hit missed \n";
			return *EH = *EH;	}
	}

	int Player_Kick() {
	    srand(time(NULL));
		int *EH = &Enemy_Health;
		int s = r(2);
		s;
		if (s == 1)	{
			++p3k;
			if(p3k == 3)	{
					system("PAUSE");
					system("CLS");	
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(TRIPLE KICK Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Player << " Landed 3 succesful kicks.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Player;
				cout << " Attemps TRIPLE KICK\n ";
					int sum = 0;
				for (int i = 1; i < 4; i++)	{
					int b = r(6);
					system("PAUSE");
					system("CLS");	
					
					cout << "\n" << Player << " attempts kick #" << i << ", " << Player << " lands " <<  "- " << b <<  " damage to "  << Enemy << endl;
					sum = sum + b;
					*EH = * EH - b;
					if (i == 3)	{
						system("PAUSE");
						system("CLS");
						cout << "\nTotal damage done to " << Enemy << " is - " << sum << " damage\n";	}
	}
				p3k = 0;
				return *EH;	
			}
			cout << "Hit Succesful\n ";
			*EH = *EH - 5;
			++ki2;
				if(ki2 == 2) {
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(DOUBLE KICK Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Player << " Landed 2 consecutive succesful kicks.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Player;
				cout << " landed a DOUBLE KICK\n ";
				*EH = *EH -5;	
				ki2 = 0;	}
			return *EH;	}

		else {
			cout << "Hit missed\n";
			ki2 = 0;
			return *EH = *EH;	}
	}

	int Player_Death_Blow() {
	    srand(time(NULL));
		int *EH = &Enemy_Health;
		int s = r(10);
		s;
		if (s  < 4) {
			cout << "Hit Succesful\n";
			*EH = *EH - 10;
		++dbx3;
		if (dbx3 == 3)	{
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(Stunned Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\	" << Player << " Landed 3 Death Blows\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy;
				cout << " was STUNNED\n ";
				dbx3 = 0;
				Player_Select_Attack();	}
		
			return *EH;	}

		else {
		cout << "Hit missed, " << Enemy << " Countered The Attack";
			Enemy_Select_Attack();	}	

	}

	int Player_Potion() {
		++pot;
		srand(time(NULL));
		cout << endl << Player << " grabbed potion.\n";
		int *PH;
		PH = &Player_Health;
		int s = r(2);
		if(pot >= 4)	{
			cout << Player << " ran out of potions\n";
			return *PH = *PH;	}
		s;
		if(s == 1)	{
			cout << "Potion was used " << Player << " recieved 15 HP\n";
		 *PH = *PH + 15;
		if(*PH >= 60)	{
			return *PH = 60;	}
		}
		else	{
			cout << "This potion had no effect on " << Player << endl;
			++nl;
			if(nl == 3)	{
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(LIFE DESPERATION Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t All " << Player << " potions had no effect.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Player;
				cout << " Gained LIFE DESPERATION\n ";
				*PH = *PH +15;
			if(*PH >= 60)	{
			*PH = 60;	}
			}
			return *PH;	}
	}

	int Plife_Swap()	{
		int s = r(3);
		cout << Player << " attempted to use LIFE SWAP\n";
		cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
		cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;
		system("PAUSE");
		system("CLS");
		++LS;
		if (LS >= 2)	{
			cout << "LIFE SWAP has been used for this game, there's no more LIFE SWAPS available this game\n";
		return 0;	}
		s;
		if (s != 0)	{
			cout << Player << " Performed the spell LIFE SWAP\n" << Player << " & " << Enemy << " life points was swapped";
				swap(&Player_Health, &Enemy_Health);
				cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
				cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;
				return 0;	}
		else	{
			cout << "Spell unsuccesful, LIFE SWAP is unavailble for the rest of the game\n";
			return 0;	}
	}

	int Ptackle()	{
		system("PAUSE");
		system("CLS");
		srand(time(NULL));
		int *EH = &Enemy_Health;
		int *PH = &Player_Health;
		int s = r(3);
		s;
		if (s != 1)	{
			++pt;
		if (pt == 3)	{
			cout << "Tackle succesfful\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(ROUGH SKIN)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Player << " Landed 3 Takles.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Player;
				cout << " now gained ROUGH SKIN\n ";
				*EH = *EH -5;
				*PH = *PH +2;
				return *PH;	}
			if(pt >= 4)	{
				cout << Player << " Tackled " << Enemy << endl << Enemy << " lost 5 hp";
				*PH = *PH = +2;
				*EH = *EH -5;
					return *EH;	}
			cout << Player << " Tackled " << Enemy << endl << Enemy << " lost 5 hp" << endl << Player << " also suffered recoil damage of -2 health points";
			*PH = *PH - 2;
			return *EH = *EH -5;	}

		else	{
			cout << Player << " missed, but suffered recoil damage -2";	
			*PH = *PH -2;
			return *PH;	}
	}
	

// Enemy Attack Functions
	int Enemy_Punch() {
		srand(time(NULL));
		int *PH = &Player_Health;
		int *EH = &Enemy_Health;
		int s = r(5);
		s;
		if (s != 4)	{
			++p2i3;
			++p2i5;
			if(p2i5 == 5)	{
				cout << "Hit Succesful\n";
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(BLOOD FLOW)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy << " Landed 5 consecutive succesful punches.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy;
				cout << " got BLOOD FLOW\n\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy << " gained 10 life points";
				*EH = *EH + 10;
				p2i5 = 0;
				p2i3 = 0;
				return *EH;	}
			if(p2i3 == 3) {
				cout << "Hit Succesful";
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(Double Punch Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy << " Landed 3 consecutive succesful punches.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy;
				cout << " landed a DOUBLE PUNCH\n\t\t\t\t\t\t\t\t\t\t\t\t\t" << Player << " lost 5 life points";
				*PH = *PH -5;
				p2i3 = 0;
			return *PH;			}
			cout << "Hit Succesful\n ";
			*PH = *PH - 3;
			return *PH;	}

		else 	{
			p2i3 = 0;
			p2i5 = 0;
			cout << "Hit missed.";
			return *PH = *PH;	}
	}

	int Enemy_Kick() {
	    srand(time(NULL));
		int *PH = &Player_Health;
		int s = r(2);
		s;
		if (s != 1)	{
			++e3k;
			if(e3k == 3)	{
					system("PAUSE");
					system("CLS");	
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(TRIPLE KICK Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy << " Landed 3 succesful kicks.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy;
				cout << " Attemps TRIPLE KICK\n ";
					int sum = 0;
				for (int i = 1; i < 4; i++)	{
					int b = r(6);
					system("PAUSE");
					system("CLS");	
					
					cout << "\n" << Enemy << " attempts kick #" << i << ", " << Enemy << " lands " <<  "- " << b <<  " damage to "  << Player << endl;
					sum = sum + b;
					*PH = * PH - b;
					if (i == 3)	{
						system("PAUSE");
						system("CLS");
						cout << "\nTotal damage done to " << Player << " is - " << sum << " damage\n";	}
	}
				e3k = 0;
				return *PH;	
			}
			cout << "Hit Succesful\n ";
			*PH = *PH - 5;
			++k2i2;
				if(k2i2 == 2) {
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(DOUBLE KICK Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy << " Landed 2 consecutive succesful kicks.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy;
				cout << " landed a DOUBLE KICK\n ";
				*PH = *PH -5;
				k2i2 = 0;	}
			return *PH;	}
		else	{
			cout << "Hit missed\n";
			k2i2 = 0;
			return *PH = *PH;	}
	}

	int Enemy_Death_Blow() {
	    srand(time(NULL));
		int *PH = &Player_Health;
		int s = r(10);
		s;
		if (s < 4) {
			cout << "Hit Succesful\n ";
			*PH = *PH - 10;
		++db2x3;
		if (db2x3 == 3)	{
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(Stunned Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\	" << Enemy << " Landed 3 Death Blows\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << Player;
				cout << " was STUNNED\n ";
				db2x3 = 0;
				Enemy_Select_Attack();	}
		
			return *PH;	}
		else {
			cout << "Hit missed, " << Player << " Countered The Attack";
			Player_Select_Attack(); }
	}

	int Enemy_Potion()   {
		++pot2;
		srand(time(NULL));
		cout << endl << Enemy << " grabbed potion\n";
		int *EH;
		EH = &Enemy_Health;
		int s = r(2);
		if(pot2 >= 4)	{
			cout << Enemy << " ran out of potions\n";
			return *EH = *EH;	}
		s;
		if(s == 1)	{
			cout << "Potion was used " << Enemy << " recieved 15 HP\n";
			 *EH = *EH + 15;
			if(*EH >= 60)	{
				return *EH = 60;	}
		}
		else	{
			cout << "This potion had no effect on " << Enemy << endl;
			++n2l;
			if(n2l == 3)	{
				system("PAUSE");
				system("CLS");
				system("PAUSE");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(LIFE DESPERATION Activated)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t All " << Enemy << " potions had no effect.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy;
				cout << " Gained LIFE DESPERATION\n ";
				*EH = *EH +15;
			if(*EH >= 60)	{
				*EH = 60;	}
			}
			return *EH;	}
	}

	int Elife_Swap()	{
		int s = r(3);
		cout << Enemy << " attempted to use LIFE SWAP\n";
		cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;
		system("PAUSE");
		system("CLS");
		++LS;
		if (LS >= 2)	{
			cout << "LIFE SWAP has been used for this game, there's no more LIFE SWAPS available this game\n";
		return 0;	}
		s;
		if (s != 0)	{
			cout << Enemy << " Performed the spell LIFE SWAP\n" << Enemy << " & " << Player << " life points was swapped";
		swap(&Player_Health, &Enemy_Health);
				cout << "\n\n" << Player <<" lIfe is at " << Player_Health << " Life Points" << endl;
			cout << Enemy <<" lIfe is at " << Enemy_Health << " Life Points" << endl;
				return 0;	}
		else	{
			cout << "Spell unsuccesful, LIFE SWAP is unavailble for the rest of the game\n";
			return 0;	}
	}

	int Etackle()	{
		system("PAUSE");
		system("CLS");
		srand(time(NULL));
		int *EH = &Enemy_Health;
		int *PH = &Player_Health;
		int s = r(3);
		s;
		if (s != 1)	{
			++et;
		if (et == 3)	{
			cout << "Tackle succesfful\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer ACHIEVMENT(ROUGH SKIN)\n";
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy << " Landed 3 Takles.\n"<< "\t\t\t\t\t\t\t\t\t\t\t\t\t" << Enemy;
				cout << " now gained ROUGH SKIN\n ";
				*PH = *PH -5;
				*EH = *EH +2;
				return *EH;	}
			if(et >= 4)	{
				cout << Enemy << " Tackled " << Player << endl << Player << " lost 5 hp";
				*EH = *EH + 2;
				*PH = *PH -5;
					return *PH;	}
			cout << Enemy << " Tackled " << Player << endl << Player << " lost 5 hp" << endl << Enemy << " also suffered recoil damage of -2 health points";
			*EH = *EH - 2;
			return *PH = *PH -5;	}

		else	{
			cout << Enemy << " missed, but suffered recoil damage -2";	
			*EH = *EH - 2;
			return *EH;	}
	}




// Swap function
void swap(int *a, int *b)	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

// Random Generator Function
	int r(int n) {
		return rand() % n;	}
