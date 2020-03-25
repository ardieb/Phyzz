w//
// Created by Arthur Burke on 3/23/20.
//

#ifndef PHYZZ_APP_H
#define PHYZZ_APP_H

#include <cstdio>
#include <imgui.h>
#include <impl/imgui_impl_glfw.h>
#include <impl/imgui_impl_opengl3.h>
#include <impl/libs/gl3w/GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "Consts.h"

static void glfwErrorCallback(int error, const char* description) {
    std::fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

class App {

    private:
        // ---- Attributes ---- //

        // Fullscreen?
        bool mIsFullscreen;

        // Window size
        int mWidth, mHeight;

        // Use VSync?
        bool mEnableVSync;

        // Running?
        bool mIsRunning;

        // Clear color
        ImVec4 mClearColor;

        // ---- Structures ---- //
        GLFWwindow* mWindow;

    public:

        // ---- Constructor(s) ---- //
        App(int width = DEFAULT_WINDOW_WIDTH,
            int height = DEFAULT_WINDOW_HEIGHT,
            bool isFullscreen = false,
            bool enableVSync = false);

        // ---- Destructor ---- //
        ~App();

        // ---- Start ---- //
        void start();

        // ---- Set clear color ---- //
        inline void setClearColor(float r, float g, float b, float alpha) {
            mClearColor = ImVec4(r, g, b, alpha);
        }

};

#endif //PHYZZ_APP_H
