#pragma once

static const int WIDTH = 800;
static const int HEIGHT = 600;

static const float WS_X = 1.6f;
static const float WS_Y = 2.33f;
static const float WS_Z = 2.62f;
static const float WS_X_MIN = -0.8f;
static const float WS_X_MAX = 0.8f;
static const float WS_Y_MIN = -0.4f;
static const float WS_Y_MAX = 1.95f;
static const float WS_Z_MIN = -1.31f;
static const float WS_Z_MAX = 1.31f;

//const int NUM_SHAPES = 2;
enum Shape {
	KOMIN,
	WIEZA,
	PIRAMIDA,
	NUM_SHAPES,
};