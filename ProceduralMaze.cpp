#include "ProceduralMaze.h"

// Sets default values
AProceduralMaze::AProceduralMaze()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;

    MazeWidth = 20;
    MazeHeight = 20;
}

// Called when the game starts or when spawned
void AProceduralMaze::BeginPlay()
{
    Super::BeginPlay();
}

void AProceduralMaze::GenerateMaze()
{
    InitializeMazeGrid();
    RecursiveBacktracker(0, 0);
    CreateMeshFromGrid();
}

void AProceduralMaze::InitializeMazeGrid()
{
    MazeGrid.Empty();
    MazeGrid.SetNum(MazeWidth);

    for (int i = 0; i < MazeWidth; i++)
    {
        MazeGrid[i].SetNum(MazeHeight);

        for (int j = 0; j < MazeHeight; j++)
        {
            MazeGrid[i][j].IsVisited = false;
            MazeGrid[i][j].WallNorth = true;
            MazeGrid[i][j].WallEast = true;
            MazeGrid[i][j].WallSouth = true;
            MazeGrid[i][j].WallWest = true;
        }
    }
}

void AProceduralMaze::RecursiveBacktracker(int X, int Y)
{
    // implementation of the recursive backtracker algorithm
    // TODO
}

void AProceduralMaze::CreateMeshFromGrid()
{
    // creation of procedural mesh based on the MazeGrid
    // TODO
}
