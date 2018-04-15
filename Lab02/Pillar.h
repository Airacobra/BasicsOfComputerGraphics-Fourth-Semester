#pragma once
#include "font.h"

class Pillar {
public:

	Pillar() //konstruktor domylsny, przypisujemy i inicjalizujmey parametry do obiektow w sekcji private
	{
	int xParameter = 0; // parametry x i y potrzebne do wypelniania pasa szarosci
	int yParameter = 0;
	defaultCursorPostion = 128; //poczatkowe ustawienie kursora, w polowie wysokosci pasa

	cintureUnit = new sf::Uint8[xSize * ySize * 4];    //tworzymy pas szarosci widoczny na ekranie (wyklad, wpierw x pozniej y)
	for (xParameter = 0; xParameter < 40; xParameter++)
		for (yParameter = 0; yParameter < 255; yParameter++)
			setColourToPixels(cintureUnit, xSize, xParameter, yParameter, yParameter, 255);  

	cursorTexture = new sf::Texture();      //tekstura pasa szarosci
	cursorTexture->create(xSize, ySize);  
	cursorTexture->update(cintureUnit);

	cursor = new sf::RectangleShape(sf::Vector2f(40, 3)); //kursor, bedzie przesuwal sie wraz z kliknieciami
	cursor->setFillColor(sf::Color(244, 180, 22, 250));      //uzytkownika na pasie szarosci
	cursor->setPosition(690, 128); //? 

	font.loadFromMemory(font_data, font_data_size);      //do wypisywania tekstu na ekran
	text = new sf::Text;
	text->setFont(font);
	text->setCharacterSize(20);
	text->setFillColor(sf::Color(0, 0, 0, 255));

	cinctureSprite = new sf::Sprite();
	cinctureSprite->setTexture(*cursorTexture);
	cinctureSprite->setPosition(670, 50);
	}

	void setColourToPixels(sf::Uint8 *pixels_array, int size_x, int x, int y, char rgb, char alpha)
	{
		pixels_array[4 * (y * size_x + x) + 0] = rgb;
		pixels_array[4 * (y * size_x + x) + 1] = rgb;
		pixels_array[4 * (y * size_x + x) + 2] = rgb;
		pixels_array[4 * (y * size_x + x) + 3] = alpha;
	}

	int defaultCursorPostion; // kursor, pokazuje na pas szarosci
	const int xSize = 40;  //rozmiar x pasa szarosci
	const int ySize = 255; //rozmiar y pasa szarosci
	sf::Uint8 *cintureUnit;			//do wymlaowania pasa szarosci
	sf::Sprite *cinctureSprite;     //duszek do powyzszego pasa

	sf::RectangleShape *cursor; //znacznik obecnie wybranej wartosci
	sf::Texture *cursorTexture; // tekstura kontrolera

	sf::Font font; //czcionka wypisywanego tekstu na ekran
	sf::Text *text;  //do przypisania powyzszej czcionki
};


