#include "player.h"
#include "Texture.hpp"
#include "animation_handler.h"
#include "raylib-cpp.hpp"
#include "raylib.h"
#include <utility>
#include <vector>

void Player::draw() {
    AnimationFrame af = m_animationHandler.getCurrentFrame();
    DrawTextureRec(m_textures.at(af.animKey), af.texRect, m_pos, WHITE);
}

void Player::update() { m_animationHandler.update(); }

void Player::loadTextures() {
    // Idle
    raylib::Texture2D idleTex("assets/player.idle.png");
    m_textures.insert({(int)PlayerState::IDLE, idleTex});

    std::vector<raylib::Rectangle> idleHitboxes{
        {25, 25, 25, 25},
        {25, 25, 25, 25},
    };

    AnimationData ad{.animKey = (int)PlayerState::IDLE,
                     .numFrames = 2,
                     .framesPerFrame = 30,
                     .frameWidth = 100,
                     .frameHeight = 100,
                     .loops = true,
                     .hitboxFrames = {}};

    m_animationHandler.addAnimation((int)PlayerState::IDLE, ad);
}

bool Player::isDead() { return m_isDead; }
PlayerState Player::getState() { return m_state; }
raylib::Rectangle Player::getHitbox() { return m_hitbox; }
