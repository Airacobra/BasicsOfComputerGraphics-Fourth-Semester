#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "font.h"
#include <iostream>
#include <cmath>

class Menu : public sf::Drawable
{
 private:
  sf::Font font;
  sf::Text *text;
  sf::RectangleShape *rectangle;
  
  sf::Texture *colors_texture;
  sf::Sprite *colors_sprite;
  sf::Uint8 *colors_pixels;
  const unsigned int colors_size_x = 765;
  const unsigned int colors_size_y = 60;
  inline void draw_to_color_pixels(unsigned int x, unsigned int y,unsigned char r, unsigned char g, unsigned char b)
  {
   colors_pixels[4 * (y * colors_size_x + x) + 0] = r;
   colors_pixels[4 * (y * colors_size_x + x) + 1] = g;
   colors_pixels[4 * (y * colors_size_x + x) + 2] = b;
   colors_pixels[4 * (y * colors_size_x + x) + 3] = 255;
  }

 public:
  Menu()
  {
   font.loadFromMemory(font_data, font_data_size);
   text = new sf::Text;
   text->setFont(font);
   text->setCharacterSize(12);
   text->setFillColor(sf::Color::White);

   rectangle = new sf::RectangleShape(sf::Vector2f(796, 536));
   rectangle->setFillColor(sf::Color::Transparent);
   rectangle->setOutlineColor(sf::Color::White);
   rectangle->setOutlineThickness(1.0f);
   rectangle->setPosition(2, 62);

   unsigned int x, y;
   colors_pixels = new sf::Uint8[colors_size_x * colors_size_y * 4];
   for (x = 0; x<255; x++)
    for (y = 0; y < 30; y++)
     {
      draw_to_color_pixels(x, y, x, 255, 0);
      draw_to_color_pixels(x+255, y, 255, 255-x, 0);
      draw_to_color_pixels(x + 510, y, 255, 0, x);
      draw_to_color_pixels(254 - x, y+30, 0, 255, 255-x);
      draw_to_color_pixels(509 - x, y + 30, 0, x, 255 );
      draw_to_color_pixels(764 - x, y + 30, 255-x, 0, 255);
     }

   colors_texture = new sf::Texture();
   colors_texture->create(colors_size_x, colors_size_y);
   colors_texture->update(colors_pixels);

   colors_sprite = new sf::Sprite();
   colors_sprite->setTexture(*colors_texture);
   colors_sprite->setPosition(1, 1);
  }

  void outtextxy(sf::RenderTarget& target, float x, float y, const wchar_t *str) const
  {
   text->setPosition(x, y); 
   text->setString(str); 
   target.draw(*text);
  }

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
   outtextxy(target,5, 600, L"f - wybór koloru rysowania");
   outtextxy(target, 5, 615, L"b - wybór koloru wype³niania");
   outtextxy(target, 5, 630, L"l - rysowanie linii");

   outtextxy(target, 200, 600, L"r - rysowanie prostok¹ta");
   outtextxy(target, 200, 615, L"a - rysowanie wype³nionego prostok¹ta");
   outtextxy(target, 200, 630, L"c - rysowanie okrêgu");

   outtextxy(target, 470, 600, L"w - zapis do pliku");
   outtextxy(target, 470, 615, L"o - odczyt z pliku");
   outtextxy(target, 470, 630, L"esc - wyjœcie");

   outtextxy(target, 650, 615, L"Aktualne:");

   target.draw(*rectangle);
   target.draw(*colors_sprite);
  }
};

