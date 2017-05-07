//
// Created by nyam on 07.05.17.
//

#include "Enemy.h"
#include <stdexcept>
#include <cstdlib>
#include "BitMask.h"
#include "Logging/logger.h"

void Enemy::initPhysicsPody()
{
    auto PlayerBody = PhysicsBody::createBox(Size(70.0f,121.0f), PhysicsMaterial(PLAYER_DENSITY, PLAYER_RESTITUTION, PLAYER_FRICTION));
    PlayerBody->PhysicsBody::setMass(0.1f);
    PlayerBody->setDynamic(true);
    PlayerBody->setVelocityLimit(SPEED_PLAYER_LIMIT);
    PlayerBody->setGravityEnable(true);
    PlayerBody->setRotationEnable(false);
    PlayerBody->setContactTestBitmask(true);
    PlayerBody->setCollisionBitmask(BitMask::ENEMY);
    addComponent(PlayerBody);
}

void Enemy::initIdleAnimate()
{

    std::string idleAnimTemplate = AnimFiles.at("Idle");

    int numbFrames = 12;
    Vector<SpriteFrame*> idleAnimFrames(numbFrames);

    for(int i = 1; i <= numbFrames; ++i)
    {
        std::string frame_str = getFrame(idleAnimTemplate, i);
        SpriteFrame* frame = SpriteFrame::create(frame_str,
                                                 Rect(0,0,77,121)
        );
        if (frame == nullptr)
        {
            std::string err =  "cannot create frame form" + frame_str;
            throw std::invalid_argument(err);
        }
        frame->setAnchorPoint(Vec2(0.5, 0));
        idleAnimFrames.pushBack(frame);

    }

    Animation* idleAnimation = Animation::createWithSpriteFrames(idleAnimFrames, 0.3f);
    idleAnimate = Animate::create(idleAnimation);

    if (idleAnimate == nullptr || idleAnimation == nullptr)
    {
        throw std::invalid_argument("cannot create idleAnimation");
    }

    idleAnimate->retain();
    runAction(RepeatForever::create(idleAnimate));
}

void Enemy::initMoveAnimate()
{
    std::string moveAnimTemplate = AnimFiles.at("Move");

    int numbFrames = 8;
    Vector<SpriteFrame*> moveAnimFrames(numbFrames);

    for(int i = 1; i <= numbFrames; ++i)
    {
        std::string frame_str = getFrame(moveAnimTemplate, i);
        SpriteFrame* frame = SpriteFrame::create(frame_str,
                                                 Rect(0, 0, 83, 126)
        );
        if (frame == nullptr)
        {
            std::string err =  "cannot create frame form" + frame_str;
            throw std::invalid_argument(err);
        }

        frame->setAnchorPoint(Vec2(0.5, 0));
        moveAnimFrames.pushBack(frame);
    }

    Animation* moveAnimation = Animation::createWithSpriteFrames(moveAnimFrames, 0.06f);
    moveAnimate = Animate::create(moveAnimation);

    if (moveAnimate == nullptr || moveAnimation == nullptr)
    {
        throw std::invalid_argument("cannot create moveAnimation");
    }

    moveAnimate->retain();
}

void Enemy::initJumpAnimate()
{
    std::string jumpAnimTemplate = AnimFiles.at("Jump");

    int numbFrames = 8;
    Vector<SpriteFrame*> jumpAnimFrames(numbFrames);

    for(int i = 1; i <= numbFrames; ++i)
    {
        std::string frame_str = getFrame(jumpAnimTemplate, i);
        SpriteFrame* frame = SpriteFrame::create(frame_str,
                                                 Rect(0, 0, 95, 130)
        );
        if (frame == nullptr)
        {
            std::string err =  "cannot create frame form" + frame_str;
            throw std::invalid_argument(err);
        }

        frame->setAnchorPoint(Vec2(0.5, 0));
        jumpAnimFrames.pushBack(frame);
    }

    auto jumpAnimation = Animation::createWithSpriteFrames(jumpAnimFrames, 0.15f);
    jumpAnimate = Animate::create(jumpAnimation);

    if (jumpAnimate == nullptr || jumpAnimation == nullptr)
    {
        throw std::invalid_argument("cannot create jumpAnimation");
    }

    jumpAnimate->retain();
}

void Enemy::initDeathAnimate()
{
    std::string deathAnimTemplate = AnimFiles.at("Death");

    int numbFrames = 10;

    Vector<SpriteFrame*> deathAnimFrames(numbFrames);//не забывать менять
    for(int i = 1; i <= numbFrames; ++i)
    {

        std::string frame_str = getFrame(deathAnimTemplate, i);
        SpriteFrame* frame = SpriteFrame::create(frame_str,
                                                 Rect(0, 0, 187, 139)
        );
        if (frame == nullptr)
        {
            std::string err =  "cannot create frame form" + frame_str;
            throw std::invalid_argument(err);
        }

        frame->setAnchorPoint(Vec2(0.5, 0));
        deathAnimFrames.pushBack(frame);
    }

    Animation* deathAnimation = Animation::createWithSpriteFrames(deathAnimFrames, 0.3f, 1);
    deathAnimate = Animate::create(deathAnimation);

    if (deathAnimate == nullptr || deathAnimation == nullptr)
    {
        throw std::invalid_argument("cannot create deathAnimation");
    }

    deathAnimate->retain();
}

void Enemy::initFlyingAnimate()
{
    std::string flyAnimTemplate = AnimFiles.at("Fly");

    int numbFrames = 6;

    Vector<SpriteFrame*> flyingAnimFrames(numbFrames);//не забывать менять
    for(int i = 0; i < numbFrames; ++i)
    {

        std::string frame_str = getFrame(flyAnimTemplate, i);
        SpriteFrame* frame = SpriteFrame::create(frame_str,
                                                 Rect(0, 0, 153, 128)
        );
        if (frame == nullptr)
        {
            std::string err =  "cannot create frame form" + frame_str;
            throw std::invalid_argument(err);
        }

        frame->setAnchorPoint(Vec2(0.5, 0));
        flyingAnimFrames.pushBack(frame);
    }

    Animation* flyingAnimation = Animation::createWithSpriteFrames(flyingAnimFrames, 0.15f, 10);
    flyingAnimate = Animate::create(flyingAnimation);

    if (flyingAnimate == nullptr || flyingAnimation == nullptr)
    {
        throw std::invalid_argument("cannot create flyingAnimation");
    }

    flyingAnimate->retain();
}
