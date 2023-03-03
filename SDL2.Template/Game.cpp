#include "Game.h"
#include "TextureManager.h"

SDL_Texture* playertex;

int paddle1Y = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;
int paddle2Y = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;

int ballX = SCREEN_WIDTH / 2 - BALL_SIZE / 2;
int ballY = SCREEN_HEIGHT / 2 - BALL_SIZE / 2;
int ballVelocityX = BALL_SPEED;
int ballVelocityY = BALL_SPEED;

Game::Game() {

}
Game::~Game() {

}

bool Game::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}

	playertex = TextureManager::LoadTexture("assets/rickroll.png", renderer);
	return isRunning = true;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	// Move paddles
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_W] && paddle1Y > 0) {
		paddle1Y -= PADDLE_SPEED;
	}
	if (state[SDL_SCANCODE_S] && paddle1Y + PADDLE_HEIGHT < SCREEN_HEIGHT) {
		paddle1Y += PADDLE_SPEED;
	}
	if (state[SDL_SCANCODE_UP] && paddle2Y > 0) {
		paddle2Y -= PADDLE_SPEED;
	}
	if (state[SDL_SCANCODE_DOWN] && paddle2Y + PADDLE_HEIGHT < SCREEN_HEIGHT) {
		paddle2Y += PADDLE_SPEED;
	}
}

void Game::update()
{
	// Update ball position
	ballX += ballVelocityX;
	ballY += ballVelocityY;

	// Check for collision with walls
	if (ballY < 0 || ballY + BALL_SIZE > SCREEN_HEIGHT) {
		ballVelocityY = -ballVelocityY;
	}

	// Check for collision with paddles
	if (ballX < PADDLE_WIDTH + 10) {
		if (ballY + BALL_SIZE > paddle1Y && ballY < paddle1Y + PADDLE_HEIGHT) {
			ballVelocityX = -ballVelocityX;
		}
		else {
			std::cout << "Game Over!" << std::endl;
			isRunning = false;
		}
	}
	else if (ballX + BALL_SIZE > SCREEN_WIDTH - PADDLE_WIDTH - 10) {
		if (ballY + BALL_SIZE > paddle2Y && ballY < paddle2Y + PADDLE_HEIGHT) {
			ballVelocityX = -ballVelocityX;
		} else {
			std::cout << "Game Over!" << std::endl;
			isRunning = false;
		}
	}
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, playertex, NULL, NULL);

	SDL_Rect paddle1 = {10, paddle1Y, PADDLE_WIDTH, PADDLE_HEIGHT};
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &paddle1);

	SDL_Rect paddle2 = { SCREEN_WIDTH - 10 - PADDLE_WIDTH, paddle2Y, PADDLE_WIDTH, PADDLE_HEIGHT };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &paddle2);

	SDL_Rect ball = { ballX, ballY, BALL_SIZE, BALL_SIZE };

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &ball);

	SDL_RenderPresent(renderer);
}

void Game::quit() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
