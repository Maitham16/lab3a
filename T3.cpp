#include "classes/Color.h"
#include "classes/Light.h"
#include "classes/sphereT3.h"
#include "classes/Camera.h"
#include "classes/Ray.h"
#include "classes/Vec3.h"
#include "classes/Ray_Trace.h"
#include "classes/SavePPM.h"
#include "classes/Material.h"
#include "classes/MaterialSolid.h"
#include <cmath>
#include <pugixml.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
#include <memory>

// parse surfaces from XML
std::vector<anotherSphere> parseSurfaces(const pugi::xml_node &surfacesNode)
{
    std::vector<anotherSphere> spheres;

    for (auto &&node : surfacesNode.children())
    {
        if (std::string(node.name()) == "sphere")
        {
            double radius = node.attribute("radius").as_double();
            pugi::xml_node positionNode = node.child("position");
            double x = positionNode.attribute("x").as_double();
            double y = positionNode.attribute("y").as_double();
            double z = positionNode.attribute("z").as_double();
            pugi::xml_node materialNode = node.child("material_solid");
            pugi::xml_node colorNode = materialNode.child("color");
            double r = colorNode.attribute("r").as_double();
            double g = colorNode.attribute("g").as_double();
            double b = colorNode.attribute("b").as_double();
            pugi::xml_node phongNode = materialNode.child("phong");
            double ka = phongNode.attribute("ka").as_double();
            double kd = phongNode.attribute("kd").as_double();
            double ks = phongNode.attribute("ks").as_double();
            double exponent = phongNode.attribute("exponent").as_double();
            pugi::xml_node reflectanceNode = materialNode.child("reflectance");
            double reflectance = reflectanceNode.attribute("r").as_double();
            pugi::xml_node transmittanceNode = materialNode.child("transmittance");
            double transmittance = transmittanceNode.attribute("t").as_double();
            pugi::xml_node refractionNode = materialNode.child("refraction");
            double iof = refractionNode.attribute("iof").as_double();

            // create spheres
            Vec3 position(x, y, z);
            anotherSphere sphere(position, radius, MaterialSolidT3(), Color(), position);
            sphere.material.color = Color(r, g, b);
            sphere.material.ka = ka;
            sphere.material.kd = kd;
            sphere.material.ks = ks;
            sphere.material.exponent = exponent;
            sphere.material.reflectance = reflectance;
            sphere.material.transmittance = transmittance;
            sphere.material.iof = iof;

            spheres.push_back(sphere);
            // console checking
            std::cout << "anotherSphere: Radius=" << radius << ", Position=(" << x << "," << y << "," << z << ")\n";
        }
    }
    if (spheres.empty())
    {
        std::cout << "No spheres parsed." << std::endl;
    }
    return spheres;
}

// parse lights from XML
std::pair<Light, Color> parseLights(const pugi::xml_node &lightsNode)
{
    pugi::xml_node ambientLightNode = lightsNode.child("ambient_light");
    pugi::xml_node ambientColorNode = ambientLightNode.child("color");
    double ar = ambientColorNode.attribute("r").as_double();
    double ag = ambientColorNode.attribute("g").as_double();
    double ab = ambientColorNode.attribute("b").as_double();
    Color ambientLight(ar, ag, ab);

    pugi::xml_node parallelLightNode = lightsNode.child("parallel_light");
    pugi::xml_node directionNode = parallelLightNode.child("direction");
    double x = directionNode.attribute("x").as_double();
    double y = directionNode.attribute("y").as_double();
    double z = directionNode.attribute("z").as_double();

    pugi::xml_node lightColorNode = parallelLightNode.child("color");
    double c_r = lightColorNode.attribute("r").as_double();
    double c_g = lightColorNode.attribute("g").as_double();
    double c_b = lightColorNode.attribute("b").as_double();

    Light light(Vec3(x, y, z), Color(c_r, c_g, c_b));
    return std::make_pair(light, ambientLight);
}

