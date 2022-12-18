#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <sstream>
#include <stdio.h>
#include <process.h>

bool IfMouseOnButton2(sf::FloatRect HitBox, sf::Vector2f Mouse_coordinates2)
{
	if (HitBox.contains(Mouse_coordinates2))return true;
	return false;
}

void AppleProv(int& l, bool& AppleExists, int musxy[2][1200], int musfood[4][3])
{
	bool block = true;
	srand(time(NULL));
	int j,i;
	while (block == true)
	{
		block = false;
		for (j = 0; j < 3; j++)
		{
			if (musfood[2][j] == 0)
			{
				musfood[0][j] = rand() % 40;
				musfood[1][j] = rand() % 30;
				musfood[2][j] = 1;
				musfood[3][j] = rand() % 16;

				for (i = 0; i < l; i++)
				{
				
					if ((musfood[0][j] == musxy[0][i]) && (musfood[1][j] == musxy[1][i]))
					{
						block = true;
						musfood[2][j] = 0;
						continue;
					}
					
				}
				for (i = 0; i < 3; i++)
				{
					if (musfood[0][j] == musfood[0][i] && musfood[1][j] == musfood[1][i] && j != i)
					{
						block = true;
						musfood[2][j] = 0;
						continue;
					}
				}
			}
		}
	}
	AppleExists = true;
}

