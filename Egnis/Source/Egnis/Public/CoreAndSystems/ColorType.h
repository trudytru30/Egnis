#pragma once

#include "CoreMinimal.h"
#include "ColorType.generated.h"

UENUM(BlueprintType)	// Para que se pueda ver en el editor
enum class EColorType : uint8
{
	Grey UMETA(DisplayName = "Grey"),	// Todos los personajes
	Turquoise UMETA(DisplayName = "Turquoise"),	// Ataque en area
	Indigo UMETA(DisplayName = "Indigo"),	// Utilidad
	DarkMagenta UMETA(DisplayName = "Dark Magenta"),	// Ataques mas fuertes (pero mas recursos)
	Vermillion UMETA(DisplayName = "Vermillion")	// Ataques ligeros (pocos recursos)
};