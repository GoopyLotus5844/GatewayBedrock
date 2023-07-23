//
// Created by Hank Stennes on 7/23/23.
//

#ifndef GATEWAYBEDROCK_CAMERA_H
#define GATEWAYBEDROCK_CAMERA_H

namespace GtwUI {

    const float MIN_ZOOM = 0.1, MAX_ZOOM = 3;

    class Camera {

    private:
        float x, y;

        float zoom;

        int prevMouseX, prevMouseY;

    public:
        Camera();

        void pan(int x, int y);

        void changeZoom(float dZoom, int mouseX, int mouseY, int w, int h);

        void setInitialMousePos(int x, int y);

        float getX() const;

        float getY() const;

        float getZoom() const;
    };

}


#endif //GATEWAYBEDROCK_CAMERA_H
