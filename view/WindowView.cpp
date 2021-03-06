#include <QAction>
#include <QLabel>

#include "businessLogic/I_Game.h"
#include "businessLogic/I_GameTickerService.h"
#include "infrastructure/ConnectionHelpers.h"
#include "view/I_Renderer.h"
#include "view/I_WindowUi.h"
#include "view/WindowView.h"

WindowView::WindowView(I_Game& game,
   I_WindowUi& windowUi,
   I_Renderer& renderer,
   I_GameTickerService& gameTickerService)
: game_(game)
, windowUi_(windowUi)
, renderer_(renderer)
, gameTickerService_(gameTickerService)
{
    setupGameOptions();
    connectToGame();
    setupGameTickerOptions();
    setupViewControl();
}

WindowView::~WindowView()
{
}

void WindowView::setViewModeWireframe()
{
    renderer_.setViewMode(I_Renderer::Wireframe);
}

void WindowView::setViewModeFace()
{
    renderer_.setViewMode(I_Renderer::Face);
}

void WindowView::setViewModeMulticoloured()
{
    renderer_.setViewMode(I_Renderer::MultiColored);
}

void WindowView::handlePauseGameTriggered()
{
    if (gameTickerService_.isGameActive())
    {
        gameTickerService_.pauseGame();
    }
    else
    {
        gameTickerService_.unpauseGame();
    }
}

void WindowView::handleGameActiveStateChanged(bool isGameActive)
{
    if (isGameActive)
    {
        connectToKeyboardControls();
        windowUi_.pauseAction().setText("&Pause");
    }
    else
    {
        disconnectFromKeyboardControls();
        windowUi_.pauseAction().setText("Un&pause");
    }
}

void WindowView::handleScoreChanged(int score)
{
    windowUi_.scoreLabel().setText(QString::number(score));
}

void WindowView::connectToKeyboardControls()
{
    safeConnectUnique(&windowUi_, SIGNAL(movePieceLeftRequested()), &game_, SLOT(moveLeft()));
    safeConnectUnique(&windowUi_, SIGNAL(movePieceRightRequested()), &game_, SLOT(moveRight()));
    safeConnectUnique(&windowUi_, SIGNAL(rotatePieceCounterClockwiseRequested()), &game_, SLOT(rotateCCW()));
    safeConnectUnique(&windowUi_, SIGNAL(rotatePieceClockwiseRequested()), &game_, SLOT(rotateCW()));
    safeConnectUnique(&windowUi_, SIGNAL(dropPieceRequested()), &game_, SLOT(drop()));
}

void WindowView::disconnectFromKeyboardControls()
{
    safeDisconnect(&windowUi_, SIGNAL(movePieceLeftRequested()), &game_, SLOT(moveLeft()));
    safeDisconnect(&windowUi_, SIGNAL(movePieceRightRequested()), &game_, SLOT(moveRight()));
    safeDisconnect(&windowUi_, SIGNAL(rotatePieceCounterClockwiseRequested()), &game_, SLOT(rotateCCW()));
    safeDisconnect(&windowUi_, SIGNAL(rotatePieceClockwiseRequested()), &game_, SLOT(rotateCW()));
    safeDisconnect(&windowUi_, SIGNAL(dropPieceRequested()), &game_, SLOT(drop()));
}

void WindowView::connectToGame()
{
    safeConnect(&game_, SIGNAL(scoreChanged(int)), this, SLOT(handleScoreChanged(int)));
}

void WindowView::setupGameOptions()
{
    safeConnect(&windowUi_, SIGNAL(newGameRequested()), &game_, SLOT(reset()));
    safeConnect(&windowUi_, SIGNAL(wireframeViewModeRequested()), this, SLOT(setViewModeWireframe()));
    safeConnect(&windowUi_, SIGNAL(faceViewModeRequested()), this, SLOT(setViewModeFace()));
    safeConnect(&windowUi_, SIGNAL(multicolouredViewModeRequested()), this, SLOT(setViewModeMulticoloured()));
}

void WindowView::setupGameTickerOptions()
{
    safeConnect(&windowUi_, SIGNAL(newGameRequested()), &gameTickerService_, SLOT(startGame()));
    safeConnect(&windowUi_.pauseAction(), SIGNAL(triggered()), this, SLOT(handlePauseGameTriggered()));
    safeConnect(&windowUi_, SIGNAL(speedUpGameRequested()), &gameTickerService_, SLOT(increaseRate()));
    safeConnect(&windowUi_, SIGNAL(slowDownGameRequested()), &gameTickerService_, SLOT(decreaseRate()));
    safeConnect(&windowUi_, SIGNAL(autoIncreaseGameSpeedRequested()), &gameTickerService_, SLOT(autoIncreaseRate()));
    safeConnect(&gameTickerService_, SIGNAL(gameActiveStateChanged(bool)), this, SLOT(handleGameActiveStateChanged(bool)));
}

void WindowView::setupViewControl()
{
    safeConnect(&windowUi_, SIGNAL(resetRequested()), &renderer_, SLOT(resetView()));
}
