#include "Video.h"

Video::Video(const std::string _desc) : Details()
{
    this->description = _desc;
}
std::string Video::getVideo()
{
    return this->description;
}