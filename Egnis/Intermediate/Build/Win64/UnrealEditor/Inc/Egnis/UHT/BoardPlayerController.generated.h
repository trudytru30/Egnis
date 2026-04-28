// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BoardPlayerController.h"

#ifdef EGNIS_BoardPlayerController_generated_h
#error "BoardPlayerController.generated.h already included, missing '#pragma once' in BoardPlayerController.h"
#endif
#define EGNIS_BoardPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class ACharacterBase;
class UBaseCard;
struct FClickResult;

// ********** Begin ScriptStruct FClickResult ******************************************************
#define FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FClickResult_Statics; \
	EGNIS_API static class UScriptStruct* StaticStruct();


struct FClickResult;
// ********** End ScriptStruct FClickResult ********************************************************

// ********** Begin Class ABoardPlayerController ***************************************************
#define FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCurrentHand); \
	DECLARE_FUNCTION(execBeginPlayCard); \
	DECLARE_FUNCTION(execRequestEndTurn); \
	DECLARE_FUNCTION(execGetSelectedAlly);


#define FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_49_CALLBACK_WRAPPERS
EGNIS_API UClass* Z_Construct_UClass_ABoardPlayerController_NoRegister();

#define FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_49_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoardPlayerController(); \
	friend struct Z_Construct_UClass_ABoardPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend EGNIS_API UClass* Z_Construct_UClass_ABoardPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(ABoardPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Egnis"), Z_Construct_UClass_ABoardPlayerController_NoRegister) \
	DECLARE_SERIALIZER(ABoardPlayerController)


#define FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_49_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ABoardPlayerController(ABoardPlayerController&&) = delete; \
	ABoardPlayerController(const ABoardPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoardPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoardPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoardPlayerController) \
	NO_API virtual ~ABoardPlayerController();


#define FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_46_PROLOG
#define FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_49_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_49_CALLBACK_WRAPPERS \
	FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_49_INCLASS_NO_PURE_DECLS \
	FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h_49_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ABoardPlayerController;

// ********** End Class ABoardPlayerController *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_BoardPlayerController_h

// ********** Begin Enum EInputIntent **************************************************************
#define FOREACH_ENUM_EINPUTINTENT(op) \
	op(EInputIntent::Move) \
	op(EInputIntent::Action) 

enum class EInputIntent : uint8;
template<> struct TIsUEnumClass<EInputIntent> { enum { Value = true }; };
template<> EGNIS_API UEnum* StaticEnum<EInputIntent>();
// ********** End Enum EInputIntent ****************************************************************

// ********** Begin Enum ECardSelectionState *******************************************************
#define FOREACH_ENUM_ECARDSELECTIONSTATE(op) \
	op(ECardSelectionState::None) \
	op(ECardSelectionState::SelectingUnit) \
	op(ECardSelectionState::SelectingTarget) 

enum class ECardSelectionState : uint8;
template<> struct TIsUEnumClass<ECardSelectionState> { enum { Value = true }; };
template<> EGNIS_API UEnum* StaticEnum<ECardSelectionState>();
// ********** End Enum ECardSelectionState *********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
