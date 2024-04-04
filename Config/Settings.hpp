#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>

using namespace sf;

const int SCREEN_WIDTH  = 800;
const int SCREEN_HEIGHT = 440;
const float SCREEN_SCALE = 1.0f;
const float FRAME_RATE_LIMIT = 60.0f;

const int SFX_VOLUME = 25;

constexpr auto TWO_PI = 3.14159265358979f * 2;
constexpr auto PI = 3.14159265358979f;
extern Vector2f g_mouse_pos;
