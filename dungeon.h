#pragma once

enum {
  kDoorType_Regular = 0,
  kDoorType_Regular2 = 2,
  kDoorType_4 = 4,
  kDoorType_EntranceDoor = 6,
  kDoorType_WaterfallTunnel = 8,
  kDoorType_EntranceLarge = 10,
  kDoorType_EntranceLarge2 = 12,
  kDoorType_EntranceCave = 14,
  kDoorType_EntranceCave2 = 16,
  kDoorType_ExitToOw = 18,
  kDoorType_ThroneRoom = 20,
  kDoorType_PlayerBgChange = 22,
  kDoorType_ShuttersTwoWay = 24,
  kDoorType_InvisibleDoor = 26,
  kDoorType_SmallKeyDoor = 0x1c,
  kDoorType_1E = 0x1e,
  kDoorType_StairMaskLocked0 = 32,
  kDoorType_StairMaskLocked1 = 34,
  kDoorType_StairMaskLocked2 = 36,
  kDoorType_StairMaskLocked3 = 38,
  kDoorType_BreakableWall = 0x28,
  kDoorType_LgExplosion = 48,
  kDoorType_Slashable = 50,
  kDoorType_36 = 0x36,
  kDoorType_38 = 0x38,

  kDoorType_RegularDoor33 = 64,
  kDoorType_Shutter = 68,
  kDoorType_WarpRoomDoor = 70,
  kDoorType_ShutterTrapUR = 72,
  kDoorType_ShutterTrapDL = 74,
};

struct DungPalInfo {
  uint8 pal0;
  uint8 pal1;
  uint8 pal2;
  uint8 pal3;
};

struct RoomBounds {
  union {
    struct {
      uint16 a0, b0, a1, b1;
    };
    uint16 v[4];
  };
};

#define room_bounds_y (*(RoomBounds*)(g_ram+0x600))
#define room_bounds_x (*(RoomBounds*)(g_ram+0x608))