std::string convert_INT_in_STRING(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

void TDO(sf::Font font, sf::RenderWindow& Game_ZDM, sf::Sprite Setka)
{
	int i;
	std::string T = "3", D = "2", O = "1";
	sf::Text Tri (T, font, 150), Dva(D, font, 150), Odin(O, font, 150);
	sf::Sprite WASD;
	sf::Texture T_WASD;
	T_WASD.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/wasd.png");
	WASD.setTexture(T_WASD);
	Odin.setFillColor(sf::Color::Red);
	Tri.setPosition(410, 225);
	Dva.setPosition(410, 225);
	Odin.setPosition(410, 225);
	WASD.setPosition(315, 425);

	sf::Music TDOmus;
	if (!TDOmus.openFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/321.ogg")) Game_ZDM.close();
		
	for (i = 0; i < 3; i++)
	{
		Game_ZDM.clear();
		Game_ZDM.draw(Setka);
		switch (i)
		{
		case 0:
			Game_ZDM.draw(Tri);
			break;
		case 1:
			Game_ZDM.draw(Dva);
			T_WASD.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/wasd2.png");
			break;
		case 2:
			Game_ZDM.draw(Odin);
			T_WASD.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/wasd.png");
			break;
		}
		Game_ZDM.draw(WASD);
		Game_ZDM.display();
		TDOmus.play();
		TDOmus.setPitch((float)1 + i * 0.15);
		sf::sleep(sf::milliseconds(600));
	}
}

void Pause_display(int& level, int& PauseSchet, sf::RenderWindow& Game_ZDM,
	sf::Sprite Setka, bool& p, sf::Event EVENT, sf::Font font, int& Score, sf::Texture& T_Pause,
		sf::Texture& T_Rules, sf::Sprite Rules, int& BesScore)
{
	std::string ST_Score = "Score: " + convert_INT_in_STRING(Score), BT_Score = "Best: " + convert_INT_in_STRING(BesScore);
	sf::Text text(ST_Score, font, 42), best_text(BT_Score, font, 42);
	text.setPosition(920, 50);
	best_text.setPosition(920, 100);
	sf::Sprite Pause;
	Pause.setTexture(T_Pause);
	Pause.setPosition(50, 50);

	Game_ZDM.clear();
	Game_ZDM.draw(Setka);
	Game_ZDM.draw(Rules);
	if (PauseSchet == 10 * level) T_Pause.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/pause screen2.png");
	if (PauseSchet == 20 * level)
	{
		T_Pause.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/pause screen1.png");
		PauseSchet = 0;
	}
	PauseSchet++;
	Game_ZDM.draw(Pause);
	Game_ZDM.draw(text);
	Game_ZDM.draw(best_text);
	Game_ZDM.display();
	if (EVENT.type == sf::Event::KeyPressed &&
		EVENT.key.code == sf::Keyboard::Enter) p = false; else sf::sleep(sf::milliseconds(100 / level));
}

void GAME_DISPLAY(int& summ, int& l, int& IAX, int& IAY, int& Score,
	bool& AppleExists, int musxy[2][1200], int musfood[4][3], sf::RenderWindow& Game_ZDM,
	sf::Font font, sf::Texture& T_HEAD, sf::Texture& T_Yaz, sf::Music& FOOD, int& BesScore)
{
	int j, k;
	sf::Texture T_Apple, T_Test;
	if ((!T_Apple.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Apple.png"))
		|| (!T_Test.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/test.png")));
	sf::Sprite Iaz, Head, Test, Apple;
	Iaz.setTexture(T_Yaz);
	Head.setTexture(T_HEAD);
	Test.setTexture(T_Test);
	Apple.setTexture(T_Apple);
	
	if (FOOD.getStatus() != 2) FOOD.openFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/EDA.ogg");

	for (j = l - 1; j > 0; j--)
	{
		Test.setPosition(musxy[0][j] * 20 + 50, musxy[1][j] * 20 + 50);
		Game_ZDM.draw(Test);
	}
	Head.setPosition(musxy[0][0] * 20 + 50, musxy[1][0] * 20 + 50);
	Game_ZDM.draw(Head);

	if (summ >= 35 && summ <= 39 && IAX != -1 && IAX != 40 && IAY != -1 && IAY != 30)
	{
		Iaz.setPosition(IAX * 20 + 50, IAY * 20 + 50);
		Game_ZDM.draw(Iaz);
	}
	if (summ == 40)summ = -1; else summ++;

	for (j = 0; j < 3; j++)
	{
		if ((musfood[0][j] == musxy[0][0]) && (musfood[1][j] == musxy[1][0]))
		{
			for (k = 0; k < 10; k++)
			{
				if (musfood[3][j] == k) Score++;
			}
			for (k = 10; k < 15; k++)
			{
				if (musfood[3][j] == k) Score += 2;
			}
			if (musfood[3][j] == 15) Score += 3;
			l++;
			FOOD.play();
			musfood[2][j] = 0;
			AppleExists = false;
		}
	}
	if (AppleExists == false)
	{
		AppleProv(l, AppleExists, musxy, musfood);
	}
	std::string ST_Score = "Score: " + convert_INT_in_STRING(Score),
		BT_Score = "Best: " + convert_INT_in_STRING(BesScore);
	sf::Text text(ST_Score, font, 42), best_text(BT_Score, font, 42);
	text.setPosition(920, 50);
	best_text.setPosition(920, 100);

	for (j = 0; j < 3; j++)
	{
		for (k = 0; k < 10; k++)
		{
			if (musfood[3][j] == k) T_Apple.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Apple.png");
		}
		for (k = 10; k < 15; k++)
		{
			if (musfood[3][j] == k) T_Apple.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Abricos.png");
		}
		if (musfood[3][j] == 15) T_Apple.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Banan.png");
		Apple.setPosition(musfood[0][j] * 20 + 40, musfood[1][j] * 20 + 40);
		Game_ZDM.draw(Apple);
	}
	Game_ZDM.draw(text);
	Game_ZDM.draw(best_text);
	Game_ZDM.display();
}

void Game_Over(sf::RenderWindow& Game_ZDM, sf::Sprite Setka, int& l, int& Score, int musfood[4][3],
	int musxy[2][1200], sf::Texture T_Yaz, sf::Texture T_HEAD, sf::Font font, bool& GAME_BLOCK,
	sf::Texture& T_Rules, sf::Sprite Rules, sf::Music& musicG,int& level)
{
	bool start_block = true;
	int sss, j, k, BesScore;
	FILE* Best_Score;
	fopen_s(&Best_Score, "C:/œ–Œ√–¿ÃÃ€/Zmeika/ZScore/You're a sucker if you open this file.txt", "r");
	fscanf_s(Best_Score, "%d", &BesScore);
	fclose(Best_Score);
	std::string ST_Score = "Score: " + convert_INT_in_STRING(Score), BT_Score = "Best: " + convert_INT_in_STRING(BesScore);
	sf::Text text(ST_Score, font, 42), best_text(BT_Score, font, 42);
	text.setPosition(920, 50);
	best_text.setPosition(920, 100);
	sf::Texture T_Apple, T_Test, T_GAME_OVER, T_Start, T_Exit, T_Difficult;
	if ((!T_Apple.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Apple.png"))
		|| (!T_Test.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/test.png"))
		|| (!T_GAME_OVER.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/GAME_OVER.png"))
		|| (!T_Start.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Start.png"))
		|| (!T_Exit.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Exit.png"))) Game_ZDM.close();
	
	sf::Music GO;
	if (!GO.openFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/GameOver.ogg")) Game_ZDM.close();

	switch (level)
	{
	case 2:
		T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/LV_Normal.png");
		break;
	case 3:
		T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/LV_Hard.png");
		break;
	default:
		T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/LV_Easy.png");
		break;
	}
	sf::Sprite Iaz, Head, Test, Apple, GAME_OVER, Start, Exit, Difficult;
	Iaz.setTexture(T_Yaz);
	Head.setTexture(T_HEAD);
	Test.setTexture(T_Test);
	Apple.setTexture(T_Apple);
	Difficult.setTexture(T_Difficult);
	Difficult.setPosition(365, 500);
	GAME_OVER.setTexture(T_GAME_OVER);
	GAME_OVER.setPosition(50, 50);
	Start.setTexture(T_Start);
	Start.setPosition(180, 500);
	Exit.setTexture(T_Exit);
	Exit.setPosition(550, 500);
	musicG.stop();
	GO.play();
	for (sss = 0; sss < 7; sss++)
	{
		Game_ZDM.clear();
		Game_ZDM.draw(Setka);
		Game_ZDM.draw(Rules);
		Rules.setPosition(900, 50);

		if (sss % 2 == 0)
		{
			for (j = l - 1; j > 0; j--)
			{
				Test.setPosition(musxy[0][j] * 20 + 50, musxy[1][j] * 20 + 50);
				Game_ZDM.draw(Test);
			}
			Head.setPosition(musxy[0][0] * 20 + 50, musxy[1][0] * 20 + 50);
			Game_ZDM.draw(Head);
		}

		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 10; k++)
			{
				if (musfood[3][j] == k) T_Apple.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Apple.png");
			}
			for (k = 10; k < 15; k++)
			{
				if (musfood[3][j] == k) T_Apple.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Abricos.png");
			}
			if (musfood[3][j] == 15) T_Apple.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Banan.png");

			Apple.setPosition(musfood[0][j] * 20 + 40, musfood[1][j] * 20 + 40);
			Game_ZDM.draw(Apple);
		}
		Game_ZDM.draw(text);
		Game_ZDM.draw(best_text);
		Game_ZDM.display();
		sf::sleep(sf::milliseconds(250));
	}
	if (Score > BesScore)
	{
		BesScore = Score;
		fopen_s(&Best_Score, "C:/œ–Œ√–¿ÃÃ€/Zmeika/ZScore/You're a sucker if you open this file.txt", "w+");
		fprintf_s(Best_Score, "%d", BesScore);
		fclose(Best_Score);
	}
	while (start_block==true)
	{
		sf::Event EVENT;

		sf::Vector2f Mouse_coordinates2;
		Mouse_coordinates2.x = sf::Mouse::getPosition(Game_ZDM).x;
		Mouse_coordinates2.y = sf::Mouse::getPosition(Game_ZDM).y;

		while (Game_ZDM.pollEvent(EVENT) && start_block == true)
		{
			if (IfMouseOnButton2(Start.getGlobalBounds(), sf::Vector2f(Mouse_coordinates2.x,
				Mouse_coordinates2.y)) == true)
			{
				T_Start.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Pressed start.png");
				if (EVENT.mouseButton.button == sf::Mouse::Left && EVENT.type == sf::Event::MouseButtonPressed)
				{
					start_block = false;
					GAME_BLOCK = true;
				}
			}
			else T_Start.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Start.png");

			if (IfMouseOnButton2(Exit.getGlobalBounds(), sf::Vector2f(Mouse_coordinates2.x,
				Mouse_coordinates2.y)) == true)
			{
				T_Exit.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Pressed exit.png");
				if (EVENT.mouseButton.button == sf::Mouse::Left && EVENT.type == sf::Event::MouseButtonPressed)
				{
					start_block = false;
					Game_ZDM.close();
				}
			}
			else T_Exit.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Exit.png");

			if (IfMouseOnButton2(Difficult.getGlobalBounds(), sf::Vector2f(Mouse_coordinates2.x, Mouse_coordinates2.y)) == true)
			{
				switch (level)
				{
				case 2:
					T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Pressed LV_Normal.png");
					break;
				case 3:
					T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Pressed LV_Hard.png");
					break;
				default:
					T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Pressed LV_Easy.png");
					break;
				}

				if (EVENT.mouseButton.button == sf::Mouse::Left && EVENT.type == sf::Event::MouseButtonPressed)
				{
					level++;
					if (level == 4)level = 1;
				}
			}
			else
			{
				switch (level)
				{
				case 2:
					T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/LV_Normal.png");
					break;
				case 3:
					T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/LV_Hard.png");
					break;
				default:
					T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/LV_Easy.png");
					break;
				}
			}
		}
			Game_ZDM.clear();
			Game_ZDM.draw(Setka);
			text.setPosition(310, 410);
			text.setCharacterSize(52);
			Game_ZDM.draw(GAME_OVER);
			Game_ZDM.draw(text);
			Game_ZDM.draw(Exit);
			Game_ZDM.draw(Start);
			Game_ZDM.draw(Difficult);
			Game_ZDM.display();
	}
}
//*****************************************************»√–¿****************************************************
int Game(int level)
{
	sf::RenderWindow Game_ZDM;
	Game_ZDM.create(sf::VideoMode(1250, 700), L"«ÏÂÈÍ‡ DM", sf::Style::None);
	bool GAME_BLOCK = true;
	while (GAME_BLOCK == true)
	{
		Game_ZDM.setFramerateLimit(10 * level);
		GAME_BLOCK = false;
		bool p = false, AppleExists = false;
		int x = 20, y = 15, j, jos = 2, jos2, l = 3, IAX, IAY, Score = 0, PauseSchet = 0, summ = 0,
			BesScore;
		int musxy[2][1200];
		int musfood[4][3] = { 0 };

		sf::Texture T_setka, T_HEAD, T_Yaz, T_Pause, T_Rules;
		if ((!T_setka.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/setka.png"))
			|| (!T_Yaz.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Iaz_Rightt.png"))
			|| (!T_Pause.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/pause screen1.png"))
			|| (!T_Rules.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/rules.png"))) Game_ZDM.close();
		sf::Sprite Setka, Pause, Rules;
		Setka.setTexture(T_setka);
		Rules.setTexture(T_Rules);
		Rules.setPosition(900, 50);

		sf::Music musicG, FOOD, pauseMus;
		if (!musicG.openFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/simple ZDM.ogg")
			|| (!FOOD.openFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/EDA.ogg"))
			|| (!pauseMus.openFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/pausemus.ogg"))) Game_ZDM.close();
		musicG.play();
		musicG.setLoop(true);
		musicG.setPitch((float)level * 0.15 + 0.7);
		pauseMus.play();
		pauseMus.setLoop(true);
		pauseMus.setPitch((float)level * 0.15 + 0.7);
		pauseMus.setVolume(0);
		FILE* Best_Score;
		fopen_s(&Best_Score, "C:/œ–Œ√–¿ÃÃ€/Zmeika/ZScore/You're a sucker if you open this file.txt", "r");
		fscanf_s(Best_Score, "%d", &BesScore);
		fclose(Best_Score);
		
		for (j = 0; j < l; j++)
		{
			musxy[0][j] = 20 - j;
			musxy[1][j] = 15;
		}

		sf::Font font;
		font.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/PixelFont.ttf");

		TDO(font, Game_ZDM, Setka);
		AppleProv(l, AppleExists, musxy, musfood);


		//***************************************** œŒ ¿ Œ“ –€“Œ Œ ÕŒ *****************************************
		while (Game_ZDM.isOpen()&&GAME_BLOCK==false)
		{
			sf::Event EVENT;

			jos2 = jos;
			
			pauseMus.setVolume(0);

			while (Game_ZDM.pollEvent(EVENT) || (p == true))
			{
				if (EVENT.type == sf::Event::KeyPressed && p == false)
				{
					switch (EVENT.key.code)
					{
					case sf::Keyboard::Up: case sf::Keyboard::W:
						jos = 0;
						break;
					case sf::Keyboard::Left: case sf::Keyboard::A:
						jos = 1;
						break;
					case sf::Keyboard::Right: case sf::Keyboard::D:
						jos = 2;
						break;
					case sf::Keyboard::Down: case sf::Keyboard::S:
						jos = 3;
						break;
					case sf::Keyboard::Escape:
						p = true;
						break;
					default:
						break;
					}
				}
				if (p == true)
				{
					pauseMus.setVolume(100);
					musicG.setVolume(0);
					Pause_display(level, PauseSchet, Game_ZDM, Setka, p, EVENT,
						font, Score, T_Pause, T_Rules, Rules, BesScore);
				}
			}

			musicG.setVolume(100);
			pauseMus.setVolume(0);

			if (musicG.getStatus() == 1) musicG.play();
			Game_ZDM.clear();
			Game_ZDM.draw(Setka);
			Game_ZDM.draw(Rules);
			for (j = 0; j < 4; j++)
			{
				if ((jos == 3 - j) && (jos2 == j))jos = j;
			}
			switch (jos)
			{
			case 0:
				y--;
				IAY = y - 1;
				IAX = musxy[0][0];
				T_HEAD.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/head_up.png");
				T_Yaz.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Iaz_Up.png");
				break;
			case 1:
				x--;
				IAX = x - 1;
				IAY = musxy[1][0];
				T_HEAD.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/head_left.png");
				T_Yaz.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Iaz_Left.png");
				break;
			case 2:
				x++;
				IAX = x + 1;
				IAY = musxy[1][0];
				T_HEAD.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/head_rightt.png");
				T_Yaz.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Iaz_Rightt.png");
				break;
			case 3:
				y++;
				IAY = y + 1;
				IAX = musxy[0][0];
				T_HEAD.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/head_down.png");
				T_Yaz.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Iaz_Down.png");
				break;
			default:
				break;
			}
			
			if ((y == -1) || (y == 30) || (x == -1) || (x == 40))
				Game_Over(Game_ZDM, Setka, l, Score, musfood, musxy,
					T_Yaz, T_HEAD, font, GAME_BLOCK, T_Rules, Rules, musicG, level);
			for (j = 1; j < l; j++)
			{
				if ((x == musxy[0][j]) && (y == musxy[1][j]))
					Game_Over(Game_ZDM, Setka, l, Score, musfood, musxy,
						T_Yaz, T_HEAD, font, GAME_BLOCK, T_Rules, Rules, musicG, level);
			}

			if (GAME_BLOCK == false)
			{
				for (j = l - 1; j > 0; j--)
				{
					musxy[0][j] = musxy[0][j - 1];
					musxy[1][j] = musxy[1][j - 1];
				}
				musxy[0][0] = x;
				musxy[1][0] = y;

				GAME_DISPLAY(summ, l, IAX, IAY, Score, AppleExists, musxy, musfood,
					Game_ZDM, font, T_HEAD, T_Yaz, FOOD, BesScore);
			}
		}
	}
	return 0;
}
