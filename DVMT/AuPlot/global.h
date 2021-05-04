#ifndef GLOBAL_H
#define GLOBAL_H

#define AU_VERSION "3.2.1-beta"

class global_sets{
public:
    constexpr static int FS=44100;
    constexpr static int perp=0.06*FS;
    constexpr static int step=512;
    constexpr static int times=16;
    constexpr static double m_minBound=-80;
    constexpr static double m_maxBound=0;
    constexpr static int num=3;
    constexpr static double enebound=0;
    constexpr static double rptzbound=1;
    constexpr static double speccut=0.08;
    constexpr static int maxlength=300*FS;
    constexpr static int Threads=5;
};


#endif // GLOBAL_H
