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

## 🎨 Legacy Blueprint Folder Structure
Below is the comprehensive `Content/` folder structure representing every visual Blueprint, Map, Input Asset, and Sprite inside the Unreal Editor.

```text
Content/PracticeFlappyBird/
│
├── Maps/
│   ├── MAP_Menu.umap
│   └── MAP_Sandbox.umap
│
└── Features/
    ├── Background/ (Sprites & Tilemaps)
    ├── Decorations/ (Sprites)
    ├── Tiles/ (Sprites & TileMaps)
    │
    ├── Core/
    │   ├── Controller/
    │   │   └── BP_FlappyBirdController.uasset
    │   ├── GameMode/
    │   │   ├── BP_GameModeBase.uasset
    │   │   └── BP_MenuGameModeBase.uasset
    │   ├── Obstacles/
    │   │   ├── BP_Boundary.uasset
    │   │   ├── BP_DeathZone.uasset
    │   │   └── BP_Obstacle(1-3).uasset
    │   └── BP_WorldObjectManager.uasset
    │
    ├── Input/
    │   ├── CommonUI/
    │   │   ├── DA_KeyboardMouseInput.uasset
    │   │   └── InputData.uasset
    │   └── Player/
    │       ├── IA_Jump.uasset
    │       ├── IA_TogglePause.uasset
    │       └── IMC_Default.uasset
    │
    ├── Player/
    │   ├── Animations/
    │   │   ├── FB_Idle.uasset
    │   │   ├── FB_JumpDown.uasset
    │   │   └── FB_JumpUp.uasset
    │   ├── Blueprints/
    │   │   └── BP_PlayerPaperCharacter.uasset
    │   └── Sprites/
    │       └── char_blue.uasset (And associated sliced sprites)
    │
    └── UI/
        ├── Fonts/
        │   └── (Roboto Font Family .uassets)
        ├── Style/ (CommonUI Styling Assets)
        │   ├── ButtonStyle_Primary/Secondary/Danger/Ghost/IconOnly.uasset
        │   └── TextStyle_Heading1/Heading2/Body/Caption/ButtonPrimary.uasset
        │
        ├── BP_MyGameInstance.uasset
        ├── W_Button_Default.uasset
        ├── W_Countdown.uasset
        ├── W_GameHud.uasset
        ├── W_GameLayout.uasset
        ├── W_GameOver.uasset
        ├── W_MainMenu.uasset
        ├── W_MenuLayout.uasset
        ├── W_PauseMenu.uasset
        └── W_Waiting.uasset
```
