#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralMaze.generated.h"

UCLASS()
class MAZEGAME_API AProceduralMaze : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AProceduralMaze();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
    UProceduralMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Maze")
    int MazeWidth;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Maze")
    int MazeHeight;

    UFUNCTION(BlueprintCallable, Category = "Maze")
    void GenerateMaze();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    struct Cell
    {
        bool IsVisited;
        bool WallNorth, WallEast, WallSouth, WallWest;
    };

    TArray<TArray<Cell>> MazeGrid;

    void InitializeMazeGrid();
    void RecursiveBacktracker(int X, int Y);
    void CreateMeshFromGrid();
};
