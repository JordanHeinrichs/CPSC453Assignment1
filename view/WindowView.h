#pragma once

#include <QObject>
class I_Game;
class I_WindowUi;
class I_Renderer;
class I_GameTickerService;

class WindowView : public QObject
{
    Q_OBJECT
public:
    WindowView(I_Game& game,
       I_WindowUi& windowUi,
       I_Renderer& renderer,
       I_GameTickerService& gameTickerService);
    virtual ~WindowView();

private slots:
    void setViewModeWireframe();
    void setViewModeFace();
    void setViewModeMulticoloured();

    void handlePauseGameTriggered();
    void handleGameActiveStateChanged(bool isGameActive);
    void handleScoreChanged(int score);

private:
    void connectToKeyboardControls();
    void disconnectFromKeyboardControls();
    void connectToGame();
    void setupGameOptions();
    void setupGameTickerOptions();
    void setupViewControl();

private:
    I_Game& game_;
    I_WindowUi& windowUi_;
    I_Renderer& renderer_;
    I_GameTickerService& gameTickerService_;
};
