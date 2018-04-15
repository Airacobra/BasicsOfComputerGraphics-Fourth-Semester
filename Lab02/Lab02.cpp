#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Pillar.h" //klasa opisujaca pas szarosci
#include <string>
#include <cmath>

//----------------------------------------------------------------------------------------------
//sekcja funkcji do ustawiania tekstur, wypelniania i ustawiania kolorow w zaleznosci od wartosci kursora (0,255) oraz wypisywania  //algorytmy na wyliczanie i zamiane wartosci parametrow
/*void setText(int xPosition, int yPosition, std::string textToPrint, sf::RenderTarget &win, Pillar &Bar) //
{
	Bar.text->setString(textToPrint);
	Bar.text->setPosition(xPosition, yPosition);           wyrzuci³o wyj¹tek
	win.draw(*Bar.text);
}*/

void setColourToPixels(sf::Uint8 *colourPixels, int x, int y, int r, int g, int b, char alpha) //funkcja do ustawanie kolorow,
{
	colourPixels[4 * (y * 200 + x) + 0] = r;
	colourPixels[4 * (y * 200 + x) + 1] = g;
	colourPixels[4 * (y * 200 + x) + 2] = b,
	colourPixels[4 * (y * 200 + x) + 3] = alpha;
}

void setHSL(sf::Texture *circleTexture, int cursor) // HSL - hue, saturation, and lightness
{
	sf::Uint8 *HSLUnit = new sf::Uint8[200 * 200 * 4];
	float fisrtRadius = 100;
	float secondRadius = 0;
	float hue, saturation, lightness, red, green, blue;
	float angle, cosinus, xValue, yValue;

	for (int x = 0; x < 2 * fisrtRadius; ++x)
		for (int y = 0; y < 2 * fisrtRadius; ++y)
		{
			xValue = x - fisrtRadius;
			yValue = fisrtRadius - y;
			secondRadius = sqrt(xValue*xValue + yValue * yValue);
			cosinus = xValue / secondRadius;
			angle = acosl(cosinus);

			if (y > 100)	angle = 6.283 - angle;
			saturation = secondRadius / fisrtRadius;
			lightness = (255.0f - cursor) / 255.0f;

			if (secondRadius <= 100)
			{
				if (x == 100 && y == 100) angle = 0;

				float rgbRed, rgbGreem, rgbBlue;
				float colour = (1 - fabs(2 * lightness - 1))*saturation;
				float temporaryVol2 = fmodf(angle * 6 / 6.283, 2.0) - 1.0;
				float temporary = colour * (1.0 - fabs(temporaryVol2));
				float lightValue = lightness - colour / 2;

				if (angle >= 0 && angle < 3.1415 / 3)							
				{
					rgbRed = colour;
					rgbGreem = temporary;
					rgbBlue = 0;
				}
				else if (angle >= 3.1415 / 3.0 && angle < 6.283 / 3.0)			
				{
					rgbRed = temporary;
					rgbGreem = colour;
					rgbBlue = 0;
				}
				else if (angle >= 6.283 / 3.0 && angle < 3.1415)				
				{
					rgbRed = 0;
					rgbGreem = colour;
					rgbBlue = temporary;
				}
				else if (angle >= 3.1415 && angle < 3.1415 * 4 / 3.0)			
				{
					rgbRed = 0;
					rgbGreem = temporary;
					rgbBlue = colour;
				}
				else if (angle >= 3.1415 * 4 / 3.0 && angle < 3.1415 * 5 / 3.0) 
				{
					rgbRed = temporary;
					rgbGreem = 0;
					rgbBlue = colour;
				}
				else if (angle >= 3.1415 * 5 / 3.0 && angle < 6.283)			
				{
					rgbRed = colour;
					rgbGreem = 0;
					rgbBlue = temporary;
				}
				red = (rgbRed + lightValue) * 255;
				green = (rgbGreem + lightValue) * 255;
				blue = (rgbBlue + lightValue) * 255;
			}
			if (secondRadius < fisrtRadius)				setColourToPixels(HSLUnit, x, y, red, green, blue, 255);
			else                                        setColourToPixels(HSLUnit, x, y, 0, 0, 0, 0);
		}
	circleTexture->update(HSLUnit);
	delete[] HSLUnit;
}