//-------------------------------------------------------------------------//
int main()
{

 sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;
 Menu menu;
 // Obiekty i zmienne + inicjalizacja
 sf::Color userColour(0,0,0,255); //konstruktor domyslny sprawia, ze usercolour nie jest modyfikowalna l-wartoscia?
 sf::Color userColourToFill(0,0,0,255); // (r,g,b,opacity)
 sf::VertexArray line(sf::LinesStrip, 2); // linia
 sf::RectangleShape rectangle, rectangleFilled;			  // prostokat															
 sf::CircleShape circle;				  // kolo
 sf::Texture Up;     //to co na gorze planszy 
 sf::Texture Bottom; //w buforze
	Up.create(800, 650);
	Bottom.create(800, 650);
 sf::Sprite drawTexture;
	drawTexture.setTexture(Bottom);
 sf::Font font;  //pod wypisywanie pola aktualnej czynnosci
	font.loadFromMemory(font_data, font_data_size);
 sf::Text *text = new sf::Text; //do przypisania font 
	text->setFont(font);

 float xPointStart, xPointEnd, yPointStart, yPointEnd; //do operacji na wspolrzednych
 int flag = 0;  //tlo
 char action = ' '; //do prechowywania litery odpowiadajacej za czynnosc update: cos nie tak z charem
 int letter = 0; //nowy sposob przechowywania informacji o czynnosci

 Up.update(window);
 window.setFramerateLimit(60);
 while (window.isOpen())
  {
   window.clear(sf::Color::Black);
   
   while (window.pollEvent(event))
    {	
	   // klawiatura, zamiana sposobu z action = char na letter = int
	   if (event.type == sf::Event::Closed) window.close();
	   if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
	   if (event.type == sf::Event::KeyPressed)
	   {
		   if (event.key.code == sf::Keyboard::F)
			   letter = 1;
		   if (event.key.code == sf::Keyboard::B)
			   letter = 2;
		   if (event.key.code == sf::Keyboard::L)
			   letter = 3;
		   if (event.key.code == sf::Keyboard::R)
			   letter = 4;
		   if (event.key.code == sf::Keyboard::A)
			   letter = 5;
		   if (event.key.code == sf::Keyboard::C)
			   letter = 6;
		   if (event.key.code == sf::Keyboard::W)		   
			   letter = 7;
		   if (event.key.code == sf::Keyboard::O)
			   letter = 8;
	   }
	   switch (letter)
	   {
	    case 1:
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (event.mouseButton.y <= 30)  //pewnie dalo sie prosciej
				{
					if (event.mouseButton.x <= 255)
						userColour = sf::Color(event.mouseButton.x, 255, 0, 255);
					if (event.mouseButton.x > 255 && event.mouseButton.x <= 510)
						userColour = sf::Color(255, 510 - event.mouseButton.x, 0, 255);
					if (event.mouseButton.x > 510 && event.mouseButton.x <= 765)
						userColour = sf::Color(255, 0, event.mouseButton.x - 510, 255);
				}

				if (event.mouseButton.y <= 60 && event.mouseButton.y>30)
				{
					if (event.mouseButton.x <= 255)					
						userColour = sf::Color(0, 255, event.mouseButton.x, 255);					
					if (event.mouseButton.x>255 && event.mouseButton.x <= 510)					
						userColour = sf::Color(0, 510 - event.mouseButton.x, 255, 255);					
					if (event.mouseButton.x>510 && event.mouseButton.x <= 765)					
						userColour = sf::Color(event.mouseButton.x - 510, 0, 255, 255);					
				}
			}
		   break;
	    case 2:
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (event.mouseButton.y <= 30)  
				{
					if (event.mouseButton.x <= 255)
						userColourToFill = sf::Color(event.mouseButton.x, 255, 0, 255);
					if (event.mouseButton.x > 255 && event.mouseButton.x <= 510)
						userColourToFill = sf::Color(255, 510 - event.mouseButton.x, 0, 255);
					if (event.mouseButton.x > 510 && event.mouseButton.x <= 765)
						userColourToFill = sf::Color(255, 0, event.mouseButton.x - 510, 255);
				}

				if (event.mouseButton.y <= 60 && event.mouseButton.y>30)
				{
					if (event.mouseButton.x <= 255)
						userColourToFill = sf::Color(0, 255, event.mouseButton.x, 255);
					if (event.mouseButton.x>255 && event.mouseButton.x <= 510)
						userColourToFill = sf::Color(0, 510 - event.mouseButton.x, 255, 255);
					if (event.mouseButton.x>510 && event.mouseButton.x <= 765)
						userColourToFill = sf::Color(event.mouseButton.x - 510, 0, 255, 255);
				}
			}
		   break;	
		case 7:
			Bottom.copyToImage().saveToFile("screen.png");
			break;
		case 8:
			Bottom.loadFromFile("screen.png");
			break;
	    /*case 'l':
		   break;
	    case 'r':
		   break;
	    case 'a':
		   break;
	    case 'c':
		   break;
	    case 'w':
		   Bottom.copyToImage().saveToFile("screen.png");
		   break;
	    case 'o':
			Bottom.loadFromFile("screen.png");
		   break;*/
	   default:
		   break;
	   }

	   //mysz, rysowanie 
	   if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	   {
		   xPointStart = sf::Mouse::getPosition(window).x;   //aby uniknac wyjsca 
		   yPointStart = sf::Mouse::getPosition(window).y;	 //poza ramke
		   flag = true; //rysujemy
	   }

	   if (event.type == sf::Event::MouseButtonReleased)
	   {
		   Bottom.update(Up.copyToImage()); //zapisz rysowanie
		   flag = false; //koniec rysowania
	   }	
    }

   //Draw BEGIN
   window.draw(drawTexture);
   if (flag == 1) //czy rysujemy
   {
	   switch (letter) //tworzymy obiekty
	   {
	   case 3:
		   line[0].position = sf::Vector2f(xPointStart, yPointStart); line[0].color = userColour;
		   line[1].position = sf::Vector2f(static_cast<float> (sf::Mouse::getPosition(window).x), static_cast<float> (sf::Mouse::getPosition(window).y)); line[1].color = userColourToFill;
		   window.draw(line);
		   break;
	   case 4:
		   rectangle.setSize(sf::Vector2f(static_cast<float> (sf::Mouse::getPosition(window).x - xPointStart), static_cast<float> (sf::Mouse::getPosition(window).y - yPointStart)));
		   rectangle.setFillColor(sf::Color::Transparent);		  
		   rectangle.setOutlineColor(userColour);		  
		   rectangle.setOutlineThickness(2.0f);
		   rectangle.setPosition((xPointStart), (yPointStart));
		   window.draw(rectangle);
		   break;
	   case 5:
		   rectangleFilled.setSize(sf::Vector2f(static_cast<float> (sf::Mouse::getPosition(window).x - xPointStart), static_cast<float> (sf::Mouse::getPosition(window).y - yPointStart)));
		   rectangleFilled.setFillColor(userColour);
		   rectangleFilled.setOutlineColor(userColourToFill);
		   rectangleFilled.setOutlineThickness(2.0f);
		   rectangleFilled.setPosition((xPointStart), (yPointStart));
		   window.draw(rectangleFilled);
		   break;
	   case 6:
		   //rownianie okregu (a-x)^2-(b-y)^2 = r^2
		   circle.setRadius(sqrt(static_cast<float> (pow(sf::Mouse::getPosition(window).x - xPointStart, 2) + pow(sf::Mouse::getPosition(window).y - yPointStart, 2))) / 2);
		   circle.setFillColor(sf::Color::Transparent);
		   circle.setOutlineColor(userColour);
		   circle.setOutlineThickness(2.0f);
		   circle.setPosition(sf::Vector2f(xPointStart, yPointStart));
		   window.draw(circle);
		   break;	   
	   }
   }

   rectangle.setSize(sf::Vector2f(32, 29));
   rectangle.setOutlineColor(sf::Color::Transparent);

   rectangle.setOutlineThickness(0.0f);
   rectangle.setPosition(767, 1);
   rectangle.setFillColor(userColour);
   window.draw(rectangle);
   rectangle.setPosition(767, 31);
   rectangle.setFillColor(userColourToFill);
   window.draw(rectangle);
   window.draw(rectangle);

   Up.update(window);
   window.draw(menu);

   //wypisywanie aktualnej litery - sprawdzenie i ustawienie znaku
   switch(letter)
   {
   case 1: action = 'f'; break;
   case 2: action = 'b'; break;
   case 3: action = 'l'; break;
   case 4: action = 'r'; break;
   case 5: action = 'a'; break;
   case 6: action = 'c'; break;
   case 7: action = 'w'; break;
   case 8: action = 'o'; break;
   }
   text->setCharacterSize(13);
   text->setFillColor(sf::Color::White);
   text->setPosition(710, 613);
   text->setString(action);
   window.draw(*text);

   window.display();
   //Draw END
  }
 return 0;
}