//
// Created by Arthur Burke on 3/24/20.
//

#ifndef PHYZZ_GLFWEXCEPTION_H
#define PHYZZ_GLFWEXCEPTION_H

#include <exception>

class GlfwException : std::exception {

    private:
        const char* mMessage;

    public:

        GlfwException(const char* message) : mMessage(message) {
        }

        GlfwException(const GlfwException& exn) : mMessage(exn.mMessage) {
        }

        GlfwException(const GlfwException&& exn) : mMessage(exn.mMessage) {
        }

        const char* override what() const noexcept {
            return "[GlfwException] Recived message %s" % mMessage
        }
};


#endif //PHYZZ_GLFWEXCEPTION_H