// parse camera from XML
Camera parseCamera(const pugi::xml_node &cameraNode)
{
    pugi::xml_node positionNode = cameraNode.child("position");
    double x = positionNode.attribute("x").as_double();
    double y = positionNode.attribute("y").as_double();
    double z = positionNode.attribute("z").as_double();
    pugi::xml_node lookatNode = cameraNode.child("lookat");
    double lookat_x = lookatNode.attribute("x").as_double();
    double lookat_y = lookatNode.attribute("y").as_double();
    double lookat_z = lookatNode.attribute("z").as_double();
    pugi::xml_node upNode = cameraNode.child("up");
    double up_x = upNode.attribute("x").as_double();
    double up_y = upNode.attribute("y").as_double();
    double up_z = upNode.attribute("z").as_double();
    pugi::xml_node horizontal_fovNode = cameraNode.child("horizontal_fov");
    double horizontal_fov = horizontal_fovNode.attribute("angle").as_double();
    pugi::xml_node resolutionNode = cameraNode.child("resolution");
    double horizontal = resolutionNode.attribute("horizontal").as_double();
    double vertical = resolutionNode.attribute("vertical").as_double();
    pugi::xml_node max_bouncesNode = cameraNode.child("max_bounces");
    double max_bounces = max_bouncesNode.attribute("n").as_double();

    // create camera object
    Camera camera;
    camera.position = Vec3(x, y, z);
    camera.lookAt = Vec3(lookat_x, lookat_y, lookat_z);
    camera.up = Vec3(up_x, up_y, up_z);
    camera.fov = horizontal_fov;
    camera.imgWidth = static_cast<int>(horizontal);
    camera.imgHeight = static_cast<int>(vertical);
    camera.maxBounce = static_cast<int>(max_bounces);

    return camera;
}

// parse scene from XML
void parseScene(const std::string &fileName, std::string &outputFileName, Color &bgColor, Camera &camera, std::vector<anotherSphere> &spheres, Light &light, Color &ambientLight)
{
    pugi::xml_document doc;
    if (!doc.load_file(fileName.c_str()))
    {
        std::cout << "Could not load file!" << std::endl;
        return;
    }

    auto sceneNode = doc.child("scene");

    // Parse output file
    std::string output_file = sceneNode.attribute("output_file").as_string();
    std::cout << "Output file: " << output_file << "\n";

    // Parse background color
    pugi::xml_node bgColorNode = sceneNode.child("background_color");
    double bg_r = bgColorNode.attribute("r").as_double();
    double bg_g = bgColorNode.attribute("g").as_double();
    double bg_b = bgColorNode.attribute("b").as_double();
    bgColor = Color(bg_r, bg_g, bg_b);
    std::cout << "Background color: (" << bg_r << "," << bg_g << "," << bg_b << ")\n";

    for (auto &&node : sceneNode.children())
    {
        if (std::string(node.name()) == "camera")
        {
            camera = parseCamera(node);
        }
        else if (std::string(node.name()) == "lights")
        {
            std::tie(light, ambientLight) = parseLights(node);
        }
        else if (std::string(node.name()) == "surfaces")
        {
            spheres = parseSurfaces(node);
        }
    }
    // Render the scene
    int width = 800;
    int height = 600;
    std::vector<unsigned char> imageData(width * height * 3);

    double aspectRatio = static_cast<double>(width) / height;
    double fov = 90.0;
    double scale = tan(0.5 * fov * 3.14159265359 / 180.0);
    Vec3 cameraPosition(0, 0, 1);
    std::vector<Light> lights;            
    lights.push_back(Light(Vec3(0, 1, 0), Color(1, 1, 1)));

    int maxDepth = 8;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            double u = (2.0 * (x + 0.5) / width - 1.0) * aspectRatio * scale;
            double v = (1.0 - 2.0 * (y + 0.5) / height) * scale;

            Vec3 direction(u, v, -1);
            direction = direction / sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);

            Color color = RayTrace(Ray(cameraPosition, direction), spheres, lights, maxDepth);

            unsigned char r = static_cast<unsigned char>(255.99 * color.r);
            unsigned char g = static_cast<unsigned char>(255.99 * color.g);
            unsigned char b = static_cast<unsigned char>(255.99 * color.b);

            int pixelIndex = (y * width + x) * 3;
            imageData[pixelIndex] = r;
            imageData[pixelIndex + 1] = g;
            imageData[pixelIndex + 2] = b;
        }
    }
    // Save the rendered image
    savePPM(output_file, width, height, imageData);
}

int main()
{
    // define variables to store parsed data
    std::string outputFileName;
    Color bgColor;
    Camera camera;
    std::vector<anotherSphere> spheres;
    Light light;
    Color ambientLight;

    // call parseScene to parse XML file
    parseScene("scenes/example1.xml", outputFileName, bgColor, camera, spheres, light, ambientLight);

    return 0;
}
