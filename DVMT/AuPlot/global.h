#ifndef GLOBAL_H
#define GLOBAL_H

namespace global {

class sets{
public:
static const int step=512;
static const int times=16;
constexpr static double m_minBound=-80;
constexpr static double m_maxBound=0;
static const int num=6;
constexpr static double enebound=0.005;
constexpr static double rptzbound=0.4;
constexpr static double speccut=0.08;
constexpr static int perp=0.06*44100;
};

}

#endif // GLOBAL_H
