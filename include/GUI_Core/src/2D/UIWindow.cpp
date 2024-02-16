#include <2D/UIWindow.h>
#include <iostream>

UIWindow::UIWindow(const char* p_title): m_title(p_title)
{
    
}

void UIWindow::draw()
{
    ImGui::Begin(m_title);
}

void UIWindow::shutdown()
{
    
}

GUI_Helper::ImageData GUI_Helper::loadImageToRAM(const char* filename)
{
    // Load from file
    int image_width = 0;
    int image_height = 0;
    int channels = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, &channels, 4);

    GUI_Helper::ImageData temp;
    temp.width = image_width;
    temp.height = image_height;
    temp.channels = channels;
    temp.data = image_data;
    return temp;
}

void GUI_Helper::freeImageMemory(GUI_Helper::ImageData image)
{
    stbi_image_free(image.data);
}

ImTextureID GUI_Helper::loadImageToGPU(GUI_Helper::ImageData imageData)
{   
    const bgfx::Memory* image_memory = bgfx::copy(imageData.data, imageData.width * imageData.height * imageData.channels);
    // Create texture
    auto res = bgfx::createTexture2D(imageData.width, imageData.height, false, 1,
                                     bgfx::TextureFormat::RGBA8,
                                     0ULL,
                                     image_memory);
                                    //  bgfx::makeRef(imageData.data, imageData.width * imageData.height * imageData.channels));
    if(!bgfx::isValid(res)) {
        // Something went wrong
        std::cout << "Error creating texture"<< std::endl;
        // return (void*)(intptr_t)0;
    }
    return (void*)(intptr_t)res.idx;
    /*
    // Load from file
    int image_width = 0;
    int image_height = 0;
    int channels = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, &channels, 4);

    // Create texture
    auto res = bgfx::createTexture2D(image_width, image_height, false, 1,
                                     bgfx::TextureFormat::RGBA8,
	                                 BGFX_SAMPLER_U_CLAMP
	                                 | BGFX_SAMPLER_V_CLAMP
	                                 | BGFX_SAMPLER_MIN_POINT
	                                 | BGFX_SAMPLER_MAG_POINT,
                                     bgfx::copy(image_data, image_width * image_height * channels));
    // Check if texture was created
    if(!bgfx::isValid(res)) {
        // Something went wrong
        std::cout << "Error loading image: " << filename << std::endl;
        stbi_image_free(image_data);
        ImageData temp;
        temp.texture = 0;
        temp.width = 0;
        temp.height = 0;
        return temp;
    }

    stbi_image_free(image_data);
    ImageData temp;
    temp.texture = (void*)(intptr_t)res.idx;
    temp.width = image_width;
    temp.height = image_height;
    return temp;*/
}