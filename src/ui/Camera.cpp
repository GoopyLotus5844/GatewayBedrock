//
// Created by Hank Stennes on 7/23/23.
//

#include "Camera.h"
#include <iostream>

namespace GtwUI {

    Camera::Camera() : x(0), y(0), zoom(1), prevMouseX(0), prevMouseY(0) { }

    void Camera::pan(int mouseX, int mouseY) {
        std::cout << mouseX << std::endl;
        int dx = mouseX - prevMouseX;
        int dy = mouseY - prevMouseY;
        x += dx * (1 / zoom);
        y += dy * (1 / zoom);
        prevMouseX = mouseX;
        prevMouseY = mouseY;
    }

    void Camera::changeZoom(float dZoom, int mouseX, int mouseY, int w, int h) {
        float oldZoom = zoom;
        zoom += dZoom;
        if(zoom < MIN_ZOOM) zoom = MIN_ZOOM;
        if(zoom > MAX_ZOOM) zoom = MAX_ZOOM;
        double offsetCoeff = (oldZoom - zoom) / (oldZoom * zoom);
        x += mouseX * offsetCoeff;
        y += mouseY * offsetCoeff;
    }

    void Camera::setInitialMousePos(int mouseX, int mouseY) {
        std::cout << mouseX << std::endl;
        prevMouseX = mouseX;
        prevMouseY = mouseY;
    }

    float Camera::getX() const {
        return x;
    }

    float Camera::getY() const {
        return y;
    }

    float Camera::getZoom() const {
        return zoom;
    }
}
