#pragma once

#include "animation_handler.h"
#include "raylib-cpp.hpp"
#include <array>

enum class PlayerState {
    IDLE = 0,
    WALKING,
    RUNNING,
    SNEAKING,
    HOPPING,
    JUMPING_UP,
    KNOCKED_OVER,
    AIMING,
    THROWING,
    HANGING,
    CLIMBING,
};

class Player {
  public:
    Player() = default;
    PlayerState getState();
    bool isDead();
    raylib::Rectangle getHitbox();
    void loadTextures();

    void draw();
    void update();

  private:
    // vars
    AnimationHandler m_animationHandler = AnimationHandler();
    raylib::Vector2 m_pos = {0, 0};
    PlayerState m_state = PlayerState::IDLE;
    bool m_isFacingLeft = false;
    bool m_isDead = false;
    raylib::Rectangle m_hitbox = {0, 0, 0, 0};

    std::unordered_map<int, raylib::Texture2D &> m_textures;

    // methods
};
