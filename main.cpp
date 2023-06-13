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
    // Define the camera parameters position, lookAt, up, fov, aspectRatio, maxBounce, imgHeight, imgWidth
    Vec3 cameraPosition(0.0f, 0.0f, -1.0f);
    Vec3 lookAt(0.0f, 0.0f, 0.0f);
    Vec3 up(0.0f, 1.0f, 0.0f);
    float fov = 90.0f;
    float aspectRatio = 16.0f / 9.0f;
    float maxBounce = 1;
    int imgHeight = 600;
    int imgWidth = 800;
        
    Camera camera(cameraPosition, lookAt, up, fov, aspectRatio, maxBounce, imgHeight, imgWidth);

    std::vector<Sphere> scene;
    scene.push_back(Sphere(Vec3(0.0f, 0.0f, 0.0f), 0.5f, Material(Color(1.0f, 0.0f, 0.0f), Color(0.0f, 0.0f, 0.0f), 0.0f), Color(1.0f, 0.0f, 0.0f))); 
    scene.push_back(Sphere(Vec3(0.0f, -100.5f, 0.0f), 100.0f, Material(Color(0.0f, 0.0f, 1.0f), Color(0.0f, 0.0f, 0.0f), 0.0f), Color(0.0f, 0.0f, 1.0f)));
    scene.push_back(Sphere(Vec3(1.0f, 0.0f, 0.0f), 0.5f, Material(Color(0.0f, 1.0f, 0.0f), Color(0.0f, 0.0f, 0.0f), 0.0f), Color(0.0f, 1.0f, 0.0f)));
    
    // Define the lights
    std::vector<Light> lights;
    lights.push_back(Light(Vec3(0.0f, 1.0f, -1.0f), Color(1.0f, 1.0f, 1.0f)));

    // Define the image resolution
    int imageWidth = 800;
    int imageHeight = 600;

    // Create a buffer to store the pixel colors
    std::vector<unsigned char> imageData(imageWidth * imageHeight * 3);

    // Iterate over each pixel
    for (int y = 0; y < imageHeight; y++)
    {
        for (int x = 0; x < imageWidth; x++)
        {
            // Generate a ray for the current pixel
            float u = static_cast<float>(x) / (imageWidth - 1);
            float v = static_cast<float>(y) / (imageHeight - 1);
            Ray ray = camera.getRay(u, v);

            // Trace the ray and get the color at the intersection point
            Color pixelColor = trace(ray, scene, lights, 5);

            // Set the pixel color based on the intersection result
            imageData[(y * imageWidth + x) * 3 + 0] = static_cast<unsigned char>(pixelColor.r * 255); // Red
            imageData[(y * imageWidth + x) * 3 + 1] = static_cast<unsigned char>(pixelColor.g * 255); // Green
            imageData[(y * imageWidth + x) * 3 + 2] = static_cast<unsigned char>(pixelColor.b * 255); // Blue
        }
    }

    // Save the image to a file using the savePPM function
    savePPM("output.ppm", imageWidth, imageHeight, imageData);

    return 0;
}
