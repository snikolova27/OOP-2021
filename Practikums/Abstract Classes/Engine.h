#pragma once

class Engine
{
private:
    bool state;
    static const bool ON = 1;
    static const bool OFF = 0;

public:
    Engine();
    void start();
    void stop();
};
