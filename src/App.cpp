//
// Created by Arthur Burke on 3/23/20.
//

#include "App.h"
#include "Logging/PLogger.h"
#include "Exceptions/GlfwException.h"
#include "Consts.h"

App::App(int width,
         int height,
         bool isFullscreen,
         bool enableVSync) :
         mWidth(width),
         mHeight(height),
         mIsFullscreen(isFullscreen),
         mEnableVSync(enableVSync),
         mIsRunning(false) {
    glfwSetErrorCallback(glfwErrorCallback);
    if (!glfwInit()) {
        LOG_ERROR("Glfw failed to initialize.")
        throw GlfwException("Glfw failed to initialize.");
    }
    LOG_INFO("Glfw initialized successfully.")
    // Decide GL+GLSL versions
#if __APPLE__
    // GL 3.2 + GLSL 150
    const char *glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,
                   GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif
    GLFWmonitor *monitor = nullptr;
    if (mIsFullscreen) {
        // Only supports single monitor
        monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        mWidth = mode->width;
        mHeight = mode->height;
    }

    mWindow = glfwCreateWindow(mWidth, mHeight, "Phyzz", monitor, nullptr);
    if (!mWindow) {
        LOG_ERROR("Glfw failed to create window.")
        throw GlfwException("Glfw failed to create window.");
    }
    LOG_INFO("Glfw created window successfully.")
    if (mEnableVSync) {
        glfwSwapInterval(1);
    }

    if (gl3wInit() != 0) {
        LOG_ERROR("OpenGL loader failed to initialize.")
        throw GlfwException("OpenGL loader failed to initialize.");
    }
    LOG_INFO("OpenGL loader initialized successfully.")
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void) io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(mWindow, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.txt' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL)
    setClearColor(DEFAULT_CLEAR_COLOR);

}

App::~App() {
    // Shutdown ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    // Destroy Glfw window
    glfwDestroyWindow(mWindow);
    glfwTerminate();
}


void App::start() {
    while (!glfwWindowShouldClose(mWindow)) {
        glfwPollEvents();
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Fill buffers here
        // TODO

        ImGui::Render();
        glfwGetFramebufferSize(mWindow, &mWidth, &mHeight);
        glViewport(0, 0, mWidth, mHeight);
        glClearColor(mClearColor.x, mClearColor.y, mClearColor.z, mClearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // Draw dear imgui data
        glfwSwapBuffers(mWindow);
    }
}
