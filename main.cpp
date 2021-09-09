#include <RGBcolor.hpp>

int main() {

        const int Width = 1280;
        const int Height = 720;

        std::cout << "P3\n" << Width << ' ' << Height << "\n255\n";

        for(int j = Height; j >= 0; --j) {

                std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

                for(int i = 0; i < Width; ++i) {

                        RGBcolor color(double(i) / (Width - 1), double(j) / (Height - 1), 0.5);
                        writeColor(std::cout, color);
                }
        }

        std::cerr << "\nDone\n";
}