void setHSV(sf::Texture *circleTexture, int cursor) // HSV - hue, saturation, and value (brightness)
{
	sf::Uint8 *HSVUnit = new sf::Uint8[200 * 200 * 4];
	float firstRadius = 100;
	float secondRadius = 0;
	float hue, saturation, brightness, red, green, blue;
	float angle, cosinus, xValue, yValue;
	float varHue, varRed, varGreen, varBlue;
	float varIndex0, varIndex1, varIndex2, varIndex3;

	for (int x = 0; x<200; x++)
		for (int y = 0; y<200; y++)
		{
			xValue = x - firstRadius;
			yValue = firstRadius - y;
			secondRadius = sqrt(xValue*xValue + yValue * yValue);
			cosinus = xValue / secondRadius;
			angle = acosl(cosinus);

			if (y > 100)	angle = 6.283 - angle;
			hue = angle / 6.283;
			saturation = secondRadius / 100;
			brightness = (255.0f - cursor) / 255.0f;

			if (secondRadius < firstRadius) {
				if (saturation != 0)
				{
					varHue = hue * 6.0f;
					if (varHue == 6.0f) varHue = 0;
					varIndex0 = (int)(varHue);
					varIndex1 = brightness * (1.0 - saturation);
					varIndex2 = brightness * (1.0 - saturation * (varHue - varIndex0));
					varIndex3 = brightness * (1.0 - saturation * (1.0 - (varHue - varIndex0)));
					
					switch((int)varIndex0)
					{
					case 0:
						varRed = brightness; 
						varGreen = varIndex3;
						varBlue = varIndex1; 
						break;
					case 1:
						varRed = varIndex2; 
						varGreen = brightness; 
						varBlue = varIndex1;
						break;
					case 2:
						varRed = varIndex1; 
						varGreen = brightness; 
						varBlue = varIndex3;
						break;
					case 3:
						varRed = varIndex1;
						varGreen = varIndex2;
						varBlue = brightness;
						break;
					case 4:
						varRed = varIndex3;
						varGreen = varIndex1;
						varBlue = brightness;
						break;
					default:
						varRed = brightness; 
						varGreen = varIndex1; 
						varBlue = varIndex2;
						break;
					}
					red = varRed * 255;
					green = varGreen * 255;
					blue = varBlue * 255;
				}
				else 
				{
					red = brightness * 255.0;
					green = brightness * 255.0;
					blue = brightness * 255.0;
				}
			}
			if (secondRadius < firstRadius)			setColourToPixels(HSVUnit, x, y, red, green, blue, 255);
			else                                    setColourToPixels(HSVUnit, x, y, 0, 0, 0, 0);
		}
	circleTexture->update(HSVUnit);
	delete[] HSVUnit;
}

void setCMY(sf::Texture *circleTexture, int cursor) //CMY - C Cyan, M  Magneta, Y Yellow 
{
	sf::Uint8 *CMYUnit = new sf::Uint8[200 * 200 * 4];
	float fisrtRadius = 100;
	float secondRadius = 0;
	float angle, cosinus, xValue, yValue;

	for (int x = 0; x<200; ++x)
		for (int y = 0; y < 200; ++y)
		{
			float xValue = x - fisrtRadius;
			float yValue = fisrtRadius - y;
			secondRadius = sqrt(xValue*xValue + yValue * yValue);
			cosinus = xValue / secondRadius;
			angle = acosl(cosinus);

			if (y>100)							angle = 6.283 - angle;
			if (secondRadius < fisrtRadius)		setColourToPixels(CMYUnit, x, y, 255 - 255 * secondRadius / fisrtRadius, 255 - 255 * angle / 6.283, cursor, 255);
			else								setColourToPixels(CMYUnit, x, y, 0, 0, 0, 0);
		}
	circleTexture->update(CMYUnit);
	delete[] CMYUnit;
}

