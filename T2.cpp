// T2: Output an image with spheres on it after ray tracing them.
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

    // Create the scene
    std::vector<Sphere> scene;
    scene.push_back(Sphere(Vec3(0.0f, 0.0f, 0.0f), 0.5f, Material(Color(1.0f, 0.0f, 0.0f), Color(0.0f, 0.0f, 0.0f), 0.0f), Color(1.0f, 0.0f, 0.0f))); // Red

    // Define the lights
    std::vector<Light> lights;
    lights.push_back(Light(Vec3(0.0f, 0.0f, -1.0f), Color(1.0f, 1.0f, 1.0f)));

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
            // Generate a ray for the current pixel
            float u = static_cast<float>(x) / (imageWidth - 1);
            float v = static_cast<float>(y) / (imageHeight - 1);
            Ray ray = camera.getRay(u, v);

            // Trace the ray and check for intersection with the sphere
            float t;
            if (scene[0].intersect(ray, t))
            {
                // Calculate the point on the sphere surface
                Vec3 intersectionPoint = ray.origin + ray.direction * t;

                // Calculate the normalized direction from the sphere center to the intersection point
                Vec3 direction = (intersectionPoint - scene[0].center).normalize();

                // Calculate the color based on the direction
                Color pixelColor((direction.x + 1.0f) * 0.5f, (direction.y + 1.0f) * 0.5f, (direction.z + 1.0f) * 0.5f);

                // Set the pixel color
                imageData[(y * imageWidth + x) * 3 + 0] = static_cast<unsigned char>(pixelColor.r * 255); // Red
                imageData[(y * imageWidth + x) * 3 + 1] = static_cast<unsigned char>(pixelColor.g * 255); // Green
                imageData[(y * imageWidth + x) * 3 + 2] = static_cast<unsigned char>(pixelColor.b * 255); // Blue
            }
        }
    }

    // Save the image to a file using the savePPM function
    savePPM("T2_Sphere.ppm", imageWidth, imageHeight, imageData);

    // 0 means the program exited successfully
    return 0;
}
