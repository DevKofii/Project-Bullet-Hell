#include "Game.hpp"

using namespace controllers;

Vector2f g_mouse_pos = Vector2f(0, 0);

Game::Game() : CWindow(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"PROJECT BULLET HELL",sf::Style::Close){
    // SceneManager::getInstance()->registerScene(new MainMenuScene());
    // SceneManager::getInstance()->registerScene(new TestScene());
    // SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU_SCENE);
}

wall::wall(Vector2f pos1, Vector2f pos2)
{
	start = pos1;
	end = pos2;
}

ray::ray(float x, float y)
{
	m_relative_end = Vector2f(x, y) * 3000.f;
}

// Reset end-point of ray
void ray::reset()
{
	m_end = g_mouse_pos + m_relative_end;
}

void ray::calc_hit(Vector2f p3, Vector2f p4)
{
	const Vector2f p1 = g_mouse_pos;
	const Vector2f p2 = m_end;

	// Calculates denominator of equations
	const float den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);

	if (den == 0)
		return;

	const float t =  ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / den;
	const float u = -((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / den;

	// If there's an intersection...
	if (t > 0 && t < 1 && u > 0 && u < 1)
	{
		// Gets intersection point
		m_end.x = p1.x + t * (p2.x - p1.x);
		m_end.y = p1.y + t * (p2.y - p1.y);
	}
}

int Game::random(int max) { 
    return rand() % (max - 0) + 0; 
}

void Game::run() {
	srand(time(NULL));

    // Make walls
	std::vector<wall> walls;
	for (int i = 0; i < 4; i++)
	{
		// Randomize start and end positions
		const Vector2f start(this->random(SCREEN_WIDTH), this->random(SCREEN_HEIGHT));
		const Vector2f end(this->random(SCREEN_WIDTH), this->random(SCREEN_HEIGHT));
		walls.push_back(wall(start, end));
	}

	// Make rays
	std::vector<ray> rays;
	const float step = 1.f / ray_density;
	for (float a = 0; a < PI; a += step)
	{
		const float y = cos(a);
		const float x = sin(a);
		rays.push_back(ray(x, y));
	}

	std::vector<ray> rays2;
	for (float a = 0; a < PI; a += step)
	{
		const float y = cos(a);
		const float x = -sin(a);
		rays2.push_back(ray(x, y));
	}

    // Make line used for drawing rays
	VertexArray ray_line(Lines, 2);
	ray_line[0].color = ray_color;
	ray_line[1].color = ray_color;

	// Make line used for drawing walls
	VertexArray wall_line(Lines, 2);
	wall_line[0].color = wall_color;
	wall_line[1].color = wall_color;

	// Main loop
	Vector2f mouse_snapshot;

    // sf::Clock CClock = sf::Clock();
    // sf::Time tTimePerFrame = sf::seconds(1.0f / FRAME_RATE_LIMIT);
    // sf::Time tTimeSinceLastUpdate = sf::Time::Zero;

    this->CWindow.setFramerateLimit(FRAME_RATE_LIMIT);

    while(this->CWindow.isOpen()) {
		this->processEvents(); 
	
		if (Keyboard::isKeyPressed(Keyboard::D)) this->side = 0;
		else if (Keyboard::isKeyPressed(Keyboard::A)) this->side = 1;
		
		g_mouse_pos = Vector2f(Mouse::getPosition(this->CWindow));
		if (mouse_snapshot == g_mouse_pos) continue;
		ray_line[0].position = g_mouse_pos;
		std::cout << ray_line[0].position.x << std::endl;

        // tTimeSinceLastUpdate += CClock.restart();
        // while(tTimeSinceLastUpdate > tTimePerFrame) {
        //     tTimeSinceLastUpdate -= tTimePerFrame;
        //     this->processEvents();
        //     //this->update(tTimePerFrame);
        // }

        //SceneManager::getInstance()->checkLoadScene();
        //ObjectCollisionManager::getInstance()->checkCollision();
        //this->render();
		this->CWindow.clear();

		
		if(side == 0)
		{
			// Calculate intersections and draw rays
			for (int i = 0; i < rays.size(); i++)
			{
				// Set ray end-point to default
				rays[i].reset();

				// Cycle through every wall and set end point to intersection
				// When an intersection is found, the end-point is set to that intersection, meaning the next check will check for walls
				// between mouse and the new end-point. This means the ray will always go to the nearest wall
				for (int j = 0; j < walls.size(); j++)
				{
					// Calculate ray end-point
					rays[i].calc_hit(walls[j].start, walls[j].end);
				}
				
				// Set drawing-line end to final intersection
				ray_line[1].position = rays[i].m_end;
				
				// Draw ray
				CWindow.draw(ray_line);
			}
		}
        
		
		if(side == 1)
		{
			// Calculate intersections and draw rays
			for (int i = 0; i < rays2.size(); i++)
			{
				// Set ray end-point to default
				rays2[i].reset();

				// Cycle through every wall and set end point to intersection
				// When an intersection is found, the end-point is set to that intersection, meaning the next check will check for walls
				// between mouse and the new end-point. This means the ray will always go to the nearest wall
				for (int j = 0; j < walls.size(); j++)
				{
					// Calculate ray end-point
					rays2[i].calc_hit(walls[j].start, walls[j].end);
				}
				
				// Set drawing-line end to final intersection
				ray_line[1].position = rays2[i].m_end;
				
				// Draw ray
				CWindow.draw(ray_line);
			}
		}

        // Draw walls
		for (int i = 0; i < walls.size(); i++)
		{
			wall_line[0].position = walls[i].start;
			wall_line[1].position = walls[i].end;
			this->CWindow.draw(wall_line);
		}
		this->CWindow.display();
        // Save current mouse position
		mouse_snapshot = g_mouse_pos;
		}
}


void Game::processEvents() {
    sf::Event CEvent;
    while(this->CWindow.pollEvent(CEvent)) {
        switch(CEvent.type){
            case sf::Event::Closed:
                this->CWindow.close();
                break;

            
            default:
                //GameObjectManager::getInstance()->processEvents(CEvent);
                break;
        }
    }
}

void Game::update(sf::Time tDeltaTime) {
    GameObjectManager::getInstance()->update(tDeltaTime);
}

void Game::render() {
    this->CWindow.clear();
    GameObjectManager::getInstance()->draw(&this->CWindow);
    this->CWindow.display();
}

