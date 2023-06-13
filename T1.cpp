// T1: Output a valid black image file.
#include "classes/Camera.h"
#include "classes/Color.h"
#include "classes/Light.h"
#include "classes/Material.h"
#include "classes/Ray.h"
#include "classes/SavePPM.h"
#include "classes/Sphere.h"
#include "classes/Trace.h"
#include "classes/Vec3.h"

#include <vector>

int main()
{
    // Define the camera parameters
    Vec3 cameraPosition(0.0f, 0.0f, -1.0f);
    Vec3 lookAt(0.0f, 0.0f, 0.0f);
    Vec3 up(0.0f, 1.0f, 0.0f);
    float fov = 90.0f;
    float aspectRatio = 16.0f / 9.0f;

    // Create the camera
    Camera camera(cameraPosition, lookAt, up, fov, aspectRatio, 1, 1, 1);

    // Define the image resolution
    int imageWidth = 800;
    int imageHeight = 600;

    // Create a buffer to store the pixel colors
    std::vector<unsigned char> imageData(imageWidth * imageHeight * 3, 0);

    // Iterate over each pixel
    for (int y = 0; y < imageHeight; y++)
    {
        for (int x = 0; x < imageWidth; x++)
        {
            // Set the pixel color to black
            imageData[(y * imageWidth + x) * 3 + 0] = 0; // Red
            imageData[(y * imageWidth + x) * 3 + 1] = 0; // Green
            imageData[(y * imageWidth + x) * 3 + 2] = 0; // Blue
        }
    }

    // Save the image to a file using the savePPM function
    savePPM("T1_black_image.ppm", imageWidth, imageHeight, imageData);

    // 0 means success
    return 0;
}
