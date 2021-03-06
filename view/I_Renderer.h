#pragma once
/*
* CPSC 453 - Introduction to Computer Graphics
* Assignment 1
*/

class I_Renderer
{
public:
    virtual ~I_Renderer() {}

    enum ViewMode
    {
        Wireframe,
        Face,
        MultiColored
    };

    virtual void setViewMode(ViewMode viewMode) = 0;

public: //slots:
    virtual void resetView() = 0;
};
