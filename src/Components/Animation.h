#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

class Animation {
public:
    unsigned m_index;
    unsigned m_numFrames;
    unsigned m_animationSpeed;
    Animation() = default;
    Animation(unsigned index, unsigned numFrames, unsigned animationSpeed);
};

#endif //GAME_ANIMATION_H
