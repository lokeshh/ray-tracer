#include <iostream>
#include <FreeImage.h>
#include <string>

using namespace std;

int w = 2;
int h = 4;

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
    sample.x = pixelNumber / w;
    sample.y = pixelNumber % w;
    // Increment
    pixelNumber += 1;
    return true;
  }
};

int main(void)
{
  // FreeImage_Initialise();
  //
  // int w = 2, h = 2;
  // int pix = w * h;
  // BYTE * pixels = new BYTE[3*pix] ;
  // pixels[0] = 255;          // Blue
  // pixels[1] = 0;
  // pixels[2] = 0;
  // pixels[3] = 0;            // Red
  // pixels[4] = 0;
  // pixels[5] = 255;
  // pixels[6] = 0;            // Red
  // pixels[7] = 0;
  // pixels[8] = 255;
  // pixels[9] = 0;            // Black
  // pixels[10] = 0;
  // pixels[11] = 0;
  //
  // string fname = "test.png";
  //
  // FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, w, h, w * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);
  // FreeImage_Save(FIF_PNG, img, fname.c_str(), 0);
  // FreeImage_DeInitialise();

  Sampler sampler;
  Sample sample;
  sampler.getSample(sample);
  cout << sample.x << " " << sample.y << endl;
  sampler.getSample(sample);
  cout << sample.x << " " << sample.y << endl;
  sampler.getSample(sample);
  cout << sample.x << " " << sample.y << endl;
  sampler.getSample(sample);
  cout << sample.x << " " << sample.y << endl;
  sampler.getSample(sample);
  cout << sample.x << " " << sample.y << endl;
  cout << "It's working." << endl;
}
