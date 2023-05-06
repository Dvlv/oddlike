#pragma once

#include "raylib-cpp.hpp"
#include <string>
#include <unordered_map>
#include <vector>

struct AnimationData {
    int animKey;
    int numFrames;
    int framesPerFrame;
    int frameWidth;
    int frameHeight;
    bool loops;
    std::vector<raylib::Rectangle> hitboxFrames;
};

struct AnimationFrame {
    int animKey;
    raylib::Rectangle texRect;
    raylib::Rectangle hitbox;
};

class AnimationHandler {
  public:
    AnimationHandler() = default;

    AnimationFrame getCurrentFrame();
    void setCurrentAnimation(int animation);
    void addAnimation(int key, AnimationData animData);
    void setDefaultAnimation(int key);

    void update();

  private:
    int m_animFrameCounter = 0;
    int m_currentFrame = 0;
    int m_maxFrame = 0;
    std::unordered_map<int, AnimationData> m_animations;
    int m_currentAnimation = 0;
    int m_defaultAnimation = 0;
};
