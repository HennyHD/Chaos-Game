// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
    // Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos the Game", Style::Default);

		//Text Box stuff
	Font font;  //create font class
	if(!font.loadFromFile("Lobster-Regular.ttf")) // load a ttf file (font file, put with cpp)
	{
		throw("FONT FAILED TO LOAD");  // throw a text if failed
	}

	Text text;			//Text Customization
	text.setFont(font);  // link font
	text.setCharacterSize(24);  
	text.setColor(Color::Red);
	text.setString("OH HOW IT FEELS TO BE ALIVE");  //Set a string into the buffer
	

    vector<Vector2f> vertices;
    vector<Vector2f> points;
    double randomVertex = rand() % 5;
    double randLast = randomVertex;

	while (window.isOpen())
	{
        	/*
		****************************************
		Handle the players input
		****************************************
		*/
        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < 5)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if(points.size() == 0)
                    {
                        ///fourth click
                        ///push back to points vector
                        points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
        	/*
		****************************************
		Update
		****************************************
		*/
	double count = points.size() - 1;
        if(points.size() > 0)
        {
            ///generate more point(s)
            ///select random vertex
            ///calculate midpoint between random vertex and the last point in the vector
            ///push back the newly generated coord.
            	//Triangle
            	
            	double count = points.size() - 1;
            	while (randLast == randomVertex) {  // no duplicated vertex
            		randomVertex = rand() % 5;
            	}
            	randLast = randomVertex;
            	double midPointx = (points.at(count).x + vertices.at(randomVertex).x) * 0.5;
		double midPointy = (points.at(count).y + vertices.at(randomVertex).y) * 0.5;
		points.push_back(Vector2f(midPointx, midPointy));
	}
		
		


        	/*
		****************************************
		Draw
		****************************************
		*/
        window.clear();
	window.draw(text);  // Display text buffer
        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(5,5));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }
     
     	for(int i = 0; i < points.size(); i++){
            RectangleShape rect(Vector2f(5,5));
            rect.setPosition(Vector2f(points[i].x, points[i].y));
            rect.setFillColor(Color::Yellow);
            window.draw(rect);
            }
        
        window.display();
    }
}
