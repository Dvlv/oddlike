#include "animation_handler.h"
#include "raylib-cpp.hpp"
#include <string>

AnimationFrame AnimationHandler::getCurrentFrame() {
    AnimationData currentAnimData = m_animations.at(m_currentAnimation);

    raylib::Rectangle texRect = {
        (float)m_currentFrame * currentAnimData.frameWidth,
        0,
        (float)currentAnimData.frameWidth,
        (float)currentAnimData.frameHeight,
    };

    AnimationFrame af = {
        .animKey = m_currentAnimation,
        .texRect = texRect,
        .hitbox = currentAnimData.hitboxFrames.at(m_currentFrame),
    };

    return af;
}

void AnimationHandler::setCurrentAnimation(int animation) {
    m_currentFrame = 0;
    m_currentAnimation = animation;
}

void AnimationHandler::addAnimation(int key, AnimationData animData) {
    m_animations.insert({key, animData});
}

void AnimationHandler::setDefaultAnimation(int key) {
    m_defaultAnimation = key;
}

void AnimationHandler::update() {
    AnimationData currentAnimData = m_animations.at(m_currentAnimation);

    ++m_animFrameCounter;
    if (m_animFrameCounter >= currentAnimData.framesPerFrame) {
        m_animFrameCounter = 0;
        ++m_currentFrame;
        if (m_currentFrame >= currentAnimData.numFrames) {
            m_currentFrame = 0;
            // current anim finished, if this is not looping, set to default
            if (!currentAnimData.loops) {
                setCurrentAnimation(m_defaultAnimation);
            }
        }
    }
}
