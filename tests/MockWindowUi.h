#pragma once

#include <QAction>
#include <QLabel>
#include <QWidget>
#include "gmock/gmock.h"
#include "view/I_WindowUi.h"

class MockWindowUi : public QWidget, public I_WindowUi
{
    Q_OBJECT
public:
    MockWindowUi();
    virtual ~MockWindowUi();

    QAction& pauseAction();
    QLabel& scoreLabel();

    void emitNewGameRequested();
    void emitResetRequested();
    void emitWireframeViewModeRequested();
    void emitFaceViewModeRequested();
    void emitMulticolouredViewModeRequested();
    void emitSpeedUpGameRequested();
    void emitSlowDownGameRequested();
    void emitAutoIncreaseGameSpeedRequested();
    void emitMovePieceLeftRequested();
    void emitMovePieceRightRequested();
    void emitRotatePieceCounterClockwiseRequested();
    void emitRotatePieceClockwiseRequested();
    void emitDropPieceRequested();

signals:
    void newGameRequested();
    void resetRequested();
    void wireframeViewModeRequested();
    void faceViewModeRequested();
    void multicolouredViewModeRequested();
    void speedUpGameRequested();
    void slowDownGameRequested();
    void autoIncreaseGameSpeedRequested();

    void movePieceLeftRequested();
    void movePieceRightRequested();
    void rotatePieceCounterClockwiseRequested();
    void rotatePieceClockwiseRequested();
    void dropPieceRequested();

private:
    QAction* pauseAction_;
    QLabel* scoreLabel_;
};
