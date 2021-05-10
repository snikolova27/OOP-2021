#ifndef VIDEO_H
#define VIDEO_H
#include "Details.h"

class Video : public Details
{
    private:
    std::string description;
    public:
    Video(const std::string _desc);
    std::string getVideo();
};
#endif