void setRGB(sf::Texture *texture, int cursor) // RGB - R Red, G Green, B Blue
{
	sf::Uint8 *RGBUnit = new sf::Uint8[200 * 200 * 4];
	float fisrtRadius = 100;
	float secondRadius = 0;
	float angle, cosinus, xValue, yValue;

	for (int x = 0; x<200; ++x)
		for (int y = 0; y < 200; ++y)
		{
			xValue = x - fisrtRadius;
			yValue = fisrtRadius - y;
			secondRadius = sqrt(xValue*xValue + yValue * yValue);
			cosinus = xValue / secondRadius;
			angle = acosl(cosinus);

			if (y>100)							  angle = 6.283 - angle;
			if (secondRadius < fisrtRadius)	      setColourToPixels(RGBUnit, x, y, 255 * secondRadius / fisrtRadius, 255 * angle / 6.283, 255- cursor, 255);
			else                                  setColourToPixels(RGBUnit, x, y, 0, 0, 0, 0);
		}
	texture->update(RGBUnit);
	delete[] RGBUnit;
}

//----------------------------------------------------------------------------------------------
int main()
{
	//obiekty i wstepna inicjalizacja
	sf::RenderWindow window(sf::VideoMode(800, 600), "Lab02 - Modele i przestrzenie barw", sf::Style::Titlebar | sf::Style::Close); //okno 
	sf::Clock clock; // do liczenia fps
	Pillar InteractiveBar;     //stworzenie obiektu klasy Pillar, reprezentujace interaktywny pasek do zamaniany kol
	sf::Vector2f cursourCurrentLocation; //akktalny prostokat reperezentujacay kursor
	sf::Texture * HSLCircleTexture = new sf::Texture;             // tworzenie textur
		HSLCircleTexture->create(200, 200);						  // o rozmiarze 200x200
	sf::Texture * HSVCircleTexture = new sf::Texture;			  // pod cztery kola
		HSVCircleTexture->create(200, 200);						  // HSL - hue, saturation, and lightness
	sf::Texture * CMYCircleTexture = new sf::Texture;             // HSV - hue, saturation, and value (brightness)
		CMYCircleTexture->create(200, 200);                       // CMY - C Cyan, M  Magneta, Y Yellow 
	sf::Texture * RGBCircleTexture = new sf::Texture;             // RGB - R Red, G Green, B Blue
		RGBCircleTexture->create(200, 200);
	//sekcja nadawania tresci teksturom i zapisywania ich do duszkow
	sf::Sprite HSLSprite;
	sf::Sprite HSVSprite;
	sf::Sprite CMYSprite;
	sf::Sprite RGBSprite;
		HSLSprite.setPosition(50, 50);	    //ustalenie odpowiednich pozycji
		HSVSprite.setPosition(380, 50);
		CMYSprite.setPosition(50, 360);	
		RGBSprite.setPosition(380, 360);
		
		setHSL(HSLCircleTexture, InteractiveBar.defaultCursorPostion);   //czas utworzyc kola w zaleznosci od ewentualnego
		setHSV(HSVCircleTexture, InteractiveBar.defaultCursorPostion);   //kursora lub mieszanki
		setRGB(RGBCircleTexture, InteractiveBar.defaultCursorPostion);
		setCMY(CMYCircleTexture, InteractiveBar.defaultCursorPostion);
				
		HSLSprite.setTexture(*HSLCircleTexture);       //ladujemy do duszkow
		HSVSprite.setTexture(*HSVCircleTexture);	
		RGBSprite.setTexture(*RGBCircleTexture);	
		CMYSprite.setTexture(*CMYCircleTexture);

    //----------------------------------------------------------------------------------------------
	//tworzenie zmiennych	
	unsigned int FPS = 0, frame_counter = 0; //do liczenia fps
	int currentCursorIndex; 
	float number1, number2, number3, number4;
	std::string timeText; //Time + fps info
	std::string sHSL = "HSL";
	std::string sHSV = "HSV";
	std::string sRGB = "RGB";
	std::string sCMY = "CMY";
	std::string str1, str2, str3, str4;
	//----------------------------------------------------------------------------------------------
	//inicjalizacja 
	clock.restart().asMilliseconds();
	while (window.isOpen())
	{
		sf::Event event;
		window.clear(sf::Color::White);

		while (window.pollEvent(event)) // zdarzenia
		{
			if (event.type == sf::Event::Closed) 
				window.close();
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //wlasciwie to jest jedyne potrzebne zdarzenie poza sf::event::close
			{
				if (event.type == sf::Event::MouseMoved && (event.mouseMove.x >= 670 && event.mouseMove.y >= 50) && (event.mouseMove.x <= 710 && event.mouseMove.y <= 305)) //czy jestesmy na pasie
				{
					InteractiveBar.defaultCursorPostion = 305 - event.mouseMove.y; //gdzie jest kursor

					setHSL(HSLCircleTexture, InteractiveBar.defaultCursorPostion);   //zmieniamy parametry
					setHSV(HSVCircleTexture, InteractiveBar.defaultCursorPostion);
					setRGB(RGBCircleTexture, InteractiveBar.defaultCursorPostion);
					setCMY(CMYCircleTexture, InteractiveBar.defaultCursorPostion);

					HSLSprite.setTexture(*HSLCircleTexture);  //zapisujemy do duszkow
					HSVSprite.setTexture(*HSVCircleTexture);
					RGBSprite.setTexture(*RGBCircleTexture);
					CMYSprite.setTexture(*CMYCircleTexture);
				}
			}

		}

		//----------------------------------------------------------------------------------------------
		//rysowanie + info o fps
		cursourCurrentLocation.y = 303 - InteractiveBar.defaultCursorPostion; cursourCurrentLocation.x = 670;  //czas najwyzszy ustalic pozycje kursora do prostokata
		InteractiveBar.cursor->setPosition(cursourCurrentLocation);

		window.draw(*InteractiveBar.cinctureSprite);			//rysujemy pas
		window.draw(*InteractiveBar.cursor, sf::BlendMultiply); 

		window.draw(HSLSprite);                                    //duszki rysujemy
		window.draw(HSVSprite);
		window.draw(RGBSprite);
		window.draw(CMYSprite);


		//the hard way :/ 
		InteractiveBar.text->setPosition(50, 40);  //wypisanie stalych tekstow
		InteractiveBar.text->setString(sHSL);
		window.draw(*InteractiveBar.text);

		InteractiveBar.text->setPosition(380, 40); 
		InteractiveBar.text->setString(sHSV);
		window.draw(*InteractiveBar.text);

		InteractiveBar.text->setPosition(380, 350);
		InteractiveBar.text->setString(sRGB);
		window.draw(*InteractiveBar.text);

		InteractiveBar.text->setPosition(50, 350);
		InteractiveBar.text->setString(sCMY);
		window.draw(*InteractiveBar.text);

		//czesc wypisujaca na ekran zmieniajacy sie parametr
		 currentCursorIndex = InteractiveBar.defaultCursorPostion;
		{
		    number1 = 255 - currentCursorIndex;
			char tab1[10];
			sprintf_s(tab1, "B = %.0f", number1);
			str1 = tab1;
			InteractiveBar.text->setPosition(540, 560);
			InteractiveBar.text->setString(str1);
			window.draw(*InteractiveBar.text);
		}
		
		{
		    number2 = currentCursorIndex * 100 / 255.0f;
			char tab2[10];
			sprintf_s(tab2, "Y = %.0f%%", number2);
			str2 = tab2;
			InteractiveBar.text->setPosition(220, 560);
			InteractiveBar.text->setString(str2);
			window.draw(*InteractiveBar.text);
		}
		
		{
		    number3 = 1 -  currentCursorIndex / 255.0f;
			char tab3[10];	
			sprintf_s(tab3, "L = %.3lf", number3);
			str3 = tab3;
			InteractiveBar.text->setPosition(150, 270);
			InteractiveBar.text->setString(str3);
			window.draw(*InteractiveBar.text);
		}
		
		{
		    number4 = 1 - currentCursorIndex / 255.0f;
			char tab4[10];
			sprintf_s(tab4, "V = %.3lf", number4);
			str4 = tab4;
			InteractiveBar.text->setPosition(500, 270);
			InteractiveBar.text->setString(str4);
			window.draw(*InteractiveBar.text);
		}
		

		if (clock.getElapsedTime().asSeconds() >= 1.0f)
		{
			FPS = (unsigned int)((float)frame_counter / clock.getElapsedTime().asSeconds());
			clock.restart();
			frame_counter = 0;
		}
		frame_counter++;

		InteractiveBar.text->setPosition(670, 340);         //wypisz liczbe fps na ekran
		InteractiveBar.text->setString(std::to_string(FPS)+std::string(" FPS"));
		window.draw(*InteractiveBar.text);
		window.display();
	}
	delete HSLCircleTexture;
	delete HSVCircleTexture;
	delete RGBCircleTexture;
	delete CMYCircleTexture;

}
