#ifndef DETECTCOLOR_H
#define DETECTCOLOR_H

const int interruptPin = 2;


void isr();
// void getRawData_noDelay(uint16_t *red, uint16_t *green, uint16_t *blue, uint16_t *clear);
void DetectColor_setup();
void DetectColor_run(int&, int&, int&); 

// ternary min
static double Min(double a, double b) {
	return a <= b ? a : b;
}
// ternary max
static double Max(double a, double b) {
	return a >= b ? a : b;
}

class RGB
{
public:
	unsigned char R;
	unsigned char G;
	unsigned char B;

	RGB(unsigned char r, unsigned char g, unsigned char b)
	{
		R = r;
		G = g;
		B = b;
	}

	bool Equals(RGB rgb)
	{
		return (R == rgb.R) && (G == rgb.G) && (B == rgb.B);
	}
};

class HSV
{
public:
	double H;
	double S;
	double V;

	HSV(double h, double s, double v)
	{
		H = h;
		S = s;
		V = v;
	}

	bool Equals(HSV hsv)
	{
		return (H == hsv.H) && (S == hsv.S) && (V == hsv.V);
	}
};

// https://en.wikipedia.org/wiki/HSL_and_HSV
// hue 360 degrees, saturation set [0,1], value set [0,1]
static HSV RGBToHSV(RGB rgb) {
	double delta, min;
	double h = 0, s, v;

	min = Min(Min(rgb.R, rgb.G), rgb.B);
	v = Max(Max(rgb.R, rgb.G), rgb.B);
	delta = v - min;

	if (v == 0.0)
		s = 0;
	else
		s = delta / v;

	if (s == 0)
		h = 0.0;

	else
	{
		if (rgb.R == v)
			h = (rgb.G - rgb.B) / delta;
		else if (rgb.G == v)
			h = 2 + (rgb.B - rgb.R) / delta;
		else if (rgb.B == v)
			h = 4 + (rgb.R - rgb.G) / delta;

		h *= 60;

		if (h < 0.0)
			h = h + 360;
	}

	return HSV(h, s, (v / 255));
}


#endif