extern const uint8 kDungAnimatedTiles[24];
uint16 *DstoPtr(uint16 d);
void Object_Fill_Nx1(int n, const uint16 *src, uint16 *dst);
void Object_Draw_5x4(const uint16 *src, uint16 *dst);
void Object_Draw_4x2_BothBgs(const uint16 *src, uint16 dsto);
void Object_ChestPlatform_Helper(const uint16 *src, int dsto);
void Object_Hole(const uint16 *src, uint16 *dst);
void LoadType1ObjectSubtype1(uint8 idx, uint16 *dst, uint16 dsto);
void Object_DrawNx3_BothBgs(int n, const uint16 *src, int dsto);
void LoadType1ObjectSubtype2(uint8 idx, uint16 *dst, uint16 dsto);
void Object_BombableFloorHelper(uint16 a, const uint16 *src, const uint16 *src_below, uint16 *dst, uint16 dsto);
void LoadType1ObjectSubtype3(uint8 idx, uint16 *dst, uint16 dsto);
void RoomBounds_AddA(RoomBounds *r);
void RoomBounds_AddB(RoomBounds *r);
void RoomBounds_SubB(RoomBounds *r);
void RoomBounds_SubA(RoomBounds *r);
void Dungeon_StartInterRoomTrans_Left();
void Dung_StartInterRoomTrans_Left_Plus();
void Dungeon_StartInterRoomTrans_Up();
void Dungeon_StartInterRoomTrans_Down();
void Dungeon_Store2x2(uint16 pos, uint16 t0, uint16 t1, uint16 t2, uint16 t3, uint8 attr);
uint16 Dungeon_MapVramAddr(uint16 pos);
uint16 Dungeon_MapVramAddrNoSwap(uint16 pos);
void Door_Up_EntranceDoor(uint16 dsto);
void Door_Down_EntranceDoor(uint16 dsto);
void Door_Left_EntranceDoor(uint16 dsto);
void Door_Right_EntranceDoor(uint16 dsto);
void Door_Draw_Helper4(uint8 door_type, uint16 dsto);
const uint16 *GetRoomDoorInfo(int room);
const uint8 *GetRoomHeaderPtr(int room);
const uint8 *GetDefaultRoomLayout(int i);
const uint8 *GetDungeonRoomLayout(int i);
void Dung_TagRoutine_0x22_0x3B(int k, uint8 j);
void Sprite_HandlePushedBlocks_One(int i);
void Object_Draw_DoorLeft_3x4(uint16 src, int door);
void Object_Draw_DoorRight_3x4(uint16 src, int door);
void Dungeon_OpeningLockedDoor_Combined(bool skip_anim);
const DungPalInfo *GetDungPalInfo(int idx);
uint16 Dungeon_GetTeleMsg(int room);
uint8 GetEntranceMusicTrack(int entrance);
bool Dungeon_IsPitThatHurtsPlayer();
void Dungeon_PrepareNextRoomQuadrantUpload();
void WaterFlood_BuildOneQuadrantForVRAM();
void TileMapPrep_NotWaterOnTag();
void OrientLampLightCone();
void PrepareDungeonExitFromBossFight();
void SavePalaceDeaths();
void Dungeon_LoadRoom();
void RoomDraw_DrawAllObjects(const uint8 *level_data);
void RoomData_DrawObject_Door(uint16 a);
void RoomData_DrawObject(uint16 r0, const uint8 *level_data);
void RoomDraw_DrawFloors(const uint8 *level_data);
void RoomDraw_FloorChunks(const uint16 *src);
void RoomDraw_A_Many32x32Blocks(int n, const uint16 *src, uint16 *dst);
void RoomDraw_1x3_rightwards(int n, const uint16 *src, uint16 *dst);
bool RoomDraw_CheckIfWallIsMoved();
void MovingWall_FillReplacementBuffer(int dsto);
void Object_Table_Helper(const uint16 *src, uint16 *dst);
void DrawWaterThing(uint16 *dst, const uint16 *src);
void RoomDraw_4x4(const uint16 *src, uint16 *dst);
void RoomDraw_Object_Nx4(int n, const uint16 *src, uint16 *dst);
void Object_DrawNx4_BothBgs(int n, const uint16 *src, int dsto);
void RoomDraw_Rightwards2x2(const uint16 *src, uint16 *dst);
void Object_Draw_3x2(const uint16 *src, uint16 *dst);
void RoomDraw_WaterHoldingObject(int n, const uint16 *src, uint16 *dst);
void RoomDraw_SomeBigDecors(int n, const uint16 *src, uint16 dsto);
void RoomDraw_SingleLampCone(uint16 a, uint16 y);
void RoomDraw_AgahnimsWindows(uint16 dsto);
void RoomDraw_FortuneTellerRoom(uint16 dsto);
void Object_Draw8x8(const uint16 *src, uint16 *dst);
void RoomDraw_Door_North(int type, int pos_enum);
void Door_Up_StairMaskLocked(uint8 door_type, uint16 dsto);
void Door_PrioritizeCurDoor();
void RoomDraw_NormalRangedDoors_North(uint8 door_type, uint16 dsto, int pos_enum);
void RoomDraw_OneSidedShutters_North(uint8 door_type, uint16 dsto);
void RoomDraw_Door_South(int type, int pos_enum);
void RoomDraw_CheckIfLowerLayerDoors_Y(uint8 door_type, uint16 dsto);
void RoomDraw_Door_West(int type, int pos_enum);
void RoomDraw_NormalRangedDoors_West(uint8 door_type, uint16 dsto, int pos_enum);
void RoomDraw_Door_East(int type, int pos_enum);
void RoomDraw_NormalRangedDoors_East(uint8 door_type, uint16 dsto);
void RoomDraw_OneSidedShutters_East(uint8 door_type, uint16 dsto);
void RoomDraw_NorthCurtainDoor(uint16 dsto);
void RoomDraw_Door_ExplodingWall(int pos_enum);
void RoomDraw_ExplodingWallSegment(const uint16 *src, uint16 dsto);
void RoomDraw_ExplodingWallColumn(const uint16 *src, uint16 *dst);
void RoomDraw_HighRangeDoor_North(uint8 door_type, uint16 dsto, int pos_enum);
void RoomDraw_OneSidedLowerShutters_South(uint8 door_type, uint16 dsto);
void RoomDraw_HighRangeDoor_West(uint8 door_type, uint16 dsto, int pos_enum);
void RoomDraw_OneSidedLowerShutters_East(uint8 door_type, uint16 dsto);
void RoomDraw_MakeDoorHighPriority_North(uint16 dsto);
void RoomDraw_MakeDoorHighPriority_South(uint16 dsto);
void RoomDraw_MakeDoorHighPriority_West(uint16 dsto);
void RoomDraw_MakeDoorHighPriority_East(uint16 dsto);
void RoomDraw_MarkDungeonToggleDoor(uint16 dsto);
void RoomDraw_MarkLayerToggleDoor(uint16 dsto);
void RoomDraw_GetObjectSize_1to16();
void Object_SizeAtoAplus15(uint8 a);
void RoomDraw_GetObjectSize_1to15or26();
void RoomDraw_GetObjectSize_1to15or32();
int RoomDraw_FlagDoorsAndGetFinalType(uint8 direction, uint8 door_type, uint16 dsto);
void RoomDraw_MakeDoorPartsHighPriority_Y(uint16 dsto);
void RoomDraw_MakeDoorPartsHighPriority_X(uint16 dsto);
void RoomDraw_Downwards4x2VariableSpacing(int increment, const uint16 *src, uint16 *dst);
uint16 *RoomDraw_DrawObject2x2and1(const uint16 *src, uint16 *dst);
uint16 *RoomDraw_RightwardShelfEnd(const uint16 *src, uint16 *dst);
uint16 *RoomDraw_RightwardBarSegment(const uint16 *src, uint16 *dst);
void DrawBigGraySegment(uint16 a, const uint16 *src, uint16 *dst, uint16 dsto);
void RoomDraw_SinglePot(const uint16 *src, uint16 *dst, uint16 dsto);
void RoomDraw_BombableFloor(const uint16 *src, uint16 *dst, uint16 dsto);
void RoomDraw_HammerPegSingle(const uint16 *src, uint16 *dst, uint16 dsto);
void DrawObjects_PushableBlock(uint16 dsto_x2, uint16 slot);
void DrawObjects_LightableTorch(uint16 dsto_x2, uint16 slot);
void Dungeon_LoadHeader();
void Dungeon_CheckAdjacentRoomsForOpenDoors(int idx, int room);
void Dungeon_LoadAdjacentRoomDoors(int room);
void Dungeon_LoadAttribute_Selectable();
void Dungeon_LoadAttributeTable();
void Dungeon_LoadBasicAttribute_full(uint16 loops);
void Dungeon_LoadObjectAttribute();
void Dungeon_LoadDoorAttribute();
void Dungeon_LoadSingleDoorAttribute(int k);
void Door_LoadBlastWallAttr(int k);
void ChangeDoorToSwitch();
void Dungeon_FlipCrystalPegAttribute();
void Dungeon_HandleRoomTags();
void Dung_TagRoutine_0x00(int k);
void Dungeon_DetectStaircase();
void RoomTag_NorthWestTrigger(int k);
void Dung_TagRoutine_0x2A(int k);
void Dung_TagRoutine_0x2B(int k);
void Dung_TagRoutine_0x2C(int k);
void Dung_TagRoutine_0x2D(int k);
void Dung_TagRoutine_0x2E(int k);
void Dung_TagRoutine_0x2F(int k);
void Dung_TagRoutine_0x30(int k);
void RoomTag_QuadrantTrigger(int k);
void Dung_TagRoutine_TrapdoorsUp();
void RoomTag_RoomTrigger(int k);
void RoomTag_RekillableBoss(int k);
void RoomTag_RoomTrigger_BlockDoor(int k);
void RoomTag_PrizeTriggerDoorDoor(int k);
void RoomTag_SwitchTrigger_HoldDoor(int k);
void RoomTag_SwitchTrigger_ToggleDoor(int k);
void PushPressurePlate(uint8 attr);
void RoomTag_TorchPuzzleDoor(int k);
void RoomTag_Switch_ExplodingWall(int k);
void RoomTag_PullSwitchExplodingWall(int k);
void Dung_TagRoutine_BlastWallStuff(int k);
void RoomTag_GetHeartForPrize(int k);
void RoomTag_Agahnim(int k);
void RoomTag_GanonDoor(int tagidx);
void RoomTag_KillRoomBlock(int k);
void RoomTag_PushBlockForChest(int k);
void RoomTag_TriggerChest(int k);
void RoomTag_OperateChestReveal(int k);
void RoomTag_TorchPuzzleChest(int k);
void RoomTag_MovingWall_East(int k);
void RoomTag_MovingWallShakeItUp(int k);
void RoomTag_MovingWall_West(int k);
void RoomTag_MovingWallTorchesCheck(int k);
int MovingWall_MoveALittle();
int RoomTag_AdvanceGiganticWall(int k);
void RoomTag_WaterOff(int k);
void RoomTag_WaterOn(int k);
void RoomTag_WaterGate(int k);
void Dung_TagRoutine_0x1B(int k);
void RoomTag_Holes0(int k);
void Dung_TagRoutine_0x23(int k);
void Dung_TagRoutine_0x34(int k);
void Dung_TagRoutine_0x35(int k);
void Dung_TagRoutine_0x36(int k);
void Dung_TagRoutine_0x37(int k);
void Dung_TagRoutine_0x39(int k);
void Dung_TagRoutine_0x3A(int k);
void Dung_TagRoutine_Func2(uint8 av);
void RoomTag_ChestHoles0(int k);
void Dung_TagRoutine_0x3B(int k);
void RoomTag_Holes2(int k);
void RoomTag_OperateWaterFlooring();
bool RoomTag_MaybeCheckShutters(uint8 *attr_out);
int RoomTag_GetTilemapCoords();
bool RoomTag_CheckForPressedSwitch(uint8 *y_out);
void Dungeon_ProcessTorchesAndDoors();
void Bomb_CheckForDestructibles(uint16 x, uint16 y, uint8 r14);
int DrawDoorOpening_Step1(int door, int dma_ptr);
void DrawShutterDoorSteps(int door);
void DrawEyeWatchDoor(int door);
void Door_BlastWallExploding_Draw(int dsto);
void OperateShutterDoors();
void OpenCrackedDoor();
void Dungeon_LoadToggleDoorAttr_OtherEntry(int door);
void Dungeon_LoadSingleDoorTileAttribute();
void DrawCompletelyOpenDoor();
void Dungeon_ClearAwayExplodingWall();
uint16 Dungeon_CheckForAndIDLiftableTile();
void Dungeon_PushBlock_Handler();
void RoomDraw_16x16Single(uint8 index);
void PushBlock_CheckForPit(uint8 y);
uint8 Dungeon_LiftAndReplaceLiftable(Point16U *pt);
uint8 ThievesAttic_DrawLightenedHole(uint16 pos6, uint16 a, Point16U *pt);
uint8 HandleItemTileAction_Dungeon(uint16 x, uint16 y);
void ManipBlock_Something(Point16U *pt);
void RevealPotItem(uint16 pos6, uint16 pos4);
void Dungeon_UpdateTileMapWithCommonTile(int x, int y, uint8 v);
void Dungeon_PrepSpriteInducedDma(int x, int y, uint8 v);
void Dungeon_DeleteRupeeTile(uint16 x, uint16 y);
uint8 OpenChestForItem(uint8 tile, int *chest_position);
void OpenBigChest(uint16 loc, int *chest_position);
uint8 OpenMiniGameChest(int *chest_position);
uint16 RoomTag_BuildChestStripes(uint16 pos, uint16 y);
void Dungeon_SetAttrForActivatedWaterOff();
void Dungeon_FloodSwampWater_PrepTileMap();
void Dungeon_AdjustWaterVomit(const uint16 *src, int depth);
void Dungeon_SetAttrForActivatedWater();
void FloodDam_Expand();
void FloodDam_PrepTiles_init();
void Watergate_Main_State1();
void FloodDam_Fill();
void Ganon_ExtinguishTorch_adjust_translucency();
void Ganon_ExtinguishTorch();
void Dungeon_ExtinguishTorch();
void SpiralStairs_MakeNearbyWallsHighPriority_Entering();
void SpiralStairs_MakeNearbyWallsLowPriority();
void ClearAndStripeExplodingWall(uint16 dsto);
void Dungeon_DrawRoomOverlay(const uint8 *src);
void GetDoorDrawDataIndex_North_clean_door_index(int door);
int DoorDoorStep1_North(int door, int dma_ptr);
void GetDoorDrawDataIndex_North(int door, int r4_door);
void DrawDoorToTileMap_North(int door, int r4_door);
void Object_Draw_DoorUp_4x3(uint16 src, int door);
void GetDoorDrawDataIndex_South_clean_door_index(int door);
int DoorDoorStep1_South(int door, int dma_ptr);
void GetDoorDrawDataIndex_South(int door, int r4_door);
void DrawDoorToTileMap_South(int door, int r4_door);
void Object_Draw_DoorDown_4x3(uint16 src, int door);
void GetDoorDrawDataIndex_West_clean_door_index(int door);
int DoorDoorStep1_West(int door, int dma_ptr);
void GetDoorDrawDataIndex_West(int door, int r4_door);
void DrawDoorToTileMap_West(int door, int r4_door);
void GetDoorDrawDataIndex_East_clean_door_index(int door);
int DoorDoorStep1_East(int door, int dma_ptr);
void GetDoorDrawDataIndex_East(int door, int r4_door);
void DrawDoorToTileMap_East(int door, int r4_door);
uint8 GetDoorGraphicsIndex(int door, int r4_door);
void ClearExplodingWallFromTileMap_ClearOnePair(uint16 *dst, const uint16 *src);
void Dungeon_DrawRoomOverlay_Apply(int p);
void ApplyGrayscaleFixed_Incremental();
void Dungeon_ApproachFixedColor_variable(uint8 a);
void Module_PreDungeon();
void Module_PreDungeon_setAmbientSfx();
void LoadOWMusicIfNeeded();
void Module07_Dungeon();
void Dungeon_TryScreenEdgeTransition();
void Dungeon_HandleEdgeTransitionMovement(int dir);
void Module07_00_PlayerControl();
void Module07_01_SubtileTransition();
void DungeonTransition_Subtile_ResetShutters();
void DungeonTransition_Subtile_PrepTransition();
void DungeonTransition_Subtile_ApplyFilter();
void DungeonTransition_Subtile_TriggerShutters();
void Module07_02_SupertileTransition();
void Module07_02_00_InitializeTransition();
void Module07_02_01_LoadNextRoom();
void Dungeon_InterRoomTrans_State3();
void Dungeon_InterRoomTrans_State10();
void Dungeon_SpiralStaircase11();
void Dungeon_InterRoomTrans_notDarkRoom();
void Dungeon_InterRoomTrans_State9();
void Dungeon_SpiralStaircase12();
void Dungeon_InterRoomTrans_State4();
void Dungeon_InterRoomTrans_State12();
void Dungeon_Staircase14();
void Dungeon_ResetTorchBackgroundAndPlayer();
void Dungeon_ResetTorchBackgroundAndPlayerInner();
void Dungeon_InterRoomTrans_State7();
void DungeonTransition_RunFiltering();
void Module07_02_FadedFilter();
void Dungeon_InterRoomTrans_State15();
void Dungeon_PlayMusicIfDefeated();
void Module07_03_OverlayChange();
void Module07_04_UnlockDoor();
void Module07_05_ControlShutters();
void Module07_06_FatInterRoomStairs();
void Module07_0E_01_HandleMusicAndResetProps();
void ResetTransitionPropsAndAdvance_ResetInterface();
void ResetTransitionPropsAndAdvanceSubmodule();
void Dungeon_InitializeRoomFromSpecial();
void DungeonTransition_LoadSpriteGFX();
void DungeonTransition_AdjustForFatStairScroll();
void ResetThenCacheRoomEntryProperties();
void DungeonTransition_TriggerBGC34UpdateAndAdvance();
void DungeonTransition_TriggerBGC56UpdateAndAdvance();
void Module07_07_FallingTransition();
void Module07_07_00_HandleMusicAndResetRoom();
void Module07_07_06_SyncBG1and2();
void Module07_07_0F_FallingFadeIn();
void Dungeon_PlayBlipAndCacheQuadrantVisits();
void Module07_07_10_LandLinkFromFalling();
void Module07_07_11_CacheRoomAndSetMusic();
void Module07_08_NorthIntraRoomStairs();
void Module07_08_00_InitStairs();
void Module07_08_01_ClimbStairs();
void Module07_10_SouthIntraRoomStairs();
void Module07_10_00_InitStairs();
void Module07_10_01_ClimbStairs();
void Module07_09_OpenCrackedDoor();
void Module07_0A_ChangeBrightness();
void Module07_0B_DrainSwampPool();
void Module07_0C_FloodSwampWater();
void Module07_0D_FloodDam();
void Module07_0E_SpiralStairs();
void Dungeon_DoubleApplyAndIncrementGrayscale();
void Module07_0E_02_ApplyFilterIf();
void Dungeon_SyncBackgroundsFromSpiralStairs();
void Dungeon_AdvanceThenSetBossMusicUnorthodox();
void Dungeon_SetBossMusicUnorthodox();
void Dungeon_SpiralStaircase17();
void Dungeon_SpiralStaircase18();
void Module07_0E_00_InitPriorityAndScreens();
void Module07_0E_13_SetRoomAndLayerAndCache();
void RepositionLinkAfterSpiralStairs();
void SpiralStairs_MakeNearbyWallsHighPriority_Exiting();
void Module07_0F_LandingWipe();
void Module07_0F_00_InitSpotlight();
void Module07_0F_01_OperateSpotlight();
void Module07_11_StraightInterroomStairs();
void Module07_11_00_PrepAndReset();
void Module07_11_01_FadeOut();
void Module07_11_02_LoadAndPrepRoom();
void Module07_11_03_FilterAndLoadBGChars();
void Module07_11_04_FilterDoBGAndResetSprites();
void Module07_11_0B_PrepDestination();
void Module07_11_09_LoadSpriteGraphics();
void Module07_11_19_SetSongAndFilter();
void Module07_11_11_KeepSliding();
void Module07_14_RecoverFromFall();
void Module07_14_00_ScrollCamera();
void Module07_15_WarpPad();
void Module07_15_01_ApplyMosaicAndFilter();
void Module07_15_04_SyncRoomPropsAndBuildOverlay();
void Module07_15_0E_FadeInFromWarp();
void Module07_15_0F_FinalizeAndCacheEntry();
void Module07_16_UpdatePegs();
void Module07_17_PressurePlate();
void Module07_18_RescuedMaiden();
void Module07_19_MirrorFade();
void Module07_1A_RoomDraw_OpenTriforceDoor_bounce();
void Module11_DungeonFallingEntrance();
void Module11_02_LoadEntrance();
void Dungeon_LoadSongBankIfNeeded();
void Mirror_SaveRoomData();
void SaveDungeonKeys();
void Dungeon_AdjustAfterSpiralStairs();
void Dungeon_AdjustForTeleportDoors(uint8 room, uint8 flag);
void Dungeon_AdjustForRoomLayout();
void HandleEdgeTransitionMovementEast_RightBy8();
void Dungeon_StartInterRoomTrans_Right();
void HandleEdgeTransitionMovementSouth_DownBy16();
void Dung_HandleExitToOverworld();
void AdjustQuadrantAndCamera_right();
void SetAndSaveVisitedQuadrantFlags();
void SaveQuadrantsToSram();
void AdjustQuadrantAndCamera_left();
void AdjustQuadrantAndCamera_down();
void AdjustQuadrantAndCamera_up();
void Dungeon_FlagRoomData_Quadrants();
void Dung_SaveDataForCurrentRoom();
void HandleEdgeTransition_AdjustCameraBoundaries(uint8 arg);
void Dungeon_AdjustQuadrant();
void Dungeon_HandleCamera();
void MirrorBg1Bg2Offs();
void DungeonTransition_AdjustCamera_X(uint8 arg);
void DungeonTransition_AdjustCamera_Y(uint8 arg);
void DungeonTransition_ScrollRoom();
void Module07_11_0A_ScrollCamera();
void DungeonTransition_FindSubtileLanding();
void SubtileTransitionCalculateLanding();
void Dungeon_InterRoomTrans_State13();
void Dungeon_IntraRoomTrans_State5();
bool DungeonTransition_MoveLinkOutDoor();
uint8 CalculateTransitionLanding();
void Dungeon_LoadAndDrawRoom();
void Dungeon_LoadEntrance();
void PushBlock_Slide(uint8 j);
void PushBlock_HandleFalling(uint8 y);
void PushBlock_ApplyVelocity(uint8 i);
void PushBlock_HandleCollision(uint8 i, uint16 x, uint16 y);
void Sprite_Dungeon_DrawAllPushBlocks();
void UsedForStraightInterRoomStaircase();
void HandleLinkOnSpiralStairs();
void SpiralStairs_FindLandingSpot();
void Dungeon_HandleLayerEffect();
void LayerEffect_Nothing();
void LayerEffect_Scroll();
void LayerEffect_Trinexx();
void LayerEffect_Agahnim2();
void LayerEffect_InvisibleFloor();
void LayerEffect_Ganon();
void LayerEffect_WaterRapids();
void Dungeon_LoadCustomTileAttr();
void Link_CheckBunnyStatus();
void CrystalCutscene_Initialize();
void CrystalCutscene_SpawnMaiden();
