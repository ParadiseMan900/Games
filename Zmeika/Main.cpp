#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Game.hpp"

bool IfMouseOnButton(sf::FloatRect HitBox, sf::Vector2f Mouse_coordinates)
{
	if (HitBox.contains(Mouse_coordinates))return true;
	return false;
}

void Obnov_sreda(sf::RenderWindow& Menu_ZDM,sf::Event Obnovlenie, sf::Vector2f Mouse_coordinates,
	sf::Sprite Start, sf::Sprite Exit, sf::Sprite Difficult,
	sf::Texture& T_Start, sf::Texture& T_Exit, sf::Texture& T_Difficult,
	int& level, sf::Music& MainMus)
{
	if (IfMouseOnButton(Start.getGlobalBounds(), sf::Vector2f(Mouse_coordinates.x, Mouse_coordinates.y)) == true)
	{
		T_Start.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Pressed start.png");
		if (Obnovlenie.mouseButton.button == sf::Mouse::Left && Obnovlenie.type == sf::Event::MouseButtonPressed)
		{
			MainMus.stop();
			Menu_ZDM.close();
			Game(level);
		}
	}
	else T_Start.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Start.png");

	if (IfMouseOnButton(Exit.getGlobalBounds(), sf::Vector2f(Mouse_coordinates.x, Mouse_coordinates.y)) == true)
	{
		T_Exit.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Pressed exit.png");
		if (Obnovlenie.mouseButton.button == sf::Mouse::Left)Menu_ZDM.close();
	}
	else T_Exit.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Exit.png");

	if (IfMouseOnButton(Difficult.getGlobalBounds(), sf::Vector2f(Mouse_coordinates.x, Mouse_coordinates.y)) == true)
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

		if (Obnovlenie.mouseButton.button == sf::Mouse::Left && Obnovlenie.type == sf::Event::MouseButtonPressed)
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
int main()
{
	int i = 0, level = 2;
	sf::RenderWindow Menu_ZDM;
	Menu_ZDM.create(sf::VideoMode(400, 400), L"«ÏÂÈÍ‡ DM",sf::Style::None);

	Menu_ZDM.setVerticalSyncEnabled(true);

	sf::Texture ChB_bg,LogoMenu,T_Start,T_Exit,T_Difficult;
	if ((!ChB_bg.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Z_Menu1.png"))
		|| (!LogoMenu.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Zmeika.png"))
		|| (!T_Start.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Start.png"))
		||(!T_Exit.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Exit.png"))
		||(!T_Difficult.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/LV_Normal.png"))) return 1;
	sf::Sprite bg, Logo, Start, Exit, Difficult;
	bg.setTexture(ChB_bg);
	Logo.setTexture(LogoMenu);
	Start.setTexture(T_Start);
	Start.setPosition(115, 145);
	Exit.setTexture(T_Exit);
	Exit.setPosition(115, 274);
	Difficult.setTexture(T_Difficult);
	Difficult.setPosition(115, 209);

	sf::Music MainMus;
	if (!MainMus.openFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/musMenu.ogg")) Menu_ZDM.close();
	MainMus.play();
	MainMus.setLoop(true);

	while (Menu_ZDM.isOpen())
	{
		sf::Event Obnovlenie;

		sf::Vector2f Mouse_coordinates;
		Mouse_coordinates.x = sf::Mouse::getPosition(Menu_ZDM).x;
		Mouse_coordinates.y = sf::Mouse::getPosition(Menu_ZDM).y;

		while (Menu_ZDM.pollEvent(Obnovlenie)) 
			Obnov_sreda(Menu_ZDM, Obnovlenie, Mouse_coordinates, 
				Start, Exit, Difficult, T_Start, T_Exit, T_Difficult, level, MainMus);

		if (i == 20) ChB_bg.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Z_Menu2.png");
		if (i == 40) ChB_bg.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Z_Menu3.png");
		if (i == 60) ChB_bg.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Z_Menu4.png");
		if (i == 80)
		{
			ChB_bg.loadFromFile("C:/œ–Œ√–¿ÃÃ€/Zmeika/ZSprites/Z_Menu1.png");
			i = 0;
		}
		i++;
		Menu_ZDM.draw(bg);
		Menu_ZDM.draw(Logo);
		Menu_ZDM.draw(Start);
		Menu_ZDM.draw(Difficult);
		Menu_ZDM.draw(Exit);
		MainMus.setPitch((float)level * 0.15 + 0.7);
		Menu_ZDM.display();
	}
	return 0;
}
