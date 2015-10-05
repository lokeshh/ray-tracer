#include <iostream>
#include <FreeImage.h>
#include <string>

using namespace std;

int w = 200;
int h = 400;
int pix = w * h;
BYTE * pixels = new BYTE[3*pix] ;

class Sample
{
public:
  int x, y;
};

class Sampler
{
public:
  int pixelNumber;
  Sampler()
  {
    pixelNumber = 0;
  }
  bool getSample(Sample& sample)
  {
    // Check
    if (pixelNumber >= w * h)
    {
      return false;
    }
    // Do it
    sample.x = pixelNumber % w;
    sample.y = pixelNumber / w;
    // Increment
    pixelNumber += 1;
    return true;
  }
};

class Color
{
public:
  Color(int R = 0, int G = 0, int B = 0)
  {
    r = R;
    g = G;
    b = B;
  }
  
  int r, g, b;
  Color operator+(Color& c2)
  {
    Color res;
    res.r = r + c2.r;
    res.g = g + c2.g;
    res.b = b + c2.b;
    return res;
  }
  
  Color operator-(Color& c2)
  {
    // will fill later
  }
  
};

class Film
{
public:
  void commit(Sample& sample, Color& color)
  {
    int pixelNumber = sample.y * w + sample.x;
    pixels[pixelNumber * 3]     = color.b;
    pixels[pixelNumber * 3 + 1] = color.g;
    pixels[pixelNumber * 3 + 2] = color.r;
  }
  
  void writeImage()
  {
    FreeImage_Initialise();
    string fname = "test.png";
    FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, w, h, w * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);
    FreeImage_Save(FIF_PNG, img, fname.c_str(), 0);
    FreeImage_DeInitialise();    
  }
};

int main(void)
{
  Sampler sampler;
  Sample sample;
  Film film;
  
  Color Blue(0, 0, 255);
  while (sampler.getSample(sample))
  {
    film.commit(sample, Blue);
  }
  
  film.writeImage();
  


  cout << "It's working." << endl;
}
