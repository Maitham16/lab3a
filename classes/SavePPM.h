// header class to save as ppm
#ifndef SAVEPPM_H
#define SAVEPPM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Color.h"

#include <fstream>

void savePPM(const std::string& filename, int width, int height, const std::vector<unsigned char>& imageData)
{
    std::ofstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Failed to open the file for writing: " << filename << std::endl;
        return;
    }

    // Write the PPM header
    file << "P6\n";
    file << width << " " << height << "\n";
    file << "255\n";

    // Write the pixel data
    file.write(reinterpret_cast<const char*>(imageData.data()), imageData.size());

    file.close();

    std::cout << "Image saved as PPM: " << filename << std::endl;
};

#endif