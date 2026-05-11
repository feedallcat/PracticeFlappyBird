# Practice Flappy Bird

A foundational C++ project built to study AAA game architecture, UI routing, and input management.

**Built With:** Unreal Engine 5.7

## 🌟 Key Features Implemented
* **Common UI Architecture:** Fully integrated stack-based UI routing (`GameLayout`) with C++ base classes for strictly separating Menus and HUDs.
* **Enhanced Input:** Clean input mapping contexts (IMC) tied directly to the `PlayerController`.
* **Event-Driven Data:** UI updates via `OnPlayerScoreChanged` delegates instead of expensive `Tick()` functions.
* **C++ Interfaces:** Used `MortalEntity` and `ScoreCollector` interfaces to completely decouple physical interactions (pipes, death zones) from the player class.
* **Save Game System:** Implemented standard `USaveGame` and `GameInstance` logic to cache and safely write high scores to the local hard drive.

## 📂 Legacy C++ Folder Structure
Below is the historical `Source/` folder structure, mapping out the features and class names exactly as they were completed during this practice phase.

```text
Source/PracticeFlappyBird/Features/
│
├── Core/
│   ├── GameMode/
│   │   ├── MainGameModeBase.cpp / .h
│   │   └── MenuGameModeBase.cpp / .h
│   ├── Interface/
│   │   ├── MortalEntity.cpp / .h
│   │   ├── OffscreenDespawn.cpp / .h
│   │   └── ScoreCollector.cpp / .h
│   ├── Obstacles/
│   │   ├── DeathZone.cpp / .h
│   │   ├── MovingPipe.cpp / .h
│   │   └── OffscreenBoundary.cpp / .h
│   ├── PlayerState/
│   │   └── MyPlayerState.cpp / .h
│   ├── Save/
│   │   └── FlappyBirdSaveGameData.cpp / .h
│   ├── UI/ (Common UI Foundations)
│   │   ├── CoreButtonBase.cpp / .h
│   │   ├── CoreGameScreenBase.cpp / .h
│   │   ├── CoreLayoutBase.cpp / .h
│   │   └── CoreMenuScreenBase.cpp / .h
│   ├── GameDefinitions.cpp / .h
│   ├── MainGameStateBase.cpp / .h
│   ├── MyGameInstance.cpp / .h
│   └── WorldObjectManager.cpp / .h
│
├── Input/
│   └── Player/
│       └── FlappyBirdPlayerController.cpp / .h
│
├── Player/
│   └── PlayerPaperCharacter.cpp / .h
│
└── UI/ (Concrete Layouts and Screens)
    ├── CountdownScreen.cpp / .h
    ├── GameHUDScreen.cpp / .h
    ├── GameLayout.cpp / .h
    ├── GameOverScreen.cpp / .h
    ├── MainMenuScreen.cpp / .h
    ├── PauseScreen.cpp / .h
    └── WaitingScreen.cpp / .h
```
