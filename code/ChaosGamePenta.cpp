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
	text.setCharacterSize(30);  
	text.setColor(Color::Green);
	text.setString("1. Please left click five\npoints to outline the shape\nof a large pentagon\n\n2. To begin, choose a\nspot and left click one\n last time");  //Set a string into the buffer
	
	//Declaring more variables
    vector<Vector2f> vertices;  //Vectors to track and record clicks and positions
    vector<Vector2f> points;
    double randomVertex = rand() % 5;  //formula to pick random vertices notice size 5 for penta
    double randLast = randomVertex;  //Tracking what the last Vertices is for unique penta

	while (window.isOpen())
		{
        	/*
		****************************************
		Handle the players input
		****************************************
		*/
        Event event;
		while (window.pollEvent(event))  //open a window to start the program
		{
            if (event.type == Event::Closed)  //check to close
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)  //check mouse presses
            {
                if (event.mouseButton.button == sf::Mouse::Left)  //left mouse actions, track 5 for vertices, 1 for starter point then automate
                {
                    std::cout << "the left button was pressed" << std::endl;  //record and display left mouse inputs on terminal
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < 5)  
                    {	//first 5 cliks
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));  //record in vector
                    }
                    else if(points.size() == 0)
                    {
                        //6th click
                        points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) //get me out button
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
            //generate more point(s)
            //select random vertex
            	double count = points.size() - 1;
            	while (randLast == randomVertex) {  // no duplicated vertex
            		randomVertex = rand() % 5;  
            	}
            	randLast = randomVertex;
            	double midPointx = (points.at(count).x + vertices.at(randomVertex).x) * 0.5;  //Calculate midpoint
		double midPointy = (points.at(count).y + vertices.at(randomVertex).y) * 0.5;
		points.push_back(Vector2f(midPointx, midPointy));  //log new midpoint into vector
	}

		
        	/*
		****************************************
		Draw
		****************************************
		*/

		
        window.clear();
	window.draw(text);  // Display text buffer from beginning
        for(int i = 0; i < vertices.size(); i++)  //loop to draw rectancles of vertices
        {
            RectangleShape rect(Vector2f(5,5));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }
     
     	for(int i = 0; i < points.size(); i++){  //loop to draw rectancles of points
            RectangleShape rect(Vector2f(5,5));
            rect.setPosition(Vector2f(points[i].x, points[i].y));
            rect.setFillColor(Color::Yellow);
            window.draw(rect);
            }
        
        window.display(); //frame 1 iteration
    }
}
